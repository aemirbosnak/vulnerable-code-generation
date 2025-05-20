//FormAI DATASET v1.0 Category: Interprocess communication ; Style: imaginative
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

typedef struct {
    pid_t pid;
    char message[256];
} mailbox_t;

mailbox_t *mailbox_;

void sig_handler(int signo) {
    if (signo == SIGINT) {
        shmdt((void *) mailbox_);
        shmctl(shmget(777, sizeof(mailbox_t), 0666), IPC_RMID, NULL);
        printf("\nExiting...\n");
        exit(0);
    }
}

int main(void) {
    int shmid;
    pid_t pid;

    // Create shared memory
    if ((shmid = shmget(777, sizeof(mailbox_t), IPC_CREAT|0666)) < 0) {
        perror("Error creating shared memory");
        exit(1);
    }

    // Attach shared memory
    if ((mailbox_ = shmat(shmid, NULL, 0)) == (mailbox_t *) -1) {
        perror("Error attaching shared memory");
        exit(1);
    }

    // Initialize shared memory
    mailbox_->pid = getpid();
    strcpy(mailbox_->message, "");

    // Register signal handler
    signal(SIGINT, sig_handler);

    // Start message loop
    while (1) {
        printf("Enter a message: ");
        fgets(mailbox_->message, sizeof(mailbox_->message), stdin);

        // Remove newline character
        mailbox_->message[strcspn(mailbox_->message, "\n")] = 0;

        // Print message
        printf("Message sent: %s\n", mailbox_->message);

        // Wait for response
        while (strlen(mailbox_->message) == 0) {
            sleep(1);
        }

        // Print response
        printf("Response received: %s\n", mailbox_->message);

        // Clear message
        strcpy(mailbox_->message, "");
    }
}