//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

struct node {
    char *data;
    struct node *next;
};

struct node *compress(struct node *head) {
    struct node *current = head;
    struct node *previous = NULL;
    struct node *new_head = NULL;
    char buffer[MAX_LEN];
    int i = 0;

    while (current != NULL) {
        if (i > 0) {
            buffer[i] = current->data[i];
        }
        i++;

        if (current->next != NULL) {
            previous = current;
            current = current->next;
        } else {
            previous = current;
            current = NULL;
        }
    }

    new_head = (struct node *)malloc(sizeof(struct node));
    new_head->data = buffer;
    new_head->next = NULL;

    return new_head;
}

int main() {
    struct node *head = NULL;
    struct node *node1 = (struct node *)malloc(sizeof(struct node));
    struct node *node2 = (struct node *)malloc(sizeof(struct node));
    struct node *node3 = (struct node *)malloc(sizeof(struct node));

    node1->data = "Hello";
    node2->data = "World";
    node3->data = "!";

    head = compress(head);

    printf("%s\n", head->data);

    return 0;
}