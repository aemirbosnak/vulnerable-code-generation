//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define TRUE 1
#define FALSE 0
#define SHM_KEY 0x1A2B3C4D
#define SHM_SIZE 1024

typedef struct {
    int id;
    char name[20];
    int age;
} person_t;

int main() {
    int shmid;
    key_t key;
    int i;
    person_t *shm;

    // Create shared memory segment
    key = SHM_KEY;
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shm = (person_t *) shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory segment
    for (i = 0; i < 10; i++) {
        shm[i].id = i + 1;
        sprintf(shm[i].name, "Person %d", i + 1);
        shm[i].age = i * 10;
    }

    // Print shared memory segment
    for (i = 0; i < 10; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", shm[i].id, shm[i].name, shm[i].age);
    }

    // Detach shared memory segment from process
    if (shmdt(shm) == -1) {
        printf("Error detaching shared memory segment\n");
        exit(1);
    }

    // Delete shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error deleting shared memory segment\n");
        exit(1);
    }

    return 0;
}