//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>

#define TRUE 1
#define FALSE 0
#define SEM_KEY 1000
#define SHM_KEY 2000
#define MAX_SIZE 10

typedef struct {
    int count;
    int semid;
    int shmid;
} shared_data;

void initialize_shared_memory(shared_data* data) {
    data->semid = semget(SEM_KEY, 1, 0666);
    data->shmid = shmget(SHM_KEY, MAX_SIZE * sizeof(int), 0666);
    if (data->semid == -1 || data->shmid == -1) {
        printf("Error initializing shared memory.\n");
        exit(1);
    }
}

void destroy_shared_memory(shared_data* data) {
    semctl(data->semid, 0, IPC_RMID);
    shmctl(data->shmid, IPC_RMID, NULL);
}

int create_child_processes(shared_data* data, int num_children) {
    int i;
    int child_pid;
    for (i = 0; i < num_children; i++) {
        child_pid = fork();
        if (child_pid == -1) {
            printf("Error creating child process.\n");
            destroy_shared_memory(data);
            exit(1);
        } else if (child_pid == 0) {
            execlp("child_process", "child_process", NULL);
            printf("Error executing child process.\n");
            exit(1);
        }
    }
    return 0;
}

int main(int argc, char* argv[]) {
    shared_data data;
    initialize_shared_memory(&data);
    int num_children = atoi(argv[1]);
    int i;
    for (i = 0; i < num_children; i++) {
        create_child_processes(&data, num_children);
    }

    int count = 0;
    while (count < num_children) {
        semop(data.semid, &(struct sembuf){0, -1, IPC_NOWAIT}, 1);
        sleep(1);
    }

    for (i = 0; i < num_children; i++) {
        int status;
        waitpid(0, &status, WNOHANG);
    }

    destroy_shared_memory(&data);
    return 0;
}