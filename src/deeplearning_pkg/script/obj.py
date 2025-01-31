import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import numpy as np
import cv2


class ObjectWarningNode(Node):
    def __init__(self):
        super().__init__('object_warning_node')

        # Parameters
        self.depth_topic = "/zed/zed_node/depth/depth_registered"  # Replace with your depth image topic
        self.distance_threshold = 50  # Threshold in millimeters (50mm = 5cm)
        self.warning_percentage = 5  # Percentage of pixels below the threshold to trigger warning

        # Depth image subscriber
        self.depth_sub = self.create_subscription(Image, self.depth_topic, self.depth_callback, 10)

        # CV Bridge for ROS image conversion
        self.bridge = CvBridge()

    def depth_callback(self, msg):
        try:
            # Convert ROS Image message to OpenCV format
            depth_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding="passthrough")

            # Check for nearby objects
            self.check_nearby_objects(depth_image)

        except Exception as e:
            self.get_logger().error(f"Failed to process depth image: {e}")

    def check_nearby_objects(self, depth_image):
        # Convert depth data to a NumPy array and handle NaN values
        depth_array = np.nan_to_num(depth_image, nan=np.inf)
        print("depth image array",depth_array)


        # Identify pixels where the depth is below the threshold
        nearby_mask = depth_array < self.distance_threshold

        # Calculate the percentage of "nearby" pixels
        nearby_percentage = (np.sum(nearby_mask) / depth_array.size) * 100

        if nearby_percentage > self.warning_percentage:
            self.get_logger().info("No nearby objects detected.")

        else:
            self.get_logger().warn(f"WARNING: Object detected nearby! {nearby_percentage:.2f}% of pixels are close.")


        # Visualize the depth image with nearby pixels highlighted
        self.visualize_depth(depth_image, nearby_mask)

    def visualize_depth(self, depth_image, nearby_mask):
        # Normalize depth image for visualization
        depth_normalized = cv2.normalize(depth_image, None, 0, 255, cv2.NORM_MINMAX)
        depth_colored = cv2.applyColorMap(depth_normalized.astype(np.uint8), cv2.COLORMAP_JET)

        # Highlight nearby regions in red
        depth_colored[nearby_mask] = [0, 0, 255]  # Red for nearby objects

        # Display the depth image
        # cv2.imshow("Depth Image with Nearby Objects Highlighted", depth_colored)
        # cv2.waitKey(1)

    def shutdown(self):
        cv2.destroyAllWindows()


def main(args=None):
    rclpy.init(args=args)
    node = ObjectWarningNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.shutdown()
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
