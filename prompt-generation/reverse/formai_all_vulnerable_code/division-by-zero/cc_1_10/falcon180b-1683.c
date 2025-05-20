//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_ELEVATORS 3

typedef struct {
    int current_floor;
    int destination_floor;
    int moving_direction;
} elevator;

elevator elevators[MAX_ELEVATORS];
int num_elevators;
int num_floors;
int num_passengers;

void initialize_elevators() {
    int i;
    for (i = 0; i < MAX_ELEVATORS; i++) {
        elevators[i].current_floor = 0;
        elevators[i].destination_floor = 0;
        elevators[i].moving_direction = 0;
    }
}

void initialize_building() {
    int i;
    printf("Enter the number of floors in the building: ");
    scanf("%d", &num_floors);

    printf("Enter the number of elevators in the building: ");
    scanf("%d", &num_elevators);

    printf("Enter the number of passengers in the building: ");
    scanf("%d", &num_passengers);

    srand(time(NULL));
    int j;
    for (j = 0; j < num_passengers; j++) {
        int from_floor = rand() % num_floors;
        int to_floor = rand() % num_floors;
        while (from_floor == to_floor) {
            to_floor = rand() % num_floors;
        }
        elevators[j % num_elevators].current_floor = from_floor;
        elevators[j % num_elevators].destination_floor = to_floor;
        elevators[j % num_elevators].moving_direction = (to_floor > from_floor)? 1 : -1;
    }
}

void move_elevators() {
    int i;
    for (i = 0; i < num_elevators; i++) {
        if (elevators[i].current_floor!= elevators[i].destination_floor) {
            elevators[i].current_floor += elevators[i].moving_direction;
            if (elevators[i].current_floor == elevators[i].destination_floor) {
                elevators[i].moving_direction = 0;
            }
        }
    }
}

void print_building() {
    int i;
    for (i = 0; i < num_floors; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (i = 0; i < num_elevators; i++) {
        int j;
        for (j = 0; j < num_floors; j++) {
            if (j == elevators[i].current_floor) {
                printf("E");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
}

int main() {
    initialize_building();
    while (1) {
        move_elevators();
        print_building();
        usleep(100000);
    }

    return 0;
}