//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 100
#define MAX_FLIGHTS 20
#define MAX_TERMINALS 10

struct flight {
    int flight_num;
    int departure_time;
    int arrival_time;
    int terminal;
    int baggage[MAX_BAGGAGE];
};

void generate_flights(struct flight flights[], int num_flights, int max_terminals);
void generate_baggage(int baggage[], int max_baggage);
void sort_flights(struct flight flights[], int num_flights);
void display_flights(struct flight flights[], int num_flights);
void display_baggage(struct flight flights[], int num_flights);

int main() {
    int num_flights, max_terminals;
    srand(time(NULL));
    printf("Enter the number of flights: ");
    scanf("%d", &num_flights);
    printf("Enter the maximum number of terminals: ");
    scanf("%d", &max_terminals);
    struct flight flights[num_flights];
    generate_flights(flights, num_flights, max_terminals);
    sort_flights(flights, num_flights);
    display_flights(flights, num_flights);
    display_baggage(flights, num_flights);
    return 0;
}

void generate_flights(struct flight flights[], int num_flights, int max_terminals) {
    int i, j;
    for (i = 0; i < num_flights; i++) {
        flights[i].flight_num = i + 1;
        flights[i].departure_time = rand() % 24 + 1;
        flights[i].arrival_time = flights[i].departure_time + (rand() % 4) + 1;
        flights[i].terminal = rand() % max_terminals + 1;
        generate_baggage(flights[i].baggage, MAX_BAGGAGE);
    }
}

void generate_baggage(int baggage[], int max_baggage) {
    int i;
    for (i = 0; i < max_baggage; i++) {
        baggage[i] = rand() % 2;
    }
}

void sort_flights(struct flight flights[], int num_flights) {
    int i, j, min_index;
    struct flight temp;
    for (i = 0; i < num_flights - 1; i++) {
        min_index = i;
        for (j = i + 1; j < num_flights; j++) {
            if (flights[j].departure_time < flights[min_index].departure_time) {
                min_index = j;
            }
        }
        if (min_index != i) {
            temp = flights[i];
            flights[i] = flights[min_index];
            flights[min_index] = temp;
        }
    }
}

void display_flights(struct flight flights[], int num_flights) {
    int i;
    printf("FLIGHT\tDEPARTURE\tARRIVAL\t\tTERMINAL\n");
    for (i = 0; i < num_flights; i++) {
        printf("%d\t%d:00\t\t%d:00\t\t%d\n", flights[i].flight_num, flights[i].departure_time, flights[i].arrival_time, flights[i].terminal);
    }
}

void display_baggage(struct flight flights[], int num_flights) {
    int i, j, total_baggage = 0;
    printf("FLIGHT\tBAGGAGE\n");
    for (i = 0; i < num_flights; i++) {
        total_baggage = 0;
        for (j = 0; j < MAX_BAGGAGE; j++) {
            if (flights[i].baggage[j] == 1) {
                total_baggage++;
            }
        }
        printf("%d\t%d\n", flights[i].flight_num, total_baggage);
    }
}