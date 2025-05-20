//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <time.h>

#define SHM_NAME "/my_shared_memory"
#define SEM_PRODUCER "/semaphore_producer"
#define SEM_CONSUMER "/semaphore_consumer"
#define BUFFER_SIZE 10

typedef struct {
    int buffer[BUFFER_SIZE];
    int count;
} shared_data;

void producer(shared_data *data, sem_t *sem_producer, sem_t *sem_consumer) {
    for(int i = 0; i < 20; i++) {
        sem_wait(sem_producer);  // Wait if buffer is full
        data->buffer[data->count] = rand() % 100; // Generate random number
        printf("Produced: %d\n", data->buffer[data->count]);
        data->count++;
        sem_post(sem_consumer);  // Signal consumer
        sleep(rand() % 2); // Simulate varying production time
    }
}

void consumer(shared_data *data, sem_t *sem_producer, sem_t *sem_consumer) {
    for(int i = 0; i < 20; i++) {
        sem_wait(sem_consumer);  // Wait if buffer is empty
        data->count--;
        int num = data->buffer[data->count];
        printf("Consumed: %d\n", num);
        sem_post(sem_producer); // Signal producer
        sleep(rand() % 2); // Simulate varying consumption time
    }
}

int main() {
    srand(time(NULL));

    int shm_fd;
    shared_data *data;
    
    // Create shared memory
    shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, sizeof(shared_data));
    data = mmap(0, sizeof(shared_data), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    
    // Initialize shared data
    data->count = 0;

    // Create semaphores
    sem_t *sem_producer = sem_open(SEM_PRODUCER, O_CREAT, 0666, BUFFER_SIZE);
    sem_t *sem_consumer = sem_open(SEM_CONSUMER, O_CREAT, 0666, 0);

    // Create the producer and consumer processes
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process - Consumer
        consumer(data, sem_producer, sem_consumer);
        exit(0);
    } else { // Parent process - Producer
        producer(data, sem_producer, sem_consumer);
        wait(NULL);
    }

    // Cleanup
    sem_close(sem_producer);
    sem_close(sem_consumer);
    sem_unlink(SEM_PRODUCER);
    sem_unlink(SEM_CONSUMER);
    
    munmap(data, sizeof(shared_data));
    shm_unlink(SHM_NAME);

    return 0;
}