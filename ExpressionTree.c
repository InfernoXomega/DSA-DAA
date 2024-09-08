#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(char data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

TreeNode* buildExpressionTree(char postfix[]) {
    int stackSize = strlen(postfix);
    TreeNode** stack = (TreeNode**)malloc(stackSize * sizeof(TreeNode*));
    int top = -1;

    for (int i = 0; i < stackSize; i++) {
        TreeNode* node = createNode(postfix[i]);

        if (!isOperator(postfix[i])) {
            stack[++top] = node;
        } else {
            node->right = stack[top--];
            node->left = stack[top--];
            stack[++top] = node;
        }
    }

    TreeNode* root = stack[top--];
    free(stack);
    return root;
}

int evaluateExpressionTree(TreeNode* root) {
    if (!root)
        return 0;

    if (!isOperator(root->data))
        return root->data - '0';

    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);

    switch (root->data) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            return leftValue / rightValue;
        default:
            return 0;
    }
}

int main() {
    char postfix[100]; // Define a buffer for the postfix expression
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    TreeNode* root = buildExpressionTree(postfix);

    printf("Postfix Expression: %s\n", postfix);
    printf("Result: %d\n", evaluateExpressionTree(root));

    return 0;
}