//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

typedef struct Resistor {
    float resistance; // in ohms
    struct Resistor* next;
} Resistor;

typedef struct Capacitor {
    float capacitance; // in farads
    struct Capacitor* next;
} Capacitor;

float calculate_total_resistance(Resistor* head) {
    float total_resistance = 0.0;
    Resistor* current = head;
    while (current != NULL) {
        total_resistance += current->resistance; // Series circuit
        current = current->next;
    }
    return total_resistance;
}

float calculate_total_capacitance(Capacitor* head) {
    float total_capacitance = 0.0;
    Capacitor* current = head;
    while (current != NULL) {
        total_capacitance += current->capacitance; // Series circuit
        current = current->next;
    }
    return total_capacitance;
}

void free_resistors(Resistor* head) {
    Resistor* current = head;
    Resistor* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void free_capacitors(Capacitor* head) {
    Capacitor* current = head;
    Capacitor* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    int num_resistors, num_capacitors;
    Resistor* resistor_head = NULL;
    Capacitor* capacitor_head = NULL;

    printf("Welcome to the Simple Circuit Simulator!\n");

    // Input resistors
    printf("How many resistors are in your circuit? ");
    scanf("%d", &num_resistors);
    
    for (int i = 0; i < num_resistors; i++) {
        Resistor* r = (Resistor*)malloc(sizeof(Resistor));
        printf("Enter resistance for resistor %d (in ohms): ", i + 1);
        scanf("%f", &r->resistance);
        r->next = resistor_head;
        resistor_head = r;
    }

    // Input capacitors
    printf("How many capacitors are in your circuit? ");
    scanf("%d", &num_capacitors);

    for (int i = 0; i < num_capacitors; i++) {
        Capacitor* c = (Capacitor*)malloc(sizeof(Capacitor));
        printf("Enter capacitance for capacitor %d (in farads): ", i + 1);
        scanf("%f", &c->capacitance);
        c->next = capacitor_head;
        capacitor_head = c;
    }

    // Calculate total resistance and capacitance
    float total_resistance = calculate_total_resistance(resistor_head);
    float total_capacitance = calculate_total_capacitance(capacitor_head);

    // Output results
    printf("\nTotal Resistance in circuit: %.2f ohms\n", total_resistance);
    printf("Total Capacitance in circuit: %.6f farads\n", total_capacitance);

    // Free memory
    free_resistors(resistor_head);
    free_capacitors(capacitor_head);

    printf("Thank you for using the circuit simulator!\n");
    return 0;
}