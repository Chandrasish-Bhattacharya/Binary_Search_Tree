#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node *n;
    n = (struct node *) malloc(sizeof(struct node));
    n->data = data; 
    n->left = NULL; 
    n->right = NULL; 
    return n; 
}


void in_order(struct node *root){
    if(root!=NULL){
        in_order(root->left);
        printf("%3d",root->data);
        in_order(root->right);
        
    }
}

int isBST(struct  node* root){
    static struct node *prev = NULL; 
    if(root!=NULL){
        if(!isBST(root->left)){ // check wheather the left subtree is bst or not 
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);  // check wheather the right subtree is bst or not 
    }
    else{
        return 1;
    }
}



void insert(struct node *root, int key){
   struct node *prev = NULL;
   while(root!=NULL){
       prev = root;
       if(key==root->data){ // checking that is the root is present in the tree or not 
           printf("Cannot insert %d, already in BST", key);
           return;
       }
       else if(key<root->data){ // if the root key is less than the root then the new node is the left subtree's root 
           root = root->left;
       }
       else{
           root = root->right; // else the root changed to the right sub tree 
       }
   }
   struct node* new = createNode(key); // create the node and inserting the value of the key 
   if(key<prev->data){ 
       prev->left = new; // if the previous node was less than the key node then the node will be inserted in the left side 
   }
   else{
       prev->right = new; // else in the write side 
   }

}

int main(){
     
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(10);
    struct node *p1 = createNode(8);
    struct node *p2 = createNode(12);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(9);
    //         10
    //        /  \
    //       8   12
    //      / \
    //     5   9

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    insert(p, 16);
    in_order(p);
    return 0;
}
