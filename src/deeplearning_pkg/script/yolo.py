# import cv2
# from ultralytics import YOLO

# class YOLODetector:
#     def __init__(self, model_path="yolov8n.pt"):  # Default to YOLOv8 nano model
#         # Load the YOLO model
#         self.model = YOLO(model_path)
#         print(f"Model {model_path} loaded successfully.")

#     def detect_objects(self, frame):
#         # Perform detection
#         results = self.model(frame, stream=True)
#         detections = []
#         for result in results:
#             # Process detections
#             for box in result.boxes:
#                 x1, y1, x2, y2 = map(int, box.xyxy[0])  # Bounding box coordinates
#                 conf = box.conf[0]  # Confidence
#                 cls = int(box.cls[0])  # Class ID
#                 detections.append((x1, y1, x2, y2, conf, cls))
#         return detections

#     def draw_detections(self, frame, detections, class_names):
#         for x1, y1, x2, y2, conf, cls in detections:
#             label = f"{class_names[cls]} {conf:.2f}"
#             color = (0, 255, 0)  # Green bounding box
#             cv2.rectangle(frame, (x1, y1), (x2, y2), color, 2)
#             cv2.putText(frame, label, (x1, y1 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, color, 2)
#         return frame

# def main():
#     # Define video source (0 for webcam, or path to a video file)
#     video_source = 0  # Change to video file path if needed

#     # Initialize the YOLO detector
#     detector = YOLODetector(model_path="yolov8n.pt")  # Use your custom model path if needed

#     # Class names (use your own if you have custom training)
#     class_names = detector.model.names  # Predefined YOLOv8 class names

#     # Open the video source
#     cap = cv2.VideoCapture(video_source)
#     if not cap.isOpened():
#         print("Error: Unable to open video source.")
#         return

#     while True:
#         ret, frame = cap.read()
#         if not ret:
#             print("End of video stream.")
#             break

#         # Detect objects
#         detections = detector.detect_objects(frame)

#         # Draw detections on the frame
#         frame = detector.draw_detections(frame, detections, class_names)

#         # Display the result
#         cv2.imshow("YOLO Object Detection", frame)

#         # Break the loop on 'q' key press
#         if cv2.waitKey(1) & 0xFF == ord('q'):
#             break

#     # Release resources
#     cap.release()
#     cv2.destroyAllWindows()

# if __name__ == "__main__":
#     main()


import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
from ultralytics import YOLO

class YoloImageProcessor(Node):
    def __init__(self):
        super().__init__('yolo_image_processor')
        self.bridge = CvBridge()
        
        # Load YOLO model
        self.yolo_model = YOLO('yolov8n.engine')  # Use a YOLO model

        # Image subscriber
        self.image_subscriber = self.create_subscription(
            Image,
            '/zed/zed_node/left/image_rect_color',  # Change this to your input topic
            self.image_callback,
            10
        )

        # Image publisher
        self.image_publisher = self.create_publisher(
            Image,
            '/output_image_topic',  # Change this to your output topic
            10
        )

    def image_callback(self, msg):
        self.get_logger().info('Received an image!')

        # Convert ROS Image to OpenCV image
        cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')

        # Perform object detection with YOLO
        results = self.yolo_model(cv_image)

        # Draw bounding boxes on the images
        annotated_image = results[0].plot()

        # Convert OpenCV image back to ROS Image and publish
        ros_image = self.bridge.cv2_to_imgmsg(annotated_image, encoding='bgr8')
        self.image_publisher.publish(ros_image)
        self.get_logger().info('Published annotated image!')


def main(args=None):
    rclpy.init(args=args)
    node = YoloImageProcessor()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
