//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: futuristic
#include <stdbool.h>
#include <stdio.h>

typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

typedef struct Stack {
    struct Node *top;
    int size;
} Stack;

Node *create_node(char data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Stack *create_stack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void push(Stack *stack, Node *node) {
    node->right = stack->top;
    stack->top = node;
    stack->size++;
}

Node *pop(Stack *stack) {
    if (stack->size == 0) {
        return NULL;
    }
    Node *temp = stack->top;
    stack->top = temp->right;
    stack->size--;
    return temp;
}

bool is_operator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int evaluate(char *expression) {
    Stack *stack = create_stack();
    int i = 0;
    while (expression[i] != '\0') {
        char ch = expression[i];
        if (isdigit(ch)) {
            int num = ch - '0';
            push(stack, create_node(num));
        } else if (is_operator(ch)) {
            Node *op2 = pop(stack);
            Node *op1 = pop(stack);
            int result = 0;
            switch (ch) {
                case '+':
                    result = op1->data + op2->data;
                    break;
                case '-':
                    result = op1->data - op2->data;
                    break;
                case '*':
                    result = op1->data * op2->data;
                    break;
                case '/':
                    result = op1->data / op2->data;
                    break;
            }
            push(stack, create_node(result));
        }
        i++;
    }
    return pop(stack)->data;
}

int main() {
    char expression[] = "1+2*3-4/5";
    int result = evaluate(expression);
    printf("Result: %d\n", result);
    return 0;
}