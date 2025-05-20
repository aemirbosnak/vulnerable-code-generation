//FormAI DATASET v1.0 Category: Interprocess communication ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_KEY 1234 // Shared Memory Key
#define BUFFER_SIZE 1024 // Maximum size of the buffer

typedef struct {
    int pid;
    char message[BUFFER_SIZE];
} message_data; // Struct that holds the message and sender's PID

int main() {

    // Creating the Shared Memory ID
    int shmid = shmget(SHM_KEY, sizeof(message_data), IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("Error: Shared Memory Creation Failed");
        exit(1);
    }

    // Attaching the Shared Memory Segment
    message_data* message_container = (message_data*) shmat(shmid, NULL, 0);
    if (message_container == (void*) -1) {
        perror("Error: Shared Memory Attachment Failed");
        exit(1);
    }

    int pid = fork();
    if (pid < 0) { // Fork Failed
        perror("Error: Fork Failed");
        exit(1);
    }
    else if (pid == 0) { // Child Process (Consumer)
        printf("Consumer Process (PID: %d) Started\n", getpid());

        while (1) {
            sleep(1); // Sleep for 1 second

            if (message_container->pid > 0) { // If Message is Present
                printf("Consumer Process (PID: %d) Received Message: %s (From PID: %d)\n", getpid(), message_container->message, message_container->pid);

                // Clearing the Message and Sender's PID After Consuming
                message_container->pid = 0;
                sprintf(message_container->message, "%s", "");
            }
        }
    }
    else { // Parent Process (Producer)
        printf("Producer Process (PID: %d) Started\n", getpid());

        char input[BUFFER_SIZE];
        while (1) {
            printf("Enter a Message (Type 'exit' to Stop): ");
            fgets(input, BUFFER_SIZE, stdin);
            input[strcspn(input, "\n")] = 0; // Removing the Newline Character

            if (strcmp(input, "exit") == 0) { // Exit Condition
                break;
            }

            sprintf(message_container->message, "%s", input); // Setting the Message in the Shared Memory
            message_container->pid = getpid(); // Setting the Sender's PID in the Shared Memory

            printf("Producer Process (PID: %d) Sent Message: %s (To PID: %d)\n", getpid(), message_container->message, message_container->pid);
        }

        // Waiting for the Child Process to Exit
        waitpid(pid, NULL, 0);

        // Detaching and Removing the Shared Memory
        shmdt(message_container);
        shmctl(shmid, IPC_RMID, NULL);

        printf("Producer Process (PID: %d) Exited\n", getpid());
        exit(0);
    }
    
    return 0; // End of the Program
}