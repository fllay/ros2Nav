# CMake generated Testfile for 
# Source directory: /home/pi/amr_ws/src/costmap_converter/costmap_converter
# Build directory: /home/pi/amr_ws/src/build/costmap_converter
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_costmap_polygons "/usr/bin/python3.10" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/pi/amr_ws/src/build/costmap_converter/test_results/costmap_converter/test_costmap_polygons.gtest.xml" "--package-name" "costmap_converter" "--output-file" "/home/pi/amr_ws/src/build/costmap_converter/ament_cmake_gtest/test_costmap_polygons.txt" "--command" "/home/pi/amr_ws/src/build/costmap_converter/test_costmap_polygons" "--gtest_output=xml:/home/pi/amr_ws/src/build/costmap_converter/test_results/costmap_converter/test_costmap_polygons.gtest.xml")
set_tests_properties(test_costmap_polygons PROPERTIES  LABELS "gtest" REQUIRED_FILES "/home/pi/amr_ws/src/build/costmap_converter/test_costmap_polygons" TIMEOUT "60" WORKING_DIRECTORY "/home/pi/amr_ws/src/build/costmap_converter" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/home/pi/amr_ws/src/costmap_converter/costmap_converter/CMakeLists.txt;90;ament_add_gtest;/home/pi/amr_ws/src/costmap_converter/costmap_converter/CMakeLists.txt;0;")
subdirs("gtest")
