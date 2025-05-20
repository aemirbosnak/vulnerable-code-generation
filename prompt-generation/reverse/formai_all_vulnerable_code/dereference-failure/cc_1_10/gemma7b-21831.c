//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_CIRcuits 10
#define MAX_COMPONENTS 20

typedef struct Circuit
{
    char name[20];
    int numComponents;
    struct Component** components;
} Circuit;

typedef struct Component
{
    char name[20];
    double resistance;
    double capacitance;
    double inductance;
} Component;

Circuit** circuits = NULL;

void createCircuit(char* name)
{
    Circuit* newCircuit = malloc(sizeof(Circuit));
    strcpy(newCircuit->name, name);
    newCircuit->numComponents = 0;
    newCircuit->components = NULL;

    circuits = realloc(circuits, (MAX_CIRcuits + 1) * sizeof(Circuit));
    circuits[MAX_CIRcuits] = newCircuit;
}

void addComponent(Circuit* circuit, char* name, double resistance, double capacitance, double inductance)
{
    Component* newComponent = malloc(sizeof(Component));
    strcpy(newComponent->name, name);
    newComponent->resistance = resistance;
    newComponent->capacitance = capacitance;
    newComponent->inductance = inductance;

    circuit->components = realloc(circuit->components, (circuit->numComponents + 1) * sizeof(Component));
    circuit->components[circuit->numComponents++] = newComponent;
}

int main()
{
    createCircuit("Circuit 1");
    addComponent(circuits[0], "Resistor 1", 10, 0, 0);
    addComponent(circuits[0], "Capacitor 1", 0, 10, 0);

    createCircuit("Circuit 2");
    addComponent(circuits[1], "Inductor 1", 0, 0, 10);

    for (int i = 0; i < MAX_CIRcuits; i++)
    {
        if (circuits[i] != NULL)
        {
            printf("Circuit: %s\n", circuits[i]->name);
            for (int j = 0; j < circuits[i]->numComponents; j++)
            {
                printf("Component: %s, Resistance: %.2f, Capacitance: %.2f, Inductance: %.2f\n", circuits[i]->components[j]->name, circuits[i]->components[j]->resistance, circuits[i]->components[j]->capacitance, circuits[i]->components[j]->inductance);
            }
        }
    }

    return 0;
}