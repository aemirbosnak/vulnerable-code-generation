//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

typedef struct {
    int id;
    char name[32];
    int data;
} ShapeShifter;

int main(int argc, char **argv) {
    key_t key;
    int shmid;
    ShapeShifter *shm;
    char name[32];
    int data;
    int i;

    if (argc != 3) {
        printf("Usage: %s <name> <data>\n", argv[0]);
        exit(1);
    }

    strcpy(name, argv[1]);
    data = atoi(argv[2]);

    key = ftok("shm.txt", 1);
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    shm = (ShapeShifter *)shmget(shmid, sizeof(ShapeShifter), 0);

    shm->id = getpid();
    strcpy(shm->name, name);
    shm->data = data;

    printf("[PID %d] I am %s with data %d. Shifting into another form...\n", getpid(), name, data);

    // Shift into a producer form
    if (strcmp(name, "Producer") == 0) {
        while (1) {
            ShapeShifter producer;
            printf("[PID %d] Producing data...\n", getpid());
            producer.data = rand() % 100;
            shm->data = producer.data;
            sleep(1);
        }
    }

    // Shift into a consumer form
    if (strcmp(name, "Consumer") == 0) {
        while (1) {
            if (shm->data > 50) {
                printf("[PID %d] Consuming data %d\n", getpid(), shm->data);
                shm->data--;
            }
            sleep(1);
        }
    }

    shmdt(shm);
    shmctl(shmid, IPC_RMID, 0);

    return 0;
}