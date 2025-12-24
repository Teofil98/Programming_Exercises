# =========================
# Compiler
# =========================
FC := gfortran

# =========================
# Build type (debug/release)
# =========================
BUILD ?= release

ifeq ($(BUILD),debug)
  FFLAGS := -Wall -Wextra -g -O0 -fcheck=all -fbacktrace
else
  FFLAGS := -O3
endif

LINK_FLAGS := -L../../../../.libraries/Fortran/lib  -lmylib  -Wl,-rpath,../../../../.libraries/Fortran/lib
INCLUDE_FLAGS := -I../../../../.libraries/Fortran

# =========================
# Select implementation
# =========================
# Usage:
#   make IMPL=solution1
#   make BUILD=debug IMPL=template1
#
IMPL ?= solution

IMPL_SRC := $(IMPL).f90

# =========================
# Files
# =========================
TARGET := main
SRCS   := $(IMPL_SRC) main.f90
OBJS   := $(SRCS:.f90=.o)
MODS   := *.mod

# =========================
# Default target
# =========================
.PHONY: all
all: clean $(TARGET)

# =========================
# Link
# =========================
$(TARGET): $(OBJS)
	$(FC)  $(OBJS) $(LINK_FLAGS) -o $@

# =========================
# Compile
# =========================
%.o: %.f90
	$(FC) $(FFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

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
	rm -f $(TARGET) *.o *.mod

