//FormAI DATASET v1.0 Category: Interprocess communication ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

int main(int argc, char *argv[]){
    int shmid;
    char *shmaddr;

    key_t key = ftok(".", 's');

    // Create shared memory segment
    shmid = shmget(key, SHM_SIZE, 0666|IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach to shared memory segment
    shmaddr = shmat(shmid, (void *)0, 0);
    if (shmaddr == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }

    // Write data to shared memory
    sprintf(shmaddr, "Hi there! I am your invasive program. What's your name?");

    // Detach from shared memory segment
    shmdt(shmaddr);

    // Wait for response
    sleep(5);

    // Attach to shared memory segment again
    shmaddr = shmat(shmid, (void *)0, 0);
    if (shmaddr == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }

    // Read response from shared memory and output it
    char response[SHM_SIZE];
    strcpy(response, shmaddr);
    printf("Nice to meet you, %s! You can't escape me now.\n", response);

    // Detach from shared memory segment again and delete it
    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}