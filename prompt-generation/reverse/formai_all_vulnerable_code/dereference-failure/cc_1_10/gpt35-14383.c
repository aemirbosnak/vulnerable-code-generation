//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int bag_id;
    int weight;
} Baggage;

typedef struct {
    int gate_no;
    int num_bags;
    Baggage* bags;
} Flight;

typedef struct {
    int num_gates;
    Flight* flights;
} Airport;

Airport* create_airport(int num_gates) {
    Airport* airport = (Airport *)malloc(sizeof(Airport));
    airport->num_gates = num_gates;
    airport->flights = (Flight *)malloc(sizeof(Flight) * num_gates);
    return airport;
}

Baggage* create_baggage(int num_bags) {
    Baggage* bags = (Baggage *)malloc(sizeof(Baggage) * num_bags);
    for (int i=0; i<num_bags; i++) {
        bags[i].bag_id = i + 1;
        bags[i].weight = rand() % 31 + 10;
    }
    return bags;
}

Flight create_flight(int gate_no, int num_bags) {
    Flight flight;
    flight.gate_no = gate_no;
    flight.num_bags = num_bags;
    flight.bags = create_baggage(num_bags);
    return flight;
}

void simulate_airport(Airport* airport) {
    for (int i=0; i<airport->num_gates; i++) {
        int total_weight = 0;
        printf("Gate no: %d\n", airport->flights[i].gate_no);
        printf("Number of bags: %d\n", airport->flights[i].num_bags);
        for (int j=0; j<airport->flights[i].num_bags; j++) {
            printf("Bag id: %d, Weight: %d\n", airport->flights[i].bags[j].bag_id, airport->flights[i].bags[j].weight);
            total_weight += airport->flights[i].bags[j].weight;
        }
        printf("Total weight: %d\n", total_weight);
        printf("------------------------------\n");
    }
}

int main() {
    // Create airport with 5 gates
    Airport* airport = create_airport(5);
    
    // Create flights with random number of bags
    airport->flights[0] = create_flight(1, 3);
    airport->flights[1] = create_flight(2, 5);
    airport->flights[2] = create_flight(3, 2);
    airport->flights[3] = create_flight(4, 4);
    airport->flights[4] = create_flight(5, 6);

    // Simulate airport and print baggage information
    simulate_airport(airport);

    return 0;
}