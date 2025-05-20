//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define component types
typedef enum {
    RESISTOR,
    CAPACITOR,
    UNKNOWN
} ComponentType;

// Structure to represent a circuit component
typedef struct Component {
    ComponentType type;
    float value;
    struct Component *next;
} Component;

// Function to create a component
Component* createComponent(ComponentType type, float value) {
    Component* newComponent = (Component*)malloc(sizeof(Component));
    newComponent->type = type;
    newComponent->value = value;
    newComponent->next = NULL;
    return newComponent;
}

// Function to calculate total resistance in series
float totalResistance(Component *head) {
    float total = 0.0;
    while (head != NULL) {
        if (head->type == RESISTOR) {
            total += head->value;
        }
        head = head->next;
    }
    return total;
}

// Function to calculate total capacitance in parallel
float totalCapacitance(Component *head) {
    float total = 0.0;
    while (head != NULL) {
        if (head->type == CAPACITOR) {
            total += head->value;
        }
        head = head->next;
    }
    return total;
}

// Function to display current circuit components
void displayCircuit(Component *head) {
    printf("Current Circuit Components:\n");
    while (head != NULL) {
        const char *typeStr = (head->type == RESISTOR) ? "Resistor" : "Capacitor";
        printf("%s: %.2f\n", typeStr, head->value);
        head = head->next;
    }
}

int main() {
    Component *circuit = NULL;
    Component *tail = NULL;
    char command[20];
    float value;
    int componentType;

    printf("Welcome to the Brave Circuit Simulator!\n");
    printf("Enter components to add (0: Resistor; 1: Capacitor; -1: Stop):\n");

    while (1) {
        printf("Enter component type (0/1/-1): ");
        scanf("%d", &componentType);
        if (componentType == -1) {
            break;
        }

        printf("Enter component value: ");
        scanf("%f", &value);

        if (componentType == 0) {
            Component* newComponent = createComponent(RESISTOR, value);
            if (circuit == NULL) {
                circuit = newComponent;
                tail = newComponent;
            } else {
                tail->next = newComponent;
                tail = newComponent;
            }
        } else if (componentType == 1) {
            Component* newComponent = createComponent(CAPACITOR, value);
            if (circuit == NULL) {
                circuit = newComponent;
                tail = newComponent;
            } else {
                tail->next = newComponent;
                tail = newComponent;
            }
        } else {
            printf("Unknown component type. Please use 0 for Resistor or 1 for Capacitor.\n");
        }
    }

    displayCircuit(circuit);
    float totalR = totalResistance(circuit);
    printf("Total Resistance in Series: %.2f Ohms\n", totalR);
    float totalC = totalCapacitance(circuit);
    printf("Total Capacitance in Parallel: %.2f Farads\n", totalC);

    // Free allocated memory
    Component* current = circuit;
    while (current != NULL) {
        Component* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}