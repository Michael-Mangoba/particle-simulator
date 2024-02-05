# CMakeList.txt : CMake project for Particle Simulator, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Particle Simulator")

# Add source to this project's executable.
add_executable (particle "particleSimulator/particleSimulator.cpp" "particleSimulator/particleSimulator.h" "particleSimulator/simulatorGUI.cpp" "particleSimulator/simulatorGUI.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET particle PROPERTY CXX_STANDARD 20)
endif()

# Add installation prefix of vcpkg to CMAKE_PREFIX_PATH
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/x64-windows)

# Copy GLFW DLL to output directory
add_custom_command(TARGET particle POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
	"${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/x64-windows/bin/glfw3.dll" $<TARGET_FILE_DIR:particle>)

# Packages
find_package(glad CONFIG REQUIRED)
target_link_libraries(particle PRIVATE glad::glad )

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(particle PRIVATE glfw)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(particle PRIVATE imgui::imgui)