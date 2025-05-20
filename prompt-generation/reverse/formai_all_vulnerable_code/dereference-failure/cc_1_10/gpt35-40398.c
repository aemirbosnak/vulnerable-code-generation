//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// Define a struct for a resistor
typedef struct resistor {
    double resistance;
    struct resistor *next;
} Resistor;

// Define a struct for a capacitor
typedef struct capacitor {
    double capacitance;
    double voltage;
    struct capacitor *next;
} Capacitor;

// Define a function to add a resistor to the circuit
void add_resistor(Resistor **head, double resistance) {
    Resistor *new_resistor = malloc(sizeof(Resistor));
    new_resistor->resistance = resistance;
    new_resistor->next = *head;
    *head = new_resistor;
}

// Define a function to add a capacitor to the circuit
void add_capacitor(Capacitor **head, double capacitance, double voltage) {
    Capacitor *new_capacitor = malloc(sizeof(Capacitor));
    new_capacitor->capacitance = capacitance;
    new_capacitor->voltage = voltage;
    new_capacitor->next = *head;
    *head = new_capacitor;
}

int main() {
    Resistor *resistor_list = NULL;
    Capacitor *capacitor_list = NULL;

    // Add resistors to the circuit
    add_resistor(&resistor_list, 100);
    add_resistor(&resistor_list, 220);
    add_resistor(&resistor_list, 330);
    add_resistor(&resistor_list, 470);

    // Add capacitors to the circuit
    add_capacitor(&capacitor_list, 0.1, 5);
    add_capacitor(&capacitor_list, 0.22, 12);
    add_capacitor(&capacitor_list, 0.33, 8);
    add_capacitor(&capacitor_list, 0.47, 3);

    // Print out the resistors in the circuit
    printf("Resistors in circuit:\n");
    Resistor *resistor_ptr = resistor_list;
    while (resistor_ptr != NULL) {
        printf("%f ohms\n", resistor_ptr->resistance);
        resistor_ptr = resistor_ptr->next;
    }

    // Print out the capacitors in the circuit
    printf("Capacitors in circuit:\n");
    Capacitor *capacitor_ptr = capacitor_list;
    while (capacitor_ptr != NULL) {
        printf("%f Farads, %f Volts\n", capacitor_ptr->capacitance, capacitor_ptr->voltage);
        capacitor_ptr = capacitor_ptr->next;
    }

    return 0;
}