//FormAI DATASET v1.0 Category: Interprocess communication ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 1234

#define MSG_LENGTH 256

typedef struct message_struct {
    pid_t sender_pid;
    char message[MSG_LENGTH];
    int message_length;
} message;

void signal_handler(int sig_num) {
    printf("Signal %d received!\n", sig_num);
}

int main() {
    key_t shm_key = ftok(".", SHM_KEY);
    int shm_id;

    pid_t child_pid;

    if ((shm_id = shmget(shm_key, sizeof(message), 0644 | IPC_CREAT)) == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    message *shared_message = shmat(shm_id, NULL, 0);
    shared_message->message_length = 0;

    if ((child_pid = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        while (1) {
            printf("Enter message to parent: ");
            fflush(stdout);
            char buffer[MSG_LENGTH];
            fgets(buffer, MSG_LENGTH, stdin);

            shared_message->sender_pid = getpid();
            strncpy(shared_message->message, buffer, MSG_LENGTH);
            shared_message->message_length = strlen(buffer);

            kill(getppid(), SIGUSR1);
        }
    }

    if (signal(SIGUSR1, signal_handler) == SIG_ERR) {
        printf("Could not register signal handler for SIGUSR1\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        pause();

        printf("Message received from child process (PID %d): %s\n", shared_message->sender_pid, shared_message->message);
        printf("Enter message to child: ");
        fflush(stdout);
        char buffer[MSG_LENGTH];
        fgets(buffer, MSG_LENGTH, stdin);

        shared_message->sender_pid = getpid();
        strncpy(shared_message->message, buffer, MSG_LENGTH);
        shared_message->message_length = strlen(buffer);

        kill(child_pid, SIGUSR1);
    }

    return 0;
}