//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COMPONENTS 100
#define MAX_CONNECTIONS 100

typedef struct {
    char name[20];
    double value; // In ohms for resistors, farads for capacitors, henrys for inductors
} Component;

typedef struct {
    int from; // Index of component from
    int to;   // Index of component to
} Connection;

typedef struct {
    Component components[MAX_COMPONENTS];
    int componentCount;
    Connection connections[MAX_CONNECTIONS];
    int connectionCount;
} Circuit;

void addComponent(Circuit *circuit, const char *name, double value) {
    if (circuit->componentCount < MAX_COMPONENTS) {
        Component newComponent;
        snprintf(newComponent.name, sizeof(newComponent.name), "%s", name);
        newComponent.value = value;

        circuit->components[circuit->componentCount] = newComponent;
        circuit->componentCount++;
    } else {
        printf("Max component limit reached\n");
    }
}

void addConnection(Circuit *circuit, int from, int to) {
    if (circuit->connectionCount < MAX_CONNECTIONS) {
        if (from >= circuit->componentCount || to >= circuit->componentCount) {
            printf("Invalid component index\n");
            return;
        }
        
        circuit->connections[circuit->connectionCount].from = from;
        circuit->connections[circuit->connectionCount].to = to;
        circuit->connectionCount++;
    } else {
        printf("Max connection limit reached\n");
    }
}

void printCircuit(const Circuit *circuit) {
    printf("\nCircuit Components:\n");
    for (int i = 0; i < circuit->componentCount; i++) {
        printf("%d: %s (Value: %f)\n", i, circuit->components[i].name, circuit->components[i].value);
    }
    printf("\nConnections:\n");
    for (int i = 0; i < circuit->connectionCount; i++) {
        printf("Connection from %s to %s\n",
               circuit->components[circuit->connections[i].from].name,
               circuit->components[circuit->connections[i].to].name);
    }
}

double calculateTotalResistance(Circuit *circuit) {
    double totalResistance = 0.0;
    for (int i = 0; i < circuit->connectionCount; i++) {
        int from = circuit->connections[i].from;
        int to = circuit->connections[i].to;
        // Only add values of resistors
        if (strcmp(circuit->components[from].name, "Resistor") == 0) {
            totalResistance += circuit->components[from].value;
        }
        if (strcmp(circuit->components[to].name, "Resistor") == 0) {
            totalResistance += circuit->components[to].value;
        }
    }
    return totalResistance;
}

int main() {
    Circuit circuit = {.componentCount = 0, .connectionCount = 0};

    addComponent(&circuit, "Resistor1", 100.0);
    addComponent(&circuit, "Resistor2", 150.0);
    addComponent(&circuit, "Capacitor1", 0.001);
    addComponent(&circuit, "Inductor1", 0.01);
    
    addConnection(&circuit, 0, 1); // Resistor1 to Resistor2
    addConnection(&circuit, 1, 2); // Resistor2 to Capacitor1
    addConnection(&circuit, 2, 3); // Capacitor1 to Inductor1

    printCircuit(&circuit);
    
    double totalResistance = calculateTotalResistance(&circuit);
    printf("\nTotal Resistance in the Circuit: %f Ohms\n", totalResistance);

    return 0;
}