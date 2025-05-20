//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

typedef struct Resistor {
    float resistance;
    struct Resistor *next;
} Resistor;

Resistor* createResistor(float resistance) {
    Resistor *newResistor = (Resistor*)malloc(sizeof(Resistor));
    newResistor->resistance = resistance;
    newResistor->next = NULL;
    return newResistor;
}

void freeResistors(Resistor *head) {
    Resistor *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

float totalResistanceSeries(Resistor *head) {
    float total = 0.0;
    while (head != NULL) {
        total += head->resistance;
        head = head->next;
    }
    return total;
}

float totalResistanceParallel(Resistor *head) {
    float total = 0.0;
    while (head != NULL) {
        total += 1.0 / head->resistance;
        head = head->next;
    }
    return total > 0 ? 1.0 / total : 0;
}

void simulateCircuit() {
    int option;
    Resistor *head = NULL, *tail = NULL;
    float voltage, current, resistanceValue;

    while (1) {
        printf("Circuit Simulator Menu:\n");
        printf("1. Add Resistor\n");
        printf("2. Calculate Total Resistance in Series\n");
        printf("3. Calculate Total Resistance in Parallel\n");
        printf("4. Calculate Current (Ohm's Law)\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter resistor value (in Ohms): ");
                scanf("%f", &resistanceValue);
                Resistor *newResistor = createResistor(resistanceValue);
                if (head == NULL) {
                    head = newResistor;
                    tail = newResistor;
                } else {
                    tail->next = newResistor;
                    tail = newResistor;
                }
                printf("Resistor of %.2f Ohms added.\n", resistanceValue);
                break;

            case 2:
                printf("Total Resistance in Series: %.2f Ohms\n", totalResistanceSeries(head));
                break;

            case 3:
                printf("Total Resistance in Parallel: %.2f Ohms\n", totalResistanceParallel(head));
                break;

            case 4:
                printf("Enter Voltage (in Volts): ");
                scanf("%f", &voltage);
                printf("Total Series Resistance: %.2f Ohms\n", totalResistanceSeries(head));
                current = voltage / totalResistanceSeries(head);
                printf("Total Current in Series: %.2f Amperes\n", current);
                break;

            case 5:
                printf("Exiting...\n");
                freeResistors(head);
                return;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to the C Circuit Simulator!\n");
    simulateCircuit();
    return 0;
}