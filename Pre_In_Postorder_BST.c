#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct Stack {
    struct TreeNode* data;
    struct Stack* next;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Stack* createStack() {
    return NULL;
}

bool isEmpty(struct Stack* stack) {
    return stack == NULL;
}

void push(struct Stack** stack, struct TreeNode* node) {
    struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack));
    newNode->data = node;
    newNode->next = *stack;
    *stack = newNode;
}

struct TreeNode* pop(struct Stack** stack) {
    if (isEmpty(*stack)) {
        return NULL;
    }
    struct Stack* temp = *stack;
    *stack = (*stack)->next;
    struct TreeNode* popped = temp->data;
    free(temp);
    return popped;
}

void preorder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    struct Stack* stack = createStack();
    push(&stack, root);
    while (!isEmpty(stack)) {
        struct TreeNode* current = pop(&stack);
        printf("%d ", current->data);
        if (current->right != NULL) {
            push(&stack, current->right);
        }
        if (current->left != NULL) {
            push(&stack, current->left);
        }
    }
}

void inorder(struct TreeNode* root) {
    struct Stack* stack = createStack();
    struct TreeNode* current = root;
    while (!isEmpty(stack) || current != NULL) {
        if (current != NULL) {
            push(&stack, current);
            current = current->left;
        } else {
            current = pop(&stack);
            printf("%d ", current->data);
            current = current->right;
        }
    }
}

void postorder(struct TreeNode* root) {
    struct Stack* stack1 = createStack();
    struct Stack* stack2 = createStack();
    push(&stack1, root);
    while (!isEmpty(stack1)) {
        struct TreeNode* current = pop(&stack1);
        push(&stack2, current);
        if (current->left != NULL) {
            push(&stack1, current->left);
        }
        if (current->right != NULL) {
            push(&stack1, current->right);
        }
    }
    while (!isEmpty(stack2)) {
        printf("%d ", pop(&stack2)->data);
    }
}

int main() {
    struct TreeNode* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
