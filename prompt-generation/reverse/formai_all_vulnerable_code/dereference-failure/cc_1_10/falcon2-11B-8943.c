//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char* name;
    int id;
    struct node* next;
} Node;

Node* create_node(char* name, int id) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->name = strdup(name);
    node->id = id;
    node->next = NULL;
    return node;
}

void add_node(Node* head, Node* node) {
    if (head == NULL) {
        head = node;
    } else {
        Node* curr = head;
        while (curr->next!= NULL) {
            curr = curr->next;
        }
        curr->next = node;
    }
}

void print_nodes(Node* head) {
    if (head == NULL) {
        printf("No nodes in the network.\n");
        return;
    }

    Node* curr = head;
    while (curr!= NULL) {
        printf("%s (%d)\n", curr->name, curr->id);
        curr = curr->next;
    }
}

int main() {
    Node* head = NULL;
    Node* node1 = create_node("Node 1", 1);
    add_node(head, node1);

    Node* node2 = create_node("Node 2", 2);
    add_node(head, node2);

    Node* node3 = create_node("Node 3", 3);
    add_node(head, node3);

    printf("Network topology:\n");
    print_nodes(head);
    printf("\n");

    return 0;
}