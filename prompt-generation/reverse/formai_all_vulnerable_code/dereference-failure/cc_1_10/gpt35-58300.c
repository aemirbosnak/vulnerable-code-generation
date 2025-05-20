//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 50
#define MAX_COMPONENTS 10

// Define circuit component struct
typedef struct component {
    char name[20];
    char type[5];
    double value;
} Component;

// Define circuit struct
typedef struct circuit {
    Component components[MAX_COMPONENTS];
    int num_components;
} Circuit;

// Function to add a component to a circuit
void addComponent(Circuit *circuit, Component component) {
    if (circuit->num_components < MAX_COMPONENTS) {
        circuit->components[circuit->num_components++] = component;
    } else {
        printf("Circuit is full. Cannot add another component.\n");
    }
}

// Function to print out all components in a circuit
void printComponents(Circuit *circuit) {
    printf("Circuit components:\n");
    for (int i = 0; i < circuit->num_components; i++) {
        printf("%s %s %.2lf\n", circuit->components[i].name, circuit->components[i].type, circuit->components[i].value);
    }
}

int main() {
    Circuit circuit;
    circuit.num_components = 0;

    char input[MAX_INPUT];

    while (1) {
        printf("Enter a component (or 'done' to finish): ");

        // Read in user input
        if (fgets(input, MAX_INPUT, stdin) == NULL) {
            break;
        }

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // Exit loop if user enters 'done'
        if (strcmp(input, "done") == 0) {
            break;
        }

        // Parse component information from input
        Component component;
        char *pch = strtok(input, " ");

        // Set component name
        strcpy(component.name, pch);

        // Set component type
        pch = strtok(NULL, " ");
        strcpy(component.type, pch);

        // Set component value
        pch = strtok(NULL, " ");
        component.value = atof(pch);

        // Add component to circuit
        addComponent(&circuit, component);
    }

    // Print out all components in circuit
    printComponents(&circuit);

    return 0;
}