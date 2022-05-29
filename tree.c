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
    node previous=left;
    node next=right;
    while(previous->node_right!=NULL){
        previous=previous->node_right;
    }
    previous->node_right=e;
    e->node_left=previous;
    while(next->node_left!=NULL){
        next=next->node_left;
    }
    next->node_left=e;
    e->node_right=next;
    return e;
}

node create_leaf(float x){
    node e=exprnew();
    e->label.leaf_num=x;
    return e;
}
node left_node(node e){
    node new=exprnew();
    e->node_left=new;
    new->node_right=e;
    return e;
}

node node_right(node e){
    node new=exprnew();
    e->node_right=new;
    new->node_left=e;
    return e;
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
    int c =1;
    if(is_empty(next)|| is_empty(e->node_right)){return;}
    printf("%c", '(');
    printf("%c",node_name(next->node_right));
    printf("%f ", leaf_root(next));
    next=next->node_right;

    while(next->node_right!=NULL){
        next=next->node_right;
        if(is_internal(next)){
            if(node_name(next)=='*'||node_name(next)=='%'||node_name(next)=='/'){c=0; printf("%c ",')');}
            printf("%c ",node_name(next));
        }
        if(is_leaf(next)){
            if(node_name(next->node_left)=='*'||node_name(next->node_left)=='%'||node_name(next->node_left)=='/'|| node_name(next->node_left)=='!'){c=1; printf("%c",'(');}
            printf("%f",leaf_root(next));
        }
    }
    if(c==1){printf("%c ",')');}
    printf("\n");
}

float eval(node e){
   node next =e;
   if(is_empty(next)){return 0;}
   if(is_empty(next->node_right)){return next->label.leaf_num;}
   float f=next->label.leaf_num;
   next=next->node_right;
   if(next->label.node_name='-'){f=-f;};
   next=next->node_right;
   while(!is_empty(next)&&!is_empty(next->node_right)){
        switch (node_name(next)){  
            case '*':
            f=f*next->node_right->label.leaf_num;
            break;

            case '-':
            f=f-next->node_right->label.leaf_num;
            break;

            case '+':
            f=f+next->node_right->label.leaf_num;
            break;
            
            case '%':
            f=(int)f%(int)(next->node_right->label.leaf_num);
            break;

            case '/':
            f=f/next->node_right->label.leaf_num;
            break;
    
            default:
            return f;
        }
        next=next->node_right->node_right;
   }
   return f;
}

bool est_valide(node e){
    node next = e;
    if(is_empty(next)||is_empty(next->node_right)
    || next->label.leaf_num<0 
    || next->node_right->label.node_name!='-' 
    || next->node_right->label.node_name!='+'){return 0;}
    next=next->node_right->node_right;
    while(!is_empty(next)&&!is_empty(next->node_right)){
        if(next->node_right->node_right->label.leaf_num<0){return 0;}
        switch (node_name(next)){  
            case '*':
            break;

            case '-':
            break;

            case '+':
            break;

            case '%':
            break;

            case '/':
            break;
    
            default:
            return 0;
        }
        next=next->node_right->node_right;
    }

    return 1;
}