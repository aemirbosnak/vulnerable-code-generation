//MISTRAL-7B DATASET v1.0 Category: Temperature monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x1234
#define TEMP_SIZE 100
#define SHAPE_SIZE 50

typedef struct {
    float temp;
    char shape[SHAPE_SIZE];
} ShiftData;

int main() {
    int shmid;
    ShiftData *data;

    // Initialize shared memory
    shmid = shmget(SHM_KEY, TEMP_SIZE, 0666 | IPC_CREAT);
    if (shmid < 0) {
        perror("Error initializing shared memory");
        exit(EXIT_FAILURE);
    }
    data = (ShiftData *) shmget(SHM_KEY, TEMP_SIZE, 0);
    if (!data) {
        perror("Error attaching to shared memory");
        shmctl(shmid, IPC_RMID, NULL);
        exit(EXIT_FAILURE);
    }

    // Set initial temperature and shape
    data->temp = 25.0;
    strcpy(data->shape, "O_o");

    while (1) {
        // Generate random temperature and shape based on temperature
        data->temp += (drand48() - 0.5) * 5.0;
        if (data->temp > 50.0) data->temp = 50.0;
        if (data->temp < -50.0) data->temp = -50.0;

        switch ((int) (data->temp / 10)) {
            case -1:
                strcpy(data->shape, "(-_-)");
                break;
            case 0:
                strcpy(data->shape, "O_o");
                break;
            case 1:
                strcpy(data->shape, "V_V");
                break;
            case 2:
                strcpy(data->shape, "^_^");
                break;
            case 3:
                strcpy(data->shape, ">:) >:");
                break;
            default:
                strcpy(data->shape, "Invalid temperature");
        }

        printf("Temperature: %.1f°C\nShape: %s\n", data->temp, data->shape);
        sleep(1);
    }

    // Detach from shared memory
    shmdt(data);
    shmctl(shmid, IPC_RMID, NULL);

    return EXIT_SUCCESS;
}