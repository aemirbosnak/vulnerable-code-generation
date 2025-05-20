//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct Node {
    char* data;
    struct Node* next;
};

struct Stack {
    struct Node* head;
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->head = NULL;
    return stack;
}

void push(struct Stack* stack, char* data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = stack->head;
    stack->head = node;
}

char* pop(struct Stack* stack) {
    if (stack->head == NULL) {
        return NULL;
    }
    struct Node* temp = stack->head;
    stack->head = stack->head->next;
    char* data = temp->data;
    free(temp);
    return data;
}

void freeStack(struct Stack* stack) {
    struct Node* current = stack->head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }
    free(stack);
}

void parser(const char* filename) {
    FILE* fp;
    char line[MAX_SIZE];
    struct Stack* stack = createStack();
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Invalid filename!\n");
        return;
    }
    while (fgets(line, MAX_SIZE, fp)) {
        char* token = strtok(line, "<>\n");
        while (token != NULL) {
            if (token[0] == '/') {
                char* openTag = pop(stack);
                if (strcmp(openTag, &token[1]) != 0) {
                    printf("Invalid XML!\n");
                    freeStack(stack);
                    fclose(fp);
                    return;
                }
                printf("%s -- %s\n", openTag, token);
            } else if (token[0] != '?' && token[0] != '!') {
                push(stack, strdup(token));
                printf("%s -- \n", token);
            }
            token = strtok(NULL, "<>\n");
        }
    }
    if (stack->head != NULL) {
        printf("Invalid XML!\n");
        freeStack(stack);
        fclose(fp);
        return;
    }
    fclose(fp);
    freeStack(stack);
}

int main() {
    parser("example.xml");
    return 0;
}