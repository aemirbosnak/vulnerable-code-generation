//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COMPONENTS 100
#define MAX_NODES 10
#define MAX_ITERATIONS 100

typedef enum { RESISTOR, CAPACITOR, VOLTAGE_SOURCE } ComponentType;

typedef struct {
    ComponentType type;
    int node1;
    int node2;
    double value; // resistance in Ohms, capacitance in Farads, or voltage in Volts
} Component;

typedef struct {
    Component components[MAX_COMPONENTS];
    int componentCount;
    double nodeVoltages[MAX_NODES];
    int nodeCount;
} Circuit;

void initCircuit(Circuit* circuit) {
    circuit->componentCount = 0;
    circuit->nodeCount = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        circuit->nodeVoltages[i] = 0.0;
    }
}

void addResistor(Circuit* circuit, int node1, int node2, double resistance) {
    if (circuit->componentCount < MAX_COMPONENTS) {
        circuit->components[circuit->componentCount++] = (Component){ RESISTOR, node1, node2, resistance };
    }
}

void addCapacitor(Circuit* circuit, int node1, int node2, double capacitance) {
    if (circuit->componentCount < MAX_COMPONENTS) {
        circuit->components[circuit->componentCount++] = (Component){ CAPACITOR, node1, node2, capacitance };
    }
}

void addVoltageSource(Circuit* circuit, int node1, int node2, double voltage) {
    if (circuit->componentCount < MAX_COMPONENTS) {
        circuit->components[circuit->componentCount++] = (Component){ VOLTAGE_SOURCE, node1, node2, voltage };
    }
}

void printCircuit(const Circuit* circuit) {
    printf("Circuit Components:\n");
    for (int i = 0; i < circuit->componentCount; i++) {
        char* typeStr = circuit->components[i].type == RESISTOR ? "Resistor" : 
                        circuit->components[i].type == CAPACITOR ? "Capacitor" : "Voltage Source";
        printf("Type: %s, Node1: %d, Node2: %d, Value: %f\n",
               typeStr, circuit->components[i].node1, circuit->components[i].node2, circuit->components[i].value);
    }
}

double calculateNodalVoltage(Circuit* circuit) {
    double matrix[MAX_NODES][MAX_NODES] = { 0.0 };
    double b[MAX_NODES] = { 0.0 };

    for (int i = 0; i < circuit->componentCount; i++) {
        Component c = circuit->components[i];
        if (c.type == RESISTOR) {
            matrix[c.node1][c.node1] += 1.0 / c.value;
            matrix[c.node2][c.node2] += 1.0 / c.value;
            matrix[c.node1][c.node2] -= 1.0 / c.value;
            matrix[c.node2][c.node1] -= 1.0 / c.value;
        } else if (c.type == VOLTAGE_SOURCE) {
            b[c.node1] -= c.value; // Assume passive sign convention
        }
    }
    
    // Solve matrix using Gaussian elimination (simple method for small circuits)
    for (int k = 0; k < circuit->nodeCount; k++) {
        for (int i = k + 1; i < circuit->nodeCount; i++) {
            if (matrix[i][k] != 0) {
                double factor = matrix[k][k] / matrix[i][k];
                for (int j = k; j < circuit->nodeCount; j++) {
                    matrix[i][j] -= matrix[k][j] * factor;
                }
                b[i] -= b[k] * factor;
            }
        }
    }
    
    for (int i = circuit->nodeCount - 1; i >= 0; i--) {
        double sum = b[i];
        for (int j = i + 1; j < circuit->nodeCount; j++) {
            sum -= matrix[i][j] * circuit->nodeVoltages[j];
        }
        circuit->nodeVoltages[i] = sum / matrix[i][i];
    }
    
    return circuit->nodeVoltages[0]; // Returning the voltage at the first node for example
}

int main() {
    Circuit circuit;
    initCircuit(&circuit);
    
    addResistor(&circuit, 0, 1, 1000.0); // 1k Ohm between Node 0 and Node 1
    addVoltageSource(&circuit, 0, 2, 5.0); // 5V between Node 0 and Node 2
    addResistor(&circuit, 1, 2, 2000.0); // 2k Ohm between Node 1 and Node 2
    
    // Assume nodeCount has been adjusted for involved nodes
    circuit.nodeCount = 3; // nodes 0, 1, 2

    printCircuit(&circuit);
    
    double voltage = calculateNodalVoltage(&circuit);
    printf("Calculated Voltage at Node 0: %f V\n", voltage);
    
    return 0;
}