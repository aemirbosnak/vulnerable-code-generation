//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct for holding information about a node in the network
typedef struct Node {
    int id;
    char name[50];
    struct Node* next;
} Node;

// add a node to the network
void addNode(Node* head, int id, char* name) {
    Node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = (Node*) malloc(sizeof(Node));
    curr->next->id = id;
    strcpy(curr->next->name, name);
    curr->next->next = NULL;
}

// print the network topology
void printTopology(Node* head) {
    Node* curr = head;
    printf("Network Topology:\n");
    while (curr->next != NULL) {
        printf("%s (%d) --> ", curr->name, curr->id);
        curr = curr->next;
    }
    printf("%s (%d)\n", curr->name, curr->id);
}

int main() {
    // create some sample nodes in the network
    Node* head = (Node*) malloc(sizeof(Node));
    head->id = 1;
    strcpy(head->name, "Router A");
    head->next = NULL;

    addNode(head, 2, "Switch B");
    addNode(head, 3, "Router C");
    addNode(head, 4, "PC D");
    addNode(head, 5, "Server E");

    // print the network topology
    printTopology(head);

    // free memory
    Node* curr = head;
    Node* temp;
    while (curr != NULL) {
        temp = curr->next;
        free(curr);
        curr = temp;
    }

    return 0;
}