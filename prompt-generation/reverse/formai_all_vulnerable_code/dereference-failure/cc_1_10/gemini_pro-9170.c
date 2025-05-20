//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// Shared memory segment
int *shared_memory;

// Mutex to protect shared memory
pthread_mutex_t mutex;

// Thread function to write to shared memory
void *write_to_shared_memory(void *arg) {
    // Get the thread ID
    int tid = (int)arg;

    // Write to shared memory
    pthread_mutex_lock(&mutex);
    *shared_memory = tid;
    sleep(1);
    printf("Thread %d wrote to shared memory: %d\n", tid, *shared_memory);
    pthread_mutex_unlock(&mutex);

    // Exit the thread
    pthread_exit(NULL);
}

// Thread function to read from shared memory
void *read_from_shared_memory(void *arg) {
    // Get the thread ID
    int tid = (int)arg;

    // Read from shared memory
    pthread_mutex_lock(&mutex);
    int value = *shared_memory;
    sleep(1);
    printf("Thread %d read from shared memory: %d\n", tid, value);
    pthread_mutex_unlock(&mutex);

    // Exit the thread
    pthread_exit(NULL);
}

// Main function
int main() {
    // Create shared memory segment
    int shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment to process
    shared_memory = (int *)shmat(shmid, NULL, 0);
    if (shared_memory == (int *)-1) {
        perror("shmat");
        exit(1);
    }

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_t writer_thread, reader_thread;
    pthread_create(&writer_thread, NULL, write_to_shared_memory, (void *)1);
    pthread_create(&reader_thread, NULL, read_from_shared_memory, (void *)2);

    // Join threads
    pthread_join(writer_thread, NULL);
    pthread_join(reader_thread, NULL);

    // Detach shared memory segment from process
    if (shmdt(shared_memory) < 0) {
        perror("shmdt");
        exit(1);
    }

    // Destroy shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) < 0) {
        perror("shmctl");
        exit(1);
    }

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}