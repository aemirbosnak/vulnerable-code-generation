//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char key[20];
    char value[100];
    struct Node *next;
} Node;

typedef struct Stack {
    int top;
    Node **elements;
    int capacity;
} Stack;

void init_stack(Stack *stack, int capacity) {
    stack->capacity = capacity;
    stack->elements = (Node **) calloc(stack->capacity, sizeof(Node *));
    stack->top = -1;
}

void push(Stack *stack, Node *item) {
    stack->top++;
    stack->elements[stack->top] = item;
}

Node *pop(Stack *stack) {
    if (stack->top < 0) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    Node *item = stack->elements[stack->top];
    stack->top--;
    return item;
}

void init_node(Node *node, char *key, char *value) {
    strcpy(node->key, key);
    strcpy(node->value, value);
    node->next = NULL;
}

void parse_line(char *line, Stack *stack) {
    char *token = strtok(line, ":");
    if (token == NULL) {
        return;
    }

    Node *node = (Node *) malloc(sizeof(Node));
    init_node(node, token, "");

    token = strtok(NULL, ":");
    if (token != NULL) {
        strcpy(node->value, token);
    }

    push(stack, node);
}

void parse_resume(char *filename, Stack *stack) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        parse_line(line, stack);
    }

    fclose(file);
}

void print_stack(Stack *stack) {
    Node *current = stack->elements[stack->top];
    while (current != NULL) {
        printf("%s: %s\n", current->key, current->value);
        current = current->next;
    }
}

int main() {
    Stack stack;
    init_stack(&stack, 100);

    parse_resume("resume.txt", &stack);
    print_stack(&stack);

    Node *node;
    while ((node = pop(&stack)) != NULL) {
        free(node);
    }

    free(stack.elements);

    return 0;
}