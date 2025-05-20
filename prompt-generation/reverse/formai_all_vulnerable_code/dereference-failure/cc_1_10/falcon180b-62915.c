//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define MAX_SIZE 100
#define SEM_KEY 1234
#define SHM_KEY 5678

typedef struct {
    char data[MAX_SIZE];
    int count;
} shared_data;

void sem_wait(int sem_id) {
    struct sembuf sem_buf;
    sem_buf.sem_num = 0;
    sem_buf.sem_op = -1;
    sem_buf.sem_flg = SEM_UNDO;

    int ret = semop(sem_id, &sem_buf, 1);
    if (ret == -1) {
        printf("Error waiting on semaphore: %s\n", strerror(errno));
        exit(1);
    }
}

void sem_post(int sem_id) {
    struct sembuf sem_buf;
    sem_buf.sem_num = 0;
    sem_buf.sem_op = 1;
    sem_buf.sem_flg = SEM_UNDO;

    int ret = semop(sem_id, &sem_buf, 1);
    if (ret == -1) {
        printf("Error posting on semaphore: %s\n", strerror(errno));
        exit(1);
    }
}

int main() {
    int sem_id = semget(SEM_KEY, 1, 0666 | IPC_CREAT);
    if (sem_id == -1) {
        printf("Error creating semaphore: %s\n", strerror(errno));
        exit(1);
    }

    shared_data* shared_mem = (shared_data*) shmat(shmget(SHM_KEY, sizeof(shared_data), 0666 | IPC_CREAT), 0, 0);
    if (shared_mem == (void*) -1) {
        printf("Error attaching to shared memory: %s\n", strerror(errno));
        exit(1);
    }

    sem_wait(sem_id);

    int child_pid = fork();
    if (child_pid == -1) {
        printf("Error forking: %s\n", strerror(errno));
        exit(1);
    }

    if (child_pid == 0) {
        sem_post(sem_id);

        shared_mem->data[0] = 'c';
        shared_mem->count = 1;

        sem_wait(sem_id);

        printf("Child wrote %s to shared memory\n", shared_mem->data);
    } else {
        sem_wait(sem_id);

        printf("Parent waiting for child to write to shared memory\n");

        sem_post(sem_id);

        wait(NULL);

        printf("Child wrote %s to shared memory\n", shared_mem->data);
    }

    sem_destroy(sem_id);
    shmdt(shared_mem);

    return 0;
}