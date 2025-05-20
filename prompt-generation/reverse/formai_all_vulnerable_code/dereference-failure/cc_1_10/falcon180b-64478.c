//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SIZE 20

typedef struct {
    int id;
    char name[10];
} student;

student *shared_memory;

int main() {

    int shmid;
    key_t key;

    key = ftok("shmfile", 65);

    if((shmid = shmget(key, sizeof(student) * SIZE, IPC_CREAT | 0777)) == -1) {
        perror("shmget");
        exit(1);
    }

    shared_memory = (student *) shmat(shmid, NULL, 0);

    if((shared_memory == (void *) -1)) {
        perror("shmat");
        exit(2);
    }

    for(int i = 0; i < SIZE; i++) {
        shared_memory[i].id = i+1;
        sprintf(shared_memory[i].name, "Student %d", i+1);
    }

    int pid;

    if((pid = fork()) == 0) {
        for(int i = 0; i < SIZE; i++) {
            printf("Child process: Student %d - %s\n", shared_memory[i].id, shared_memory[i].name);
        }
        exit(0);
    }
    else {
        wait(NULL);
        for(int i = 0; i < SIZE; i++) {
            printf("Parent process: Student %d - %s\n", shared_memory[i].id, shared_memory[i].name);
        }
    }

    if(shmdt(shared_memory) == -1) {
        perror("shmdt");
        exit(3);
    }

    if(shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(4);
    }

    return 0;
}