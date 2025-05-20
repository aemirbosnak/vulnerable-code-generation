//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Constants for the circuit types
#define RESISTOR 1
#define CAPACITOR 2
#define INDUCTOR 3

// Structure to define a circuit element
typedef struct Element {
    int type;
    char name[10];
    double value; // Could be resistance, capacitance, or inductance
    struct Element* next; // Pointer to the next element
} Element;

// Function to create a new element
Element* createElement(int type, const char* name, double value) {
    Element* newElement = (Element*)malloc(sizeof(Element));
    newElement->type = type;
    strncpy(newElement->name, name, sizeof(newElement->name) - 1);
    newElement->value = value;
    newElement->next = NULL;
    return newElement;
}

// Function to add an element to the end of the element list
void addElement(Element** head, Element* newElement) {
    if (*head == NULL) {
        *head = newElement;
    } else {
        Element* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newElement;
    }
}

// Function to print the circuit elements
void printCircuit(Element* head) {
    Element* current = head;
    printf("Circuit Elements:\n");
    while (current != NULL) {
        const char* typeStr;
        if (current->type == RESISTOR)
            typeStr = "Resistor";
        else if (current->type == CAPACITOR)
            typeStr = "Capacitor";
        else if (current->type == INDUCTOR)
            typeStr = "Inductor";
        else
            typeStr = "Unknown";

        printf("Element: %s, Type: %s, Value: %.2f\n", current->name, typeStr, current->value);
        current = current->next;
    }
}

// Calculate the total resistance in series
double calculateTotalResistance(Element* head) {
    double total = 0.0;
    Element* current = head;
    while (current != NULL) {
        if (current->type == RESISTOR) {
            total += current->value;
        }
        current = current->next;
    }
    return total;
}

// Function to calculate the total capacitance in series
double calculateTotalCapacitance(Element* head) {
    double total = 0.0;
    Element* current = head;
    while (current != NULL) {
        if (current->type == CAPACITOR) {
            total += 1.0 / current->value;
        }
        current = current->next;
    }
    return (total > 0) ? (1.0 / total) : 0; // If no capacitors, return 0
}

// Function to free the allocated memory for the circuit
void freeCircuit(Element* head) {
    Element* current = head;
    while (current != NULL) {
        Element* temp = current;
        current = current->next;
        free(temp);
    }
}

// Main function to run the circuit simulator
int main() {
    Element* circuit = NULL;

    // Adding some circuit elements
    addElement(&circuit, createElement(RESISTOR, "R1", 100.0));
    addElement(&circuit, createElement(RESISTOR, "R2", 150.0));
    addElement(&circuit, createElement(CAPACITOR, "C1", 0.001));
    addElement(&circuit, createElement(INDUCTOR, "L1", 0.005));

    // Print the current circuit
    printCircuit(circuit);

    // Calculate and print total resistance
    double totalResistance = calculateTotalResistance(circuit);
    printf("Total Resistance in Series: %.2f Ohms\n", totalResistance);

    // Calculate and print total capacitance
    double totalCapacitance = calculateTotalCapacitance(circuit);
    printf("Total Capacitance in Series: %.2f Farads\n", totalCapacitance);

    // Clean up the circuit
    freeCircuit(circuit);
    return 0;
}