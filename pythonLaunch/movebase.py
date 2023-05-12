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



    use_sim_time = LaunchConfiguration('use_sim_time', default='false')
    urdf = '/home/pi/amr_config/eru.urdf'

    # Major refactor of the robot_state_publisher
    # Reference page: https://github.com/ros2/demos/pull/426
    with open(urdf, 'r') as infp:
        robot_desc = infp.read()

    rsp_params = {'robot_description': robot_desc}

    ld = LaunchDescription([

        Node(
            package='micro_ros_agent',
            executable='micro_ros_agent',
            name='micro_ros_agent',
            arguments=["serial", "--dev", "/dev/ttyACM0", "-v6"]
        ),
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            output='screen',
            parameters=[rsp_params, {'use_sim_time': use_sim_time}]),
    ])
    ls = LaunchService()
    ls.include_launch_description(ld)
    ls.run()


def main():
    run()

if __name__=="__main__":
    main()
