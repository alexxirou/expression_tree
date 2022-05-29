#ifndef TREE_H
#define TREE_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_node {
union {char node_name; float leaf_num;} label;
struct s_node *node_left; 
struct s_node *node_right;
} *node;

node exprnew(); 
node merge(char x, node left, node right);
node create_leaf(float x) ;
node left_node(node e);
node right_node(node e);
bool is_leaf(node e);
bool is_empty(node e);
bool is_internal(node e);
char internal_root(node e);
float leaf_root(node e); 
void affiche(node e);
float eval(node e);
bool est_valide(node e);
#endif