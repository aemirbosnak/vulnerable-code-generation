//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

typedef struct Component {
    char type; // 'R' for resistor, 'C' for capacitor
    float value; // ohms for resistor, farads for capacitor
    struct Component* next;
} Component;

typedef struct Circuit {
    Component* head;
} Circuit;

void initializeCircuit(Circuit* circuit) {
    circuit->head = NULL;
}

void addComponent(Circuit* circuit, char type, float value) {
    Component* newComponent = (Component*)malloc(sizeof(Component));
    newComponent->type = type;
    newComponent->value = value;
    newComponent->next = circuit->head;
    circuit->head = newComponent;
}

void displayCircuit(Circuit* circuit) {
    Component* current = circuit->head;
    printf("Current Circuit Components:\n");
    while (current != NULL) {
        if (current->type == 'R') {
            printf("Resistor: %.2f ohms\n", current->value);
        } else if (current->type == 'C') {
            printf("Capacitor: %.2f farads\n", current->value);
        }
        current = current->next;
    }
}

float calculateTotalResistance(Circuit* circuit) {
    float totalResistance = 0.0;
    Component* current = circuit->head;

    while (current != NULL) {
        if (current->type == 'R') {
            totalResistance += current->value;
        }
        current = current->next;
    }
    return totalResistance;
}

float calculateTotalCapacitance(Circuit* circuit) {
    float totalCapacitance = 0.0;
    Component* current = circuit->head;

    while (current != NULL) {
        if (current->type == 'C') {
            totalCapacitance += current->value;
        }
        current = current->next;
    }
    return totalCapacitance;
}

void freeCircuit(Circuit* circuit) {
    Component* current = circuit->head;
    Component* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Circuit circuit;
    initializeCircuit(&circuit);

    char choice;
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add Resistor\n");
        printf("2. Add Capacitor\n");
        printf("3. Display Circuit\n");
        printf("4. Calculate Total Resistance\n");
        printf("5. Calculate Total Capacitance\n");
        printf("6. Exit\n");
        printf("Your choice: ");
        choice = getchar();
        getchar(); // Clear newline character from buffer

        if (choice == '1') {
            float value;
            printf("Enter resistor value (in ohms): ");
            scanf("%f", &value);
            getchar(); // Clear newline character from buffer
            addComponent(&circuit, 'R', value);
        } else if (choice == '2') {
            float value;
            printf("Enter capacitor value (in farads): ");
            scanf("%f", &value);
            getchar(); // Clear newline character from buffer
            addComponent(&circuit, 'C', value);
        } else if (choice == '3') {
            displayCircuit(&circuit);
        } else if (choice == '4') {
            float totalResistance = calculateTotalResistance(&circuit);
            printf("Total Resistance: %.2f ohms\n", totalResistance);
        } else if (choice == '5') {
            float totalCapacitance = calculateTotalCapacitance(&circuit);
            printf("Total Capacitance: %.2f farads\n", totalCapacitance);
        } else if (choice == '6') {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    freeCircuit(&circuit);
    return 0;
}