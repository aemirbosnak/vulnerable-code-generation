//FormAI DATASET v1.0 Category: Interprocess communication ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024 /* shared memory size */

int main()
{
    char *shm_ptr;
    int shm_id;
    pid_t pid;

    /* creating a shared memory segment */
    shm_id = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id < 0) {
        perror("Error in creating shared memory segment");
        exit(1);
    }

    /* attaching the shared memory segment to the process */
    shm_ptr = (char *) shmat(shm_id, NULL, 0);
    if (shm_ptr == (char *) -1) {
        perror("Error in attaching shared memory segment to process");
        exit(1);
    }

    /* writing data to shared memory segment */
    printf("Enter a message to be sent to the other process:");
    fgets(shm_ptr, SHM_SIZE, stdin);

    /* creating a child process using fork */
    pid = fork();
    if (pid < 0) {
        perror("Error in forking");
        exit(1);
    }

    if (pid == 0) {
        /* process to receive message */
        printf("\n*** Child Process ***\n");
        printf("Message received from parent process -: %s\n", shm_ptr);

        /* detaching the shared memory segment from the process */
        if (shmdt(shm_ptr) == -1) {
            perror("Error in detaching shared memory from process");
            exit(1);
        }
    }
    else {
        /* process to send message */
        printf("\n*** Parent Process ***\n");
        printf("Message sent to child process -: %s\n", shm_ptr);

        /* detaching the shared memory segment from the process */
        if (shmdt(shm_ptr) == -1) {
            perror("Error in detaching shared memory from process");
            exit(1);
        }

        /* removing the shared memory segment */
        if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
            perror("Error in removing shared memory segment");
            exit(1);
        }
    }

    return 0;
}