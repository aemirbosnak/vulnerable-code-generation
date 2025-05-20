//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: automated
#include <stdio.h>

// Structure to represent a node in the network
typedef struct Node {
    int id;
    char* name;
    struct Node* next;
} Node;

// Structure to represent a connection between nodes
typedef struct Connection {
    int from;
    int to;
    int weight;
} Connection;

// Function to add a new node to the network
Node* addNode(Node* head, int id, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->name = name;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

// Function to add a new connection to the network
void addConnection(Connection connections[], int index, int from, int to, int weight) {
    connections[index].from = from;
    connections[index].to = to;
    connections[index].weight = weight;
}

// Function to print out the network
void printNetwork(Node* head, Connection connections[], int totalConnections) {
    Node* current = head;
    printf("Nodes:\n");
    while (current != NULL) {
        printf("Node %d: %s\n", current->id, current->name);
        current = current->next;
    }
    printf("Connections:\n");
    for (int i = 0; i < totalConnections; i++) {
        printf("%d -> %d (Weight: %d)\n", connections[i].from, connections[i].to, connections[i].weight);
    }
}

int main() {
    Node* head = NULL;
    head = addNode(head, 1, "Web Server");
    head = addNode(head, 2, "Database Server");
    head = addNode(head, 3, "Firewall");
    head = addNode(head, 4, "Router");
    head = addNode(head, 5, "Switch");

    Connection connections[10];
    addConnection(connections, 0, 1, 4, 2);
    addConnection(connections, 1, 2, 4, 4);
    addConnection(connections, 2, 3, 4, 3);
    addConnection(connections, 3, 4, 5, 1);
    addConnection(connections, 4, 5, 1, 5);

    printNetwork(head, connections, 5);

    return 0;
}