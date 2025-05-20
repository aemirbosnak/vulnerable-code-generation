//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <pthread.h>

#define SHM_SIZE 1024
#define SHM_KEY 0x12345678

typedef struct {
    int value;
    pthread_mutex_t mutex;
} shared_data;

void *writer_thread(void *arg) {
    shared_data *data = (shared_data *)arg;
    for (int i = 0; i < 100; i++) {
        pthread_mutex_lock(&data->mutex);
        data->value += i;
        pthread_mutex_unlock(&data->mutex);
    }
    return NULL;
}

void *reader_thread(void *arg) {
    shared_data *data = (shared_data *)arg;
    for (int i = 0; i < 100; i++) {
        pthread_mutex_lock(&data->mutex);
        printf("Value: %d\n", data->value);
        pthread_mutex_unlock(&data->mutex);
    }
    return NULL;
}

int main() {
    int shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    shared_data *data = (shared_data *)shmat(shm_id, NULL, 0);
    if (data == (void *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }
    pthread_mutex_init(&data->mutex, NULL);

    pthread_t writer, reader;
    pthread_create(&writer, NULL, writer_thread, data);
    pthread_create(&reader, NULL, reader_thread, data);

    pthread_join(writer, NULL);
    pthread_join(reader, NULL);

    pthread_mutex_destroy(&data->mutex);
    shmdt(data);
    shmctl(shm_id, IPC_RMID, NULL);
    return EXIT_SUCCESS;
}