//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <time.h>
#define SHM_KEY 0x2000
#define SHM_SIZE 1024
#define MESSAGE_SIZE 100
typedef struct {
    char message[MESSAGE_SIZE];
    int length;
} Message;
int main() {
    int pid, shmid, status;
    Message *shm_message;
    char *shm_addr;
    char sender_message[MESSAGE_SIZE];
    int sender_length;
    
    // Create Shared Memory
    shmid = shmget(SHM_KEY, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    
    // Attach Shared Memory
    shm_addr = shmat(shmid, NULL, 0);
    if (shm_addr == (void *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }
    
    // Initialize shared memory
    shm_message = (Message *) shm_addr;
    memset(shm_message->message, '\0', MESSAGE_SIZE);
    shm_message->length = 0;
    
    // Fork child process
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process
        printf("I, %d, write a romantic message for you, %d...\n", getpid(), pid);
        strcpy(sender_message, "I love you more than the stars in the night sky.");
        sender_length = strlen(sender_message) + 1;
        
        // Write message to shared memory
        shm_message->length = sender_length;
        strcpy(shm_message->message, sender_message);
        
        printf("I have written the message in the shared memory, %d. Waiting for you to read it...\n", pid);
        wait(&status);
    } else {
        // Child process
        printf("You, %d, read the romantic message from your beloved, %d...\n", getpid(), getppid());
        
        // Read message from shared memory
        while (shm_message->length > 0) {
            printf("%s\n", shm_message->message);
            shm_message->length -= strlen(shm_message->message) + 1;
            memset(shm_message->message, '\0', MESSAGE_SIZE);
        }
        
        exit(EXIT_SUCCESS);
    }
    
    // Detach Shared Memory
    shmdt(shm_addr);
    
    // Delete Shared Memory
    shmctl(shmid, IPC_RMID, NULL);
    
    return EXIT_SUCCESS;
}