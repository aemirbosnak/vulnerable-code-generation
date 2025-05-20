//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

typedef struct Component {
    char type; // 'R' for Resistor, 'C' for Capacitor, 'V' for Voltage Source
    double value; // Value of the component: Resistance in ohms, Capacitance in Farads, Voltage in Volts
    struct Component* next;
} Component;

Component* head = NULL;

void addComponent(char type, double value) {
    Component* newComponent = (Component*)malloc(sizeof(Component));
    newComponent->type = type;
    newComponent->value = value;
    newComponent->next = head; // Add to the beginning of the list
    head = newComponent;
}

void displayComponents() {
    if (head == NULL) {
        printf("No components in the circuit.\n");
        return;
    }
    Component* current = head;
    printf("Components in the circuit:\n");
    while (current != NULL) {
        if (current->type == 'R') {
            printf("Resistor: %.2f Ohms\n", current->value);
        } else if (current->type == 'C') {
            printf("Capacitor: %.2f Farads\n", current->value);
        } else if (current->type == 'V') {
            printf("Voltage Source: %.2f Volts\n", current->value);
        }
        current = current->next;
    }
}

double calculateTotalResistance() {
    double totalResistance = 0;
    Component* current = head;
    while (current != NULL) {
        if (current->type == 'R') {
            totalResistance += current->value; // Series connection
        }
        current = current->next;
    }
    return totalResistance;
}

double calculateTotalVoltage() {
    double totalVoltage = 0;
    Component* current = head;
    while (current != NULL) {
        if (current->type == 'V') {
            totalVoltage += current->value; // Summing voltage sources
        }
        current = current->next;
    }
    return totalVoltage;
}

void freeComponents() {
    Component* current = head;
    while (current != NULL) {
        Component* nextComponent = current->next;
        free(current);
        current = nextComponent;
    }
    head = NULL;
}

int main() {
    int choice;
    char type;
    double value;

    do {
        printf("\nCircuit Simulator Menu:\n");
        printf("1. Add Resistor\n");
        printf("2. Add Capacitor\n");
        printf("3. Add Voltage Source\n");
        printf("4. Display Components\n");
        printf("5. Calculate Total Resistance\n");
        printf("6. Calculate Total Voltage\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter resistance value in Ohms: ");
                scanf("%lf", &value);
                addComponent('R', value);
                break;
            case 2:
                printf("Enter capacitance value in Farads: ");
                scanf("%lf", &value);
                addComponent('C', value);
                break;
            case 3:
                printf("Enter voltage value in Volts: ");
                scanf("%lf", &value);
                addComponent('V', value);
                break;
            case 4:
                displayComponents();
                break;
            case 5: {
                double totalResistance = calculateTotalResistance();
                printf("Total Resistance in series: %.2f Ohms\n", totalResistance);
                break;
            }
            case 6: {
                double totalVoltage = calculateTotalVoltage();
                printf("Total Voltage from sources: %.2f Volts\n", totalVoltage);
                break;
            }
            case 7:
                printf("Exiting the simulator.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 7);

    freeComponents();
    return 0;
}