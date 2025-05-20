//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Define the circuit elements
struct circuit_element {
    char type;
    double value;
    struct circuit_element *next;
};

// Function prototypes
struct circuit_element *create_element(char type, double value);
void print_circuit(struct circuit_element *head);
double evaluate_circuit(struct circuit_element *head);

// Create a circuit element
struct circuit_element *create_element(char type, double value) {
    struct circuit_element *new_element = (struct circuit_element *) malloc(sizeof(struct circuit_element));
    new_element->type = type;
    new_element->value = value;
    new_element->next = NULL;
    return new_element;
}

// Print the circuit
void print_circuit(struct circuit_element *head) {
    printf("Circuit:\n");
    while (head!= NULL) {
        printf("%c = %lf\n", head->type, head->value);
        head = head->next;
    }
}

// Evaluate the circuit
double evaluate_circuit(struct circuit_element *head) {
    double result = 0;
    struct circuit_element *current_element = head;
    while (current_element!= NULL) {
        switch (current_element->type) {
            case 'R':
                result += current_element->value;
                break;
            case 'C':
                result += 1 / (current_element->value * PI);
                break;
            case 'L':
                result += current_element->value * PI;
                break;
            default:
                printf("Invalid element type: %c\n", current_element->type);
                exit(1);
        }
        current_element = current_element->next;
    }
    return result;
}

int main() {
    struct circuit_element *head = NULL;

    // Create a resistor
    head = create_element('R', 100);

    // Create a capacitor
    head->next = create_element('C', 0.001);

    // Create an inductor
    head->next->next = create_element('L', 0.01);

    // Print the circuit
    print_circuit(head);

    // Evaluate the circuit
    double result = evaluate_circuit(head);
    printf("Result: %lf\n", result);

    return 0;
}