# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chris/exercism/cpp/bank-account

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chris/exercism/cpp/bank-account/build

# Include any dependencies generated for this target.
include CMakeFiles/bank-account.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bank-account.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bank-account.dir/flags.make

CMakeFiles/bank-account.dir/bank_account_test.cpp.o: CMakeFiles/bank-account.dir/flags.make
CMakeFiles/bank-account.dir/bank_account_test.cpp.o: ../bank_account_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chris/exercism/cpp/bank-account/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bank-account.dir/bank_account_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bank-account.dir/bank_account_test.cpp.o -c /home/chris/exercism/cpp/bank-account/bank_account_test.cpp

CMakeFiles/bank-account.dir/bank_account_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bank-account.dir/bank_account_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chris/exercism/cpp/bank-account/bank_account_test.cpp > CMakeFiles/bank-account.dir/bank_account_test.cpp.i

CMakeFiles/bank-account.dir/bank_account_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bank-account.dir/bank_account_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chris/exercism/cpp/bank-account/bank_account_test.cpp -o CMakeFiles/bank-account.dir/bank_account_test.cpp.s

CMakeFiles/bank-account.dir/bank_account.cpp.o: CMakeFiles/bank-account.dir/flags.make
CMakeFiles/bank-account.dir/bank_account.cpp.o: ../bank_account.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chris/exercism/cpp/bank-account/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/bank-account.dir/bank_account.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bank-account.dir/bank_account.cpp.o -c /home/chris/exercism/cpp/bank-account/bank_account.cpp

CMakeFiles/bank-account.dir/bank_account.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bank-account.dir/bank_account.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chris/exercism/cpp/bank-account/bank_account.cpp > CMakeFiles/bank-account.dir/bank_account.cpp.i

CMakeFiles/bank-account.dir/bank_account.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bank-account.dir/bank_account.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chris/exercism/cpp/bank-account/bank_account.cpp -o CMakeFiles/bank-account.dir/bank_account.cpp.s

CMakeFiles/bank-account.dir/test/tests-main.cpp.o: CMakeFiles/bank-account.dir/flags.make
CMakeFiles/bank-account.dir/test/tests-main.cpp.o: ../test/tests-main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chris/exercism/cpp/bank-account/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/bank-account.dir/test/tests-main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bank-account.dir/test/tests-main.cpp.o -c /home/chris/exercism/cpp/bank-account/test/tests-main.cpp

CMakeFiles/bank-account.dir/test/tests-main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bank-account.dir/test/tests-main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chris/exercism/cpp/bank-account/test/tests-main.cpp > CMakeFiles/bank-account.dir/test/tests-main.cpp.i

CMakeFiles/bank-account.dir/test/tests-main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bank-account.dir/test/tests-main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chris/exercism/cpp/bank-account/test/tests-main.cpp -o CMakeFiles/bank-account.dir/test/tests-main.cpp.s

# Object files for target bank-account
bank__account_OBJECTS = \
"CMakeFiles/bank-account.dir/bank_account_test.cpp.o" \
"CMakeFiles/bank-account.dir/bank_account.cpp.o" \
"CMakeFiles/bank-account.dir/test/tests-main.cpp.o"

# External object files for target bank-account
bank__account_EXTERNAL_OBJECTS =

bank-account: CMakeFiles/bank-account.dir/bank_account_test.cpp.o
bank-account: CMakeFiles/bank-account.dir/bank_account.cpp.o
bank-account: CMakeFiles/bank-account.dir/test/tests-main.cpp.o
bank-account: CMakeFiles/bank-account.dir/build.make
bank-account: CMakeFiles/bank-account.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chris/exercism/cpp/bank-account/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable bank-account"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bank-account.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bank-account.dir/build: bank-account

.PHONY : CMakeFiles/bank-account.dir/build

CMakeFiles/bank-account.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bank-account.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bank-account.dir/clean

CMakeFiles/bank-account.dir/depend:
	cd /home/chris/exercism/cpp/bank-account/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chris/exercism/cpp/bank-account /home/chris/exercism/cpp/bank-account /home/chris/exercism/cpp/bank-account/build /home/chris/exercism/cpp/bank-account/build /home/chris/exercism/cpp/bank-account/build/CMakeFiles/bank-account.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bank-account.dir/depend

