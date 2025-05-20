//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

typedef struct {
    int id;
    char name[20];
} process;

int main(int argc, char *argv[]) {
    int shmid, semid;
    key_t key;
    process *proc;
    int i, j;
    char *buffer;
    int num_processes = 5;
    int *shm_array;

    // create shared memory
    key = ftok("shm_file", 65);
    shmid = shmget(key, sizeof(process) * num_processes, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory\n");
        exit(1);
    }

    // create semaphore
    semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        printf("Error creating semaphore\n");
        exit(1);
    }

    // initialize shared memory
    proc = (process *)shmat(shmid, NULL, 0);
    for (i = 0; i < num_processes; i++) {
        proc[i].id = i;
        strcpy(proc[i].name, "Process ");
        proc[i].name[10] = '0' + i;
    }

    // create child processes
    for (i = 0; i < num_processes; i++) {
        if (fork() == 0) {
            buffer = (char *)shmat(shmid, NULL, 0);
            printf("Child process %d started\n", proc[i].id);
            sleep(1);
            shmdt(buffer);
            exit(0);
        }
    }

    // wait for child processes to finish
    for (i = 0; i < num_processes; i++) {
        wait(NULL);
    }

    // clean up
    shmdt(proc);
    semctl(semid, 0, IPC_RMID);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}