//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100
#define SEARCH_VALUE "secret"

struct node {
    char value[MAX_LENGTH];
    struct node* next;
};

struct node* create_node(char* value) {
    struct node* new_node = malloc(sizeof(struct node));
    strcpy(new_node->value, value);
    new_node->next = NULL;
    return new_node;
}

int search_node(struct node* head, char* value) {
    int count = 0;
    struct node* current = head;

    while (current != NULL) {
        if (strcmp(current->value, value) == 0) {
            count++;
            break;
        }
        current = current->next;
    }

    return count;
}

int main() {
    struct node* head = NULL;

    // Create some nodes
    head = create_node("apple");
    head->next = create_node("banana");
    head->next->next = create_node("cherry");

    // Search for the secret value
    int count = search_node(head, SEARCH_VALUE);

    if (count > 0) {
        printf("Found %d nodes with value %s\n", count, SEARCH_VALUE);
    } else {
        printf("No nodes found with value %s\n", SEARCH_VALUE);
    }

    return 0;
}