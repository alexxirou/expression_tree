# Variables dossiers
SDIR=src
ODIR=obj
BDIR=bin
VER=

# -> Iinclude pour les fichiers .h
CPPFLAGS += -Iinclude -g

# Compile flags 
CFLAGS= $(CPPFLAGS) 

vpath %.c $(SDIR)
vpath %.o $(ODIR)	

# Instructions

.phony all: preBuild $(BDIR)/main
	

preBuild:	
	@mkdir -p src
	@mkdir -p include
	if [ -s tree.h ]; then mv tree.h include/ ; fi 
	if [ -s tree.c ]; then mv tree.c src/ ; fi
	if [ -s main.c ]; then mv main.c include/ ; fi  

$(BDIR)/main: $(ODIR)/main.o $(ODIR)/tree.o
	@mkdir -p $(BDIR)
	gcc  $(ODIR)/main.o $(ODIR)/tree.o -o $@ $(CFLAGS) 




$(ODIR)/%.o: $(SDIR)/%.c
	@mkdir -p $(ODIR)
	gcc $(CFLAGS) -o $@ -c $<





clean:
	rm -rf $(ODIR)/
	rm -rf $(BDIR)/
	rm -rf dist/
	rm -rf doc/

doc:
	@doxygen

help:
	@echo "======== Help Arbre Généologique $(VER) ========"
	@echo "./bin/main <grille>: éxécuter le programme"
	@echo "make: compiler le programme"
	@echo "make clean: effacer les fichiers générés"
	@echo "make dist: créer une archive du projet"
	@echo "make doc: générér la documentation doxygen"
	@echo "make help: afficher l'aide"

