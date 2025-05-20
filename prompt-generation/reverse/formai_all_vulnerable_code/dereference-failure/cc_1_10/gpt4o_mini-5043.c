//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

typedef struct Component {
    char type; // 'R' for Resistor, 'C' for Capacitor
    float value; // value in Ohms for Resistor or Farads for Capacitor
    struct Component* next;
} Component;

Component* createComponent(char type, float value) {
    Component* newComponent = (Component*)malloc(sizeof(Component));
    newComponent->type = type;
    newComponent->value = value;
    newComponent->next = NULL;
    return newComponent;
}

void addComponent(Component** head, char type, float value) {
    Component* newComponent = createComponent(type, value);
    newComponent->next = *head;
    *head = newComponent;
}

void displayCircuit(Component* head) {
    printf("Circuit Configuration:\n");
    while (head != NULL) {
        if (head->type == 'R') {
            printf("R%.2f ", head->value);
        } else if (head->type == 'C') {
            printf("C%.2f ", head->value);
        }
        head = head->next;
    }
    printf("\n");
}

float calculateTotalResistance(Component* head) {
    float totalResistance = 0.0;
    while (head != NULL) {
        if (head->type == 'R') {
            totalResistance += head->value;
        }
        head = head->next;
    }
    return totalResistance;
}

float calculateTotalCapacitance(Component* head) {
    float totalCapacitance = 0.0;
    while (head != NULL) {
        if (head->type == 'C') {
            totalCapacitance += head->value;
        }
        head = head->next;
    }
    return totalCapacitance;
}

void cleanUp(Component* head) {
    Component* current = head;
    while (current != NULL) {
        Component* toDelete = current;
        current = current->next;
        free(toDelete);
    }
}

void visualizeCircuit(Component* head) {
    printf("\nVisualizing the Circuit:\n");
    while (head != NULL) {
        if (head->type == 'R') {
            printf("[R%.2f]-", head->value);
        } else if (head->type == 'C') {
            printf("[C%.2f]-", head->value);
        }
        head = head->next;
    }
    printf(" END\n");
}

int main() {
    Component* circuit = NULL;
    char choice;
    float value;

    while (1) {
        printf("\nCircuit Simulator Menu:\n");
        printf("1. Add Resistor\n");
        printf("2. Add Capacitor\n");
        printf("3. Display Circuit\n");
        printf("4. Calculate Total Resistance\n");
        printf("5. Calculate Total Capacitance\n");
        printf("6. Visualize Circuit\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter resistance value in Ohms: ");
                scanf("%f", &value);
                addComponent(&circuit, 'R', value);
                break;
            case '2':
                printf("Enter capacitance value in Farads: ");
                scanf("%f", &value);
                addComponent(&circuit, 'C', value);
                break;
            case '3':
                displayCircuit(circuit);
                break;
            case '4':
                printf("Total Resistance: %.2f Ohms\n", calculateTotalResistance(circuit));
                break;
            case '5':
                printf("Total Capacitance: %.2f Farads\n", calculateTotalCapacitance(circuit));
                break;
            case '6':
                visualizeCircuit(circuit);
                break;
            case '0':
                cleanUp(circuit);
                printf("Exiting the simulator. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}