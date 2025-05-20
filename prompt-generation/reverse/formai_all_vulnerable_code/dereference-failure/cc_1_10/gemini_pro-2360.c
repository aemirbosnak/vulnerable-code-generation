//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

// Circuit element types
typedef enum {
    ELEMENT_TYPE_WIRE,
    ELEMENT_TYPE_NOT,
    ELEMENT_TYPE_AND,
    ELEMENT_TYPE_OR,
    ELEMENT_TYPE_XOR,
    ELEMENT_TYPE_NAND,
    ELEMENT_TYPE_NOR,
    ELEMENT_TYPE_XNOR,
} element_type_t;

// Circuit element
typedef struct {
    element_type_t type;
    uint32_t num_inputs;
    uint32_t *inputs;
    uint32_t output;
} element_t;

// Circuit
typedef struct {
    uint32_t num_elements;
    element_t *elements;
} circuit_t;

// Create a new circuit
circuit_t *circuit_new(uint32_t num_elements) {
    circuit_t *circuit = malloc(sizeof(circuit_t));
    circuit->num_elements = num_elements;
    circuit->elements = malloc(sizeof(element_t) * num_elements);
    return circuit;
}

// Free a circuit
void circuit_free(circuit_t *circuit) {
    free(circuit->elements);
    free(circuit);
}

// Add an element to a circuit
void circuit_add_element(circuit_t *circuit, element_type_t type, uint32_t num_inputs, uint32_t *inputs, uint32_t output) {
    element_t *element = &circuit->elements[circuit->num_elements];
    element->type = type;
    element->num_inputs = num_inputs;
    element->inputs = inputs;
    element->output = output;
    circuit->num_elements++;
}

// Simulate a circuit
void circuit_simulate(circuit_t *circuit) {
    for (uint32_t i = 0; i < circuit->num_elements; i++) {
        element_t *element = &circuit->elements[i];
        switch (element->type) {
            case ELEMENT_TYPE_WIRE:
                element->output = element->inputs[0];
                break;
            case ELEMENT_TYPE_NOT:
                element->output = !element->inputs[0];
                break;
            case ELEMENT_TYPE_AND:
                element->output = element->inputs[0] && element->inputs[1];
                break;
            case ELEMENT_TYPE_OR:
                element->output = element->inputs[0] || element->inputs[1];
                break;
            case ELEMENT_TYPE_XOR:
                element->output = element->inputs[0] ^ element->inputs[1];
                break;
            case ELEMENT_TYPE_NAND:
                element->output = !(element->inputs[0] && element->inputs[1]);
                break;
            case ELEMENT_TYPE_NOR:
                element->output = !(element->inputs[0] || element->inputs[1]);
                break;
            case ELEMENT_TYPE_XNOR:
                element->output = !(element->inputs[0] ^ element->inputs[1]);
                break;
        }
    }
}

// Print a circuit
void circuit_print(circuit_t *circuit) {
    for (uint32_t i = 0; i < circuit->num_elements; i++) {
        element_t *element = &circuit->elements[i];
        printf("%d: ", i);
        switch (element->type) {
            case ELEMENT_TYPE_WIRE:
                printf("WIRE ");
                break;
            case ELEMENT_TYPE_NOT:
                printf("NOT ");
                break;
            case ELEMENT_TYPE_AND:
                printf("AND ");
                break;
            case ELEMENT_TYPE_OR:
                printf("OR ");
                break;
            case ELEMENT_TYPE_XOR:
                printf("XOR ");
                break;
            case ELEMENT_TYPE_NAND:
                printf("NAND ");
                break;
            case ELEMENT_TYPE_NOR:
                printf("NOR ");
                break;
            case ELEMENT_TYPE_XNOR:
                printf("XNOR ");
                break;
        }
        for (uint32_t j = 0; j < element->num_inputs; j++) {
            printf("%d ", element->inputs[j]);
        }
        printf("%d\n", element->output);
    }
}

// Main function
int main(int argc, char **argv) {
    // Create a new circuit
    circuit_t *circuit = circuit_new(10);

    // Add elements to the circuit
    circuit_add_element(circuit, ELEMENT_TYPE_WIRE, 1, (uint32_t[]){0}, 1);
    circuit_add_element(circuit, ELEMENT_TYPE_NOT, 1, (uint32_t[]){1}, 2);
    circuit_add_element(circuit, ELEMENT_TYPE_AND, 2, (uint32_t[]){1, 2}, 3);
    circuit_add_element(circuit, ELEMENT_TYPE_OR, 2, (uint32_t[]){1, 2}, 4);
    circuit_add_element(circuit, ELEMENT_TYPE_XOR, 2, (uint32_t[]){1, 2}, 5);
    circuit_add_element(circuit, ELEMENT_TYPE_NAND, 2, (uint32_t[]){1, 2}, 6);
    circuit_add_element(circuit, ELEMENT_TYPE_NOR, 2, (uint32_t[]){1, 2}, 7);
    circuit_add_element(circuit, ELEMENT_TYPE_XNOR, 2, (uint32_t[]){1, 2}, 8);

    // Simulate the circuit
    circuit_simulate(circuit);

    // Print the circuit
    circuit_print(circuit);

    // Free the circuit
    circuit_free(circuit);

    return 0;
}