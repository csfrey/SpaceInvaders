# Compiler
CXX = clang++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -I/opt/homebrew/include

# Raylib linking (macOS requires framework flags)
LDFLAGS = -L/opt/homebrew/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

# Directories
SRC_DIR = src
BUILD_DIR = build

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Output executable
TARGET = $(BUILD_DIR)/game

# Build rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean build files
clean:
	rm -rf $(BUILD_DIR)

# Run the game
run: all
	./$(TARGET)
