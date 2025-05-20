//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

typedef struct Resistor {
    double resistance; // resistance value in ohms
    struct Resistor *next; // pointer to the next resistor
} Resistor;

typedef struct Circuit {
    Resistor *head; // head of the linked list of resistors
} Circuit;

// Function to create a new resistor
Resistor* create_resistor(double resistance) {
    Resistor *new_resistor = (Resistor *)malloc(sizeof(Resistor));
    new_resistor->resistance = resistance;
    new_resistor->next = NULL;
    return new_resistor;
}

// Function to initialize a circuit
Circuit* initialize_circuit() {
    Circuit *circuit = (Circuit *)malloc(sizeof(Circuit));
    circuit->head = NULL;
    return circuit;
}

// Function to add a resistor to the circuit
void add_resistor(Circuit *circuit, double resistance) {
    Resistor *new_resistor = create_resistor(resistance);
    new_resistor->next = circuit->head;
    circuit->head = new_resistor;
}

// Function to calculate equivalent resistance in series
double calculate_series_resistance(Circuit *circuit) {
    double total_resistance = 0.0;
    Resistor *current = circuit->head;

    while (current != NULL) {
        total_resistance += current->resistance;
        current = current->next;
    }
    
    return total_resistance;
}

// Function to calculate equivalent resistance in parallel
double calculate_parallel_resistance(Circuit *circuit) {
    double total_reciprocal = 0.0;
    Resistor *current = circuit->head;

    while (current != NULL) {
        total_reciprocal += 1.0 / current->resistance;
        current = current->next;
    }

    if (total_reciprocal != 0) {
        return 1.0 / total_reciprocal;
    } else {
        return 0; // If all resistors are infinite, return 0 for resistance 
    }
}

// Function to free the allocated memory for the circuit
void free_circuit(Circuit *circuit) {
    Resistor *current = circuit->head;
    Resistor *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(circuit);
}

// Main function
int main() {
    Circuit *circuit = initialize_circuit();
    int choice;
    double resistance;
    int stop = 0;

    printf("Simple Circuit Simulator\n");
    printf("-------------------------\n");

    while (!stop) {
        printf("\nMenu:\n");
        printf("1. Add Resistor\n");
        printf("2. Calculate Series Resistance\n");
        printf("3. Calculate Parallel Resistance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter resistance in ohms: ");
                scanf("%lf", &resistance);
                add_resistor(circuit, resistance);
                printf("Resistor of %.2f ohms added.\n", resistance);
                break;

            case 2:
                printf("Total Series Resistance: %.2f ohms\n", calculate_series_resistance(circuit));
                break;

            case 3:
                printf("Total Parallel Resistance: %.2f ohms\n", calculate_parallel_resistance(circuit));
                break;

            case 4:
                stop = 1;
                printf("Exiting the simulator...\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    free_circuit(circuit);
    return 0;
}