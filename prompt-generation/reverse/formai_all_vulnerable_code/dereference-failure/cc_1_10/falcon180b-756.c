//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10
#define MAX_ITERATIONS 5

typedef struct {
    int id;
    int count;
    int shared_mem_id;
} process_data;

void main_process(process_data *data) {
    int shared_mem_id = shmget(IPC_PRIVATE, SIZE * sizeof(int), IPC_CREAT | 0666);
    int *shared_mem = (int *)shmat(shared_mem_id, NULL, 0);
    data->shared_mem_id = shared_mem_id;
    shared_mem[0] = 0;
    int count = 0;
    while (count < MAX_ITERATIONS) {
        if (shared_mem[0] == 0) {
            if (fork() == 0) {
                data->id = getpid();
                data->count = 0;
                int i = 0;
                while (i < SIZE) {
                    shared_mem[i] = i;
                    i++;
                }
                shared_mem[0] = 1;
                exit(EXIT_SUCCESS);
            }
            wait(NULL);
        }
        count++;
        sleep(1);
    }
    shmctl(shared_mem_id, IPC_RMID, NULL);
    exit(EXIT_SUCCESS);
}

void child_process(process_data *data) {
    int shared_mem_id = data->shared_mem_id;
    int *shared_mem = (int *)shmat(shared_mem_id, NULL, 0);
    int count = 0;
    while (count < MAX_ITERATIONS) {
        if (shared_mem[0] == 1) {
            if (fork() == 0) {
                data->id = getpid();
                data->count = 0;
                int i = 0;
                while (i < SIZE) {
                    shared_mem[i] = i;
                    i++;
                }
                shared_mem[0] = 0;
                exit(EXIT_SUCCESS);
            }
            wait(NULL);
        }
        count++;
        sleep(1);
    }
    shmdt(shared_mem);
    exit(EXIT_SUCCESS);
}

int main() {
    process_data data;
    data.shared_mem_id = -1;
    data.id = getpid();
    data.count = 0;
    main_process(&data);
    return 0;
}