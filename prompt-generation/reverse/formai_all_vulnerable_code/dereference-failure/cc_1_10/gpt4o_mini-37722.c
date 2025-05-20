//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_ELEMENTS 10

typedef struct Element {
    char *name;
    double value;
    struct Element *next;
} Element;

typedef struct Circuit {
    Element *head;
} Circuit;

Element* createElement(char *name, double value) {
    Element *newElement = (Element *)malloc(sizeof(Element));
    newElement->name = name;
    newElement->value = value;
    newElement->next = NULL;
    return newElement;
}

void addElement(Circuit *circuit, char *name, double value) {
    Element *newElement = createElement(name, value);
    if (circuit->head == NULL) {
        circuit->head = newElement;
    } else {
        Element *temp = circuit->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newElement;
    }
}

void displayCircuit(Circuit *circuit) {
    Element *temp = circuit->head;
    printf("Circuit of Dreams:\n");
    while (temp != NULL) {
        printf("Component: %s, Value: %.2f\n", temp->name, temp->value);
        temp = temp->next;
    }
}

double calculateTotalResistance(Circuit *circuit) {
    double totalResistance = 0;
    Element *temp = circuit->head;
    while (temp != NULL) {
        totalResistance += (1 / temp->value);
        temp = temp->next;
    }
    return (totalResistance > 0) ? (1 / totalResistance) : INFINITY;
}

void destroyCircuit(Circuit *circuit) {
    Element *temp;
    while (circuit->head != NULL) {
        temp = circuit->head;
        circuit->head = circuit->head->next;
        free(temp);
    }
}

void surrealCircuit(Circuit *circuit) {
    srand(time(NULL));
    double resistors[NUM_ELEMENTS] = {1.0, 2.0, 3.0, 5.0, 8.0, 13.0, 21.0, 34.0, 55.0, 89.0};
    char *names[NUM_ELEMENTS] = {
        "Whispering Resistor",
        "Dancing Capacitor",
        "Laughing Diode",
        "Singing Inductor",
        "Melancholic Op-Amp",
        "Ethereal Ground",
        "Twinkling Source",
        "Sleepwalking Battery",
        "Fleeting Transistor",
        "Newt's Twilight"
    };

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        double randomValue = resistors[rand() % NUM_ELEMENTS];
        addElement(circuit, names[i], randomValue);
    }
}

int main() {
    Circuit *dreamCircuit = (Circuit *)malloc(sizeof(Circuit));
    dreamCircuit->head = NULL;

    surrealCircuit(dreamCircuit);
    displayCircuit(dreamCircuit);

    double totalRes = calculateTotalResistance(dreamCircuit);
    if (totalRes == INFINITY) {
        printf("The circuit has become an enigma, resistance is infinite.\n");
    } else {
        printf("The total resistance of this dreamscape is: %.2f\n", totalRes);
    }

    destroyCircuit(dreamCircuit);
    free(dreamCircuit);
    return 0;
}