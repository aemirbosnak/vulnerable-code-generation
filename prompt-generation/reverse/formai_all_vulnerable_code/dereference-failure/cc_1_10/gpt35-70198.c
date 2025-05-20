//FormAI DATASET v1.0 Category: Interprocess communication ; Style: multi-threaded
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

// Define struct for message passing
typedef struct {
    int id;
    char message[100];
} message_t;

// Define the two processes
void *processA(void *arg);
void *processB(void *arg);

// Define the shared message queue
message_t *messageQueue = NULL;
int numMessages = 0;

int main() {
    // Create threads for the two processes
    pthread_t threadA, threadB;

    // Initialize the message queue
    messageQueue = (message_t *)malloc(sizeof(message_t) * 100);

    // Create process A thread
    if (pthread_create(&threadA, NULL, processA, NULL)) {
        fprintf(stderr, "Error creating process A\n");
        return 1;
    }

    // Create process B thread
    if (pthread_create(&threadB, NULL, processB, NULL)) {
        fprintf(stderr, "Error creating process B\n");
        return 1;
    }

    // Wait for process A thread to finish
    pthread_join(threadA, NULL);

    // Wait for process B thread to finish
    pthread_join(threadB, NULL);

    return 0;
}

void *processA(void *arg) {
    int pidB, status;
    message_t newMessage;

    // Create process B
    pidB = fork();

    if (pidB == 0) {
        // Child process - process B
        fprintf(stderr, "Process B created with pid %d\n", getpid());

        // Add message to the queue
        newMessage.id = getpid();
        strcpy(newMessage.message, "Hello from process A!");
        messageQueue[numMessages] = newMessage;
        numMessages++;

        // Exit child process - process B
        exit(0);
    } else {
        // Parent process - process A
        fprintf(stderr, "Process A created with pid %d\n", getpid());

        // Wait for child process - process B to finish
        waitpid(pidB, &status, 0);

        // Display messages from the queue
        for (int i = 0; i < numMessages; i++) {
            printf("Message received by process A: %s\n", messageQueue[i].message);
        }
    }

    return NULL;
}

void *processB(void *arg) {
    message_t newMessage;

    // Add message to the queue
    newMessage.id = getpid();
    strcpy(newMessage.message, "Hello from process B!");
    messageQueue[numMessages] = newMessage;
    numMessages++;

    return NULL;
}