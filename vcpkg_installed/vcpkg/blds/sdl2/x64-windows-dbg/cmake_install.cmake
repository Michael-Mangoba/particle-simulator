# Install script for directory: G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/pkgs/sdl2_x64-windows/debug")
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-dbg/SDL2d.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-dbg/SDL2d.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-dbg/SDL2maind.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets.cmake"
         "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-dbg/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2Targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-dbg/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2Targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-dbg/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2Targets-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2mainTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2mainTargets.cmake"
         "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-dbg/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2mainTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2mainTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2mainTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-dbg/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2mainTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-dbg/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2mainTargets-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-dbg/SDL2Config.cmake"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-dbg/SDL2ConfigVersion.cmake"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/cmake/sdlfind.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/SDL2" TYPE FILE FILES
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_assert.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_atomic.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_audio.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_bits.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_blendmode.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_clipboard.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_copying.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_cpuinfo.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_egl.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_endian.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_error.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_events.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_filesystem.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_gamecontroller.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_gesture.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_guid.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_haptic.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_hidapi.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_hints.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_joystick.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_keyboard.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_keycode.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_loadso.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_locale.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_log.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_main.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_messagebox.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_metal.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_misc.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_mouse.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_mutex.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_name.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_opengl.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_opengl_glext.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_opengles.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_opengles2.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_opengles2_gl2.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_opengles2_gl2ext.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_opengles2_gl2platform.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_opengles2_khrplatform.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_pixels.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_platform.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_power.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_quit.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_rect.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_render.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_rwops.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_scancode.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_sensor.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_shape.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_stdinc.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_surface.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_system.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_syswm.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_test.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_test_assert.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_test_common.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_test_compare.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_test_crc32.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_test_font.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_test_fuzzer.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_test_harness.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_test_images.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_test_log.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_test_md5.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_test_memory.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_test_random.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_thread.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_timer.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_touch.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_types.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_version.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_video.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_vulkan.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/begin_code.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/close_code.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-dbg/include/SDL2/SDL_revision.h"
    "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-dbg/include-config-debug/SDL2/SDL_config.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/licenses/SDL2" TYPE FILE FILES "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/LICENSE.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-dbg/sdl2.pc")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "G:/OneDrive/OneDrive - De La Salle University - Manila/College Files/4th Year/Term 2/STDISCM/particle/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-dbg/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
