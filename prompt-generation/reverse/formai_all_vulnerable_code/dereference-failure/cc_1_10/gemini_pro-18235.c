//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: complex
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <unistd.h>

#define MESSAGE_SIZE 256

struct message {
    long message_type;
    char message_text[MESSAGE_SIZE];
};

int main(int argc, char *argv[]) {
    int message_queue_id;
    key_t message_queue_key;
    struct message message;
    char *message_text;
    pid_t child_pid;
    int status;

    if (argc != 2) {
        printf("Usage: %s <message text>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    message_queue_key = ftok("./", 'm');
    if (message_queue_key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    message_queue_id = msgget(message_queue_key, IPC_CREAT | 0666);
    if (message_queue_id == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    message_text = argv[1];
    message.message_type = 1;
    strcpy(message.message_text, message_text);

    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // Child process
        int receive_status;
        struct message received_message;
        receive_status = msgrcv(message_queue_id, &received_message, MESSAGE_SIZE, 0, 0);
        if (receive_status == -1) {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }
        printf("Child process received message: %s\n", received_message.message_text);
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        int send_status;
        send_status = msgsnd(message_queue_id, &message, sizeof(message), 0);
        if (send_status == -1) {
            perror("msgsnd");
            exit(EXIT_FAILURE);
        }
        printf("Parent process sent message: %s\n", message_text);
        waitpid(child_pid, &status, 0);
        if (WEXITSTATUS(status) != EXIT_SUCCESS) {
            printf("Child process exited with error\n");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    }

    return EXIT_SUCCESS;
}