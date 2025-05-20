//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>

typedef struct Resistor {
    float resistance; // Resistance in Ohms
    struct Resistor* next; // Pointer to the next resistor
} Resistor;

// Function to create a new resistor
Resistor* create_resistor(float resistance) {
    Resistor* new_resistor = (Resistor*)malloc(sizeof(Resistor));
    new_resistor->resistance = resistance;
    new_resistor->next = NULL;
    return new_resistor;
}

// Function to calculate total resistance in series
float total_resistance_series(Resistor* head) {
    float total = 0.0f;
    Resistor* current = head;
    
    while (current != NULL) {
        total += current->resistance;
        current = current->next;
    }
    return total;
}

// Function to calculate total resistance in parallel
float total_resistance_parallel(Resistor* head) {
    float total = 0.0f;
    Resistor* current = head;
    
    while (current != NULL) {
        total += 1.0f / current->resistance;
        current = current->next;
    }
    return (total > 0) ? (1.0f / total) : 0;
}

// Function to calculate voltage drop across each resistor
void voltage_drop(Resistor* head, float total_voltage) {
    Resistor* current = head;
    float total_resistance = total_resistance_series(head);

    while (current != NULL) {
        float drop = (current->resistance / total_resistance) * total_voltage;
        printf("Voltage drop across resistor (%.2f Ohm): %.2f V\n", current->resistance, drop);
        current = current->next;
    }
}

// Function to free the resistor list
void free_resistors(Resistor* head) {
    Resistor* current = head;
    Resistor* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

// Main function
int main() {
    Resistor* head = NULL;
    Resistor* tail = NULL;
    int choice;
    float resistance, total_voltage;

    while (1) {
        printf("\n--- Circuit Simulator ---\n");
        printf("1. Add Resistor\n");
        printf("2. Calculate Total Resistance (Series)\n");
        printf("3. Calculate Total Resistance (Parallel)\n");
        printf("4. Calculate Voltage Drops\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter resistance value (Ohms): ");
                scanf("%f", &resistance);
                Resistor* new_resistor = create_resistor(resistance);
                if (head == NULL) {
                    head = new_resistor;
                    tail = new_resistor;
                } else {
                    tail->next = new_resistor;
                    tail = new_resistor;
                }
                break;
            case 2:
                printf("Total Resistance (Series): %.2f Ohms\n", total_resistance_series(head));
                break;
            case 3:
                printf("Total Resistance (Parallel): %.2f Ohms\n", total_resistance_parallel(head));
                break;
            case 4:
                printf("Enter total voltage (Volts): ");
                scanf("%f", &total_voltage);
                voltage_drop(head, total_voltage);
                break;
            case 5:
                free_resistors(head);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}