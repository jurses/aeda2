TARGET = hormiga.exe

SRC = src
INC = inc
BIN = bin

SOURCE = $(wildcard $(SRC)/*.cpp)

OBJECT = $(patsubst %, $(BIN)/%, $(notdir $(SOURCE:.cpp=.o)))

CXX = g++
CXXFLAGS = -g -I$(INC)

ifneq ($(ARGS),'')
GDBI := --args $(BIN)/$(TARGET) $(ARGS)
else
GDBI := $(BIN)/$(TARGET)
endif

$(BIN)/$(TARGET): $(OBJECT)
	$(CXX) -o $@ $^

$(BIN)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: help run clean depurate

run: $(BIN)/
	$(BIN)/$(TARGET) ${ARGS}

clean: 
	rm -f $(OBJECT) $(BIN)/$(TARGET)

depurate:
	gdb $(GDBI) 

help:
	@echo "Para ejecutar: \`make run' o \`make ARGS=\"<argumentos>\" run'."
