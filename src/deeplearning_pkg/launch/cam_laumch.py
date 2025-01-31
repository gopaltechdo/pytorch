import os
import launch
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, LogInfo, ExecuteProcess
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # Launch the 'iare_sub.py' node
        Node(
            package='deeplearning_pkg',
            executable='sub.py',  # This will be the script name
            name='iare_sub',
            output='screen',
            emulate_tty=True,
            parameters=[],
            remappings=[]
        ),
        
        # Launch the 'yolo.py' node
        Node(
            package='deeplearning_pkg',
            executable='yolo.py',  # This will be the script name
            name='yolo',
            output='screen',
            emulate_tty=True,
            parameters=[],
            remappings=[]
        ),
    ])
