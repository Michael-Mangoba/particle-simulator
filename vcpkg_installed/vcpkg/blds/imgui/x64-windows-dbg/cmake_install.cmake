# Install script for directory: G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/imgui/src/v1.89.9-35b8d7fda8.clean

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/pkgs/imgui_x64-windows/debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "OFF")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/imgui/x64-windows-dbg/imguid.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/imgui" TYPE FILE FILES "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/imgui/x64-windows-dbg/imgui-config.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/imgui/imgui-targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/imgui/imgui-targets.cmake"
         "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/imgui/x64-windows-dbg/CMakeFiles/Export/791eb3786aa5a66c7063a763bc360501/imgui-targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/imgui/imgui-targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/imgui/imgui-targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/imgui" TYPE FILE FILES "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/imgui/x64-windows-dbg/CMakeFiles/Export/791eb3786aa5a66c7063a763bc360501/imgui-targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/imgui" TYPE FILE FILES "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/imgui/x64-windows-dbg/CMakeFiles/Export/791eb3786aa5a66c7063a763bc360501/imgui-targets-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/imgui/x64-windows-dbg/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
