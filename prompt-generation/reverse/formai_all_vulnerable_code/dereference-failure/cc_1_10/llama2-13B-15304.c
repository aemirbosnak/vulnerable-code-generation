//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

struct node {
    char data[MAX_LEN];
    struct node *next;
};

struct node *create_node(char *data) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    strcpy(node->data, data);
    node->next = NULL;
    return node;
}

void insert_node(struct node **head_ref, char *data) {
    struct node *new_node = create_node(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void print_nodes(struct node *head) {
    while (head != NULL) {
        printf("%s\n", head->data);
        head = head->next;
    }
}

int main() {
    struct node *head = NULL;

    insert_node(&head, "Hello World");
    insert_node(&head, "This is a test");
    insert_node(&head, "A longer string");

    print_nodes(head);

    // Compression logic goes here
    struct node *current = head;
    struct node *previous = NULL;
    while (current != NULL) {
        if (strlen(current->data) > 3) {
            // Find the longest common prefix of the current string and the previous string
            int len = strlen(current->data);
            char *prefix = current->data;
            while (previous != NULL && strlen(previous->data) < len) {
                prefix = previous->data;
                previous = previous->next;
            }

            // Replace the current string with the prefix
            current->data[0] = prefix[0];
            current->data[1] = prefix[1];
            current->data[2] = prefix[2];
            current->data[3] = '\0';

            // Remove the previous string from the list
            if (previous != NULL) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            current = previous;
        } else {
            previous = current;
        }
    }

    print_nodes(head);

    return 0;
}