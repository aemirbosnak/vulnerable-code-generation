//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_OF_BAGS 50
#define MAX_BAG_WEIGHT 50

typedef struct {
    int bag_id;
    int dest_gate_num;
    int weight;
    bool is_late;
} Baggage;

typedef struct {
    int gate_num;
    int num_of_bags_received;
    int num_of_late_bags;
    int total_weight_received;
    int total_weight_late_bags;
} Gate;

Baggage* generate_baggage(int id, int max_gate_num) {
    // Randomly generate a new bag
    Baggage* bag = (Baggage*) malloc(sizeof(Baggage));
    bag->bag_id = id;
    bag->dest_gate_num = rand() % max_gate_num + 1;
    bag->weight = rand() % MAX_BAG_WEIGHT + 1;
    bag->is_late = rand() % 2 == 0;

    return bag;
}

void load_gate(Gate* gate, Baggage* baggage) {
    // Load the baggage into the appropriate gate
    gate->num_of_bags_received++;
    gate->total_weight_received += baggage->weight;

    if (baggage->is_late) {
        gate->num_of_late_bags++;
        gate->total_weight_late_bags += baggage->weight;
    }

    printf("Bag %d arrived at Gate %d with weight %d kg%s.\n", 
            baggage->bag_id, baggage->dest_gate_num, baggage->weight, 
            baggage->is_late ? " (late)" : "");
}

void unload_gate(Gate* gate) {
    // Unload all baggage from the gate and reset the gate's information
    printf("\nGate %d is unloading %d bags...\n", gate->gate_num, 
            gate->num_of_bags_received);
    printf("%d on-time bags and %d late bags were unloaded with total weight "
            "%d kg and %d kg respectively.\n\n", 
            gate->num_of_bags_received - gate->num_of_late_bags, 
            gate->num_of_late_bags, gate->total_weight_received, 
            gate->total_weight_late_bags);

    gate->num_of_bags_received = 0;
    gate->num_of_late_bags = 0;
    gate->total_weight_received = 0;
    gate->total_weight_late_bags = 0;
}

int main() {
    srand(time(NULL));

    // Create four gates
    Gate* gates[4];
    for (int i = 0; i < 4; i++) {
        gates[i] = (Gate*) malloc(sizeof(Gate));
        gates[i]->gate_num = i + 1;
        gates[i]->num_of_bags_received = 0;
        gates[i]->num_of_late_bags = 0;
        gates[i]->total_weight_received = 0;
        gates[i]->total_weight_late_bags = 0;
    }

    // Generate NUM_OF_BAGS baggage and distribute them randomly to the gates
    printf("%d bags have been generated and are being distributed...\n", 
            NUM_OF_BAGS);
    for (int i = 0; i < NUM_OF_BAGS; i++) {
        Baggage* new_bag = generate_baggage(i + 1, 4);
        load_gate(gates[new_bag->dest_gate_num - 1], new_bag);
    }

    // Unload all the gates
    for (int i = 0; i < 4; i++) {
        unload_gate(gates[i]);
    }

    return 0;
}