//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: visionary
/*
 * Classical Circuit Simulator
 * Visionary Example Program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element Element;
struct Element {
    char type[10];
    double value;
    char name[20];
    Element* next;
};

typedef struct Circuit Circuit;
struct Circuit {
    Element* head;
};

Circuit* new_circuit() {
    Circuit* circuit = (Circuit*) malloc(sizeof(Circuit));
    circuit->head = NULL;
    return circuit;
}

void add_element(Circuit* circuit, char* type, double value, char* name) {
    Element* element = (Element*) malloc(sizeof(Element));
    strcpy(element->type, type);
    element->value = value;
    strcpy(element->name, name);
    element->next = circuit->head;
    circuit->head = element;
}

void print_circuit(Circuit* circuit) {
    Element* element = circuit->head;
    while (element != NULL) {
        printf("%s %f %s\n", element->type, element->value, element->name);
        element = element->next;
    }
}

int main() {
    Circuit* circuit = new_circuit();

    add_element(circuit, "RESISTOR", 1000, "R1");
    add_element(circuit, "CAPACITOR", 1e-6, "C1");
    add_element(circuit, "RESISTOR", 2000, "R2");

    print_circuit(circuit);

    return 0;
}