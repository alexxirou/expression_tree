#include "tree.h"

int main(){
    node a=create_leaf(2);
    node b=merge('-', a, NULL);

    node d=create_leaf(1);
    node c=merge('+', b, d);
    node f=create_leaf(5);
    node e=merge('*',c,f);
    //bool valid=eval(e);
    //printf("Is valid expression ? %s\n", valid? "True" : "False");
    affiche(e);
    //float f=eval(e);
    //printf("%f\n",f);
    return 0;
}