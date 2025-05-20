//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAGIC_NUMBER 0xF00B1B1C
#define BUFFER_SIZE 1024

struct node {
    char *data;
    struct node *next;
};

void compress(struct node **head_ref) {
    struct node *head = *head_ref;
    struct node *current = head;
    struct node *previous = NULL;
    char buffer[BUFFER_SIZE];
    int buffer_index = 0;

    // Step 1: Scan the list and find the first duplicate
    while (current != NULL) {
        if (strcmp(current->data, previous->data) == 0) {
            // Found a duplicate!
            previous->next = current->next;
            current->next = NULL;
            current = previous;
        } else {
            previous = current;
            current = current->next;
        }
    }

    // Step 2: Compress the list by replacing duplicates with a single node
    while (current != NULL) {
        if (current->next != NULL) {
            // This node has a next node, so we can replace it with a single node
            current->next = NULL;
            current->data = current->next->data;
            current->next = current->next->next;
        }
        current = current->next;
    }

    // Step 3: Write the compressed list to the output buffer
    while (current != NULL) {
        strcpy(buffer + buffer_index, current->data);
        buffer_index += strlen(current->data) + 1;
        current = current->next;
    }

    // Step 4: Set the output buffer as the new head of the list
    *head_ref = current;
}

int main() {
    struct node *head = NULL;
    char *strings[] = {"Hello", "World", "Cool", "Code", "Guru", "99", "Bikes"};
    int i;

    // Initialize the list with the input strings
    for (i = 0; i < sizeof(strings) / sizeof(strings[0]); i++) {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = strings[i];
        new_node->next = head;
        head = new_node;
    }

    // Compress the list
    compress(&head);

    // Print the compressed list
    char *curr = head->data;
    while (curr != NULL) {
        printf("%s\n", curr);
        curr = head->next->data;
    }

    return 0;
}