from launch import LaunchContext 
from launch import LaunchDescription 
from launch.actions import DeclareLaunchArgument 
from launch.actions import ExecuteProcess 
from launch.conditions import IfCondition 
from launch.substitutions import LaunchConfiguration 
from launch_ros.actions import Node 
from launch_ros.substitutions import FindPackage 
from pathlib import Path
import os
context = LaunchContext()
def generate_launch_description(): 
    web_bridge = Node( package='rosbridge_server', node_name='rosbridge_server_node', node_namespace='gui', node_executable='rosbridge_websocket' )
    return LaunchDescription([web_bridge])
