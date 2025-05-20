//FormAI DATASET v1.0 Category: Syntax parsing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct token {
    char type[MAX_LENGTH];
    char value[MAX_LENGTH];
} token;

typedef struct node {
    token tk;
    struct node* next;
} node;

node* head = NULL;

void add_token(char* type, char* value) {
    node* new_node = malloc(sizeof(node));
    strcpy(new_node->tk.type, type);
    strcpy(new_node->tk.value, value);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_tokens() {
    node* current = head;
    while (current != NULL) {
        printf("<%s, %s>\n", current->tk.type, current->tk.value);
        current = current->next;
    }
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a C syntax statement:\n");
    fgets(input, MAX_LENGTH, stdin);

    char* token = strtok(input, " ");

    while (token != NULL) {
        if (strcmp(token, "int") == 0 || strcmp(token, "char") == 0 || strcmp(token, "float") == 0) {
            add_token("DATA_TYPE", token);
        } else if (strcmp(token, "==") == 0 || strcmp(token, "!=") == 0 || strcmp(token, ">=") == 0) {
            add_token("OPERATOR", token);
        } else if (token[0] >= '0' && token[0] <= '9') {
            add_token("CONSTANT", token);
        } else {
            add_token("IDENTIFIER", token);
        }

        token = strtok(NULL, " ");
    }

    printf("Tokens:\n");
    print_tokens();

    return 0;
}