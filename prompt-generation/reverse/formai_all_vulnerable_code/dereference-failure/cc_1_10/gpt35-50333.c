//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_FLOORS 10
#define MAX_ELEVATORS 5

sem_t elevator_sems[MAX_ELEVATORS];
sem_t floor_sem[MAX_FLOORS];
pthread_mutex_t g_mutex;

int g_elevator_pos[MAX_ELEVATORS];
int g_elevator_dest[MAX_ELEVATORS];
int g_floor_requests[MAX_FLOORS][MAX_ELEVATORS];

void* elevator_thread(void* arg)
{
    int id = *(int*)arg;

    while (1)
    {
        sem_wait(&elevator_sems[id]);
        pthread_mutex_lock(&g_mutex);

        int curr_floor = g_elevator_pos[id];
        int dest_floor = g_elevator_dest[id];

        while (curr_floor != dest_floor)
        {
            if (curr_floor < dest_floor)
            {
                curr_floor++;
            }
            else if (curr_floor > dest_floor)
            {
                curr_floor--;
            }

            g_elevator_pos[id] = curr_floor;

            if (g_floor_requests[curr_floor][id])
            {
                printf("Elevator %d: Stopping at floor %d\n", id, curr_floor);

                g_floor_requests[curr_floor][id] = 0;
                sem_post(&floor_sem[curr_floor]);
            }
        }

        pthread_mutex_unlock(&g_mutex);
    }

    return NULL;
}

void* floor_thread(void* arg)
{
    int floor = *(int*)arg;

    while (1)
    {
        sem_wait(&floor_sem[floor]);
        pthread_mutex_lock(&g_mutex);

        int closest_elevator = -1;
        int closest_dist = MAX_FLOORS;

        for (int i = 0; i < MAX_ELEVATORS; i++)
        {
            if (abs(g_elevator_pos[i] - floor) < closest_dist)
            {
                closest_elevator = i;
                closest_dist = abs(g_elevator_pos[i] - floor);
            }
        }

        printf("Floor %d: Requesting elevator %d\n", floor, closest_elevator);
        g_floor_requests[floor][closest_elevator] = 1;
        g_elevator_dest[closest_elevator] = floor;
        sem_post(&elevator_sems[closest_elevator]);

        pthread_mutex_unlock(&g_mutex);
    }

    return NULL;
}

int main()
{
    pthread_t elevator_threads[MAX_ELEVATORS];
    pthread_t floor_threads[MAX_FLOORS];

    for (int i = 0; i < MAX_ELEVATORS; i++)
    {
        sem_init(&elevator_sems[i], 0, 0);
        g_elevator_pos[i] = 0;
        g_elevator_dest[i] = -1;

        int* id = malloc(sizeof(int));
        *id = i;
        pthread_create(&elevator_threads[i], NULL, elevator_thread, id);
    }

    for (int i = 0; i < MAX_FLOORS; i++)
    {
        sem_init(&floor_sem[i], 0, 0);
        int* floor = malloc(sizeof(int));
        *floor = i;
        pthread_create(&floor_threads[i], NULL, floor_thread, floor);
    }

    while (1)
    {
        int input_floor;

        printf("Enter floor number (0-9): ");
        scanf("%d", &input_floor);

        sem_post(&floor_sem[input_floor]);
    }

    return 0;
}