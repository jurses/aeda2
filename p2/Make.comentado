TARGET = hormiga.exe
# ^^^ nombre final del programa

SRC = src
INC = inc
BIN = bin
# ^^^ variables que contienen los directorios donde se guardan los archivos de nuestro proyecto

SOURCE = $(wildcard $(SRC)/*.cpp)
# ^^^ wildcard/comodín es usado para que `*.cpp' no sea tratado como una cadena.

OBJECT = $(patsubst %, $(BIN)/%, $(notdir $(SOURCE:.cpp=.o)))
# ^^^ notdir quita el directorio.
# `$(SOURCE:.cpp=.o)' cambia el nombre de la extensión `.cpp' de `SOURCE' a `.o'.
# `$(patsubst PATTERN, REPLACEMENT, TEXT)' Sustito de patrones: encuentra palabras
#	separadas por espacios en `TEXT' que coinciden con `PATTERN' y lo reemplaza
#	con `REPLACEMENT'

CXX = g++
CXXFLAGS = -g -I$(INC)
# ^^^ -I es una opción del compilador la cual se le pasa el directorio donde se encuentra los `includes'

$(BIN)/$(TARGET): $(OBJECT)
	$(CXX) -o $@ $^

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

##### BREVE CHULETA DE VARIABLES AUTOMÁTICAS #####
# objetivo: prerrequisitos
# 	COMANDO
# $< primer prerrequisito
# $? toda la lista
# $@ se reemplaza por el nombre del objetivo
# $^ todos los prerrequisitos
# % como * pero va uno por uno.

# Vídeo donde se explica muy bien
# https://www.youtube.com/watch?v=Wt6KGlMkLz0
