//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: lively
/* Welcome to my Classical Circuit Simulator! */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_INPUTS 4
#define MAX_OUTPUTS 4

/* Node structure to hold circuit components */
typedef struct Node {
    char* name;
    bool value;
    bool evaluated;
    int num_inputs;
    struct Node** inputs;
    struct Node** outputs;
    bool (*fn)(bool inputs[]);
} Node;

/* Function prototypes */
Node* create_node(char* name, int num_inputs, bool (*fn)(bool inputs[]));
void evaluate(Node* node);
void print_values(Node* node);
void connect(Node* node1, Node* node2);
void simulate(Node* inputs[], int num_inputs, Node* outputs[], int num_outputs);

/* Circuit components */
bool and_gate(bool inputs[]) {
    return inputs[0] && inputs[1];
}

bool or_gate(bool inputs[]) {
    return inputs[0] || inputs[1];
}

bool not_gate(bool inputs[]) {
    return !inputs[0];
}

bool xor_gate(bool inputs[]) {
    return (inputs[0] && !inputs[1]) || (!inputs[0] && inputs[1]);
}

/* Creating a new node */
Node* create_node(char* name, int num_inputs, bool (*fn)(bool inputs[])) {
    Node* node = malloc(sizeof(Node));
    node->name = name;
    node->value = false;
    node->evaluated = false;
    node->num_inputs = num_inputs;
    node->inputs = malloc(num_inputs * sizeof(Node*));
    node->outputs = malloc(num_inputs * sizeof(Node*));
    node->fn = fn;
    return node;
}

/* Evaluating a node */
void evaluate(Node* node) {
    if (!node->evaluated) {
        bool inputs[node->num_inputs];
        for (int i = 0; i < node->num_inputs; i++) {
            inputs[i] = node->inputs[i]->value;
            evaluate(node->inputs[i]);
        }
        node->value = node->fn(inputs);
        node->evaluated = true;
    }
}

/* Printing node values */
void print_values(Node* node) {
    printf("%s: %d\n", node->name, node->value);
    for (int i = 0; i < node->num_inputs; i++) {
        print_values(node->inputs[i]);
    }
}

/* Connecting two nodes */
void connect(Node* node1, Node* node2) {
    node1->outputs[node1->num_inputs] = node2;
    node2->inputs[0] = node1;
    node1->num_inputs++;
}

/* Simulating a circuit */
void simulate(Node* inputs[], int num_inputs, Node* outputs[], int num_outputs) {
    /* Connect input nodes to circuit */
    for (int i = 0; i < num_inputs; i++) {
        for (int j = 0; j < num_outputs; j++) {
            connect(inputs[i], outputs[j]);
        }
    }
    /* Evaluate output nodes */
    for (int i = 0; i < num_outputs; i++) {
        evaluate(outputs[i]);
    }
}

int main() {
    /* Creating nodes */
    Node* a = create_node("A", 0, NULL);
    Node* b = create_node("B", 0, NULL);
    Node* c = create_node("C", 2, and_gate);
    Node* d = create_node("D", 2, or_gate);
    Node* e = create_node("E", 1, not_gate);
    Node* f = create_node("F", 2, xor_gate);
    Node* g = create_node("G", 2, and_gate);
    Node* h = create_node("H", 1, not_gate);
    Node* i = create_node("I", 2, or_gate);
    Node* j = create_node("J", 1, not_gate);

    /* Connecting nodes */
    connect(a, c);
    connect(b, c);
    connect(c, d);
    connect(d, e);
    connect(e, f);
    connect(f, g);
    connect(g, h);
    connect(g, i);
    connect(i, j);

    /* Setting input values */
    a->value = true;
    b->value = false;

    /* Simulating circuit */
    Node* inputs[MAX_INPUTS] = {a, b};
    Node* outputs[MAX_OUTPUTS] = {j};
    simulate(inputs, 2, outputs, 1);

    /* Printing node values */
    print_values(j);

    return 0;
}