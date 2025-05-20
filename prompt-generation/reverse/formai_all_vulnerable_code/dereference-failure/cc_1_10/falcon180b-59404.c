//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SIZE 100

typedef struct {
    int id;
    char name[20];
    int age;
} person;

void main() {
    int shmid, pid, i;
    key_t key = 1111;
    person* shared_memory = NULL;
    int shared_memory_size = SIZE * sizeof(person);

    shmid = shmget(key, shared_memory_size, IPC_CREAT | 0666);

    if (shmid == -1) {
        printf("Shared memory creation failed\n");
        exit(1);
    }

    shared_memory = (person*) shmat(shmid, NULL, 0);

    if (shared_memory == (void*) -1) {
        printf("Shared memory attachment failed\n");
        exit(2);
    }

    pid = fork();

    if (pid == 0) {
        for (i = 0; i < SIZE; i++) {
            sprintf(shared_memory[i].name, "Person %d", i + 1);
            shared_memory[i].id = i + 1;
            shared_memory[i].age = i + 1;
        }
    } else {
        wait(NULL);

        for (i = 0; i < SIZE; i++) {
            printf("ID: %d, Name: %s, Age: %d\n", shared_memory[i].id, shared_memory[i].name, shared_memory[i].age);
        }
    }

    shmdt(shared_memory);
    shmctl(shmid, IPC_RMID, NULL);

    exit(0);
}