TARGET = hormiga.exe

SRC = src
INC = inc
BIN = bin

SOURCE = $(wildcard $(SRC)/*.cpp)

OBJECT = $(patsubst %, $(BIN)/%, $(notdir $(SOURCE:.cpp=.o)))

CXX = g++
CXXFLAGS = -g -I$(INC)

$(BIN)/$(TARGET): $(OBJECT)
	$(CXX) -o $@ $^ -lncurses

$(BIN)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: help run clean depurate

run: $(BIN)/
	$(BIN)/$(TARGET)

clean: 
	rm -f $(OBJECT) $(BIN)/$(TARGET)

depurate:
	gdb $(BIN)/$(TARGET)

help:
	@echo "src: $(SOURCE)"
	@echo "obj: $(OBJECT)"
