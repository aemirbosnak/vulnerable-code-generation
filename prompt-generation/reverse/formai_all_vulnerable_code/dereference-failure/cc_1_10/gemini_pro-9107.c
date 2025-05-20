//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVELERS 100

typedef struct TimeTraveler {
    char *name;
    int year_of_birth;
    int year_of_departure;
    int year_of_arrival;
} TimeTraveler;

TimeTraveler *time_travelers[MAX_TIME_TRAVELERS];
int num_time_travelers = 0;

void add_time_traveler(char *name, int year_of_birth, int year_of_departure, int year_of_arrival) {
    if (num_time_travelers == MAX_TIME_TRAVELERS) {
        printf("Error: Too many time travelers!\n");
        return;
    }

    TimeTraveler *time_traveler = malloc(sizeof(TimeTraveler));
    time_traveler->name = name;
    time_traveler->year_of_birth = year_of_birth;
    time_traveler->year_of_departure = year_of_departure;
    time_traveler->year_of_arrival = year_of_arrival;

    time_travelers[num_time_travelers++] = time_traveler;
}

void print_time_travelers() {
    for (int i = 0; i < num_time_travelers; i++) {
        TimeTraveler *time_traveler = time_travelers[i];
        printf("Time traveler: %s\n", time_traveler->name);
        printf("Year of birth: %d\n", time_traveler->year_of_birth);
        printf("Year of departure: %d\n", time_traveler->year_of_departure);
        printf("Year of arrival: %d\n", time_traveler->year_of_arrival);
        printf("\n");
    }
}

int main() {
    // Create some time travelers
    add_time_traveler("Marty McFly", 1968, 1985, 2015);
    add_time_traveler("Doc Brown", 1925, 1985, 2015);
    add_time_traveler("Clara Oswald", 1866, 2013, 2015);
    add_time_traveler("The Doctor", 1830, 2010, 2015);

    // Print the time travelers
    print_time_travelers();

    return 0;
}