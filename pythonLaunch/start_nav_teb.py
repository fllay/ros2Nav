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
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.conditions import IfCondition
from launch_ros.substitutions import FindPackageShare
from launch_ros.actions import Node


ls = None


def run():
    global ls    
    nav2_launch_path = PathJoinSubstitution(
        [FindPackageShare('nav2_bringup'), 'launch', 'bringup_launch.py']
    )

 

    #default_map_path = '/home/pi/amr_config/maps/pleoffice.yaml'
    #default_map_path = '/home/pi/amr_config/maps/office511A.yaml'
    default_map_path = '/home/pi/amr_config/maps/house2ndFloorNew.yaml'
    #nav2_config_path = '/home/pi/amr_config/navigation.yaml'
    nav2_config_path = '/home/pi/amr_config/nav2_parameter_teb.yaml'


    ld = LaunchDescription([
        DeclareLaunchArgument(
            name='sim', 
            default_value='false',
            description='Enable use_sime_time to true'
        ),



       DeclareLaunchArgument(
            name='map', 
            default_value=default_map_path,
            description='Navigation map path'
        ),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(nav2_launch_path),
            launch_arguments={
                'map': LaunchConfiguration("map"),
                'use_sim_time': LaunchConfiguration("sim"),
                'params_file': nav2_config_path
            }.items()
        )
    ])
    ls = LaunchService()
    ls.include_launch_description(ld)
    ls.run()


def main():
    run()

if __name__=="__main__":
    main()
