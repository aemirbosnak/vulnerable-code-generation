//MISTRAL-7B DATASET v1.0 Category: Traffic Light Controller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

// Function to generate random numbers
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Traffic Light Structure
typedef struct {
    int red_light;
    int yellow_light;
    int green_light;
} traffic_light;

// Shared Memory ID
int shmid;

// Traffic Light Controller Function
void traffic_controller() {
    traffic_light *light;

    shmid = shmget(IPC_PRIVATE, sizeof(traffic_light), IPC_CREAT | 0666);
    light = (traffic_light *) shmget(shmid, sizeof(traffic_light), 0);

    while(1) {
        // Generate random sequence of traffic lights
        light->red_light = rand_num(1, 3);
        light->yellow_light = rand_num(1, 3);
        light->green_light = rand_num(1, 3);

        // Check if the sequence is valid (each number should be different)
        if (light->red_light == light->yellow_light || light->red_light == light->green_light || light->yellow_light == light->green_light) {
            continue;
        }

        // Set the sequence in the shared memory
        shmctl(shmid, IPC_SET, light);

        printf("New sequence: Red Light = %d, Yellow Light = %d, Green Light = %d\n", light->red_light, light->yellow_light, light->green_light);

        // Sleep for a random time between 1 to 5 seconds
        sleep(rand_num(1, 5));
    }
}

// Child Process Function
void child_process() {
    int shmid;
    traffic_light *light;

    while(1) {
        shmid = shmget(IPC_PRIVATE, sizeof(traffic_light), 0);
        light = (traffic_light *) shmget(shmid, sizeof(traffic_light), 0);

        printf("Received sequence: Red Light = %d, Yellow Light = %d, Green Light = %d\n", light->red_light, light->yellow_light, light->green_light);

        sleep(1);

        shmctl(shmid, IPC_RMID, NULL);
    }
}

int main() {
    pid_t pid;

    signal(SIGINT, SIG_IGN);

    pid = fork();

    if (pid > 0) {
        traffic_controller();
    } else {
        child_process();
    }

    return 0;
}