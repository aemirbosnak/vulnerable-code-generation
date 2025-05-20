//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define structure for nodes in the network
typedef struct Node {
    char name[30];
    int x;
    int y;
    struct Node* next;
} Node;

//Function to create a new node
Node* newNode(char* name, int x, int y) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

//Function to add a node to the network
void addNode(Node** head, char* name, int x, int y) {
    Node* node = newNode(name, x, y);
    node->next = *head;
    *head = node;
}

//Function to print the network topology
void printNetwork(Node* head) {
    Node* current = head;
    printf("Network topology:\n");
    while (current != NULL) {
        printf("[%s (%d, %d)] --> ", current->name, current->x, current->y);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    //Create a network topology with 4 nodes
    Node* head = NULL;
    addNode(&head, "Node1", 10, 20);
    addNode(&head, "Node2", 30, 40);
    addNode(&head, "Node3", 50, 60);
    addNode(&head, "Node4", 70, 80);

    //Print the network topology
    printNetwork(head);

    //Free the memory allocated to the nodes
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}