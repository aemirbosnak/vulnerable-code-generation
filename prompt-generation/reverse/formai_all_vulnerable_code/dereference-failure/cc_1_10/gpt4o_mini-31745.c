//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the circuit component types
typedef enum {
    RESISTOR,
    CAPACITOR,
    INDUCTOR,
    VOID
} ComponentType;

// Structure for a circuit component
typedef struct {
    ComponentType type;
    double value; // Value in Ohms for resistor, Farads for capacitor, Henries for inductor
    char name[20]; // Name of the component
} Component;

// Structure for a circuit
typedef struct {
    Component* components;
    int num_components;
} Circuit;

// Function to create a new circuit
Circuit* create_circuit(int capacity) {
    Circuit* circuit = (Circuit*)malloc(sizeof(Circuit));
    circuit->components = (Component*)malloc(sizeof(Component) * capacity);
    circuit->num_components = 0;
    return circuit;
}

// Function to add a component to the circuit
void add_component(Circuit* circuit, ComponentType type, double value, const char* name) {
    Component* cmp = &circuit->components[circuit->num_components++];
    cmp->type = type;
    cmp->value = value;
    strncpy(cmp->name, name, sizeof(cmp->name) - 1);
    cmp->name[sizeof(cmp->name) - 1] = '\0'; // Ensure null-termination
}

// Function to calculate total resistance for resistors in series
double calculate_total_resistance(Circuit* circuit) {
    double total = 0.0;
    for (int i = 0; i < circuit->num_components; i++) {
        if (circuit->components[i].type == RESISTOR) {
            total += circuit->components[i].value;
        }
    }
    return total;
}

// Function to display the circuit components
void display_circuit(Circuit* circuit) {
    printf("Circuit Components:\n");
    for (int i = 0; i < circuit->num_components; i++) {
        printf("Component %d: %s, Type: ", i + 1, circuit->components[i].name);
        switch (circuit->components[i].type) {
            case RESISTOR: 
                printf("Resistor, Value: %.2f Ohms\n", circuit->components[i].value);
                break;
            case CAPACITOR:
                printf("Capacitor, Value: %.2f Farads\n", circuit->components[i].value);
                break;
            case INDUCTOR:
                printf("Inductor, Value: %.2f Henries\n", circuit->components[i].value);
                break;
            default:
                printf("Unknown Type\n");
                break;
        }
    }
}

// Function to free the circuit resources
void free_circuit(Circuit* circuit) {
    free(circuit->components);
    free(circuit);
}

// Main function to run the simulator
int main() {
    int capacity = 10;
    Circuit* circuit = create_circuit(capacity);
    
    add_component(circuit, RESISTOR, 100.5, "R1");
    add_component(circuit, RESISTOR, 150.0, "R2");
    add_component(circuit, CAPACITOR, 0.01, "C1");
    add_component(circuit, INDUCTOR, 0.5, "L1");
    add_component(circuit, RESISTOR, 200.0, "R3");

    display_circuit(circuit);

    double total_resistance = calculate_total_resistance(circuit);
    printf("Total Resistance in Series: %.2f Ohms\n", total_resistance);

    free_circuit(circuit);
    return 0;
}