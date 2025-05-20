//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define PIPE_NAME_LENGTH 50
#define MESSAGE_LENGTH 100

void create_pipe(char *pipe_name);
void write_message(int fd_out, char *message, int message_length);
void read_message(int fd_in, char *message, int message_length);

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s sender_name receiver_name\n", argv[0]);
        return 1;
    }

    char sender_name[PIPE_NAME_LENGTH];
    char receiver_name[PIPE_NAME_LENGTH];
    strcpy(sender_name, argv[1]);
    strcpy(receiver_name, argv[2]);

    int fd_sender, fd_receiver;
    mkfifo(sender_name, 0666);
    mkfifo(receiver_name, 0666);

    fd_sender = open(sender_name, O_WRONLY);
    fd_receiver = open(receiver_name, O_RDONLY);

    char message[MESSAGE_LENGTH];
    while (1) {
        printf("Sender enters a message (type 'quit' to exit):\n");
        fgets(message, MESSAGE_LENGTH, stdin);
        message[strcspn(message, "\n")] = 0;

        if (strcmp(message, "quit") == 0) {
            close(fd_sender);
            close(fd_receiver);
            unlink(sender_name);
            unlink(receiver_name);
            return 0;
        }

        write_message(fd_sender, message, strlen(message) + 1);
        read_message(fd_receiver, message, MESSAGE_LENGTH);
        printf("Receiver's response: %s\n", message);
    }

    close(fd_sender);
    close(fd_receiver);
    unlink(sender_name);
    unlink(receiver_name);

    return 0;
}

void create_pipe(char *pipe_name) {
    mkfifo(pipe_name, 0666);
}

void write_message(int fd_out, char *message, int message_length) {
    write(fd_out, message, message_length);
}

void read_message(int fd_in, char *message, int message_length) {
    read(fd_in, message, message_length);
}