//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/shm.h>

#define SIZE 10
#define MAX_COMMAND_LENGTH 100

typedef struct {
    int id;
    char name[MAX_COMMAND_LENGTH];
} command_t;

void execute_command(command_t* command) {
    pid_t pid;
    int status;

    switch (command->id) {
        case 1:
            printf("Executing command: %s\n", command->name);
            system(command->name);
            break;
        case 2:
            printf("Executing command: %s\n", command->name);
            exit(0);
            break;
        default:
            printf("Invalid command\n");
            exit(1);
            break;
    }
}

int main() {
    int shmid;
    key_t key;
    int shm_fd;
    command_t* shared_memory;
    int i;

    key = ftok(".", 'a');
    shmid = shmget(key, sizeof(command_t) * SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory\n");
        exit(1);
    }

    shared_memory = (command_t*) shmat(shmid, NULL, 0);
    if (shared_memory == (void*) -1) {
        printf("Error attaching shared memory\n");
        exit(1);
    }

    for (i = 0; i < SIZE; i++) {
        shared_memory[i].id = 0;
        strcpy(shared_memory[i].name, "");
    }

    while (1) {
        printf("Enter command to be executed: ");
        fgets(shared_memory[0].name, MAX_COMMAND_LENGTH, stdin);
        shared_memory[0].id = 1;

        // Notify child process
        if (fork() == 0) {
            execute_command(&shared_memory[0]);
            exit(0);
        }

        // Wait for child process to finish
        wait(NULL);

        // Clear shared memory
        memset(shared_memory, 0, sizeof(command_t) * SIZE);
    }

    return 0;
}