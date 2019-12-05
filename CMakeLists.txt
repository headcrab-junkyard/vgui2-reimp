cmake_minimum_required(VERSION 3.14)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/public)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set path to SDK
set(OGS_SDK_PATH ${CMAKE_SOURCE_DIR}/../ogs-sdk/goldsrc
	CACHE PATH
	"Path to engine SDK"
)


# Add engine sdk directory
add_subdirectory(${OGS_SDK_PATH} ${CMAKE_BINARY_DIR}/sdk)

add_subdirectory(src)