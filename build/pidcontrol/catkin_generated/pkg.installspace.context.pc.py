# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include".split(';') if "${prefix}/include" != "" else []
PROJECT_CATKIN_DEPENDS = "geometry_msgs;nav_msgs;roscpp;rospy;tf".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lpidcontrol".split(';') if "-lpidcontrol" != "" else []
PROJECT_NAME = "pidcontrol"
PROJECT_SPACE_DIR = "/home/german/catkin_ws/install"
PROJECT_VERSION = "0.0.0"
