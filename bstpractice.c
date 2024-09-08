#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    struct node *left, *right; 
};

struct node* newnode(int value){
    struct node* temp= (struct node*)malloc(sizeof(struct node));
    temp->key=value;
    temp->left=temp->right=NULL;
    return temp;
}

struct node* insert(struct node* node, int key) {
    if (node == NULL)
        return newnode(key);
 
    if (key < node->key)
        node->left = insert(node->left, key);

    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main(){
    struct node *root = NULL;
    root = insert(root, 9);
    insert(root, 54);
    insert(root, 23);
    insert(root, 15);
    insert(root, 102);
    insert(root, 92);
    insert(root, 4);
    insert(root, 89);


    inorder (root);

    return 0;
}