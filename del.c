#include<stdio.h>
#include<malloc.h>

struct node{ //basic node structure of a tree 
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data){  // creation of the node
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
}

void insert(struct node *root,int key){
    struct node *prev;
    while(root!=NULL){
        prev = root;
        if(key == root->data){
            printf("Key already exist");
            return;
        }
        else if(key<root->data)
            root = root->left;
        else 
            root = root->right;
    }
    struct node *new = createNode(key);
    if(key<prev->data)
        prev->left = new;
    
    else 
        prev->right = new;

}
struct node *inorderSucceser(struct node *root){  // this function is use to find the inorder succesor for the node 
    //                 100 
    //               /     \
    //              90     110
    //             /  \    /  \
    //            70  95  101  120 
    //         now the inorder is 70 90 95 100 101 120   in order succssor of 100 is 101 so that is the left child of the right subtree 
    root = root->right;
    while(root->left !=NULL){
        root = root->left;
    }
    return root;
}

void in_order(struct node *root){
    if(root!=NULL){
        in_order(root->left);
        printf("%3d",root->data);
        in_order(root->right);
        
    }
}

struct node *delete(struct node *root,int key){
    struct node *isuc;
    if(root==NULL)  //checking condition that the root is null or not 
        return NULL;
    if (root->left == NULL && root ->right==NULL ){ // this means that the root pointer is pointing to the left of the tree 
        free(root);
        return NULL;
    }
    // Searching for node to find the node to be deleted 
    if(key <root->data){
        root->left = delete(root->left , key);
    }
    else if (key>root->data){
       root->right = delete(root->right , key);
    }
    //Deleting 
    else {
        isuc = inorderSucceser(root);
        root->data = isuc->data;
        root->right = delete(root->right , isuc->data);
    }
    return root;
}

void main(){
    int d; // to delete
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
    printf("TREE :-");
    in_order(p);
    printf("\nEnter the value which you want to delete");
    scanf("%d",&d);
    delete(p,d);
    printf("\nTREE after deletion:- ");
    in_order(p);
}