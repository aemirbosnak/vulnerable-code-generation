//MISTRAL-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <sys/sem.h>
#include <string.h>

#define CARS 50
#define LANES 4
#define MAX_SPEED 10
#define MIN_SPEED 5
#define TIME_QUANTUM 10000
#define SHM_SIZE 1024
#define SEM_SIZE 3

typedef struct {
    int id;
    int speed;
    int position;
} car_t;

typedef struct {
    int cars[CARS];
    int free_spots[CARS];
} shm_data_t;

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
};

int main(void) {
    shm_data_t *data;
    int shmid, semid, i, j, cars_on_road, car_id;
    car_t *car;
    union semun arg;

    srand(time(NULL));

    shmid = shmget(IPC_PRIVATE, SHM_SIZE, 0666 | IPC_CREAT);
    data = (shm_data_t *)shmget(shmid, SHM_SIZE, 0);

    for (i = 0; i < CARS; i++) {
        data->cars[i] = -1;
        data->free_spots[i] = i;
    }

    shmid = shmget(IPC_PRIVATE, SHM_SIZE, 0666 | IPC_CREAT);
    semid = semget(IPC_PRIVATE, SEM_SIZE, 0666 | IPC_CREAT);

    arg.val = 1;
    semctl(semid, 0, SETVAL, arg);
    semctl(semid, 1, SETVAL, arg);
    semctl(semid, 2, SETVAL, arg);

    for (i = 0; i < CARS; i++) {
        car = (car_t *)&data->cars[data->free_spots[i]];
        car->id = i;
        car->speed = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
        car->position = 0;
        data->free_spots[i] = -1;

        for (j = 0; j < TIME_QUANTUM; j++) {
            cars_on_road = 0;
            for (car_id = 0; car_id < CARS; car_id++) {
                car = (car_t *)&data->cars[car_id];

                if (car->position >= LANES) continue;

                arg.val = car_id;
                semop(semid, &arg, 1);

                car->position++;
                cars_on_road++;

                arg.val = -1;
                semop(semid, &arg, 1);
            }

            usleep(1000);

            if (cars_on_road == 0) {
                usleep(TIME_QUANTUM - j);
                break;
            }
        }
    }

    shmdt(data);
    shmctl(shmid, IPC_RMID, NULL);
    semctl(semid, 0, IPC_RMID, 0);
    semctl(semid, 1, IPC_RMID, 0);
    semctl(semid, 2, IPC_RMID, 0);

    return EXIT_SUCCESS;
}