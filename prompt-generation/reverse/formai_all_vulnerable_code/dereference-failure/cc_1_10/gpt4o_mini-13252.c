//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Resistor {
    double resistance; // Resistance in ohms
} Resistor;

typedef struct Capacitor {
    double capacitance; // Capacitance in farads
} Capacitor;

typedef struct VoltageSource {
    double voltage; // Voltage in volts
} VoltageSource;

typedef struct Circuit {
    Resistor *resistor;
    Capacitor *capacitor;
    VoltageSource *voltageSource;
    double dt; // Time increment for simulation
} Circuit;

double calculateCurrent(Circuit *circuit) {
    if (circuit->resistor && circuit->voltageSource) {
        return circuit->voltageSource->voltage / circuit->resistor->resistance;
    }
    return 0.0;
}

double calculateVoltageAcrossCapacitor(Circuit *circuit, double time) {
    if (circuit->capacitor) {
        double charge = calculateCurrent(circuit) * time;
        return charge / circuit->capacitor->capacitance;
    }
    return 0.0;
}

void simulateCircuit(Circuit *circuit, double totalTime) {
    for (double t = 0; t <= totalTime; t += circuit->dt) {
        double current = calculateCurrent(circuit);
        double voltageAcrossCapacitor = calculateVoltageAcrossCapacitor(circuit, t);
        
        printf("Time: %.2f s, Current: %.2f A, Voltage across Capacitor: %.2f V\n", 
               t, current, voltageAcrossCapacitor);
    }
}

Circuit* createCircuit(double resistance, double capacitance, double voltage, double dt) {
    Circuit *circuit = malloc(sizeof(Circuit));
    circuit->resistor = malloc(sizeof(Resistor));
    circuit->capacitor = malloc(sizeof(Capacitor));
    circuit->voltageSource = malloc(sizeof(VoltageSource));
    
    circuit->resistor->resistance = resistance;
    circuit->capacitor->capacitance = capacitance;
    circuit->voltageSource->voltage = voltage;
    circuit->dt = dt;

    return circuit;
}

void freeCircuit(Circuit *circuit) {
    free(circuit->resistor);
    free(circuit->capacitor);
    free(circuit->voltageSource);
    free(circuit);
}

int main() {
    double resistance = 1000.0; // 1000 ohms
    double capacitance = 0.000001; // 1 microfarad
    double voltage = 5.0; // 5 volts
    double dt = 0.01; // 10 milliseconds
    double totalTime = 1.0; // 1 second of simulation

    Circuit *circuit = createCircuit(resistance, capacitance, voltage, dt);
    
    printf("Simulating circuit with:\n");
    printf("- Resistor: %.2f ohms\n", circuit->resistor->resistance);
    printf("- Capacitor: %.2e farads\n", circuit->capacitor->capacitance);
    printf("- Voltage Source: %.2f volts\n", circuit->voltageSource->voltage);
    
    simulateCircuit(circuit, totalTime);
    
    freeCircuit(circuit);
    
    return 0;
}