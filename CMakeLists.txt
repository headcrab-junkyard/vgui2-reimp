cmake_minimum_required(VERSION 3.14)
project(VGUI2Reimp)

#####################################################################

option(VGUI2_STANDALONE "Build as a standalone library" ON)

#####################################################################

# Only generate Debug and Release configuration types
set(CMAKE_CONFIGURATION_TYPES Debug Release)

# Set C language standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
#set(CMAKE_C_STANDARD_EXTENSIONS ON)

# Set C++ language standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_STANDARD_EXTENSIONS ON)

#####################################################################

# Specify output directory (for compiled binaries)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# Set path to SDK
set(OGS_SDK_PATH ${CMAKE_SOURCE_DIR}/../ogs-sdk/goldsrc
	CACHE PATH
	"Path to engine SDK"
)

#####################################################################

# Add include directories

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/public)

#####################################################################

# Add subdirectories

# Add engine sdk directory
if(VGUI2_STANDALONE)
	add_subdirectory(${OGS_SDK_PATH} ${CMAKE_BINARY_DIR}/sdk)
endif()

# Add main sources directory
add_subdirectory(src)