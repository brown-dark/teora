#-------------------------------------------------------------------#
# cmake version

cmake_minimum_required(VERSION 3.20)

#-------------------------------------------------------------------#
# find Qt6 libraries

set(QT_VER "6.3.1")

if(WIN32)
    set(QT6_INSTALL_DIR "C:/Qt")
    set(QT6_OS_PREFIX "msvc2019_64")
endif()

set(QT6_FULL_PATH "${QT6_INSTALL_DIR}/${QT_VER}/${QT6_OS_PREFIX}")

set(CMAKE_PREFIX_PATH "${QT6_FULL_PATH}/lib/cmake;${CMAKE_PREFIX_PATH}")
find_package(Qt6Core REQUIRED)
find_package(Qt6Gui REQUIRED)
find_package(Qt6Widgets REQUIRED)

#-------------------------------------------------------------------#