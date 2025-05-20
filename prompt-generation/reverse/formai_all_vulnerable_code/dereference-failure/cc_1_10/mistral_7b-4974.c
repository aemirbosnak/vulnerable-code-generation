//MISTRAL-7B DATASET v1.0 Category: Drone Remote Control ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_KEY 0x2000
#define BUF_SIZE 100

typedef struct {
    int x;
    int y;
    int z;
    int pitch;
    int roll;
    int yaw;
    int throttle;
} DroneState;

int main() {
    int shmid;
    DroneState *drone_state;
    char happy_message[BUF_SIZE];

    srand(time(NULL));

    shmid = shmget(SHM_KEY, sizeof(DroneState), 0666 | IPC_CREAT);
    if (shmid < 0) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    drone_state = (DroneState *)shmat(shmid, NULL, 0);
    if ((int)drone_state == -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    memset(drone_state, 0, sizeof(DroneState));

    printf("Happy Drone Remote Control System Started!\n");
    printf("Press 'h' to send happy commands to the drone.\n");

    while (1) {
        int c;
        if ((c = getchar()) == 'h') {
            drone_state->x = rand() % 10 + 5;
            drone_state->y = rand() % 10 + 5;
            drone_state->z = rand() % 10 + 5;
            drone_state->pitch = rand() % 30 + 10;
            drone_state->roll = rand() % 30 + 10;
            drone_state->yaw = rand() % 360;
            drone_state->throttle = rand() % 100 + 50;

            sprintf(happy_message, "Sending happy commands to drone: (%d, %d, %d) pitch: %d roll: %d yaw: %d throttle: %d\n",
                    drone_state->x, drone_state->y, drone_state->z, drone_state->pitch, drone_state->roll, drone_state->yaw, drone_state->throttle);
            printf("%s", happy_message);
        }
    }

    shmdt(drone_state);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}