# Variables
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TARGET = $(BIN_DIR)/jeu_de_la_vie

# Liste des fichiers sources
SRC = $(wildcard $(SRC_DIR)/*.cpp) main.cpp Jeu.cpp Grille.cpp Afficheur.cpp CelluleVivante.cpp CelluleObstacle.cpp Observable.cpp
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

# Règles
all: $(TARGET)

# Création de l'exécutable
$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CXX) $^ -o $@ $(LDFLAGS)

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Nettoyage complet
dist-clean: clean
	rm -rf resultats_out

# Exécution
run: all
	./$(TARGET) etat_initial.txt
