//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

struct node {
    char *name;
    int size;
    struct node *next;
};

void add_node(struct node *head, char *name, int size) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->name = strdup(name);
    new_node->size = size;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print_list(struct node *head) {
    while (head!= NULL) {
        printf("%s (%d bytes)\n", head->name, head->size);
        head = head->next;
    }
}

int main() {
    struct node *head = NULL;
    char input[MAX_SIZE];

    while (1) {
        printf("Enter a string to allocate memory for: ");
        fgets(input, MAX_SIZE, stdin);

        char *allocated_memory = malloc(strlen(input) + 1);
        strcpy(allocated_memory, input);

        add_node(head, input, strlen(input));

        free(allocated_memory);
    }

    return 0;
}