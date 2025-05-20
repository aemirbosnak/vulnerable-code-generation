//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Paranoid circuit simulator

// Circuit elements
typedef struct {
    char *name;
    int num_inputs;
    int num_outputs;
    bool *inputs;
    bool *outputs;
} Element;

// Circuit
typedef struct {
    int num_elements;
    Element *elements;
} Circuit;

// Create a new circuit
Circuit *new_circuit(int num_elements) {
    Circuit *circuit = malloc(sizeof(Circuit));
    circuit->num_elements = num_elements;
    circuit->elements = malloc(sizeof(Element) * num_elements);
    return circuit;
}

// Add an element to a circuit
void add_element(Circuit *circuit, Element element) {
    circuit->elements[circuit->num_elements++] = element;
}

// Create a new element
Element new_element(char *name, int num_inputs, int num_outputs) {
    Element element;
    element.name = strdup(name);
    element.num_inputs = num_inputs;
    element.num_outputs = num_outputs;
    element.inputs = malloc(sizeof(bool) * num_inputs);
    element.outputs = malloc(sizeof(bool) * num_outputs);
    return element;
}

// Set the inputs of an element
void set_inputs(Element *element, bool *inputs) {
    memcpy(element->inputs, inputs, sizeof(bool) * element->num_inputs);
}

// Get the outputs of an element
void get_outputs(Element *element, bool *outputs) {
    memcpy(outputs, element->outputs, sizeof(bool) * element->num_outputs);
}

// Simulate a circuit
void simulate_circuit(Circuit *circuit) {
    for (int i = 0; i < circuit->num_elements; i++) {
        Element *element = &circuit->elements[i];

        // Calculate the outputs of the element
        for (int j = 0; j < element->num_outputs; j++) {
            element->outputs[j] = true;  // Paranoid: always set to true
        }
    }
}

// Print the results of a simulation
void print_results(Circuit *circuit) {
    for (int i = 0; i < circuit->num_elements; i++) {
        Element *element = &circuit->elements[i];

        printf("%s: ", element->name);
        for (int j = 0; j < element->num_outputs; j++) {
            printf("%d ", element->outputs[j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new circuit
    Circuit *circuit = new_circuit(3);

    // Add elements to the circuit
    Element element1 = new_element("AND", 2, 1);
    add_element(circuit, element1);
    Element element2 = new_element("OR", 2, 1);
    add_element(circuit, element2);
    Element element3 = new_element("NOT", 1, 1);
    add_element(circuit, element3);

    // Set the inputs of the elements
    bool inputs1[] = {true, false};
    set_inputs(&element1, inputs1);
    bool inputs2[] = {false, true};
    set_inputs(&element2, inputs2);
    bool inputs3[] = {true};
    set_inputs(&element3, inputs3);

    // Simulate the circuit
    simulate_circuit(circuit);

    // Print the results of the simulation
    print_results(circuit);

    return 0;
}