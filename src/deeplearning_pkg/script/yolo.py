

# # import rclpy
# # from rclpy.node import Node
# # from sensor_msgs.msg import Image
# # from cv_bridge import CvBridge
# # import cv2
# # from ultralytics import YOLO

# # class YoloImageProcessor(Node):

# #     def __init__(self):
# #         super().__init__('yolo_image_processor')
# #         self.bridge = CvBridge()
        
# #         # Load YOLO model
# #         self.yolo_model = YOLO('yolo11n.engine')  # Use a YOLO model

# #         # Image subscriber
# #         self.image_subscriber = self.create_subscription(
# #             Image,
# #             '/zed/zed_node/left/image_rect_color',  # Change this to your input topic
# #             self.image_callback,
# #             10
# #         )

# #         # Image publisher
# #         self.image_publisher = self.create_publisher(
# #             Image,
# #             '/output_image_topic',  # Change this to your output topic
# #             10
# #         )
# #     def calculate_distance(bbox, frame_width, frame_height):
# #             # Define a safe distance threshold (in meters, for demonstration)
# #         SAFE_DISTANCE =0.3  # Adjust based on sensor or application

# #         """
# #         Estimate distance from the object based on bounding box size.
# #         Adjust the calculation based on actual sensor calibration.
# #         """
# #         bbox_width = bbox[2] - bbox[0]
# #         # Simple heuristic: the smaller the box, the farther the object
# #         distance = SAFE_DISTANCE * frame_width / (bbox_width + 1e-5)  # Avoid division by zero
# #         return round(distance, 2)   
# #     def image_callback(self, msg):
# #             self.get_logger().info('Received an image!')

# #             # Get frame dimensions


# #             # Convert ROS Image to OpenCV image
# #             cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')

# #             # Perform object detection with YOLO
# #             results = self.yolo_model(cv_image)

# #             # Draw bounding boxes on the images
# #             annotated_image = results[0].plot()

# #             # Convert OpenCV image back to ROS Image and publish
# #             ros_image = self.bridge.cv2_to_imgmsg(annotated_image, encoding='bgr8')
# #             self.image_publisher.publish(ros_image)
# #             self.get_logger().info('Published annotated image!')


# # def main(args=None):
# #     rclpy.init(args=args)
# #     node = YoloImageProcessor()
# #     try:
# #         rclpy.spin(node)
# #     except KeyboardInterrupt:
# #         pass
# #     finally:
# #         node.destroy_node()
# #         rclpy.shutdown()


# # if __name__ == '__main__':
# #     main()


# import rclpy
# from rclpy.node import Node
# from sensor_msgs.msg import Image
# from cv_bridge import CvBridge
# import cv2
# from ultralytics import YOLO

# from std_msgs.msg import String

# class YoloImageProcessor(Node):

#     def __init__(self):
#         super().__init__('yolo_image_processor')
#         self.bridge = CvBridge()
        
#         # Load YOLO model
#         self.yolo_model = YOLO('yolo11n.engine')  # Use a YOLO model

#         # Image subscriber
#         self.image_subscriber = self.create_subscription(
#             Image,
#             '/zed/zed_node/left/image_rect_color',  # Change this to your input topic
#             self.image_callback,
#             10
#         )

#         self.timer = self.create_timer(1.0, self.publish_text)

#         # Image publisher
#         self.image_publisher = self.create_publisher(
#             Image,
#             '/output_image_topic',  # Change this to your output topic
#             10
#         )
#     def publish_text(self):
#             msg = String()
#             msg.data = 'Hello, ROS 2!'
#             self.publisher_.publish(msg)
#             self.get_logger().info(f'Published: "{msg.data}"')

#     @staticmethod
#     def calculate_distance(bbox, frame_width, frame_height):
#         """
#         Estimate distance from the object based on bounding box size.
#         Adjust the calculation based on actual sensor calibration.
#         """
#         SAFE_DISTANCE = 0.3  # Adjust this threshold as per your application
#         bbox_width = bbox[2] - bbox[0]
#         distance = SAFE_DISTANCE * frame_width / (bbox_width + 1e-5)  # Avoid division by zero
#         return round(distance, 2)

#     def image_callback(self, msg):
#         self.get_logger().info('Received an image!')

#         # Convert ROS Image to OpenCV image
#         cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')

#         # Get frame dimensions
#         frame_height, frame_width, _ = cv_image.shape

#         # Perform object detection with YOLO
#         results = self.yolo_model(cv_image)

#         # Annotate detections and calculate distances
#         annotated_image = cv_image.copy()
#         for result in results:
#             for bbox, confidence, cls in zip(result.boxes.xyxy, result.boxes.conf, result.boxes.cls):
#                 bbox = bbox.cpu().numpy().astype(int)
#                 label = f"{result.names[int(cls)]} {confidence:.2f}"

#                 # Calculate distance
#                 distance = self.calculate_distance(bbox, frame_width, frame_height)

#                 # Draw bounding box and label
#                 cv2.rectangle(annotated_image, (bbox[0], bbox[1]), (bbox[2], bbox[3]), (0, 255, 0), 2)
#                 cv2.putText(
#                     annotated_image,
#                     f"{label} {distance}m",
#                     (bbox[0], bbox[1] - 10),
#                     cv2.FONT_HERSHEY_SIMPLEX,
#                     0.5,
#                     (255, 255, 255),
#                     2
#                 )
#                 if distance < 0.5:
#                     self.get_logger().info("Hey stop")
                    

#                 # self.get_logger().info(f"Object: {label}, Distance: {distance}m")

#         # Convert OpenCV image back to ROS Image and publish
#         ros_image = self.bridge.cv2_to_imgmsg(annotated_image, encoding='bgr8')
#         self.image_publisher.publish(ros_image)
#         self.get_logger().info('Published annotated image!')


# def main(args=None):
#     rclpy.init(args=args)
#     node = YoloImageProcessor()
#     try:
#         rclpy.spin(node)
#     except KeyboardInterrupt:
#         pass
#     finally:
#         node.destroy_node()
#         rclpy.shutdown()


# if __name__ == '__main__':
#     main()




import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
from ultralytics import YOLO

from std_msgs.msg import String

class YoloImageProcessor(Node):

    def __init__(self):
        super().__init__('yolo_image_processor')
        self.bridge = CvBridge()
        
        # Load YOLO model
        self.yolo_model = YOLO('yolo11n.engine')  # Use a YOLO model

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

        # Text message publisher for warnings
        self.warning_publisher = self.create_publisher(
            String,
            '/warning_topic',  # Change this to your warning topic
            10
        )

    @staticmethod
    def calculate_distance(bbox, frame_width, frame_height):
        """
        Estimate distance from the object based on bounding box size.
        Adjust the calculation based on actual sensor calibration.
        """
        SAFE_DISTANCE = 0.3  # Adjust this threshold as per your application
        bbox_width = bbox[2] - bbox[0]
        distance = SAFE_DISTANCE * frame_width / (bbox_width + 1e-5)  # Avoid division by zero
        return round(distance, 2)

    def image_callback(self, msg):
        self.get_logger().info('Received an image!')

        # Convert ROS Image to OpenCV image
        cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')

        # Get frame dimensions
        frame_height, frame_width, _ = cv_image.shape

        # Perform object detection with YOLO
        results = self.yolo_model(cv_image)

        # Annotate detections and calculate distances
        annotated_image = cv_image.copy()
        for result in results:
            for bbox, confidence, cls in zip(result.boxes.xyxy, result.boxes.conf, result.boxes.cls):
                bbox = bbox.cpu().numpy().astype(int)
                label = f"{result.names[int(cls)]} {confidence:.2f}"

                # Calculate distance
                distance = self.calculate_distance(bbox, frame_width, frame_height)

                # Draw bounding box and label
                cv2.rectangle(annotated_image, (bbox[0], bbox[1]), (bbox[2], bbox[3]), (0, 255, 0), 2)
                cv2.putText(
                    annotated_image,
                    f"{label} {distance}m",
                    (bbox[0], bbox[1] - 10),
                    cv2.FONT_HERSHEY_SIMPLEX,
                    0.5,
                    (255, 255, 255),
                    2
                )

                # Publish a warning if the distance is below 0.5 meters
                if distance < 0.5:
                    warning_msg = String()
                    warning_msg.data = f"Object detected too close ({label}, {distance}m). Stop!"
                    self.warning_publisher.publish(warning_msg)
                    self.get_logger().info(warning_msg.data)
                else :
                    warning_msg = String()
                    warning_msg.data = f"goog to go "
                    self.warning_publisher.publish(warning_msg)
                    self.get_logger().info(warning_msg.data)


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
