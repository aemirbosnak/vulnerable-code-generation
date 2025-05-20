//FormAI DATASET v1.0 Category: Interprocess communication ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>

#define SHM_SIZE 1024

void handle_detach(int signum);

void* shared_memory;
int shmid;

int main() {
    key_t key = ftok("shmfile",65);
    shmid = shmget(key, SHM_SIZE, 0666|IPC_CREAT);
    if(shmid == -1) {
        perror("Error in creating shared memory segment");
        exit(-1);
    }
    printf("Shared memory segment created with id=%d\n", shmid);

    shared_memory = shmat(shmid, NULL, 0);
    if(shared_memory == (void*)-1) {
        perror("Error in attaching to shared memory segment");
        exit(-1);
    }
    printf("Attached to shared memory segment with address=%p\n", shared_memory);

    signal(SIGINT, handle_detach);
    signal(SIGQUIT, handle_detach);
    signal(SIGTERM, handle_detach);

    while(1) {
        printf("Enter a string to write to shared memory:");
        fgets((char*)shared_memory, SHM_SIZE, stdin);
        printf("Input string is: %s", (char*)shared_memory);
    }

    return 0;
}

void handle_detach(int signum) {
    printf("\nCaught signal=%d, detaching from shared memory segment...\n", signum);
    shmdt(shared_memory);
    printf("Detached from shared memory segment\n");

    printf("Cleaning up shared memory segment...\n");
    shmctl(shmid, IPC_RMID, NULL);
    printf("Shared memory segment cleaned up\n");

    printf("Exiting program...\n");
    exit(0);
}