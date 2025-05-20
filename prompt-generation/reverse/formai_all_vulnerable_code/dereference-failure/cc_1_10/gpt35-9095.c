//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the circuit component struct
typedef struct component {
    char* name;
    char* type;
    double value;
    struct component* next;
} Component;

// Define the function to add a component to the circuit
void addComponent(Component** head, char* name, char* type, double value) {
    Component* newComponent = (Component*)malloc(sizeof(Component));
    newComponent->name = strdup(name); // Copy the name string
    newComponent->type = strdup(type); // Copy the type string
    newComponent->value = value;
    newComponent->next = *head;
    *head = newComponent;
}

// Define the function to remove a component from the circuit
void removeComponent(Component** head, char* name) {
    Component* current = *head;
    Component* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->name);
            free(current->type);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Define the function to print the current state of the circuit
void printCircuit(Component* head) {
    printf("-----CIRCUIT-----\n");
    Component* current = head;
    while (current != NULL) {
        printf("%s %s %f\n", current->name, current->type, current->value);
        current = current->next;
    }
}

int main() {
    Component* circuit = NULL;

    addComponent(&circuit, "R1", "resistor", 100);
    addComponent(&circuit, "C1", "capacitor", 0.0001);
    addComponent(&circuit, "L1", "inductor", 0.01);

    printCircuit(circuit);

    removeComponent(&circuit, "C1");

    printCircuit(circuit);

    return 0;
}