//FormAI DATASET v1.0 Category: Interprocess communication ; Style: paranoid
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define SHM_SIZE 1024
#define KEY 1234

int main(void) {
    int shm_id;
    void *shared_memory = (void *)0;
    char input_buffer[256];
    char *shared_message;
    char *secret_code = "1234";
    int authenticated = 0;

    // Create a shared memory segment
    shm_id = shmget(KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment
    shared_memory = shmat(shm_id, (void *)0, 0);
    if (shared_memory == (void *)-1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    shared_message = (char *)shared_memory;

    printf("Welcome to the paranoid IPC program.\n");
    printf("Enter the secret code to proceed: ");

    // Get the secret code from the user
    fgets(input_buffer, sizeof(input_buffer), stdin);
    input_buffer[strcspn(input_buffer, "\n")] = 0;

    // Check if the secret code matches
    if (strcmp(input_buffer, secret_code) == 0) {
        authenticated = 1;
    }

    if (authenticated) {
        printf("Access Granted!\n");

        // Loop to receive messages from the user
        while (1) {
            printf("Enter a message to send: ");

            // Get the message from the user
            fgets(input_buffer, sizeof(input_buffer), stdin);
            input_buffer[strcspn(input_buffer, "\n")] = 0;

            // Copy the message to the shared memory segment
            strncpy(shared_message, input_buffer, SHM_SIZE);

            // Check if the user wants to exit
            if (strcmp(input_buffer, "exit") == 0) {
                break;
            }
        }

        // Detach the shared memory segment
        if (shmdt(shared_memory) == -1) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
        }

        // Delete the shared memory segment
        if (shmctl(shm_id, IPC_RMID, 0) == -1) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
        }

        printf("Exiting IPC program.\n");
        exit(EXIT_SUCCESS);
    }
    else {
        printf("Access Denied!\n");
        exit(EXIT_FAILURE);
    }
}