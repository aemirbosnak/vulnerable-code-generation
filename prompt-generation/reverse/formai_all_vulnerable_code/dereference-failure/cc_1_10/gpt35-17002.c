//FormAI DATASET v1.0 Category: Syntax parsing ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char* data;
    struct node* next;
} node_t;

typedef struct stack {
    node_t* head;
    int size;
} stack_t;

char* buffer = NULL;
int buffer_size = 0;

stack_t* create_stack() {
    stack_t* stack = (stack_t*)malloc(sizeof(stack_t));
    stack->head = NULL;
    stack->size = 0;
    return stack;
}

void push(stack_t* stack, char* data) {
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->data = data;
    node->next = stack->head;
    stack->head = node;
    stack->size++;
}

char* pop(stack_t* stack) {
    if (stack->size == 0)
        return NULL;
    node_t* node = stack->head;
    stack->head = node->next;
    stack->size--;
    return node->data;
}

char* peek(stack_t* stack) {
    if (stack->size == 0)
        return NULL;
    return stack->head->data;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    buffer = (char*)malloc(sizeof(char) * file_size);
    fread(buffer, sizeof(char), file_size, file);
    buffer_size = file_size;

    stack_t* stack = create_stack();

    int i;
    for (i = 0; i < buffer_size; i++) {
        if (buffer[i] == '(' || buffer[i] == '{' || buffer[i] == '[') {
            char* c = (char*)malloc(sizeof(char));
            *c = buffer[i];
            push(stack, c);
        } else if (buffer[i] == ')' || buffer[i] == '}' || buffer[i] == ']') {
            char* top = peek(stack);
            if (top == NULL) {
                printf("Error: Mismatched parentheses/brackets/braces\n");
                return 1;
            }
            if ((buffer[i] == ')' && *top == '(') || (buffer[i] == '}' && *top == '{') || (buffer[i] == ']' && *top == '[')) {
                pop(stack);
            } else {
                printf("Error: Mismatched parentheses/brackets/braces\n");
                return 1;
            }
        }
    }
    if (stack->size > 0) {
        printf("Error: Mismatched parentheses/brackets/braces\n");
        return 1;
    }
    printf("Syntax is correct\n");
    fclose(file);
    return 0;
}