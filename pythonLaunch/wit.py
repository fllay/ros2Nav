import os
import sys
import time
from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node
from launch import LaunchDescription
from launch import LaunchService
import launch_ros.actions

ls = None


def run():
    global ls    
    config_witmotion = '/home/pi/amr_config/wt61c.yml'
  
    ld = LaunchDescription([

        Node(
            package = 'witmotion_ros',
            executable = 'witmotion_ros_node',
            parameters = [config_witmotion]
        ),
    ])
    ls = LaunchService()
    ls.include_launch_description(ld)
    ls.run()


def main():
    run()

if __name__=="__main__":
    main()
