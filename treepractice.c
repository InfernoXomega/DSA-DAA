#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* left;
  struct node* right;
};

struct node* createnode(data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data =data;
    newnode->left =NULL;
    newnode->right =NULL;
    return newnode;
}

struct node* leftinsert(struct node* root,int n) {
  root->left = createnode(n);
  return root->left;
}

struct node* rightinsert(struct node* root,int n){
    root->right = createnode(n);
    return root->right;
}

void inorder(struct node* root){
    if (root!=NULL){
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
    }
}

void preorder(struct node* root){
    if (root!=NULL){
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
    }
}

void postorder(struct node* root){
    if (root!=NULL){
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->data);
    }
}

int main(){
    struct node* root = NULL;
    createnode(root, 1);
    leftinsert(root, 2);
    rightinsert(root, 3);
    leftinsert(root->left, 4);

    printf("Inorder traversal \n");
    inorder(root);

    printf("\nPreorder traversal \n");
    preorder(root);

    printf("\nPostorder traversal \n");
    postorder(root);
}

//        1
//       /|
//      2 3
//     /
//    4