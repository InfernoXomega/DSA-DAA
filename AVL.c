// operations on AVL Tree
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    int height;
    struct Node *left;
    struct Node *right;
};
struct Node *newNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->val = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    return (temp);
}

int height(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}
int max(int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    return b;
}

int balancefactor(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return (height(node->left) - height(node->right));
}

struct Node *rotateleft(struct Node *node)
{
    struct Node *x = node->right;
    struct Node *temp = x->left;

    x->left = node;
    node->right = temp;

    node->height = 1 + max(height(node->left), height(node->right));
    x->height = 1 + max(height(x->left), height(x->right));

    printf("check4\n");
    return x;
}

struct Node *rotateright(struct Node *node)
{
    struct Node *x = node->left;
    struct Node *temp = x->right;

    x->right = node;
    node->left = temp;

    node->height = 1 + max(height(node->left), height(node->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

void inorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

struct Node *insertNode(struct Node *node, int data)
{
    if (node == NULL)
    {
        printf("check1\n");
        return newNode(data);
    }
    if (data < node->val)
    {
        node->left = insertNode(node->left, data);
    }
    else if (data > node->val)
    {
        node->right = insertNode(node->right, data);
        printf("check2\n");
    }
    else
    {
        return node;
    }

    node->height = max(height(node->left), height(node->right)) + 1;

    int bf = balancefactor(node);
    printf("bf %d\n",bf);

    if (bf > 1 && data < (node->left->val))
    {
        return rotateright(node);
    }
    if (bf < -1 && data > (node->right->val))
    {
        return rotateleft(node);
        // printf("check3\n");

    }
    if (bf > 1 && data > (node->left->val))
    {
        node->left = rotateleft(node->left);
        return rotateright(node);
    }
    if (bf < -1 && data < (node->right->val))
    {
        node->right = rotateright(node->right);
        return rotateleft(node);
    }

    return node;
}

struct Node *deletenode(struct Node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->val)
    {
        root->left = deletenode(root->left, key);
    }
    else if (key > root->val)
    {
        root->right = deletenode(root->right, key);
    }
    else
    {
        if (root->left == NULL || root->right == NULL)
        {
            struct Node *temp = root->left ? root->left : root->right;

            if (temp==NULL)
            {
                temp=root;
                root=NULL;
            }
            else{
                *root=*temp;
            }
            free(temp);
        }
        else{
            /*find the minimum node of right sub-tree*/
            struct Node* current=root->right;
            while(current->left!=NULL){
                current=current->left;
            }

            root->val=current->val;
            root->right=deletenode(root->right,current->val);
        }
    }
    if(root==NULL){
        return root;
    }

    root->height=1+max(height(root->left),height(root->right));

    int bf=balancefactor(root);
    int bfLeft=balancefactor(root->left);
    int bfRight=balancefactor(root->right);

    if (bf > 1 && bfLeft>=0)
    {
        return rotateright(root);
    }
    if (bf < -1 && bfRight<=0)
    {
        return rotateleft(root);
    }
    if (bf > 1 && bfLeft<=0)
    {
        root = rotateleft(root);
        return rotateright(root);
    }
    if (bf < -1 && bfRight>=0)
    {
        root->right = rotateright(root);
        return rotateleft(root);
    }

    return root;
}
int main()
{
    struct Node *root = NULL;
    int data;

    while (1)
    {
        printf("Enter a value you want to insert or enter -1 to exit\n");
        scanf("%d",&data);
        if(data!=-1){
            root=insertNode(root,data);
            printf("AVL tree after inorder traversal\n");
            inorder(root);
            printf("\n");
        }
        else{
            break;
        }
    }

    while (1)
    {
        printf("Enter a value you want to delete or enter -1 to exit\n");
        scanf("%d",&data);
        if(data!=-1){
            root=deletenode(root,data);
            printf("AVL tree after inorder traversal\n");
            inorder(root);
            printf("\n");
        }
        else{
            break;
        }
    }

    return 0;
}
