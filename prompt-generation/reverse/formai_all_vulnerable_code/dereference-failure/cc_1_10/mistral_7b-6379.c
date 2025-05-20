//MISTRAL-7B DATASET v1.0 Category: Traffic Light Controller ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define LIGHTS 3

typedef struct {
    int state;
} Light;

int main() {
    int shmid;
    Light *traffic_lights;

    srand(time(NULL));

    shmid = shmget(IPC_PRIVATE, sizeof(Light) * LIGHTS, 0644 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    traffic_lights = (Light *) shmat(shmid, NULL, 0);
    if (traffic_lights == (Light *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < LIGHTS; ++i) {
        traffic_lights[i].state = i % 3;
        printf("Light %d initialized with color %s\n", i + 1,
               (traffic_lights[i].state == 0) ? "Red" :
               (traffic_lights[i].state == 1) ? "Yellow" : "Green");
    }

    while (1) {
        for (int i = 0; i < LIGHTS; ++i) {
            sleep(1);
            printf("\nLight %d is now ", i + 1);
            if (traffic_lights[i].state == 0) {
                printf("Red\n");
                traffic_lights[i].state = 1;
            } else if (traffic_lights[i].state == 1) {
                printf("Yellow\n");
                traffic_lights[i].state = 2;
            } else {
                printf("Green\n");
                traffic_lights[i].state = 0;
                int random_index = rand() % LIGHTS;
                int temp_state = traffic_lights[random_index].state;
                traffic_lights[random_index].state = traffic_lights[i].state;
                traffic_lights[i].state = temp_state;
            }
        }
    }

    shmdt(traffic_lights);
    shmctl(shmid, IPC_RMID, 0);

    return EXIT_SUCCESS;
}