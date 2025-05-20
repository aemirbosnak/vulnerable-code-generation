//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: ultraprecise
/* 
   AIRPORT BAGGAGE HANDLING SIMULATION
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BAGGAGE 100
#define MAX_CHECKIN_LINES 10
#define MAX_FLIGHTS 20
#define MAX_BAGGAGE_PER_FLIGHT 50

/* Baggage struct */
typedef struct {
    int weight;
    int destination_flight;
} Baggage;

/* Check-in struct */
typedef struct {
    int id;
    int current_weight;
    int max_weight;
    int current_flight_id;
    int *flight_ids;
} CheckIn;

/* Flight struct */
typedef struct {
    int id;
    int baggage_count;
    Baggage *baggage_list;
} Flight;

/* Function prototypes */
int generate_random_num(int min, int max);
void initialize_check_in(CheckIn *check_in, int check_in_id, int max_weight, int *flight_ids);
void check_in_passenger(CheckIn *check_in, Baggage *baggage, bool *is_check_in_full);
void assign_flight_to_baggage(CheckIn *all_check_in[MAX_CHECKIN_LINES], Flight *all_flights[MAX_FLIGHTS], int flight_id);
void print_baggage_info(Baggage *baggage);
void print_check_in_info(CheckIn *check_in, int check_in_num);
void print_flight_info(Flight *flight);

/* Main function */
int main() {
    srand(time(0)); // Seed for random number generator

    /* Variables */
    int i, j, random_num;
    CheckIn *all_check_in[MAX_CHECKIN_LINES]; // Array of pointer to CheckIn struct
    Flight *all_flights[MAX_FLIGHTS]; // Array of pointer to Flight struct
    Baggage *all_baggage[MAX_BAGGAGE]; // Array of pointer to Baggage struct

    /* Initialize all CheckIn struct */
    for (i = 0; i < MAX_CHECKIN_LINES; i++) {
        all_check_in[i] = (CheckIn*)malloc(sizeof(CheckIn));
        initialize_check_in(all_check_in[i], i+1, generate_random_num(20, 40), NULL);
    }

    /* Initialize all Flight struct */
    for (i = 0; i < MAX_FLIGHTS; i++) {
        all_flights[i] = (Flight*)malloc(sizeof(Flight));
        all_flights[i]->id = i+1;
        all_flights[i]->baggage_count = 0;
        all_flights[i]->baggage_list = (Baggage*)malloc(MAX_BAGGAGE_PER_FLIGHT*sizeof(Baggage));
    }

    /* Generate all Baggage */
    for (i = 0; i < MAX_BAGGAGE; i++) {
        all_baggage[i] = (Baggage*)malloc(sizeof(Baggage));
        all_baggage[i]->weight = generate_random_num(10, 30);
        all_baggage[i]->destination_flight = 0;
    }

    /* Assign flights to each check-in */
    for (i = 0; i < MAX_CHECKIN_LINES; i++) {
        all_check_in[i]->flight_ids = (int*)malloc(MAX_FLIGHTS*sizeof(int));
        for (j = 0; j < MAX_FLIGHTS; j++) {
            all_check_in[i]->flight_ids[j] = j+1;
        }
    }

    /* Check-in passengers and assign flights to their baggage */
    for (i = 0; i < MAX_BAGGAGE; i++) {
        random_num = generate_random_num(0, MAX_CHECKIN_LINES-1);
        check_in_passenger(all_check_in[random_num], all_baggage[i], NULL);
    }

    /* Assign each baggage to a flight */
    for (i = 0; i < MAX_FLIGHTS; i++) {
        assign_flight_to_baggage(all_check_in, all_flights, i+1);
    }

    /* Print all flight's baggage info */
    for (i = 0; i < MAX_FLIGHTS; i++) {
        print_flight_info(all_flights[i]);
    }

    /* Free malloced memory */
    for (i = 0; i < MAX_CHECKIN_LINES; i++) {
        free(all_check_in[i]->flight_ids);
        free(all_check_in[i]);
    }

    for (i = 0; i < MAX_FLIGHTS; i++) {
        free(all_flights[i]->baggage_list);
        free(all_flights[i]);
    }

    for (i = 0; i < MAX_BAGGAGE; i++) {
        free(all_baggage[i]);
    }

    return 0;
}

/* Function to generate random number within a range */
int generate_random_num(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

/* Function to initialize CheckIn struct */
void initialize_check_in(CheckIn *check_in, int check_in_id, int max_weight, int *flight_ids) {
    check_in->id = check_in_id;
    check_in->current_weight = 0;
    check_in->max_weight = max_weight;
    check_in->current_flight_id = 0;
    check_in->flight_ids = flight_ids;
}

/* Function for passenger check-in */
void check_in_passenger(CheckIn *check_in, Baggage *baggage, bool *is_check_in_full) {

    if (check_in->current_weight + baggage->weight > check_in->max_weight) {
        printf("Check-in %d is overcapacity, passenger can't check-in\n", check_in->id);
        return;
    }

    if (check_in->current_flight_id == 0) {
        check_in->current_flight_id = check_in->flight_ids[0];
    }

    baggage->destination_flight = check_in->current_flight_id;
    check_in->current_weight += baggage->weight;
    printf("Baggage checked-in at Check-in %d, Flight %d\n", check_in->id, check_in->current_flight_id);

    if (is_check_in_full != NULL) {
        *is_check_in_full = true;
    }
}

/* Function to assign flights to baggage */
void assign_flight_to_baggage(CheckIn *all_check_in[MAX_CHECKIN_LINES], Flight *all_flights[MAX_FLIGHTS], int flight_id) {

    Flight *current_flight;
    int i, j, baggage_count = 0;
    Baggage *current_baggage;

    /* Find and initialize the current Flight */
    for (i = 0; i < MAX_FLIGHTS; i++) {
        if (all_flights[i]->id == flight_id) {
            current_flight = all_flights[i];
            break;
        }
    }

    /* Loop through check-in lines */
    for (i = 0; i < MAX_CHECKIN_LINES; i++) {

        /* Loop through all baggage in i-th check-in line */
        for (j = 0; j < MAX_BAGGAGE; j++) {

            current_baggage = all_check_in[i]->flight_ids != NULL ? NULL : all_check_in[i]->flight_ids[j];

            /* If current baggage is assigned to current flight */
            if (current_baggage != NULL && current_baggage->destination_flight == flight_id) {

                /* Add current baggage to the current flight */
                current_flight->baggage_list[baggage_count].destination_flight = flight_id;
                current_flight->baggage_list[baggage_count].weight = current_baggage->weight;
                baggage_count++;

                /* Remove current baggage from its check-in line */
                all_check_in[i]->current_weight -= current_baggage->weight;
                current_baggage->destination_flight = 0;
            }
        }

        /* If all baggage has been assigned to current flight */
        if (baggage_count == MAX_BAGGAGE_PER_FLIGHT) {
            break;
        }
    }

    /* Set baggage count for current flight */
    current_flight->baggage_count = baggage_count;
}

/* Function to print information of each baggage */
void print_baggage_info(Baggage *baggage) {
    printf("Baggage %d, Destination Flight %d\n", baggage, baggage->destination_flight);
}

/* Function to print information of each check-in */
void print_check_in_info(CheckIn *check_in, int check_in_num) {
    printf("Check-in %d\n", check_in_num);
    printf("Max Weight: %d | Current Weight: %d\n", check_in->max_weight, check_in->current_weight);
    printf("Assigned Flights: ");
    if (check_in->flight_ids != NULL) {
        for (int i = 0; i < MAX_FLIGHTS; i++) {
            printf("%d ", check_in->flight_ids[i]);
        }
    }
    printf("\n\n");
}

/* Function to print information of each flight */
void print_flight_info(Flight *flight) {
    int i, total_weight = 0;
    printf("------ Flight %d - Baggage Count %d ------\n", flight->id, flight->baggage_count);
    for (i = 0; i < flight->baggage_count; i++) {
        print_baggage_info(&flight->baggage_list[i]);
        total_weight += flight->baggage_list[i].weight;
    }
    printf("\nTotal Baggage Weight: %d\n", total_weight);
}