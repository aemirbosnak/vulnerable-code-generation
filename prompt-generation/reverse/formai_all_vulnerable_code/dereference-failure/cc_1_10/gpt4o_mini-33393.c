//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Resistor {
    char name[10];
    float resistance;  // Resistance in ohms
    float voltage;     // Voltage across the resistor
    float current;     // Current through the resistor
    struct Resistor* next;
} Resistor;

typedef struct Circuit {
    Resistor* head;
} Circuit;

void add_resistor(Circuit* circuit, const char* name, float resistance) {
    Resistor* new_resistor = (Resistor*)malloc(sizeof(Resistor));
    strncpy(new_resistor->name, name, 10);
    new_resistor->resistance = resistance;
    new_resistor->voltage = 0.0;
    new_resistor->current = 0.0;
    new_resistor->next = circuit->head;
    circuit->head = new_resistor;
}

float calculate_current(Resistor* resistor) {
    return resistor->voltage / resistor->resistance;
}

void calculate_currents(Circuit* circuit) {
    Resistor* curr = circuit->head;
    while (curr != NULL) {
        curr->current = calculate_current(curr);
        curr = curr->next;
    }
}

void display_circuit(Circuit* circuit) {
    Resistor* curr = circuit->head;
    printf("Circuit Components:\n");
    printf("------------------------------------\n");
    while (curr != NULL) {
        printf("Resistor: %s, Resistance: %.2f Ohms, Voltage: %.2f Volts, Current: %.2f Amps\n", 
               curr->name, curr->resistance, curr->voltage, curr->current);
        curr = curr->next;
    }
    printf("------------------------------------\n");
}

void set_voltage(Circuit* circuit, const char* name, float voltage) {
    Resistor* curr = circuit->head;
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            curr->voltage = voltage;
            break;
        }
        curr = curr->next;
    }
}

void free_circuit(Circuit* circuit) {
    Resistor* curr = circuit->head;
    Resistor* temp;
    while (curr != NULL) {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
    circuit->head = NULL;
}

int main() {
    Circuit circuit = {NULL};

    add_resistor(&circuit, "R1", 100.0);
    add_resistor(&circuit, "R2", 200.0);
    add_resistor(&circuit, "R3", 50.0);

    set_voltage(&circuit, "R1", 10.0);
    set_voltage(&circuit, "R2", 20.0);
    set_voltage(&circuit, "R3", 5.0);

    calculate_currents(&circuit);
    display_circuit(&circuit);

    free_circuit(&circuit);
    return 0;
}