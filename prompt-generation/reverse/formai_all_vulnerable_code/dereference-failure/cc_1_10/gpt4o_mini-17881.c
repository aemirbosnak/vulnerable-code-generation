//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct Resistor {
    double resistance;
    struct Resistor *next;
} Resistor;

// Function to create a new resistor
Resistor* create_resistor(double resistance) {
    Resistor *new_resistor = (Resistor*)malloc(sizeof(Resistor));
    new_resistor->resistance = resistance;
    new_resistor->next = NULL;
    return new_resistor;
}

// Function to calculate total resistance in series
double calculate_series(Resistor *resistor) {
    if (resistor == NULL) {
        return 0.0; // Base case: no resistors
    } else {
        return resistor->resistance + calculate_series(resistor->next); // Recursive call
    }
}

// Function to calculate total resistance in parallel
double calculate_parallel(Resistor *resistor) {
    if (resistor == NULL) {
        return 0.0; // Base case: no resistors
    } else {
        double r = resistor->resistance;
        return 1.0 / (1.0 / r + 1.0 / calculate_parallel(resistor->next)); // Recursive call
    }
}

// Function to free the resistor list
void free_resistors(Resistor *resistor) {
    if (resistor == NULL) return; // Base case
    free_resistors(resistor->next); // Recursive call to the next resistor
    free(resistor); // Free current resistor
}

// Function to simulate a circuit
void simulate_circuit() {
    Resistor *head = NULL;
    Resistor *last = NULL;
    char choice;
    double resistance;
    
    // Building the circuit
    do {
        printf("Enter resistance value (ohms): ");
        scanf("%lf", &resistance);
        
        Resistor *new_resistor = create_resistor(resistance);
        if (head == NULL) {
            head = new_resistor; // First resistor
            last = new_resistor;
        } else {
            last->next = new_resistor; // Link last resistor to new one
            last = new_resistor;
        }
        
        printf("Add another resistor? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y');

    // Series Resistance Calculation
    double total_series = calculate_series(head);
    printf("Total Resistance in Series: %.2f ohms\n", total_series);

    // Parallel Resistance Calculation
    double total_parallel = calculate_parallel(head);
    printf("Total Resistance in Parallel: %.2f ohms\n", total_parallel);

    // Free allocated memory
    free_resistors(head);
}

int main() {
    printf("Welcome to the Classical Circuit Simulator!\n");
    simulate_circuit();
    return 0;
}