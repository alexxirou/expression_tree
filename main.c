#include "tree.h"
/*
       *
      / \
     +   5
    / \ 
   -    2
  /
 1
    should give ((-1+2)*5)
*/

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
    float res=eval(e);
    printf("%f\n",res);
    return 0;
}