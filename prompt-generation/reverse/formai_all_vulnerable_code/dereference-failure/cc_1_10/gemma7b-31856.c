//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CUSTOMERS 5
#define MAX_BAGS 10
#define MAX_WEIGHT 20

typedef struct Bag {
    char *name;
    int weight;
} Bag;

typedef struct Customer {
    char *name;
    int numBags;
    Bag **bags;
} Customer;

void simulate_airport() {
    // Create a list of customers
    Customer **customers = (Customer *)malloc(MAX_CUSTOMERS * sizeof(Customer));
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        customers[i] = (Customer *)malloc(sizeof(Customer));
        customers[i]->name = (char *)malloc(20 * sizeof(char));
        customers[i]->numBags = rand() % MAX_BAGS;
        customers[i]->bags = (Bag **)malloc(customers[i]->numBags * sizeof(Bag));
        for (int j = 0; j < customers[i]->numBags; j++) {
            customers[i]->bags[j] = (Bag *)malloc(sizeof(Bag));
            customers[i]->bags[j]->name = (char *)malloc(20 * sizeof(char));
            customers[i]->bags[j]->weight = rand() % MAX_WEIGHT;
        }
    }

    // Simulate the baggage handling process
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        printf("%s has %d bags:\n", customers[i]->name);
        for (int j = 0; j < customers[i]->numBags; j++) {
            printf("  Bag name: %s, weight: %d\n", customers[i]->bags[j]->name, customers[i]->bags[j]->weight);
        }
    }

    // Free the memory allocated for the customers and their bags
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        free(customers[i]->name);
        free(customers[i]->bags);
        free(customers[i]);
    }

    free(customers);
}

int main() {
    simulate_airport();

    return 0;
}