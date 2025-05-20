//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Variables */

int currentFloor = 1;         // Current floor of the elevator
int numOfPersons = 0;         // Number of persons in the elevator
int isMovingUp = 1;           // Determines whether elevator is moving up or down
int numOfFloors = 5;          // Total number of floors in the building
int maxCapacity = 10;         // Maximum capacity of the elevator
int personsOnFloor[5] = {0};  // Number of persons on each floor
int personsInElevator[10];    // Number of persons in the elevator
pthread_mutex_t lock;         // Lock for elevator movements
pthread_cond_t stopCond;      // Condition variable for stopping the elevator

/* Function Declarations */

int getPersonsOnFloor(int floor);
int getPersonRandomFloor();
void *person(void *person_id);
void *elevator();

/* Main Function */

int main(int argc, char **argv) {

    // Initializing the lock and condition variable
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&stopCond, NULL);

    // Creating elevator thread
    pthread_t elev;
    pthread_create(&elev, NULL, elevator, NULL);

    // Creating the person threads
    pthread_t persons[30];
    for (int i = 0; i < 30; i++) {
        int *pId = (int*) malloc(sizeof(int));
        *pId = i;
        pthread_create(&persons[i], NULL, person, pId);
    }

    // Joining the threads
    for (int i = 0; i < 30; i++) {
        pthread_join(persons[i], NULL);
    }
    pthread_join(elev, NULL);

    return 0;
}

/* Function Definitions */

// Returns the number of persons present on a particular floor
int getPersonsOnFloor(int floor) {
    int count = 0;
    for (int i = 0; i < 30; i++) {
        if (personsInElevator[i] == 0 && *(personsOnFloor+floor-1) > 0) {
            count++;
        }
    }
    return count;
}

// Returns a random floor
int getPersonRandomFloor() {
    return rand() % 5 + 1;
}

// Function defining the person threads
void *person(void *person_id) {
    int id = *((int *)person_id);
    free(person_id);

    // Person initializations
    int rand_floor = getPersonRandomFloor();

    while (1) {
        sleep(rand() % 10);
        pthread_mutex_lock(&lock);
        *(personsOnFloor+rand_floor-1) += 1;
        printf("[PERSON %d] Waiting on floor: %d | Persons on Floor: %d\n", id, rand_floor, *(personsOnFloor+rand_floor-1));
        pthread_mutex_unlock(&lock);
        while (1) {
            if (currentFloor == rand_floor && numOfPersons < maxCapacity) {
                pthread_mutex_lock(&lock);
                *(personsOnFloor+rand_floor-1) -= 1;
                personsInElevator[numOfPersons] = id;
                numOfPersons++;
                printf("[PERSON %d] Entered the elevator | Persons in Elevator: %d\n", id, numOfPersons);
                printf("\t\t\t[INFO] Elevator moving %s\n", isMovingUp ? "up" : "down");
                pthread_mutex_unlock(&lock);
                break;
            }
            else {
                sleep(1);
            }
        }
        while (1) {
            if (currentFloor == getPersonRandomFloor()) {
                pthread_mutex_lock(&lock);
                numOfPersons--;
                *(personsOnFloor+currentFloor-1) += 1;
                personsInElevator[numOfPersons] = 0;
                printf("[PERSON %d] Left the elevator on floor: %d | Persons on Floor: %d\n", id, currentFloor, *(personsOnFloor+currentFloor-1));
                pthread_mutex_unlock(&lock);
                break;
            }
            else {
                sleep(1);
            }
        }
    }
}

// Function defining the elevator thread
void *elevator() {
    while (1) {
        pthread_mutex_lock(&lock);

        while (numOfPersons == 0 && getPersonsOnFloor(currentFloor) == 0) {
            pthread_cond_wait(&stopCond, &lock);
        }

        if (currentFloor == numOfFloors) {
            printf("\t\t\tClimbing down the elevator...\n");
            isMovingUp = 0;
        }
        else if (currentFloor == 1) {
            printf("\t\t\tClimbing up the elevator...\n");
            isMovingUp = 1;
        }

        currentFloor += isMovingUp ? 1 : -1;
        printf("[INFO] Elevator at floor: %d\n", currentFloor);

        if (getPersonsOnFloor(currentFloor) > 0) {
            printf("[INFO] Elevator door opened at floor: %d\n", currentFloor);
            for (int i = 0; i < 30; i++) {
                if (*(personsOnFloor+currentFloor-1) > 0 && personsInElevator[i] == 0 && numOfPersons < maxCapacity) {
                    *(personsOnFloor+currentFloor-1) -= 1;
                    personsInElevator[numOfPersons] = i;
                    numOfPersons++;
                    printf("\t[INFO] Person %d entered the elevator on floor: %d | Persons in Elevator: %d\n", i, currentFloor, numOfPersons);
                }
            }
        }

        if (numOfPersons > 0 && *(personsOnFloor+currentFloor-1) == 0) {
            printf("[INFO] Elevator door opened on floor: %d\n", currentFloor);
            for (int i = 0; i < numOfPersons; i++) {
                if (personsInElevator[i] && isMovingUp == (getPersonRandomFloor() > currentFloor)) {
                    numOfPersons--;
                    int person_id = personsInElevator[i];
                    personsInElevator[i] = 0;
                    *(personsOnFloor+currentFloor-1) += 1;
                    printf("\t[INFO] Person %d left the elevator on floor: %d | Persons in Elevator: %d\n", person_id, currentFloor, numOfPersons);
                }
            }
        }

        if (numOfPersons == 0) {
            pthread_cond_signal(&stopCond);
        }

        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    
    return NULL;
}