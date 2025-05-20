//FormAI DATASET v1.0 Category: Interprocess communication ; Style: modular
/* This is a modular example to demonstrate Interprocess communication in C */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE    1024

/* Function to process data */
int process_data(char* data) {
    int result = 0;
    char* ptr = strtok(data, " ");
    while (ptr != NULL) {
        result += atoi(ptr);
        ptr = strtok(NULL, " ");
    }
    return result;
}

/* Structure to hold shared memory details */ 
typedef struct shared_memory {
    int id;
    char data[SHM_SIZE];
} shared_memory;

/* Parent process */
void parent() {
    int status;
    pid_t pid;
    key_t key;
    shared_memory* sh_mem;

    /* Generate Key */
    if ((key = ftok("shm_prog", 'R')) == -1) {
        perror("ftok");
        exit(1);
    }

    /* Allocate Shared Memory */
    if ((sh_mem = shmat(shmget(key, SHM_SIZE, 0644), 0, 0)) == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    printf("Enter data to be processed: ");
    fgets(sh_mem->data, SHM_SIZE, stdin);

    /* Fork a Child */
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        printf("Child process is processing the data...\n");
        int result = process_data(sh_mem->data);
        printf("Result = %d\n", result);
        sh_mem->id = getpid();
        exit(0);
    } else {
        waitpid(pid, &status, 0);
        printf("Child process with pid %d finished processing.\n", sh_mem->id);
        printf("Parent process cleaning up...\n");
        if (shmdt(sh_mem) == -1) {
            perror("shmdt");
            exit(1);
        }
        if (shmctl(shmget(key, SHM_SIZE, 0644), IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }
        printf("Parent process exiting.\n");
        exit(0);
    }
}

/* Child process */
void child() {
    pid_t pid;
    key_t key;
    shared_memory* sh_mem;

    /* Generate Key */
    if ((key = ftok("shm_prog", 'R')) == -1) {
        perror("ftok");
        exit(1);
    }

    /* Allocate Shared Memory */
    if ((sh_mem = shmat(shmget(key, SHM_SIZE, IPC_CREAT | 0666), 0, 0)) == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    printf("Child process waiting for data...\n");
    while (sh_mem->data[0] == 0);
    printf("Data received from parent: %s\n", sh_mem->data);
    printf("Child process exiting...\n");
    exit(0);
}

/* Main function */
int main(int argc, char* argv[]) {
    pid_t pid;

    /* Fork a Child */
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        child();
    } else {
        parent();
    }
    return 0;
}