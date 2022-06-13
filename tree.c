#include "tree.h"

node exprnew(){
    node e=malloc(sizeof *e);
    e->node_left= NULL;
    e->node_right= NULL;
    e->label.node_name='N'; 
    e->label.leaf_num=-1;
    return e;
} 

node merge(char x, node left, node right){
    node e=exprnew();
    e->label.node_name=x;
    e->node_right=right;
    e->node_left=left;
    return e;
}

node create_leaf(float x){
    node e=exprnew();
    e->label.leaf_num=x;
    return e;
}
node left_node(node e){
    node pre=e;
    while(pre->node_left!=NULL){
        pre=pre->node_left;
    }
    return pre;
}

node right_node(node e){
    node next=e;
    while(next->node_right!=NULL){
        next=next->node_right;
    }
    return next;
}

bool is_leaf(node e){
    return e->label.leaf_num>=0;
}

bool is_empty(node e){
    return e==NULL;
}

bool is_internal(node e){
    return e->label.node_name!='N';
}

char node_name(node e){
    return e->label.node_name;
}

float leaf_root(node e){
    return e->label.leaf_num;
    
} 

void affiche(node e){
    node next=e;
    int i = 0;
    while(next->node_left!=NULL){
        next=next->node_left;
        i++;
    }
    for(int j=0; j<i-1; j++){ printf("%c " ,'(');}
    next=e;
    while(i>=0){
        for(int j=0; j<i; j++){
            next=next->node_left;
        }    
        printf("%c ", next->label.node_name);
        if(next->node_left!=NULL && is_leaf(next->node_left)){printf("%f ", next->node_left->label.leaf_num);}
        if(next->node_right!=NULL){    
            next=next->node_right;
            printf("%f ", next->label.leaf_num);
            printf("%c ", ')');
        }    
        i--;
        next=e;
    }    
    printf("\n");

}

float eval(node e){
    node next=e;
   
    int i = 0;
    while(next->node_left->node_left!=NULL){
        next=next->node_left;
        i++;
    }   
    float res = next->node_left->label.leaf_num; 
  
    if (next->label.node_name='-'){ res=0-res;}
    next=e;
    while(i>=0){
        for(int j=0; j<i; j++){
            next=next->node_left;
        }    
        switch (next->label.node_name)
        {
        case '+':
            if(next->node_right!=NULL){    
                next=next->node_right;
                res=res+next->label.leaf_num;
            } 
            break;
        case '-':
            if(next->node_right!=NULL){    
                next=next->node_right;
                res=res-next->label.leaf_num;
            } 
            break;
        case '*':
            if(next->node_right!=NULL){    
                next=next->node_right;
                res=res*next->label.leaf_num;
            } 
        case '/':    
            break;
            if(next->node_right!=NULL){    
                next=next->node_right;
                res=res/next->label.leaf_num;
            } 
        default:
            return res;
        }
        i--;
        next=e;
    }    

    return res;
}

