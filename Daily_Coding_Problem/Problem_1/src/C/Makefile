# =========================
# Compiler
# =========================
CC := gcc

# =========================
# Build type (debug/release)
# =========================
BUILD ?= release

ifeq ($(BUILD),debug)
  CFLAGS := -Wall -Wextra -g -O0 -fcheck=all -fbacktrace
else
  CFLAGS := -O3
endif

LINK_FLAGS := -L../../../../.libraries/C/lib  -lmylib  -Wl,-rpath,../../../../.libraries/C/lib
INCLUDE_FLAGS := -I../../../../.libraries/C/include

# =========================
# Select implementation
# =========================
# Usage:
#   make IMPL=solution1
#   make BUILD=debug IMPL=template1
#
IMPL ?= solution

IMPL_SRC := $(IMPL).c

# =========================
# Files
# =========================
TARGET := main
SRCS   := $(IMPL_SRC) main.c
OBJS   := $(SRCS:.c=.o)

# =========================
# Default target
# =========================
.PHONY: all
all: clean $(TARGET)

# =========================
# Link
# =========================
$(TARGET): $(OBJS)
	$(CC)  $(OBJS) $(LINK_FLAGS) -o $@

# =========================
# Compile
# =========================
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

# =========================
# Run
# =========================
.PHONY: run
run: 
	./$(TARGET)

# =========================
# Convenience targets
# =========================
.PHONY: debug release
debug:
	$(MAKE) BUILD=debug

release:
	$(MAKE) BUILD=release

# =========================
# Clean
# =========================
.PHONY: clean
clean:
	rm -f $(TARGET) *.o

