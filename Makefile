# Nom du compilateur
CXX = g++

# Options de compilation
CXXFLAGS = -Wall -Wextra -std=c++17

# Bibliothèque graphique SFML
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Dossiers
SRCDIR = src
BUILDDIR = build
BINDIR = bin

# Fichiers sources et exécutables
SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SRC))
TARGET = $(BINDIR)/jeu_de_la_vie

# Commande pour créer les dossiers si nécessaire
MKDIR_P = mkdir -p

# Règle principale
all: $(TARGET)

# Construction de l'exécutable
$(TARGET): $(OBJ)
	$(MKDIR_P) $(BINDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Compilation des fichiers objets
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(MKDIR_P) $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Exécution des tests unitaires
test: $(TARGET)
	./$(TARGET) test

# Nettoyage des fichiers compilés
clean:
	rm -rf $(BUILDDIR) $(BINDIR)

# Nettoyage complet (fichiers générés)
distclean: clean
	rm -rf out/*

.PHONY: all clean distclean test
