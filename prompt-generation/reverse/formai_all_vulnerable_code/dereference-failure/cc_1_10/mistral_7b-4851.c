//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 100

typedef struct {
    char str[MAX_LENGTH];
    struct node *next;
} node;

node *head = NULL;
node *current = NULL;

void push(char *str) {
    node *new_node = (node *) malloc(sizeof(node));
    strcpy(new_node->str, str);
    new_node->next = head;
    head = new_node;
}

void print_list() {
    current = head;
    int i = 1;
    while (current != NULL) {
        printf("String %d: %s\n", i++, current->str);
        current = current->next;
    }
}

int main() {
    char *strings[MAX_STRINGS];

    for (int i = 0; i < MAX_STRINGS; i++) {
        printf("Enter string %d: ", i + 1);
        strings[i] = (char *) malloc(sizeof(char) * (MAX_LENGTH + 1));
        fgets(strings[i], MAX_LENGTH, stdin);
        strings[i][strlen(strings[i]) - 1] = '\0'; // Remove newline character

        push(strings[i]);
    }

    print_list();

    // Free memory
    current = head;
    while (head != NULL) {
        node *temp = head;
        head = head->next;
        free(temp->str);
        free(temp);
    }

    return 0;
}