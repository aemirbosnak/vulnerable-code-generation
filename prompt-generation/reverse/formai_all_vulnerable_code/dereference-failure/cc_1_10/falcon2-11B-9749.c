//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_FLOORS 10

typedef struct {
    char name[20];
    int floor;
} Person;

Person people[NUM_FLOORS];

void loadPeople(int numPeople, char *names[], int floors[]) {
    int i, j;
    for (i = 0; i < numPeople; i++) {
        for (j = 0; j < NUM_FLOORS; j++) {
            if (floors[i] == j) {
                strncpy(people[j].name, names[i], 20);
                people[j].floor = j;
                break;
            }
        }
    }
}

void printPeople(void) {
    int i;
    for (i = 0; i < NUM_FLOORS; i++) {
        printf("%s is on floor %d\n", people[i].name, i + 1);
    }
}

int main(int argc, char *argv[]) {
    int numPeople = atoi(argv[1]);
    char *names[numPeople];
    int floors[numPeople];

    srand(time(NULL));

    for (int i = 0; i < numPeople; i++) {
        names[i] = malloc(20 * sizeof(char));
        floors[i] = rand() % NUM_FLOORS;
    }

    loadPeople(numPeople, names, floors);
    printPeople();

    return 0;
}