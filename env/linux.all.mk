CC := g++

LIB_DIRS := \
	/usr/local/lib

INCLUDE_DIRS := \
	/usr/local/include

BUILD_FLAGS := \
	$(BUILD_FLAGS) \
	-pthread

LINK_LIBRARIES := \
	$(LINK_LIBRARIES) \
	X11

PRODUCTION_LINUX_ICON := sfml

PRODUCTION_LINUX_APP_NAME := Sudoku Solver
PRODUCTION_LINUX_APP_COMMENT := autoSudoku
