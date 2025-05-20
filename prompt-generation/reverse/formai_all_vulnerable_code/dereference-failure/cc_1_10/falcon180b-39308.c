//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <sys/shm.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

typedef struct {
    int count;
    int shared_memory_id;
    char *shared_memory_ptr;
} SharedMemory;

SharedMemory *create_shared_memory(int key) {
    int shared_memory_id;
    SharedMemory *shared_memory;

    shared_memory_id = shmget(key, MAX_SIZE, IPC_CREAT | IPC_EXCL | 0666);
    if (shared_memory_id == -1) {
        fprintf(stderr, "Error: Could not create shared memory. ");
        exit(1);
    }

    shared_memory = malloc(sizeof(SharedMemory));
    shared_memory->count = 0;
    shared_memory->shared_memory_id = shared_memory_id;
    shared_memory->shared_memory_ptr = shmat(shared_memory_id, NULL, 0);
    if (shared_memory->shared_memory_ptr == (void *) -1) {
        fprintf(stderr, "Error: Could not attach to shared memory. ");
        exit(1);
    }

    return shared_memory;
}

void destroy_shared_memory(SharedMemory *shared_memory) {
    shmdt(shared_memory->shared_memory_ptr);
    shmctl(shared_memory->shared_memory_id, IPC_RMID, NULL);
    free(shared_memory);
}

void *producer(void *arg) {
    SharedMemory *shared_memory = arg;
    int count = 0;

    while (TRUE) {
        if (shared_memory->count == MAX_SIZE) {
            sleep(1);
        } else {
            shared_memory->count++;
            sprintf(shared_memory->shared_memory_ptr + count * MAX_SIZE, "Message %d\n", shared_memory->count);
            count++;
        }
    }

    return NULL;
}

void *consumer(void *arg) {
    SharedMemory *shared_memory = arg;
    int count = 0;

    while (TRUE) {
        if (shared_memory->count == 0) {
            sleep(1);
        } else {
            printf("%s", shared_memory->shared_memory_ptr + count * MAX_SIZE);
            count++;
            shared_memory->count--;
        }
    }

    return NULL;
}

int main() {
    int key = ftok(".", 65);
    int producer_pid, consumer_pid;
    SharedMemory *shared_memory;

    shared_memory = create_shared_memory(key);

    producer_pid = fork();
    if (producer_pid == 0) {
        producer(shared_memory);
    } else if (producer_pid < 0) {
        fprintf(stderr, "Error: Could not create producer process. ");
        exit(1);
    }

    consumer_pid = fork();
    if (consumer_pid == 0) {
        consumer(shared_memory);
    } else if (consumer_pid < 0) {
        fprintf(stderr, "Error: Could not create consumer process. ");
        exit(1);
    }

    wait(NULL);
    destroy_shared_memory(shared_memory);

    return 0;
}