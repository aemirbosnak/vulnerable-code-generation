//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 1000

typedef struct {
    int id;
    char name[MAX_SIZE];
    int age;
} Person;

int main(int argc, char *argv[]) {
    int shmid, i;
    key_t key;
    Person *shm;

    // Get a unique key
    key = ftok(".", 'a');

    // Attach to the shared memory segment
    shmid = shmget(key, sizeof(Person) * 3, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    // Map the shared memory segment to the process address space
    shm = (Person *) shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        printf("Error mapping shared memory segment\n");
        exit(1);
    }

    // Initialize the shared data
    for (i = 0; i < 3; i++) {
        sprintf(shm[i].name, "Person %d", i + 1);
        shm[i].age = i * 10;
    }

    // Print the shared data
    for (i = 0; i < 3; i++) {
        printf("ID: %d\nName: %s\nAge: %d\n", shm[i].id, shm[i].name, shm[i].age);
    }

    // Detach from the shared memory segment
    if (shmdt(shm) == -1) {
        printf("Error detaching from shared memory segment\n");
        exit(1);
    }

    // Remove the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error removing shared memory segment\n");
        exit(1);
    }

    return 0;
}