//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 1000
#define MAX_FLIGHTS 10
#define MAX_TERMINALS 5

// a Baggage is a struct representing a bag with a unique ID
typedef struct Baggage {
    int id;
} Baggage;

// a Terminal is a struct representing a disembarkation terminal
typedef struct Terminal {
    int id;
    int num_bags_received;
    int num_bags_expected;
    Baggage* expected_bags[MAX_BAGS];
} Terminal;

// a Flight is a struct representing a flight with a unique ID and its baggage
typedef struct Flight {
    int id;
    int num_bags;
    Baggage* bags[MAX_BAGS];
} Flight;

// a BaggageHandler is a struct representing a baggage handler at the airport
typedef struct BaggageHandler {
    int id;
    Terminal* terminals[MAX_TERMINALS];
    int num_terminals;
    Flight flights[MAX_FLIGHTS];
    int num_flights;
} BaggageHandler;

// function to generate a random ID for baggage and flights
int generateRandomId() {
    srand(time(NULL));
    int id = rand() % 100000;
    return id;
}

// function to create a new baggage with a unique ID
Baggage* createNewBaggage() {
    Baggage* new_bag = (Baggage*)malloc(sizeof(Baggage));
    new_bag->id = generateRandomId();
    return new_bag;
}

// function to create a new flight with a unique ID and a random number of bags
Flight* createNewFlight(int num_bags) {
    Flight* new_flight = (Flight*)malloc(sizeof(Flight));
    new_flight->id = generateRandomId();
    new_flight->num_bags = num_bags;
    for(int i=0;i<num_bags;i++) {
        new_flight->bags[i] = createNewBaggage();
    }
    return new_flight;
}

// function to create a new terminal with a unique ID
Terminal* createNewTerminal() {
    Terminal* new_terminal = (Terminal*)malloc(sizeof(Terminal));
    new_terminal->id = generateRandomId();
    new_terminal->num_bags_received = 0;
    new_terminal->num_bags_expected = 0;
    return new_terminal;
}

// function to add a terminal to the baggage handler
void addTerminal(BaggageHandler* handler, Terminal* terminal) {
    if(handler->num_terminals < MAX_TERMINALS) {
        handler->terminals[handler->num_terminals++] = terminal;
    } else {
        printf("Maximum number of terminals reached.\n");
    }
}

// function to add a flight to the baggage handler
void addFlight(BaggageHandler* handler, Flight* flight) {
    if(handler->num_flights < MAX_FLIGHTS) {
        handler->flights[handler->num_flights++] = *flight;
        for(int i=0;i<flight->num_bags;i++) {
            for(int j=0;j<handler->num_terminals;j++) {
                handler->terminals[j]->expected_bags[handler->terminals[j]->num_bags_expected++] = flight->bags[i];
            }
        }
    } else {
        printf("Maximum number of flights reached.\n");
    }
}

// function to simulate baggage handling process
void simulate(BaggageHandler* handler) {
    for(int i=0;i<handler->num_terminals;i++) {
        for(int j=0;j<handler->terminals[i]->num_bags_expected;j++) {
            Baggage* current_bag = handler->terminals[i]->expected_bags[j];
            for(int k=0;k<handler->num_flights;k++) {
                for(int l=0;l<handler->flights[k].num_bags;l++) {
                    if(handler->flights[k].bags[l]->id == current_bag->id) {
                        handler->terminals[i]->num_bags_received++;
                        current_bag = NULL;
                        break;
                    }
                }
                if(current_bag == NULL) break;
            }
        }
    }
}

int main() {
    // create a new baggage handler
    BaggageHandler handler;
    handler.id = generateRandomId();
    handler.num_terminals = 0;
    handler.num_flights = 0;

    // add some terminals to the handler
    Terminal* terminal1 = createNewTerminal();
    Terminal* terminal2 = createNewTerminal();
    addTerminal(&handler, terminal1);
    addTerminal(&handler, terminal2);

    // add some flights to the handler
    Flight* flight1 = createNewFlight(5);
    Flight* flight2 = createNewFlight(3);
    addFlight(&handler, flight1);
    addFlight(&handler, flight2);

    // simulate the baggage handling process
    simulate(&handler);

    // print the results
    printf("Baggage handler ID: %d\n", handler.id);
    for(int i=0;i<handler.num_terminals;i++) {
        printf("Terminal ID: %d\n", handler.terminals[i]->id);
        printf("Expected bags: %d\t Received bags: %d\n", handler.terminals[i]->num_bags_expected, handler.terminals[i]->num_bags_received);
    }

    return 0;
}