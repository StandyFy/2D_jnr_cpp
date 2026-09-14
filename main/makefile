CXX := g++
PROGRAM := out/2djnr.exe
CPP_SOURCES := $(shell dir /s /b /A-D *.cpp 2>NUL)
HEADER_FILES := $(shell dir /s /b /A-D *.h 2>NUL)
INCLUDE_DIRS := $(sort $(dir $(CPP_SOURCES) $(HEADER_FILES)))
CPPFLAGS := $(addprefix -I,$(INCLUDE_DIRS))

.PHONY: default clean

default: $(PROGRAM)

$(PROGRAM): $(CPP_SOURCES) $(HEADER_FILES)
	if not exist out mkdir out
	$(CXX) $(CPPFLAGS) $(CPP_SOURCES) -o $(PROGRAM) -lraylib

clean:
	rm -f $(PROGRAM)