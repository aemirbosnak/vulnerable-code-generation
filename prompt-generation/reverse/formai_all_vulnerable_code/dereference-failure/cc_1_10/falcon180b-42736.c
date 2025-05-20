//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define BUFFER_SIZE 100

typedef struct {
    int id;
    char name[20];
    int age;
} Person;

int main() {
    int shmid;
    key_t key;
    Person *shared_memory;

    // generate unique key
    key = ftok("shared_memory.c", 65);

    // create shared memory segment
    shmid = shmget(key, sizeof(Person) * 3, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // attach shared memory segment to process
    shared_memory = (Person *) shmat(shmid, NULL, 0);
    if ((int) shared_memory == -1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // initialize shared memory
    shared_memory[0].id = 1;
    strcpy(shared_memory[0].name, "John");
    shared_memory[0].age = 25;

    shared_memory[1].id = 2;
    strcpy(shared_memory[1].name, "Jane");
    shared_memory[1].age = 30;

    shared_memory[2].id = 3;
    strcpy(shared_memory[2].name, "Bob");
    shared_memory[2].age = 20;

    // detach shared memory segment
    if (shmdt(shared_memory) == -1) {
        printf("Error detaching shared memory segment\n");
        exit(1);
    }

    // destroy shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error destroying shared memory segment\n");
        exit(1);
    }

    return 0;
}