//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[20];
    int num_links;
    struct node *next;
};

struct node *head = NULL;

void add_node(char *name, int num_links) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    strcpy(new_node->name, name);
    new_node->num_links = num_links;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct node *current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_map(struct node *current) {
    if (current == NULL) {
        printf("No nodes in the network.\n");
        return;
    }

    printf("%s\n", current->name);
    printf("Nodes connected:\n");
    struct node *next = current->next;
    while (next!= NULL) {
        printf("%s\n", next->name);
        next = next->next;
    }
}

int main() {
    add_node("Node 1", 3);
    add_node("Node 2", 2);
    add_node("Node 3", 1);

    head = head->next;
    print_map(head);

    return 0;
}