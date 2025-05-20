//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[100];
    int id;
    struct node* next;
} Node;

Node* create_node(const char* name, int id) {
    Node* node = (Node*)malloc(sizeof(Node));
    strncpy(node->name, name, sizeof(node->name));
    node->id = id;
    node->next = NULL;
    return node;
}

Node* find_node(Node* head, const char* name) {
    Node* curr = head;
    while (curr!= NULL && strcmp(curr->name, name)!= 0) {
        curr = curr->next;
    }
    return curr;
}

void add_node(Node* head, const char* name, int id) {
    Node* node = create_node(name, id);
    node->next = head;
    head = node;
}

void print_nodes(Node* head) {
    Node* curr = head;
    while (curr!= NULL) {
        printf("%s: %d\n", curr->name, curr->id);
        curr = curr->next;
    }
}

int main() {
    Node* head = NULL;
    add_node(head, "A", 1);
    add_node(head, "B", 2);
    add_node(head, "C", 3);
    add_node(head, "D", 4);
    add_node(head, "E", 5);

    print_nodes(head);
    printf("Name: ");
    char name[100];
    fgets(name, sizeof(name), stdin);
    Node* node = find_node(head, name);
    if (node == NULL) {
        printf("Node not found.\n");
    } else {
        printf("ID: %d\n", node->id);
    }

    return 0;
}