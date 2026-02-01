CC = g++

CXXFLAGS = -std=c++17 -g -O0 -Wall -Wextra -pedantic -I inc
# CXXFLAGS = -std=c++17 -O2 -Wall -Wextra -pedantic

SRCS := $(wildcard src/*.cpp)
BUILD := build
OBJS := $(patsubst %.cpp,$(BUILD)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)
TARGET := $(BUILD)/main

DEPFLAGS = -MMD -MP -MF $(BUILD)/$*.d

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $^

$(BUILD)/%.o: %.cpp | $(BUILD)/src
	$(CC) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

$(BUILD) $(BUILD)/src:
	mkdir -p $@

-include $(DEPS)

clean:
	rm -rf $(BUILD)