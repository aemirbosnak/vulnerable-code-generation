//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Claude Shannon
/* CLAUDE SHANNON STYLE ELEVATOR SIMULATION PROGRAM */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_FLOORS 10 /* Number of floors in the building */
#define MAX_PASSENGERS 20 /* Maximum number of passengers allowed in the building */
#define MAX_CAPACITY 10 /* Maximum capacity of the elevator */

/* Global variables */
int current_floor = 0; /* Current floor of the elevator */
int current_capacity = 0; /* Current number of passengers in the elevator */
int direction = 1; /* Direction of the elevator (1 for going up, -1 for going down) */
int floors[MAX_FLOORS] = {0}; /* Array to keep track of the number of passengers waiting at each floor */
int elevator_queue[MAX_FLOORS][MAX_CAPACITY] = {0}; /* 2D array to keep track of the passengers in the elevator */

/* Function prototypes */
void* passenger(void* id);
void* elevator();

/* Main function */
int main()
{
    int i;
    int* id;

    /* Initialize random number generator */
    srand(time(NULL));

    /* Create passenger threads */
    for (i = 0; i < MAX_PASSENGERS; i++)
    {
        id = malloc(sizeof(int));
        *id = i;
        pthread_t thread;
        pthread_create(&thread, NULL, passenger, id);
    }

    /* Create elevator thread */
    pthread_t elevator_thread;
    pthread_create(&elevator_thread, NULL, elevator, NULL);

    /* Wait for elevator thread to finish */
    pthread_join(elevator_thread, NULL);

    /* Exit program */
    return 0;
}

/* Function for passenger threads */
void* passenger(void* id)
{
    int current_floor = rand() % MAX_FLOORS; /* Choose random starting floor */
    int destination_floor;

    do
    {
        destination_floor = rand() % MAX_FLOORS; /* Choose random destination floor */
    }
    while (destination_floor == current_floor); /* Make sure destination floor is different from current floor */

    printf("Passenger %d is waiting at floor %d to go to floor %d\n", *(int*)id, current_floor, destination_floor);

    /* Increment the number of passengers waiting on the current floor */
    floors[current_floor]++;

    /* Wait until the elevator arrives at the current floor */
    while (elevator_queue[current_floor][0] != *(int*)id)
    {
        usleep(1000);
    }

    /* Enter the elevator */
    printf("Passenger %d enters the elevator at floor %d\n", *(int*)id, current_floor);
    elevator_queue[current_floor][0] = 0;
    current_capacity++;

    /* Wait until the elevator arrives at the destination floor */
    while (current_floor != destination_floor)
    {
        usleep(1000);
    }

    /* Leave the elevator */
    printf("Passenger %d leaves the elevator at floor %d\n", *(int*)id, destination_floor);
    current_capacity--;

    /* Decrement the number of passengers waiting on the destination floor */
    floors[destination_floor]--;

    /* Free memory */
    free(id);

    /* Exit thread */
    pthread_exit(NULL);
}

/* Function for elevator thread */
void* elevator()
{
    while (1)
    {
        /* Wait for passengers to enter */
        while (current_capacity < MAX_CAPACITY && floors[current_floor] > 0)
        {
            /* Add the first passenger in the queue to the elevator */
            int i;
            for (i = 0; i < MAX_CAPACITY; i++)
            {
                if (elevator_queue[current_floor][i] != 0)
                {
                    int id = elevator_queue[current_floor][i];
                    elevator_queue[current_floor][i] = 0;
                    elevator_queue[current_floor][0] = id;
                    current_capacity++;
                    printf("Passenger %d enters the elevator at floor %d\n", id, current_floor);
                    break;
                }
            }

            floors[current_floor]--;
        }

        /* Determine direction of elevator */
        if (current_floor == 0)
        {
            direction = 1;
        }
        else if (current_floor == MAX_FLOORS - 1)
        {
            direction = -1;
        }

        /* Move elevator to next floor */
        current_floor += direction;

        /* Wait for elevator to arrive at next floor */
        usleep(100000);

        /* Let passengers leave */
        for (int i = 1; i < MAX_CAPACITY; i++)
        {
            if (elevator_queue[current_floor][i] != 0)
            {
                int id = elevator_queue[current_floor][i];
                elevator_queue[current_floor][i] = 0;
                printf("Passenger %d leaves the elevator at floor %d\n", id, current_floor);
                current_capacity--;
            }
        }
    }

    /* Exit thread */
    pthread_exit(NULL);
}