//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x1234
#define SHM_SIZE 1024

typedef struct {
    int pid;
    char message[100];
} Message;

int main(int argc, char **argv) {

    int shmid;
    Message *shared_memory;
    pid_t child_pid;

    // Attach shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, 0666 | IPC_CREAT);
    shared_memory = (Message *)shmat(shmid, NULL, 0);

    // Fork a child process
    child_pid = fork();

    if (child_pid < 0) { // Error occurred
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (child_pid > 0) { // Parent process
        printf("Parent: Sending message to child...\n");

        strcpy(shared_memory->message, "Hello, child! Wake up!");
        shared_memory->pid = getpid();

        wait(NULL); // Wait for child to finish

        printf("Parent: Child has finished, detaching shared memory.\n");
        shmdt(shared_memory);
        shmctl(shmid, IPC_RMID, 0);
    } else { // Child process
        printf("Child: Attaching shared memory.\n");

        shmat(shmid, NULL, 0);

        while (strcmp(shared_memory->message, "")) { // Wait for parent to send a message
            printf("Child: Parent did not send a message yet.\n");
            sleep(1);
        }

        printf("Child: Received message: %s from PID: %d\n", shared_memory->message, shared_memory->pid);

        exit(EXIT_SUCCESS);
    }

    return EXIT_SUCCESS;
}