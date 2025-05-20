//MISTRAL-7B DATASET v1.0 Category: Cat Language Translator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char symbol;
    int priority;
    struct Node* next;
} Node;

typedef struct Stack {
    int top;
    Node* data;
} Stack;

void push(Stack* stack, char symbol, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->symbol = symbol;
    newNode->priority = priority;
    newNode->next = stack->data;
    stack->data = newNode;
    stack->top++;
}

char pop(Stack* stack) {
    if (stack->top < 0) {
        printf("Error: Stack underflow.\n");
        exit(1);
    }
    char symbol = stack->data->symbol;
    Node* temp = stack->data;
    stack->data = stack->data->next;
    stack->top--;
    free(temp);
    return symbol;
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

void translate(char* input, char* output) {
    int i = 0;
    Stack opStack;
    opStack.top = -1;
    opStack.data = NULL;

    while (input[i] != '\0') {
        if (isdigit(input[i])) {
            int j = i;
            while (isdigit(input[j])) {
                j++;
            }
            int num = 0;
            while (j > i) {
                num = num * 10 + input[j] - '0';
                j--;
            }
            i = j;
            sprintf(output + strlen(output), "%d ", num);
        } else if (isalnum(input[i])) {
            sprintf(output + strlen(output), "%c", input[i]);
        } else {
            while (opStack.top >= 0 && precedence(input[i]) <= precedence(opStack.data->symbol)) {
                char op = pop(&opStack);
                sprintf(output + strlen(output), " %c", op);
            }
            push(&opStack, input[i], precedence(input[i]));
        }
    }

    while (opStack.top >= 0) {
        char op = pop(&opStack);
        sprintf(output + strlen(output), " %c", op);
    }

    output[strlen(output)] = '\0';
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s input_string output_file\n", argv[0]);
        return 1;
    }

    char* input = argv[1];
    char* output = argv[2];

    translate(input, output);

    printf("Translated output saved to %s.\n", argv[2]);

    return 0;
}