//FormAI DATASET v1.0 Category: Interprocess communication ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#define KEY 1234 // Key value for shared memory and semaphore

// Shared memory structure for storing messages
typedef struct {
    int sender_id;
    char message[100];
} Message;

// Semaphore union for performing wait and signal operations
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

// Function to perform wait operation on semaphore
int sem_wait(int sem_id) {
    struct sembuf sem_op;
    sem_op.sem_num = 0;
    sem_op.sem_op = -1;
    sem_op.sem_flg = 0;
    return semop(sem_id, &sem_op, 1);
}

// Function to perform signal operation on semaphore
int sem_signal(int sem_id) {
    struct sembuf sem_op;
    sem_op.sem_num = 0;
    sem_op.sem_op = 1;
    sem_op.sem_flg = 0;
    return semop(sem_id, &sem_op, 1);
}

int main() {
    // Create shared memory for storing messages
    int shm_id = shmget(KEY, sizeof(Message), 0666|IPC_CREAT);
    if(shm_id == -1) {
        perror("Error in creating shared memory.");
        exit(1);
    }

    // Attach shared memory to current process
    Message *msg_ptr = (Message *) shmat(shm_id, NULL, 0);
    if(msg_ptr == (void *) -1) {
        perror("Error in attaching shared memory.");
        exit(1);
    }

    // Set initial message values to default
    msg_ptr->sender_id = -1;
    msg_ptr->message[0] = '\0';

    // Create semaphore for synchronization
    int sem_id = semget(KEY, 1, 0666|IPC_CREAT);
    if(sem_id == -1) {
        perror("Error in creating semaphore.");
        exit(1);
    }

    // Initialize semaphore value to 1 for synchronization
    union semun sem_val;
    sem_val.val = 1;
    semctl(sem_id, 0, SETVAL, sem_val);

    // Fork child process for receiving messages
    pid_t child_pid = fork();
    if(child_pid == -1) {
        perror("Error in forking child process.");
        exit(1);
    }

    if(child_pid == 0) {
        // Child process - Receive messages
        while(1) {
            // Wait for semaphore to be available
            sem_wait(sem_id);

            // Read message from shared memory
            int sender_id = msg_ptr->sender_id;
            char message[100];
            strcpy(message, msg_ptr->message);

            // Print message details
            if(sender_id != -1) {
                printf("Received message from Sender %d: %s\n", sender_id, message);
            }

            // Release semaphore
            sem_signal(sem_id);

            // Sleep for some time
            usleep(100000);
        }

        // Detach shared memory
        shmdt(msg_ptr);

        // Exit child process
        exit(0);
    }

    // Parent process - Send messages
    for(int i = 0; i < 10; i++) {
        // Wait for semaphore to be available
        sem_wait(sem_id);

        // Write message to shared memory
        printf("Sending message from Sender 1.\n");
        msg_ptr->sender_id = 1;
        sprintf(msg_ptr->message, "Message %d from Sender 1", i+1);

        // Release semaphore
        sem_signal(sem_id);

        // Sleep for some time
        usleep(500000);
    }

    // Wait for child process to finish
    wait(NULL);

    // Detach shared memory
    shmdt(msg_ptr);

    // Delete shared memory and semaphore
    shmctl(shm_id, IPC_RMID, NULL);
    semctl(sem_id, 0, IPC_RMID);

    // Exit parent process
    exit(0);
}