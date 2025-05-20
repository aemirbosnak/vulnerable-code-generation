//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char name[MAX_SIZE];
    struct Node* next;
} Node;

void create_topology(Node* head) {
    head = (Node*)malloc(sizeof(Node));
    head->name[0] = '\0';
    head->next = NULL;
}

void add_node(Node* head, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->name[0] = '\0';
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (head->next == NULL) {
        head->next = newNode;
    } else {
        head->next->next = newNode;
    }
}

void traverse_topology(Node* head) {
    Node* current = head->next;
    while (current) {
        printf("%s ", current->name);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    create_topology(head);

    add_node(head, "A");
    add_node(head, "B");
    add_node(head, "C");
    add_node(head, "D");

    traverse_topology(head);

    return 0;
}