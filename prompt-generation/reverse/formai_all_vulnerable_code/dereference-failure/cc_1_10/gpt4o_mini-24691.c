//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

typedef enum { RESISTOR, CAPACITOR, INDUCTOR } ComponentType;

typedef struct {
    ComponentType type;
    double value; // In ohms for resistors, farads for capacitors, henrys for inductors
} Component;

typedef struct {
    Component **components;
    int componentCount;
} Circuit;

Circuit *createCircuit() {
    Circuit *circuit = (Circuit *)malloc(sizeof(Circuit));
    circuit->components = NULL;
    circuit->componentCount = 0;
    return circuit;
}

void addComponent(Circuit *circuit, ComponentType type, double value) {
    circuit->components = realloc(circuit->components, (circuit->componentCount + 1) * sizeof(Component *));
    Component *component = (Component *)malloc(sizeof(Component));
    component->type = type;
    component->value = value;
    circuit->components[circuit->componentCount] = component;
    circuit->componentCount++;
}

double calculateImpedance(Circuit *circuit, double frequency) {
    double totalImpedance = 0.0;
    double omega = 2 * PI * frequency;
    
    for (int i = 0; i < circuit->componentCount; i++) {
        switch (circuit->components[i]->type) {
            case RESISTOR:
                totalImpedance += circuit->components[i]->value; // Add resistive part
                break;
            case CAPACITOR:
                totalImpedance += 1.0 / (omega * circuit->components[i]->value); // Capacitive part
                break;
            case INDUCTOR:
                totalImpedance += omega * circuit->components[i]->value; // Inductive part
                break;
            default:
                break;
        }
    }

    return totalImpedance;
}

void freeCircuit(Circuit *circuit) {
    for (int i = 0; i < circuit->componentCount; i++) {
        free(circuit->components[i]);
    }
    free(circuit->components);
    free(circuit);
}

void printCircuit(Circuit *circuit) {
    printf("Circuit components:\n");
    for (int i = 0; i < circuit->componentCount; i++) {
        switch (circuit->components[i]->type) {
            case RESISTOR:
                printf("Resistor: %.2f Ohms\n", circuit->components[i]->value);
                break;
            case CAPACITOR:
                printf("Capacitor: %.2f Farads\n", circuit->components[i]->value);
                break;
            case INDUCTOR:
                printf("Inductor: %.2f Henries\n", circuit->components[i]->value);
                break;
            default:
                break;
        }
    }
}

int main() {
    Circuit *myCircuit = createCircuit();
    
    // Adding components peacefully
    addComponent(myCircuit, RESISTOR, 100.0);    // 100 Ohm resistor
    addComponent(myCircuit, CAPACITOR, 0.000001); // 1 μF capacitor
    addComponent(myCircuit, INDUCTOR, 0.01);      // 10 mH inductor
    
    // Print circuit details
    printCircuit(myCircuit);
    
    // Calculate impedance at a specified frequency
    double frequency = 1000.0; // Frequency in Hertz
    double impedance = calculateImpedance(myCircuit, frequency);
    
    printf("Total Impedance at %.2f Hz: %.2f Ohms\n", frequency, impedance);
    
    // Clean up peacefully
    freeCircuit(myCircuit);
    
    return 0;
}