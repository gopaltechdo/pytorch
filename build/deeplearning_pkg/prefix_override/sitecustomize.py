import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/gopal/ros2/macine_learning_ws/install/deeplearning_pkg'
