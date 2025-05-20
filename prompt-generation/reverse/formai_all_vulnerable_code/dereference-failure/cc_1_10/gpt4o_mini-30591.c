//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for Circuit Components
typedef struct Component {
    char name[20];
    char type[20]; // type can be Resistor, Capacitor, Inductor, etc.
    double value;  // value could be resistance in Ohms, capacitance in Farads, etc.
    struct Component* next;
} Component;

// Struct for the Circuit
typedef struct Circuit {
    Component* head;
} Circuit;

// Function to create a new component
Component* createComponent(const char* name, const char* type, double value) {
    Component* newComponent = (Component*)malloc(sizeof(Component));
    if (!newComponent) {
        fprintf(stderr, "Error: Memory allocation failed in createComponent.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newComponent->name, name);
    strcpy(newComponent->type, type);
    newComponent->value = value;
    newComponent->next = NULL;
    return newComponent;
}

// Function to add a component to the circuit
void addComponent(Circuit* circuit, const char* name, const char* type, double value) {
    Component* newComponent = createComponent(name, type, value);
    newComponent->next = circuit->head;
    circuit->head = newComponent;
}

// Function to simulate the circuit
void simulateCircuit(Circuit* circuit) {
    printf("==== Circuit Simulation Results ====\n");
    
    Component* current = circuit->head;
    while (current != NULL) {
        printf("Component Name: %s\n", current->name);
        printf("Type: %s\n", current->type);
        printf("Value: %.2f\n\n", current->value);
        current = current->next;
    }
    
    // Sample Simulation Logic (Placeholder)
    printf("Simulation complete. The wasteland whispers tales of energy flows...\n");
}

// Function to clean up the circuit
void freeCircuit(Circuit* circuit) {
    Component* current = circuit->head;
    while (current != NULL) {
        Component* toDelete = current;
        current = current->next;
        free(toDelete);
    }
    free(circuit);
}

// Function to print the introduction of the simulator
void printIntroduction() {
    printf("=========================================\n");
    printf(" Post-Apocalyptic Circuit Simulator\n");
    printf("=========================================\n");
    printf(" In a world ravaged by chaos, watch as remnants of electrical circuits come to life.\n");
    printf(" Rebuild, simulate, and discover the secrets of electricity!\n");
    printf("=========================================\n");
}

int main() {
    printIntroduction();

    Circuit* myCircuit = (Circuit*)malloc(sizeof(Circuit));
    if (!myCircuit) {
        fprintf(stderr, "Error: Memory allocation failed in main.\n");
        return EXIT_FAILURE;
    }
    myCircuit->head = NULL;

    addComponent(myCircuit, "R1", "Resistor", 1000); // 1k Ohm
    addComponent(myCircuit, "C1", "Capacitor", 0.001); // 1mF
    addComponent(myCircuit, "L1", "Inductor", 0.005); // 5H
    addComponent(myCircuit, "R2", "Resistor", 220); // 220 Ohm

    simulateCircuit(myCircuit);
    freeCircuit(myCircuit);

    printf("All systems shut down. Ashes to ashes...\n");
    return EXIT_SUCCESS;
}