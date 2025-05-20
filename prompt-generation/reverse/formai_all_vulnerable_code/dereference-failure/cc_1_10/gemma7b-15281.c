//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: systematic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define FLOOR_NUM 5
#define MAX_PASSENGER 10

typedef struct Passenger {
    char name[20];
    int floor;
    struct Passenger* next;
} Passenger;

void simulateElevator(Passenger* head) {
    int currentFloor = 1;
    time_t timer = time(NULL);

    while (head) {
        if (currentFloor == head->floor) {
            printf("%s has reached floor %d.\n", head->name, currentFloor);
            head = head->next;
        } else if (currentFloor < head->floor) {
            currentFloor++;
            printf("Elevator moving up to floor %d.\n", currentFloor);
            sleep(1);
        } else if (currentFloor > head->floor) {
            currentFloor--;
            printf("Elevator moving down to floor %d.\n", currentFloor);
            sleep(1);
        }
    }

    printf("Elevator has reached the final floor.\n");
    sleep(2);
}

int main() {
    Passenger* head = NULL;

    // Create a few passengers
    Passenger* passenger1 = malloc(sizeof(Passenger));
    strcpy(passenger1->name, "John Doe");
    passenger1->floor = 3;

    Passenger* passenger2 = malloc(sizeof(Passenger));
    strcpy(passenger2->name, "Jane Doe");
    passenger2->floor = 5;

    Passenger* passenger3 = malloc(sizeof(Passenger));
    strcpy(passenger3->name, "Peter Pan");
    passenger3->floor = 2;

    head = passenger1;
    head->next = passenger2;
    head->next->next = passenger3;

    // Simulate the elevator
    simulateElevator(head);

    return 0;
}