//FormAI DATASET v1.0 Category: Interprocess communication ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <signal.h>

//Global variables
int shmid;
char *shared_memory;

//Signal Handler Function
void signal_handler(int sig) {
    if (sig == SIGINT) {
        if (shmdt(shared_memory) == -1) {
            perror("Error in detaching shared memory");
        }
        printf("\nShared memory detached successfully!\n");
        exit(0);
    }
}

int main() {
    int key = 2500;
    pid_t pid;
    char ch;
    signal(SIGINT, signal_handler);

    //Creating Shared Memory
    shmid = shmget(key, 1024, IPC_CREAT | 0666);

    if (shmid == -1) {
        perror("Error in creating shared memory");
        exit(1);
    } else {
        printf("Shared memory created successfully with id: %d\n", shmid);
    }

    //Attaching Shared Memory
    shared_memory = shmat(shmid, NULL, 0);

    if (shared_memory == (char *)-1) {
        perror("Error in attaching shared memory");
        exit(1);
    } else {
        printf("Shared memory attached successfully at address : %p\n", shared_memory);
        printf("Start typing a message for the child process:\n");
    }

    //Creating a Child Process
    pid = fork();

    if (pid < 0) {
        perror("Error in creating child process");
        exit(1);
    }

    //Child Process
    if (pid == 0) {
        printf("\nChild process Successfully created with PID: %d\n", getpid());
        while (1) {
            if (*shared_memory) {
                printf("\nMessage received from Parent: %s\n", shared_memory);
                memset(shared_memory, 0, 1024);
            }
        }
    }

    //Parent Process
    else {
        while (1) {
            ch = getchar();
            if (ch == '\n') {
                *shared_memory = '\0';
            } else {
                *shared_memory = ch;
            }
            if (*shared_memory == 'q' || *shared_memory == 'Q') {
                if (kill(pid, SIGTERM) < 0) {
                    perror("Error in terminating the child process");
                    exit(1);
                }
                if (shmdt(shared_memory) == -1) {
                    perror("Error in detaching shared memory");
                    exit(1);
                }
                printf("Shared memory detached successfully!\n");
                exit(0);
            }
        }
    }
    return 0;
}