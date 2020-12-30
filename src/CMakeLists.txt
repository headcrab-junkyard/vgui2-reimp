# We want shared libraries (and modules) without any prefix in name
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_SHARED_MODULE_PREFIX "")

#####################################################################

# Add include directories
include_directories(
	${OGS_SDK_PATH}
	${OGS_SDK_PATH}/public
)

#####################################################################

# Add subdirectories

add_subdirectory(vgui2)