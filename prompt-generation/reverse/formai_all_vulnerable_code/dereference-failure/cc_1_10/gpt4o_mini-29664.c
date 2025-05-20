//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a resistor
typedef struct Resistor {
    double resistance; // Resistance value
    struct Resistor *next; // Pointer to the next resistor in the circuit
} Resistor;

// Function to create a new resistor
Resistor* create_resistor(double resistance) {
    Resistor* new_resistor = (Resistor*)malloc(sizeof(Resistor));
    new_resistor->resistance = resistance;
    new_resistor->next = NULL;
    return new_resistor;
}

// Function to calculate equivalent resistance in series
double equivalent_resistance_series(Resistor* head) {
    double total_resistance = 0.0;
    Resistor* current = head;
    
    while (current != NULL) {
        total_resistance += current->resistance;
        current = current->next;
    }
    return total_resistance;
}

// Function to calculate equivalent resistance in parallel
double equivalent_resistance_parallel(Resistor* head) {
    double total_resistance = 0.0;
    Resistor* current = head;
    
    while (current != NULL) {
        if (current->resistance != 0) {
            total_resistance += 1 / current->resistance; // Add inverse of resistance
        }
        current = current->next;
    }
    if (total_resistance == 0) return 0; // Prevent division by zero
    return 1 / total_resistance; // Return the inverse of the sum
}

// Function to free the list of resistors
void free_resistors(Resistor* head) {
    Resistor* current = head;
    Resistor* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    // Create a linked list of resistors for a series circuit
    Resistor* head = create_resistor(10.0); // 10 Ohms
    head->next = create_resistor(15.0); // 15 Ohms
    head->next->next = create_resistor(5.0); // 5 Ohms

    // Calculate the equivalent resistance in series
    double series_resistance = equivalent_resistance_series(head);
    printf("Equivalent Resistance in Series: %.2f Ohms\n", series_resistance);

    // Free the series resistors list
    free_resistors(head);

    // Create a new linked list of resistors for a parallel circuit
    head = create_resistor(10.0); // 10 Ohms
    head->next = create_resistor(15.0); // 15 Ohms
    head->next->next = create_resistor(5.0); // 5 Ohms

    // Calculate the equivalent resistance in parallel
    double parallel_resistance = equivalent_resistance_parallel(head);
    printf("Equivalent Resistance in Parallel: %.2f Ohms\n", parallel_resistance);

    // Free the parallel resistors list
    free_resistors(head);

    return 0;
}