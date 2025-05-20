//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_CIRcuits 10

typedef struct Circuit {
    char name[20];
    double resistance;
    double capacitance;
    double inductance;
    double voltage;
    double current;
    struct Circuit *next;
} Circuit;

Circuit *head = NULL;

void createCircuit(char *name, double resistance, double capacitance, double inductance, double voltage) {
    Circuit *newCircuit = (Circuit *)malloc(sizeof(Circuit));
    strcpy(newCircuit->name, name);
    newCircuit->resistance = resistance;
    newCircuit->capacitance = capacitance;
    newCircuit->inductance = inductance;
    newCircuit->voltage = voltage;
    newCircuit->current = 0;
    newCircuit->next = NULL;

    if (head == NULL) {
        head = newCircuit;
    } else {
        Circuit *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newCircuit;
    }
}

void simulateCircuit(char *name) {
    Circuit *circuit = head;
    while (circuit) {
        if (strcmp(circuit->name, name) == 0) {
            double resistance = circuit->resistance;
            double capacitance = circuit->capacitance;
            double inductance = circuit->inductance;
            double voltage = circuit->voltage;

            double current = voltage / (resistance + 1 / (capacitance * inductance));

            circuit->current = current;

            printf("Circuit Name: %s\n", circuit->name);
            printf("Resistance: %.2f ohms\n", resistance);
            printf("Capacitance: %.2f farads\n", capacitance);
            printf("Inductance: %.2f henrys\n", inductance);
            printf("Voltage: %.2f volts\n", voltage);
            printf("Current: %.2f amperes\n", current);
            break;
        }
        circuit = circuit->next;
    }
}

int main() {
    createCircuit("Series Circuit", 20, 10, 0, 10);
    createCircuit("Parallel Circuit", 10, 20, 0, 10);
    createCircuit("LC Circuit", 0, 10, 1, 10);

    simulateCircuit("Series Circuit");

    return 0;
}