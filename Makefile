SRC_DIR = src 
BUILD_DIR = build/debug
CC = g++
SCR_FILES = $(wildcard src/*.cpp)
OBJ_NAME = play
INCLUDE_PATHS = -Iinclude
LIBRAY_PATHS = -Llib
COMPILER_FLAGS = -std=c++11 -Wall -O0 -g
LINKER_FLAGS = -lsdl2 -lsdl2_image

all:
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRAY_PATHS) $(SCR_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)