//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>

typedef struct Resistor {
    double resistance; // Resistance in Ohms
    struct Resistor* next;
} Resistor;

typedef struct Capacitor {
    double capacitance; // Capacitance in Farads
    struct Capacitor* next;
} Capacitor;

typedef struct Circuit {
    Resistor* resistors;
    Capacitor* capacitors;
} Circuit;

Circuit* createCircuit() {
    Circuit* circuit = (Circuit*)malloc(sizeof(Circuit));
    circuit->resistors = NULL;
    circuit->capacitors = NULL;
    return circuit;
}

void addResistor(Circuit* circuit, double resistance) {
    Resistor* newResistor = (Resistor*)malloc(sizeof(Resistor));
    newResistor->resistance = resistance;
    newResistor->next = circuit->resistors;
    circuit->resistors = newResistor;
}

void addCapacitor(Circuit* circuit, double capacitance) {
    Capacitor* newCapacitor = (Capacitor*)malloc(sizeof(Capacitor));
    newCapacitor->capacitance = capacitance;
    newCapacitor->next = circuit->capacitors;
    circuit->capacitors = newCapacitor;
}

double calculateTotalResistance(Circuit* circuit) {
    double totalResistance = 0.0;
    Resistor* current = circuit->resistors;
    while (current != NULL) {
        totalResistance += current->resistance;
        current = current->next;
    }
    return totalResistance;
}

double calculateTotalCapacitance(Circuit* circuit) {
    double totalCapacitance = 0.0;
    Capacitor* current = circuit->capacitors;
    while (current != NULL) {
        totalCapacitance += current->capacitance;
        current = current->next;
    }
    return totalCapacitance;
}

void freeCircuit(Circuit* circuit) {
    Resistor* r_current = circuit->resistors;
    while (r_current != NULL) {
        Resistor* temp = r_current;
        r_current = r_current->next;
        free(temp);
    }

    Capacitor* c_current = circuit->capacitors;
    while (c_current != NULL) {
        Capacitor* temp = c_current;
        c_current = c_current->next;
        free(temp);
    }

    free(circuit);
}

int main() {
    Circuit* myCircuit = createCircuit();
    int choice;
    double value;

    printf("Welcome to the Circuit Simulator!\n");
    do {
        printf("1. Add Resistor\n");
        printf("2. Add Capacitor\n");
        printf("3. Calculate Total Resistance\n");
        printf("4. Calculate Total Capacitance\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter resistance (Ohms): ");
                scanf("%lf", &value);
                addResistor(myCircuit, value);
                break;
            case 2:
                printf("Enter capacitance (Farads): ");
                scanf("%lf", &value);
                addCapacitor(myCircuit, value);
                break;
            case 3:
                printf("Total Resistance: %.2f Ohms\n", calculateTotalResistance(myCircuit));
                break;
            case 4:
                printf("Total Capacitance: %.2f Farads\n", calculateTotalCapacitance(myCircuit));
                break;
            case 0:
                printf("Exiting Circuit Simulator. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 0);

    freeCircuit(myCircuit);
    return 0;
}