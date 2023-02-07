ALL_SRCS	= $(wildcard src/*.cpp)
# remove lib.cpp from sources
SRCS		= $(patsubst src/libalkstat.cpp,,$(ALL_SRCS))
RELEASE_TARGET	= $(patsubst src/%.cpp,release/%.bin,$(SRCS))
DEBUG_TARGET	= $(patsubst src/%.cpp,debug/%.debug,$(SRCS))

all: $(RELEASE_TARGET) $(DEBUG_TARGET)

release/%.bin: src/%.cpp src/libalkstat.cpp src/libalkstat.hpp
	mkdir -p release
	g++ -o $@ -O2 $^ -lm 

debug/%.debug: src/%.cpp src/libalkstat.cpp src/libalkstat.hpp
	mkdir -p debug
	g++ -o $@ -g $^ -lm

clean:
	rm $(RELEASE_TARGET) $(DEBUG_TARGET)
