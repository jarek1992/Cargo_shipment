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
CMAKE_SOURCE_DIR = /home/jarek1992/JAREK/Cargo_project/Cargo_shipment

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jarek1992/JAREK/Cargo_project/Cargo_shipment/build

# Include any dependencies generated for this target.
include CMakeFiles/cargo_management.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cargo_management.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cargo_management.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cargo_management.dir/flags.make

CMakeFiles/cargo_management.dir/main.cpp.o: CMakeFiles/cargo_management.dir/flags.make
CMakeFiles/cargo_management.dir/main.cpp.o: ../main.cpp
CMakeFiles/cargo_management.dir/main.cpp.o: CMakeFiles/cargo_management.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jarek1992/JAREK/Cargo_project/Cargo_shipment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cargo_management.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cargo_management.dir/main.cpp.o -MF CMakeFiles/cargo_management.dir/main.cpp.o.d -o CMakeFiles/cargo_management.dir/main.cpp.o -c /home/jarek1992/JAREK/Cargo_project/Cargo_shipment/main.cpp

CMakeFiles/cargo_management.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cargo_management.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jarek1992/JAREK/Cargo_project/Cargo_shipment/main.cpp > CMakeFiles/cargo_management.dir/main.cpp.i

CMakeFiles/cargo_management.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cargo_management.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jarek1992/JAREK/Cargo_project/Cargo_shipment/main.cpp -o CMakeFiles/cargo_management.dir/main.cpp.s

# Object files for target cargo_management
cargo_management_OBJECTS = \
"CMakeFiles/cargo_management.dir/main.cpp.o"

# External object files for target cargo_management
cargo_management_EXTERNAL_OBJECTS =

cargo_management: CMakeFiles/cargo_management.dir/main.cpp.o
cargo_management: CMakeFiles/cargo_management.dir/build.make
cargo_management: libcargo_management-lib.a
cargo_management: CMakeFiles/cargo_management.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jarek1992/JAREK/Cargo_project/Cargo_shipment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cargo_management"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cargo_management.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cargo_management.dir/build: cargo_management
.PHONY : CMakeFiles/cargo_management.dir/build

CMakeFiles/cargo_management.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cargo_management.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cargo_management.dir/clean

CMakeFiles/cargo_management.dir/depend:
	cd /home/jarek1992/JAREK/Cargo_project/Cargo_shipment/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jarek1992/JAREK/Cargo_project/Cargo_shipment /home/jarek1992/JAREK/Cargo_project/Cargo_shipment /home/jarek1992/JAREK/Cargo_project/Cargo_shipment/build /home/jarek1992/JAREK/Cargo_project/Cargo_shipment/build /home/jarek1992/JAREK/Cargo_project/Cargo_shipment/build/CMakeFiles/cargo_management.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cargo_management.dir/depend

