//FormAI DATASET v1.0 Category: Interprocess communication ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <signal.h>

#define SHMSIZE 1024 // shared memory size

void handler(int signo); // signal handler for SIGINT

// function to get input from user
char* get_input() {
    char* input = (char*) malloc(sizeof(char)*SHMSIZE);
    printf("Enter your message: ");
    fgets(input, SHMSIZE, stdin);
    return input;
}

int main(int argc, char const *argv[])
{
    // signal handling
    if (signal(SIGINT, handler) == SIG_ERR) {
        printf("Error handling signal.\n");
        exit(EXIT_FAILURE);
    }

    // shared memory setup
    int shmid;
    key_t key;
    char* shared_memory;
    char* message;
    int pid;

    key = ftok(".", 'S'); // creating unique key
    shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666);

    if (shmid < 0) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    shared_memory = (char*) shmat(shmid, NULL, 0);

    if (shared_memory == (char*) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // child process
    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // child process
        while(1) {
            if (strcmp(shared_memory, "exit") == 0) {
                printf("Parent process has exited. Child process exiting.\n");
                shmdt(shared_memory);
                shmctl(shmid, IPC_RMID, NULL);
                exit(EXIT_SUCCESS);
            }

            printf("Parent says: %s", shared_memory);
            sleep(1);
        }
    } else { // parent process
        while(1) {
            message = get_input();
            memcpy(shared_memory, message, strlen(message)+1); // copy message to shared memory
            free(message);

            if (strcmp(shared_memory, "exit\n") == 0) {
                printf("Exiting.\n");
                break;
            }
        }

        waitpid(pid, NULL, 0); // wait for child process to exit
        shmdt(shared_memory); // detach shared memory
        shmctl(shmid, IPC_RMID, NULL); // remove shared memory
    }

    return 0;
}

void handler(int signo) {
    printf("\nExiting due to interrupt signal.\n");
    exit(EXIT_SUCCESS);
}