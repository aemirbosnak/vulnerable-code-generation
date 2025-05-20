//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 5678
#define SHM_SIZE 1024

typedef struct {
    char name[20];
    int age;
} Person;

void main() {
    int shmid;
    key_t key = SHM_KEY;
    Person *ptr;

    // Create shared memory segment
    shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT);
    if (shmid == -1) {
        printf("Error in creating shared memory segment\n");
        exit(0);
    }

    // Attach to shared memory segment
    ptr = (Person *) shmat(shmid, NULL, 0);
    if (ptr == (Person *) -1) {
        printf("Error in attaching to shared memory segment\n");
        exit(0);
    }

    // Fill in data
    strcpy(ptr->name, "Sherlock Holmes");
    ptr->age = 35;

    // Detach from shared memory segment
    if (shmdt(ptr) == -1) {
        printf("Error in detaching from shared memory segment\n");
        exit(0);
    }

    // Attach to shared memory segment again
    ptr = (Person *) shmat(shmid, NULL, 0);
    if (ptr == (Person *) -1) {
        printf("Error in attaching to shared memory segment\n");
        exit(0);
    }

    // Print data
    printf("Name: %s\n", ptr->name);
    printf("Age: %d\n", ptr->age);

    // Detach from shared memory segment
    if (shmdt(ptr) == -1) {
        printf("Error in detaching from shared memory segment\n");
        exit(0);
    }

    // Remove shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error in removing shared memory segment\n");
        exit(0);
    }
}