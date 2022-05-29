#include "tree.h"

int main(){
    node e=create_leaf(2);
    node e1=exprnew();
    e->node_right=e1;
    e1->label.node_name='-';
    node e3=create_leaf(1);
    node e2=merge('+', e1, e3);
    node e5=create_leaf(5);
    node e6=merge('*',e3,e5);
    affiche(e);
    return 0;
}