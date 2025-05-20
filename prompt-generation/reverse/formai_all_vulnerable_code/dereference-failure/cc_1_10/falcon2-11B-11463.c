//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[20];
    int x, y;
    struct node* next;
};

struct node* create_node(char name[], int x, int y) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    strcpy(node->name, name);
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

struct node* add_node(struct node* head, char name[], int x, int y) {
    struct node* new_node = create_node(name, x, y);
    struct node* current = head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

void print_nodes(struct node* head) {
    struct node* current = head;
    while (current!= NULL) {
        printf("%s (%d, %d)\n", current->name, current->x, current->y);
        current = current->next;
    }
}

int main() {
    struct node* head = NULL;
    add_node(head, "A", 0, 0);
    add_node(head, "B", 1, 0);
    add_node(head, "C", 0, 1);
    add_node(head, "D", 2, 0);
    add_node(head, "E", 1, 1);
    add_node(head, "F", 2, 1);
    add_node(head, "G", 3, 0);
    add_node(head, "H", 3, 1);
    add_node(head, "I", 4, 0);
    add_node(head, "J", 4, 1);

    print_nodes(head);

    return 0;
}