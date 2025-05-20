//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_COMPONENTS 100

typedef enum {
    RESISTOR,
    CAPACITOR,
    INDUCTOR,
    VOLTAGE_SOURCE,
    CURRENT_SOURCE
} ComponentType;

typedef struct {
    ComponentType type;
    char name[20];
    double value; // ohms for resistor, farads for capacitor, henrys for inductor, volts for voltage source, amps for current source
} Component;

typedef struct {
    Component* components[MAX_COMPONENTS];
    int count;
} Circuit;

Circuit* createCircuit() {
    Circuit* circuit = (Circuit*)malloc(sizeof(Circuit));
    circuit->count = 0;
    return circuit;
}

void addComponent(Circuit* circuit, ComponentType type, const char* name, double value) {
    if (circuit->count >= MAX_COMPONENTS) {
        printf("Cannot add more components, maximum limit reached.\n");
        return;
    }
    Component* component = (Component*)malloc(sizeof(Component));
    component->type = type;
    strcpy(component->name, name);
    component->value = value;

    circuit->components[circuit->count] = component;
    circuit->count++;
}

void displayCircuit(Circuit* circuit) {
    printf("Circuit Components:\n");
    for (int i = 0; i < circuit->count; i++) {
        Component* component = circuit->components[i];
        char* typeStr;
        switch (component->type) {
            case RESISTOR: typeStr = "Resistor"; break;
            case CAPACITOR: typeStr = "Capacitor"; break;
            case INDUCTOR: typeStr = "Inductor"; break;
            case VOLTAGE_SOURCE: typeStr = "Voltage Source"; break;
            case CURRENT_SOURCE: typeStr = "Current Source"; break;
            default: typeStr = "Unknown"; break;
        }
        printf("%s: %s, Value: %.2f\n", typeStr, component->name, component->value);
    }
}

void simulateCircuit(Circuit* circuit) {
    double totalResistance = 0.0;
    double totalCapacitance = 0.0;
    double totalInductance = 0.0;
    double totalVoltage = 0.0;
    double totalCurrent = 0.0;

    for (int i = 0; i < circuit->count; i++) {
        Component* component = circuit->components[i];
        switch (component->type) {
            case RESISTOR:
                totalResistance += component->value;
                break;
            case CAPACITOR:
                totalCapacitance += component->value;
                break;
            case INDUCTOR:
                totalInductance += component->value;
                break;
            case VOLTAGE_SOURCE:
                totalVoltage += component->value;
                break;
            case CURRENT_SOURCE:
                totalCurrent += component->value;
                break;
            default:
                break;
        }
    }

    printf("Simulation Results:\n");
    printf("Total Resistance: %.2f Ohms\n", totalResistance);
    printf("Total Capacitance: %.2f Farads\n", totalCapacitance);
    printf("Total Inductance: %.2f Henries\n", totalInductance);
    printf("Total Voltage: %.2f Volts\n", totalVoltage);
    printf("Total Current: %.2f Amps\n", totalCurrent);
}

void freeCircuit(Circuit* circuit) {
    for (int i = 0; i < circuit->count; i++) {
        free(circuit->components[i]);
    }
    free(circuit);
}

int main() {
    Circuit* myCircuit = createCircuit();

    addComponent(myCircuit, RESISTOR, "R1", 100);
    addComponent(myCircuit, CAPACITOR, "C1", 0.001);
    addComponent(myCircuit, INDUCTOR, "L1", 0.1);
    addComponent(myCircuit, VOLTAGE_SOURCE, "V1", 12);
    addComponent(myCircuit, CURRENT_SOURCE, "I1", 0.5);

    displayCircuit(myCircuit);
    simulateCircuit(myCircuit);
    freeCircuit(myCircuit);

    return 0;
}