//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_NODES 5
#define MAX_CIRCUIT_SIZE 10

typedef struct Node {
    bool value;
    struct Node* inputs[2];
    struct Node* outputs[2];
} Node;

Node* createNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = false;
    newNode->inputs[0] = NULL;
    newNode->inputs[1] = NULL;
    newNode->outputs[0] = NULL;
    newNode->outputs[1] = NULL;
    return newNode;
}

void setNodeValue(Node* node, bool value) {
    node->value = value;
}

bool getNodeValue(Node* node) {
    return node->value;
}

Node* getRandomNode(Node* circuit[], int circuitSize) {
    int randomIndex = rand() % circuitSize;
    return circuit[randomIndex];
}

void connectNodes(Node* outputNode, Node* inputNode, int inputIndex) {
    outputNode->outputs[inputIndex] = inputNode;
    inputNode->inputs[0] = outputNode;
}

void printNodeValue(Node* node) {
    printf("%d", node->value);
}

void printCircuit(Node* circuit[], int circuitSize) {
    printf("Circuit state: ");
    for (int i = 0; i < circuitSize; i++) {
        Node* node = circuit[i];
        printNodeValue(node);
    }
    printf("\n");
}

void simulateCircuit(Node* inputs[], int numInputs, Node* circuit[], int circuitSize) {
    for (int i = 0; i < numInputs; i++) {
        setNodeValue(inputs[i], rand() % 2 == 0);
    }

    for (int i = 0; i < circuitSize; i++) {
        Node* node = circuit[i];
        bool inputValue = false;
        for (int j = 0; j < 2; j++) {
            Node* inputNode = node->inputs[j];
            if (inputNode != NULL) {
                inputValue |= getNodeValue(inputNode);
            }
        }
        setNodeValue(node, inputValue);
    }
}

int main() {
    srand(time(NULL));

    // create input nodes
    Node* inputs[NUM_NODES];
    for (int i = 0; i < NUM_NODES; i++) {
        inputs[i] = createNode();
    }

    // create circuit nodes
    Node* circuit[MAX_CIRCUIT_SIZE];
    int circuitSize = 0;
    for (int i = 0; i < 2; i++) {
        Node* node = createNode();
        circuit[circuitSize++] = node;
        for (int j = 0; j < NUM_NODES; j++) {
            connectNodes(node, inputs[j], i);
        }
    }

    Node* lastOutputNode = circuit[circuitSize - 1];
    Node* outNode = createNode();
    connectNodes(lastOutputNode, outNode, 0);
    circuit[circuitSize++] = outNode;

    printf("Initial input state: ");
    for (int i = 0; i < NUM_NODES; i++) {
        printNodeValue(inputs[i]);
    }
    printf("\n");

    printCircuit(circuit, circuitSize);

    simulateCircuit(inputs, NUM_NODES, circuit, circuitSize);

    printf("Output state after simulating circuit: ");
    printNodeValue(outNode);
    printf("\n");

    return 0;
}