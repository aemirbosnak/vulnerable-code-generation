//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_VALUE 1e12

// Structure to store a resistor or a voltage source
typedef struct {
    char type;      // 'R' for resistor, 'V' for voltage source
    int a, b;       // Nodes connected to the component
    double value;   // Resistance or voltage value
} Component;

// Structure to store a node and its connected components
typedef struct {
    int id;         // Node id
    int numComp;    // Number of components connected to the node
    Component* compArray;   // Array of components connected to the node
} Node;

int numNodes;       // Total number of nodes in the circuit
Node nodeList[MAX_NODES];   // Array of nodes in the circuit

/**
 * Function to initialize a component with default values
 */
Component* newComponent(char type, int a, int b, double value) {
    Component* comp = (Component*) malloc(sizeof(Component));
    comp->type = type;
    comp->a = a;
    comp->b = b;
    comp->value = value;
    return comp;
}

/**
 * Function to add a component to a node in the circuit
 */
void addComponentToNode(Node* node, Component* comp) {
    node->compArray = (Component*) realloc(node->compArray, (node->numComp + 1) * sizeof(Component));
    node->compArray[node->numComp] = *comp;
    node->numComp++;
}

/**
 * Function to calculate the conductance of a component
 */
double getConductance(Component* comp, double time) {
    if (comp->type == 'R') {
        return 1 / comp->value;
    } else {
        return comp->value;
    }
}

/**
 * Function to calculate the current flowing through a component
 */
double getCurrent(Component* comp, double time, double* voltages) {
    if (comp->type == 'R') {
        return (voltages[comp->a] - voltages[comp->b]) / comp->value;
    } else {
        return comp->value;
    }
}

/**
 * Function to simulate the circuit for a given time
 */
void simulate(double time, double timestep) {
    int i, j, k;
    double t, dt, err, maxErr, voltages[MAX_NODES], currents[MAX_NODES][MAX_NODES];

    // Initialize node voltages to 0
    for (i = 0; i < numNodes; i++) {
        voltages[i] = 0;
    }

    // Loop through time steps
    for (t = 0; t < time; t += timestep) {
        // Initialize node currents to 0
        for (i = 0; i < numNodes; i++) {
            for (j = 0; j < numNodes; j++) {
                currents[i][j] = 0;
            }
        }

        // Calculate currents flowing through each component
        for (i = 0; i < numNodes; i++) {
            for (j = 0; j < nodeList[i].numComp; j++) {
                Component* comp = &nodeList[i].compArray[j];
                double current = getCurrent(comp, t, voltages);
                currents[comp->a][comp->b] += current;
                currents[comp->b][comp->a] -= current;
            }
        }

        // Calculate conductances of all components
        double conductances[MAX_NODES][MAX_NODES];
        for (i = 0; i < numNodes; i++) {
            for (j = 0; j < numNodes; j++) {
                conductances[i][j] = 0;
            }
        }
        for (i = 0; i < numNodes; i++) {
            for (j = 0; j < nodeList[i].numComp; j++) {
                Component* comp = &nodeList[i].compArray[j];
                double conductance = getConductance(comp, t);
                conductances[comp->a][comp->a] += conductance;
                conductances[comp->b][comp->b] += conductance;
                conductances[comp->a][comp->b] -= conductance;
                conductances[comp->b][comp->a] -= conductance;
            }
        }

        // Apply current and conductance matrices to solve for new node voltages
        maxErr = MAX_VALUE;
        while (maxErr > 1e-6) {
            maxErr = 0;
            for (i = 0; i < numNodes; i++) {
                err = 0;
                double newVoltage = 0;
                for (j = 0; j < numNodes; j++) {
                    if (j != i) {
                        err += conductances[i][j] * voltages[j];
                    }
                    newVoltage += currents[i][j];
                }
                newVoltage /= conductances[i][i];
                err = fabs(newVoltage - voltages[i]);
                if (err > maxErr) {
                    maxErr = err;
                }
                voltages[i] = newVoltage;
            }
        }

        // Print node voltages at current time
        printf("%lf:", t);
        for (i = 0; i < numNodes; i++) {
            printf(" %lf", voltages[i]);
        }
        printf("\n");
    }
}

int main() {
    char line[100], *pch;
    int i, j, a, b;
    double value;
    Component* comp;

    // Read components from input file
    FILE* inFile = fopen("circuit.txt", "r");
    while (fgets(line, 100, inFile)) {
        pch = strtok(line, " ");
        while (pch != NULL) {
            if (pch[0] == 'R' || pch[0] == 'V') {
                a = atoi(strtok(NULL, " "));
                b = atoi(strtok(NULL, " "));
                value = atof(strtok(NULL, " "));
                comp = newComponent(pch[0], a, b, value);
                addComponentToNode(&nodeList[a], comp);
                addComponentToNode(&nodeList[b], comp);
            }
            pch = strtok(NULL, " ");
        }
    }
    fclose(inFile);

    // Set node IDs
    for (i = 0; i < MAX_NODES; i++) {
        if (nodeList[i].numComp > 0) {
            nodeList[i].id = numNodes;
            numNodes++;
        }
    }

    // Simulate the circuit for 10 seconds with a time step of 0.001 seconds
    simulate(10, 0.001);

    return 0;
}