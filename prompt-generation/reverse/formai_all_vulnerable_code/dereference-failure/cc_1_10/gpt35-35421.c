//FormAI DATASET v1.0 Category: Interprocess communication ; Style: protected
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

#define MSGSIZE 255

typedef struct _msg {
    int priority;
    char message[MSGSIZE];
} message;

volatile sig_atomic_t quit = 0;

void sigint_handler(int sig) {
    printf("Received SIGINT. Cleaning up...\n");
    quit = 1;
}

void cleanup(int shmid) {
    printf("Cleaning up shared memory...\n");
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
    }
}

int main() {
    key_t key = 1234;
    int shmid = shmget(key, sizeof(message), 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    message *msg = (message *) shmat(shmid, NULL, 0);
    if (msg == (message *) -1) {
        perror("shmat");
        cleanup(shmid);
        exit(EXIT_FAILURE);
    }

    // Set up signal handler to handle SIGINT (Ctrl+C)
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        perror("signal");
        cleanup(shmid);
        exit(EXIT_FAILURE);
    }

    printf("Message Sender process started. Enter 'quit' to exit.\n");

    while (!quit) {
        // Read priority and message from user
        int priority;
        char input[MSGSIZE];
        printf("Enter message priority: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            perror("fgets");
            continue;
        }
        priority = atoi(input);

        printf("Enter message: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            perror("fgets");
            continue;
        }
        input[strcspn(input, "\n")] = 0;  // remove trailing newline
        strcpy(msg->message, input);
        msg->priority = priority;

        printf("Message sent!\n");
    }

    if (shmdt(msg) == -1) {
        perror("shmdt");
    }

    cleanup(shmid);

    printf("Exiting...\n");

    return 0;
}