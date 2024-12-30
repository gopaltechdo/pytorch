

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
