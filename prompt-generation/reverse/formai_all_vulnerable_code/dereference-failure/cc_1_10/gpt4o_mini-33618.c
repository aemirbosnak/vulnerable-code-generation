//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

typedef struct Resistor {
    float resistance; // in Ohms
    struct Resistor* next;
} Resistor;

typedef struct Capacitor {
    float capacitance; // in Farads
    struct Capacitor* next;
} Capacitor;

typedef struct VoltageSource {
    float voltage; // in Volts
    struct VoltageSource* next;
} VoltageSource;

typedef struct Circuit {
    Resistor* resistors;
    Capacitor* capacitors;
    VoltageSource* voltageSources;
} Circuit;

void addResistor(Circuit* circuit, float resistance) {
    Resistor* newResistor = (Resistor*)malloc(sizeof(Resistor));
    newResistor->resistance = resistance;
    newResistor->next = circuit->resistors;
    circuit->resistors = newResistor;
}

void addCapacitor(Circuit* circuit, float capacitance) {
    Capacitor* newCapacitor = (Capacitor*)malloc(sizeof(Capacitor));
    newCapacitor->capacitance = capacitance;
    newCapacitor->next = circuit->capacitors;
    circuit->capacitors = newCapacitor;
}

void addVoltageSource(Circuit* circuit, float voltage) {
    VoltageSource* newVoltageSource = (VoltageSource*)malloc(sizeof(VoltageSource));
    newVoltageSource->voltage = voltage;
    newVoltageSource->next = circuit->voltageSources;
    circuit->voltageSources = newVoltageSource;
}

float calculateTotalResistance(Circuit* circuit) {
    float totalResistance = 0.0;
    Resistor* current = circuit->resistors;
    while (current != NULL) {
        totalResistance += current->resistance; // Series resistors
        current = current->next;
    }
    return totalResistance;
}

float calculateTotalVoltage(Circuit* circuit) {
    float totalVoltage = 0.0;
    VoltageSource* current = circuit->voltageSources;
    while (current != NULL) {
        totalVoltage += current->voltage; // Assuming ideal voltage sources
        current = current->next;
    }
    return totalVoltage;
}

void freeMemory(Circuit* circuit) {
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

    VoltageSource* v_current = circuit->voltageSources;
    while (v_current != NULL) {
        VoltageSource* temp = v_current;
        v_current = v_current->next;
        free(temp);
    }
}

int main() {
    Circuit circuit = {NULL, NULL, NULL};
    int choice;
    float value;

    printf("Welcome to the Circuit Simulator!\n");
    do {
        printf("\n1. Add Resistor\n");
        printf("2. Add Capacitor\n");
        printf("3. Add Voltage Source\n");
        printf("4. Calculate Total Resistance\n");
        printf("5. Calculate Total Voltage\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter resistance (Ohms): ");
                scanf("%f", &value);
                addResistor(&circuit, value);
                break;
            case 2:
                printf("Enter capacitance (Farads): ");
                scanf("%f", &value);
                addCapacitor(&circuit, value);
                break;
            case 3:
                printf("Enter voltage (Volts): ");
                scanf("%f", &value);
                addVoltageSource(&circuit, value);
                break;
            case 4:
                printf("Total Resistance: %.2f Ohms\n", calculateTotalResistance(&circuit));
                break;
            case 5:
                printf("Total Voltage: %.2f Volts\n", calculateTotalVoltage(&circuit));
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option, try again.\n");
        }
    } while (choice != 6);

    freeMemory(&circuit);
    return 0;
}