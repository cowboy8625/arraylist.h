CXX := $(shell if command -v clang > /dev/null 2>&1; then echo clang; else echo gcc; fi)
CXXFLAGS = -std=c17 -Wall -Wextra -I.

SRC_DIR = src
OBJ_DIR = bin/object

SRCS = $(SRC_DIR)/main.c

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

DEPS = $(OBJS:.o=.d)

TARGET = bin/main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJS) $(TARGET) $(DEPS)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean
