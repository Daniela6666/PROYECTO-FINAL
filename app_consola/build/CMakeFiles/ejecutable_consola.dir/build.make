# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/daniela/PROYECTO-FINAL/app_consola

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/daniela/PROYECTO-FINAL/app_consola/build

# Include any dependencies generated for this target.
include CMakeFiles/ejecutable_consola.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ejecutable_consola.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ejecutable_consola.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ejecutable_consola.dir/flags.make

CMakeFiles/ejecutable_consola.dir/src/control_db.cpp.o: CMakeFiles/ejecutable_consola.dir/flags.make
CMakeFiles/ejecutable_consola.dir/src/control_db.cpp.o: ../src/control_db.cpp
CMakeFiles/ejecutable_consola.dir/src/control_db.cpp.o: CMakeFiles/ejecutable_consola.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daniela/PROYECTO-FINAL/app_consola/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ejecutable_consola.dir/src/control_db.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ejecutable_consola.dir/src/control_db.cpp.o -MF CMakeFiles/ejecutable_consola.dir/src/control_db.cpp.o.d -o CMakeFiles/ejecutable_consola.dir/src/control_db.cpp.o -c /home/daniela/PROYECTO-FINAL/app_consola/src/control_db.cpp

CMakeFiles/ejecutable_consola.dir/src/control_db.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ejecutable_consola.dir/src/control_db.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/daniela/PROYECTO-FINAL/app_consola/src/control_db.cpp > CMakeFiles/ejecutable_consola.dir/src/control_db.cpp.i

CMakeFiles/ejecutable_consola.dir/src/control_db.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ejecutable_consola.dir/src/control_db.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/daniela/PROYECTO-FINAL/app_consola/src/control_db.cpp -o CMakeFiles/ejecutable_consola.dir/src/control_db.cpp.s

CMakeFiles/ejecutable_consola.dir/src/main.cpp.o: CMakeFiles/ejecutable_consola.dir/flags.make
CMakeFiles/ejecutable_consola.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/ejecutable_consola.dir/src/main.cpp.o: CMakeFiles/ejecutable_consola.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daniela/PROYECTO-FINAL/app_consola/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ejecutable_consola.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ejecutable_consola.dir/src/main.cpp.o -MF CMakeFiles/ejecutable_consola.dir/src/main.cpp.o.d -o CMakeFiles/ejecutable_consola.dir/src/main.cpp.o -c /home/daniela/PROYECTO-FINAL/app_consola/src/main.cpp

CMakeFiles/ejecutable_consola.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ejecutable_consola.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/daniela/PROYECTO-FINAL/app_consola/src/main.cpp > CMakeFiles/ejecutable_consola.dir/src/main.cpp.i

CMakeFiles/ejecutable_consola.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ejecutable_consola.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/daniela/PROYECTO-FINAL/app_consola/src/main.cpp -o CMakeFiles/ejecutable_consola.dir/src/main.cpp.s

CMakeFiles/ejecutable_consola.dir/src/sensor.cpp.o: CMakeFiles/ejecutable_consola.dir/flags.make
CMakeFiles/ejecutable_consola.dir/src/sensor.cpp.o: ../src/sensor.cpp
CMakeFiles/ejecutable_consola.dir/src/sensor.cpp.o: CMakeFiles/ejecutable_consola.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daniela/PROYECTO-FINAL/app_consola/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ejecutable_consola.dir/src/sensor.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ejecutable_consola.dir/src/sensor.cpp.o -MF CMakeFiles/ejecutable_consola.dir/src/sensor.cpp.o.d -o CMakeFiles/ejecutable_consola.dir/src/sensor.cpp.o -c /home/daniela/PROYECTO-FINAL/app_consola/src/sensor.cpp

CMakeFiles/ejecutable_consola.dir/src/sensor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ejecutable_consola.dir/src/sensor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/daniela/PROYECTO-FINAL/app_consola/src/sensor.cpp > CMakeFiles/ejecutable_consola.dir/src/sensor.cpp.i

CMakeFiles/ejecutable_consola.dir/src/sensor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ejecutable_consola.dir/src/sensor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/daniela/PROYECTO-FINAL/app_consola/src/sensor.cpp -o CMakeFiles/ejecutable_consola.dir/src/sensor.cpp.s

# Object files for target ejecutable_consola
ejecutable_consola_OBJECTS = \
"CMakeFiles/ejecutable_consola.dir/src/control_db.cpp.o" \
"CMakeFiles/ejecutable_consola.dir/src/main.cpp.o" \
"CMakeFiles/ejecutable_consola.dir/src/sensor.cpp.o"

# External object files for target ejecutable_consola
ejecutable_consola_EXTERNAL_OBJECTS =

ejecutable_consola: CMakeFiles/ejecutable_consola.dir/src/control_db.cpp.o
ejecutable_consola: CMakeFiles/ejecutable_consola.dir/src/main.cpp.o
ejecutable_consola: CMakeFiles/ejecutable_consola.dir/src/sensor.cpp.o
ejecutable_consola: CMakeFiles/ejecutable_consola.dir/build.make
ejecutable_consola: CMakeFiles/ejecutable_consola.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/daniela/PROYECTO-FINAL/app_consola/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ejecutable_consola"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ejecutable_consola.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ejecutable_consola.dir/build: ejecutable_consola
.PHONY : CMakeFiles/ejecutable_consola.dir/build

CMakeFiles/ejecutable_consola.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ejecutable_consola.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ejecutable_consola.dir/clean

CMakeFiles/ejecutable_consola.dir/depend:
	cd /home/daniela/PROYECTO-FINAL/app_consola/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/daniela/PROYECTO-FINAL/app_consola /home/daniela/PROYECTO-FINAL/app_consola /home/daniela/PROYECTO-FINAL/app_consola/build /home/daniela/PROYECTO-FINAL/app_consola/build /home/daniela/PROYECTO-FINAL/app_consola/build/CMakeFiles/ejecutable_consola.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ejecutable_consola.dir/depend

