//FormAI DATASET v1.0 Category: Interprocess communication ; Style: active
/*
 * This program demonstrates an interprocess communication example using shared memory and semaphores.
 * The program creates two processes - producer and consumer. The producer process writes data to shared memory,
 * and the consumer process reads the data from the shared memory. Semaphores are used to synchronize access
 * to shared memory between processes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <string.h>

#define SHM_SIZE 1024    // Size of shared memory segment
#define SEM_PROD 0       // Semaphore index for producer
#define SEM_CONS 1       // Semaphore index for consumer

struct shared_data {
    int buffer[SHM_SIZE];  // Data buffer
    int in;                // Index where producer writes data to buffer
    int out;               // Index where consumer reads data from buffer
};

union semun {
    int val;            // Value for SETVAL operation
    struct semid_ds *buf;    
    unsigned short *array;
};

// Function prototypes
void producer(int, int, struct shared_data *);
void consumer(int, int, struct shared_data *);
void sem_wait(int, int);
void sem_signal(int, int);

int main(void)
{
    int shmid;                // Shared memory ID
    int semid;                // Semaphore ID
    pid_t pid_producer, pid_consumer;
    struct shared_data *shared_memory;  // Pointer to shared memory segment

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, sizeof(struct shared_data), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach shared memory segment to process address space
    shared_memory = shmat(shmid, NULL, 0);
    if (shared_memory == (void *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Initialize shared memory data
    shared_memory->in = 0;
    shared_memory->out = 0;
    memset(shared_memory->buffer, 0, sizeof(shared_memory->buffer));

    // Create semaphores
    semid = semget(IPC_PRIVATE, 2, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("semget");
        exit(EXIT_FAILURE);
    }

    // Initialize semaphores
    union semun arg;
    arg.val = 1;
    if (semctl(semid, SEM_PROD, SETVAL, arg) == -1) {
        perror("semctl");
        exit(EXIT_FAILURE);
    }
    if (semctl(semid, SEM_CONS, SETVAL, arg) == -1) {
        perror("semctl");
        exit(EXIT_FAILURE);
    }

    // Create child processes
    pid_producer = fork();
    if (pid_producer == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid_producer == 0) {
        // Child process - producer
        producer(shmid, semid, shared_memory);
        exit(EXIT_SUCCESS);
    } else {
        pid_consumer = fork();
        if (pid_consumer == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (pid_consumer == 0) {
            // Child process - consumer
            consumer(shmid, semid, shared_memory);
            exit(EXIT_SUCCESS);
        }
    }

    // Wait for child processes to terminate
    waitpid(pid_producer, NULL, 0);
    waitpid(pid_consumer, NULL, 0);

    // Detach shared memory segment
    if (shmdt(shared_memory) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    // Delete shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(EXIT_FAILURE);
    }

    // Delete semaphores
    if (semctl(semid, 0, IPC_RMID, arg) == -1) {
        perror("semctl");
        exit(EXIT_FAILURE);
    }

    return 0;
}

// Producer process - writes data to shared memory
void producer(int shmid, int semid, struct shared_data *shared_memory)
{
    int i;
    for (i = 1; i <= SHM_SIZE; i++) {
        // Wait for permission to write to shared memory
        sem_wait(semid, SEM_PROD);

        // Write data to shared memory
        shared_memory->buffer[shared_memory->in] = i;
        shared_memory->in = (shared_memory->in + 1) % SHM_SIZE;

        printf("Producer wrote data %d to shared memory.\n", i);

        // Signal consumer that new data is available
        sem_signal(semid, SEM_CONS);
    }
}

// Consumer process - reads data from shared memory
void consumer(int shmid, int semid, struct shared_data *shared_memory)
{
    int data, i;
    for (i = 1; i <= SHM_SIZE; i++) {
        // Wait for permission to read from shared memory
        sem_wait(semid, SEM_CONS);

        // Read data from shared memory
        data = shared_memory->buffer[shared_memory->out];
        shared_memory->out = (shared_memory->out + 1) % SHM_SIZE;

        printf("Consumer read data %d from shared memory.\n", data);

        // Signal producer that buffer slot is available
        sem_signal(semid, SEM_PROD);
    }
}

// Semaphore wait operation
void sem_wait(int semid, int sem_num)
{
    struct sembuf sem_buf;
    sem_buf.sem_num = sem_num;
    sem_buf.sem_op = -1;
    sem_buf.sem_flg = SEM_UNDO;
    if (semop(semid, &sem_buf, 1) == -1) {
        perror("semop");
        exit(EXIT_FAILURE);
    }
}

// Semaphore signal operation
void sem_signal(int semid, int sem_num)
{
    struct sembuf sem_buf;
    sem_buf.sem_num = sem_num;
    sem_buf.sem_op = 1;
    sem_buf.sem_flg = SEM_UNDO;
    if (semop(semid, &sem_buf, 1) == -1) {
        perror("semop");
        exit(EXIT_FAILURE);
    }
}