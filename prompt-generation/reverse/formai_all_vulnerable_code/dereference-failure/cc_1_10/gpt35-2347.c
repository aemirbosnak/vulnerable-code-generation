//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum {GATE_AND, GATE_OR, GATE_XOR};

typedef struct Node Node;
struct Node {
    Node *in1, *in2;
    int gate_type;
    int value, state;
};

Node* create_input_node();
Node* create_gate_node(int gate_type, Node* in1, Node* in2);
void evaluate_node(Node* node, int (*lookup_table)[2]);
void simulate_circuit(Node* input1, Node* input2, Node* output, int (*lookup_table)[2]);

int main() {
    // Create two input nodes and one output node
    Node* input1 = create_input_node();
    Node* input2 = create_input_node();
    Node* output = create_gate_node(GATE_AND, input1, input2);

    // Set up the truth table
    int lookup_table[4][2] = {
        {0, 0}, {0, 1}, {1, 0}, {1, 1}
    };

    // Simulate the circuit for all possible input values
    simulate_circuit(input1, input2, output, lookup_table);

    return 0;
}

Node* create_input_node() {
    Node* node = malloc(sizeof(Node));
    node->in1 = NULL;
    node->in2 = NULL;
    node->gate_type = -1;
    node->value = -1;
    node->state = 0;
    return node;
}

Node* create_gate_node(int gate_type, Node* in1, Node* in2) {
    Node* node = malloc(sizeof(Node));
    node->in1 = in1;
    node->in2 = in2;
    node->gate_type = gate_type;
    node->value = -1;
    node->state = 0;
    return node;
}

void evaluate_node(Node* node, int (*lookup_table)[2]) {
    if (node == NULL) {
        return;
    }

    // Recursive evaluate inputs first
    evaluate_node(node->in1, lookup_table);
    evaluate_node(node->in2, lookup_table);

    // Evaluate this node's output based on its inputs and gate type
    switch (node->gate_type) {
        case GATE_AND:
            node->value = node->in1->value && node->in2->value;
            break;

        case GATE_OR:
            node->value = node->in1->value || node->in2->value;
            break;

        case GATE_XOR:
            node->value = node->in1->value ^ node->in2->value;
            break;

        default:
            // This should never happen
            node->value = 0;
            break;
    }

    // Set the node's state to 1 after its output has been evaluated
    node->state = 1;
}

void simulate_circuit(Node* input1, Node* input2, Node* output, int (*lookup_table)[2]) {
    printf("Simulating circuit...\n");

    // Try all possible input values
    for (int i = 0; i < 4; i++) {
        input1->value = lookup_table[i][0];
        input2->value = lookup_table[i][1];

        // Reset the state of all nodes to 0
        Node* current_node = output;
        while (current_node != NULL) {
            current_node->state = 0;
            current_node = current_node->in1;
        }

        // Evaluate the output
        evaluate_node(output, lookup_table);

        // Print the input and output values
        printf("Input values: %d %d\n", input1->value, input2->value);
        printf("Output value: %d\n", output->value);

        // Delay for 1 second to make the simulation more realistic
        sleep(1);
    }

    printf("Simulation complete.\n");
}