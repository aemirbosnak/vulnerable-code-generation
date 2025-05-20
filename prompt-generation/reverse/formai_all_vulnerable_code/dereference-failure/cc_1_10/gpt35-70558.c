//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Data structure to hold the network topology
typedef struct Node {
    int id;
    struct Node *next;
} Node;

// Function to add a new node to the topology graph
Node *addNode(Node *head, int id) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->id = id;
    new_node->next = NULL;
    
    if(head == NULL) {
        head = new_node;
        return head;
    }
    
    Node *ptr = head;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    
    ptr->next = new_node;
    return head;
}

// Function to print the contents of the network topology graph
void printGraph(Node *head) {
    printf("Network Topology Graph:\n");
    printf("------------------------\n");
    
    Node *ptr = head;
    while(ptr != NULL) {
        printf("%d ", ptr->id);
        ptr = ptr->next;
    }
    
    printf("\n");
}

int main() {
    Node *topology = NULL;
    
    // Adding nodes to the topology graph
    topology = addNode(topology, 1);
    topology = addNode(topology, 2);
    topology = addNode(topology, 3);
    topology = addNode(topology, 4);
    topology = addNode(topology, 5);
    
    // Printing the network topology
    printGraph(topology);
    
    return 0;
}