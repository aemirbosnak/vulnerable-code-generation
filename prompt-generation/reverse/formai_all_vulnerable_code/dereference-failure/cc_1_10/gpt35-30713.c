//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: dynamic
#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE 100

//Struct to hold the circuit node information
typedef struct Node {
    char* name;
    char* type;
    int value;
    int connectedNodes[MAX_SIZE];
    int numConnected;
} Node;

//Function to initialize a new Node struct
Node* newNode(char* name, char* type) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->name = name;
    node->type = type;
    node->numConnected = 0;
    return node;
}

//Prints the name and type of the given node
void printNode(Node* node) {
    printf("%s [%s] = %d\n", node->name, node->type, node->value);
}

//Simulates a simple circuit and prints the node values
void simulateCircuit(Node* nodes[], int numNodes) {
    //Set initial values
    nodes[0]->value = 5;
    nodes[1]->value = 2;
    nodes[2]->value = 0; //Output node
    
    //Simulate circuit
    for(int i = 0; i < numNodes; i++) {
        Node* node = nodes[i];
        if(node->type == "AND") {
            //AND gate
            int in1 = nodes[node->connectedNodes[0]]->value;
            int in2 = nodes[node->connectedNodes[1]]->value;
            node->value = in1 & in2;
        } else if(node->type == "OR") {
            //OR gate
            int in1 = nodes[node->connectedNodes[0]]->value;
            int in2 = nodes[node->connectedNodes[1]]->value;
            node->value = in1 | in2;
        } else if(node->type == "NOT") {
            //NOT gate
            int in1 = nodes[node->connectedNodes[0]]->value;
            node->value = !in1;
        }
    }
    
    //Print node values
    printf("Node Values:\n");
    for(int i = 0; i < numNodes; i++) {
        printNode(nodes[i]);
    }
}

int main() {
    //Create circuit nodes
    Node* node1 = newNode("A", "OR");
    Node* node2 = newNode("B", "AND");
    Node* node3 = newNode("C", "NOT");
    
    //Connect nodes
    node1->connectedNodes[0] = 0;
    node1->connectedNodes[1] = 1;
    node1->numConnected = 2;
    
    node2->connectedNodes[0] = 0;
    node2->connectedNodes[1] = 1;
    node2->numConnected = 2;
    
    node3->connectedNodes[0] = 2;
    node3->numConnected = 1;
    
    //Put all nodes into an array
    Node* nodes[MAX_SIZE];
    nodes[0] = node1;
    nodes[1] = node2;
    nodes[2] = node3;
    
    //Simulate the circuit and print the results
    simulateCircuit(nodes, 3);
    
    return 0;
}