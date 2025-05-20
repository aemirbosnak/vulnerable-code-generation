//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define MAX_SIZE 100
#define NUM_THREADS 5

typedef struct {
    int id;
    int count;
    char name[20];
} thread_data;

void *thread_func(void *param) {
    thread_data *data = (thread_data *) param;
    int shm_id = shmget(IPC_PRIVATE, MAX_SIZE, IPC_CREAT | 0666);
    char *shm_ptr = shmat(shm_id, NULL, 0);

    sprintf(shm_ptr, "Thread %d: %s (%d)\n", data->id, data->name, data->count);

    shmdt(shm_ptr);
    shmctl(shm_id, IPC_RMID, NULL);

    return NULL;
}

int main() {
    int shm_id, i;
    char *shm_ptr;
    thread_data *data;
    pthread_t threads[NUM_THREADS];

    shm_id = shmget(IPC_PRIVATE, MAX_SIZE, IPC_CREAT | 0666);
    shm_ptr = shmat(shm_id, NULL, 0);

    for (i = 0; i < NUM_THREADS; i++) {
        data = (thread_data *) malloc(sizeof(thread_data));
        data->id = i + 1;
        data->count = i + 1;
        sprintf(data->name, "Thread %d", data->id);

        pthread_create(&threads[i], NULL, thread_func, data);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    shmdt(shm_ptr);
    shmctl(shm_id, IPC_RMID, NULL);

    return 0;
}