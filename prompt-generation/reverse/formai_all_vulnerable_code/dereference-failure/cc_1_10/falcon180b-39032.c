//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/sem.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 10
#define SEM_KEY 1234
#define SHM_KEY 5678

typedef struct {
    char message[MAX_SIZE];
    int sem_id;
    int shm_id;
    int shm_count;
} shared_data;

void initialize_shared_data(shared_data* data) {
    strcpy(data->message, "I love you!");
    data->sem_id = semget(SEM_KEY, 1, 0644 | IPC_CREAT);
    data->shm_id = shmget(SHM_KEY, sizeof(int), 0644 | IPC_CREAT);
    data->shm_count = 0;
}

void destroy_shared_data(shared_data* data) {
    semctl(data->sem_id, 0, IPC_RMID);
    shmctl(data->shm_id, IPC_RMID, NULL);
}

void write_to_shared_memory(shared_data* data) {
    char* shm_ptr = (char*)shmat(data->shm_id, NULL, 0);
    strcpy(shm_ptr, data->message);
    data->shm_count++;
}

void read_from_shared_memory(shared_data* data) {
    char* shm_ptr = (char*)shmat(data->shm_id, NULL, 0);
    printf("Shared message: %s\n", shm_ptr);
}

void signal_semaphore(shared_data* data) {
    semop(data->sem_id, &(struct sembuf){0, -1, 0}, 1);
}

void wait_for_semaphore(shared_data* data) {
    semop(data->sem_id, &(struct sembuf){0, 1, 0}, 1);
}

int main() {
    shared_data shared_memory;
    initialize_shared_data(&shared_memory);

    fork();

    if (getpid() == 0) {
        write_to_shared_memory(&shared_memory);
        signal_semaphore(&shared_memory);
        wait_for_semaphore(&shared_memory);
        read_from_shared_memory(&shared_memory);
        exit(0);
    } else {
        wait_for_semaphore(&shared_memory);
        read_from_shared_memory(&shared_memory);
        write_to_shared_memory(&shared_memory);
        signal_semaphore(&shared_memory);
        wait_for_semaphore(&shared_memory);
        read_from_shared_memory(&shared_memory);
        destroy_shared_data(&shared_memory);
        exit(0);
    }

    return 0;
}