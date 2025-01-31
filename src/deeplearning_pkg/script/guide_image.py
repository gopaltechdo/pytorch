# import rclpy
# from rclpy.node import Node
# from sensor_msgs.msg import Image
# from cv_bridge import CvBridge
# import cv2
# import numpy as np

# class ImageVisualizer(Node):
#     def __init__(self):
#         super().__init__('image_visualizer')

#         # Subscribe to the RGB image topic
#         self.subscription = self.create_subscription(
#             Image,
#             '/zed/zed_node/rgb/image_rect_color',
#             self.image_callback,
#             10
#         )

#         # Publisher for the processed image
#         self.publisher = self.create_publisher(
#             Image,
#             '/guide_image',
#             10
#         )

#         # Bridge for converting ROS images to OpenCV
#         self.bridge = CvBridge()

#     def image_callback(self, msg):
#         try:
#             # Convert the ROS Image message to OpenCV format
#             frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')

#             # Get frame dimensions
#             height, width, _ = frame.shape

#             # Define points for the lines
#             red_line = [(int(0.02 * width), int(0.9 * height)), (int(0.99 * width), int(0.9 * height))]
#             green_line = [(int(0.20 * width), int(0.5 * height)), (int(0.85 * width), int(0.5 * height))]
#             yellow_line_2 = [(int(0.11 * width), int(0.7 * height)), (int(0.92 * width), int(0.7 * height))]

#             frame_lines = [
#                 (int(0.20 * width), int(0.5 * height)),  # Left vertical (yellow zone)
#                 (int(0.02 * width), int(0.9 * height)),  # Left vertical (red zone)
#                 (int(0.85 * width), int(0.5 * height)),  # Right vertical (yellow zone)
#                 (int(0.99 * width), int(0.9 * height)),  # Right vertical (red zone)
#             ]

#             # Draw red line
#             cv2.line(frame, red_line[0], red_line[1], (0, 0, 255), thickness=3)

#             # Draw yellow lines
#             cv2.line(frame, green_line[0], green_line[1], (0, 255, 0), thickness=3)
#             cv2.line(frame, yellow_line_2[0], yellow_line_2[1], (0, 255, 255), thickness=3)

#             # Draw the vertical lines connecting red and yellow lines
#             cv2.line(frame, frame_lines[0], frame_lines[1], (0, 255, 255), thickness=3)
#             cv2.line(frame, frame_lines[2], frame_lines[3], (0, 255, 255), thickness=3)

#             # Publish the processed image
#             guide_image_msg = self.bridge.cv2_to_imgmsg(frame, encoding='bgr8')
#             self.publisher.publish(guide_image_msg)

#             self.get_logger().info('Published guide image with proximity lines.')

#         except Exception as e:
#             self.get_logger().error(f'Failed to process image: {e}')


# def main(args=None):
#     rclpy.init(args=args)
#     visualizer = ImageVisualizer()
#     rclpy.spin(visualizer)
#     visualizer.destroy_node()
#     rclpy.shutdown()

# if __name__ == '__main__':
#     main()


import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np
from http.server import BaseHTTPRequestHandler, HTTPServer
import threading
import time

class ImageVisualizer(Node):
    def __init__(self):
        super().__init__('image_visualizer')

        # Subscribe to the RGB image topic
        self.subscription = self.create_subscription(
            Image,
           '/zed/zed_node/rgb/image_rect_color',
            self.image_callback,
            10
        )

        # Bridge for converting ROS images to OpenCV
        self.bridge = CvBridge()
        self.latest_frame = None
        self.lock = threading.Lock()

    def image_callback(self, msg):
        try:
            # Convert the ROS Image message to OpenCV format
            frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')

            # Get frame dimensions
            height, width, _ = frame.shape

            # Define points for the lines
            red_line = [(int(0.02 * width), int(0.9 * height)), (int(0.99 * width), int(0.9 * height))]
            yellow_line = [(int(0.20 * width), int(0.5 * height)), (int(0.85 * width), int(0.5 * height))]
            yellow_line_2 = [(int(0.11 * width), int(0.7 * height)), (int(0.92 * width), int(0.7 * height))]

            frame_lines = [
                (int(0.20 * width), int(0.5 * height)),  # Left vertical (yellow zone)
                (int(0.02 * width), int(0.9 * height)),  # Left vertical (red zone)
                (int(0.85 * width), int(0.5 * height)),  # Right vertical (yellow zone)
                (int(0.99 * width), int(0.9 * height)),  # Right vertical (red zone)
            ]

            # Draw red line
            cv2.line(frame, red_line[0], red_line[1], (0, 0, 255), thickness=3)

            # Draw yellow lines
            cv2.line(frame, yellow_line[0], yellow_line[1], (0, 255, 0), thickness=3)
            cv2.line(frame, yellow_line_2[0], yellow_line_2[1], (0, 255, 255), thickness=3)

            # Draw the vertical lines connecting red and yellow lines
            cv2.line(frame, frame_lines[0], frame_lines[1], (0, 255, 255), thickness=3)
            cv2.line(frame, frame_lines[2], frame_lines[3], (0, 255, 255), thickness=3)

            # Update the latest frame
            with self.lock:
                self.latest_frame = frame.copy()

        except Exception as e:
            self.get_logger().error(f'Failed to process image: {e}')


class HTTPImageServer(BaseHTTPRequestHandler):
    def do_GET(self):
        if self.path == '/video_feed':
            self.send_response(200)
            self.send_header('Content-type', 'multipart/x-mixed-replace; boundary=frame')
            self.end_headers()

            while True:
                if visualizer.latest_frame is not None:
                    with visualizer.lock:
                        # Encode the latest frame as JPEG
                        _, jpeg = cv2.imencode('.jpg', visualizer.latest_frame)
                    self.wfile.write(b'--frame\r\n')
                    self.wfile.write(b'Content-Type: image/jpeg\r\n\r\n')
                    self.wfile.write(jpeg.tobytes())
                    self.wfile.write(b'\r\n')

                time.sleep(0.1)  # Reduce CPU usage
        else:
            self.send_response(404)
            self.end_headers()


def main(args=None):
    global visualizer
    rclpy.init(args=args)
    visualizer = ImageVisualizer()

    # Start ROS 2 spinning in a separate thread
    ros_thread = threading.Thread(target=rclpy.spin, args=(visualizer,))
    ros_thread.start()

    try:
        # Start HTTP server
        server = HTTPServer(('192.168.0.205', 8080), HTTPImageServer)
        print("Server started at http://192.168.0.205:8080/video_feed")
        server.serve_forever()
    finally:
        visualizer.destroy_node()
        rclpy.shutdown()
        ros_thread.join()


if __name__ == '__main__':
    main()
