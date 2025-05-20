//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define circuit elements
typedef struct element {
    char type;              // 'R' for resistor, 'L' for inductor, 'C' for capacitor
    double value;           // element value in ohms, henries or farads
    double impedance;       // impedance of the element
    
    // Pointer to next element in the circuit
    struct element *next;
} element;

// Define circuit
typedef struct circuit {
    char name[50];          // circuit name
    int num_elements;       // number of elements in the circuit
    element *head;          // pointer to first element in the circuit
} circuit;

// Function to add a new element to the circuit
void add_element(circuit *c, char type, double value) {
    element *new_element = (element*) malloc(sizeof(element));
    new_element->type = type;
    new_element->value = value;
    
    // Calculate element impedance based on type and value
    if (type == 'R') {
        new_element->impedance = value;
    }
    else if (type == 'L') {
        new_element->impedance = 2 * 3.14159 * 60 * value;   // Assume 60Hz AC Circuit
    }
    else if (type == 'C') {
        new_element->impedance = -1 / (2 * 3.14159 * 60 * value);
    }
    
    // Add new element to the end of the linked list
    if (c->head == NULL) {
        c->head = new_element;
    }
    else {
        element *current_element = c->head;
        while (current_element->next != NULL) {
            current_element = current_element->next;
        }
        current_element->next = new_element;
    }
    c->num_elements++;
}

// Recursive function to calculate total circuit impedance
double total_impedance(element *current_element) {
    if (current_element == NULL) {
        return 0;
    }
    else {
        return current_element->impedance + total_impedance(current_element->next);
    }
}

int main() {
    // Create a new circuit
    circuit my_circuit;
    my_circuit.num_elements = 0;
    my_circuit.head = NULL;
    
    // Add some elements to the circuit
    add_element(&my_circuit, 'R', 100);
    add_element(&my_circuit, 'L', 0.1);
    add_element(&my_circuit, 'C', 0.000001);
    
    // Calculate total impedance of the circuit
    double total_imp = total_impedance(my_circuit.head);
    printf("Total Impedance: %f ohms\n", total_imp);
    
    return 0;
}