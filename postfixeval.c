#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    int items[MAX_SIZE];
} Stack;

void push(Stack *stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    stack->items[++(stack->top)] = value;
}

int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return stack->items[(stack->top)--];
}

int evaluatePostfix(char *expression) {
    Stack stack;
    stack.top = -1;

    int i, operand1, operand2, result;

    for (i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0');
        } else {
            operand2 = pop(&stack);
            operand1 = pop(&stack);

            switch (expression[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator!\n");
                    exit(1);
            }

            push(&stack, result);
        }
    }

    return pop(&stack);
}

int main() {
    char expression[MAX_SIZE];
    printf("Enter a postfix expression: ");
    scanf("%s", expression);

    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);

    return 0;
}
