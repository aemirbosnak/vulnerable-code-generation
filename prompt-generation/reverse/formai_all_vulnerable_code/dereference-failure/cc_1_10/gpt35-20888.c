//FormAI DATASET v1.0 Category: Interprocess communication ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

#define BUFFER_SIZE 1024

struct message {
    int id;
    char text[BUFFER_SIZE];
};

void signal_handler(int signal_number) {
    printf("Signal %d received. Exiting...\n", signal_number);
    exit(signal_number);
}

int main(int argc, char* argv[]) {

    signal(SIGINT, signal_handler);

    int id;
    char* message_text;

    if (argc == 3) {
        id = atoi(argv[1]);
        message_text = argv[2];
    } else {
        printf("USAGE: %s <ID> <MESSAGE>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create named pipe
    char pipe_name[100];
    snprintf(pipe_name, sizeof(pipe_name), "/tmp/%d.pipe", id);

    mkfifo(pipe_name, 0666);

    int pipe_fd = open(pipe_name, O_WRONLY);

    if (pipe_fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    struct message* msg = malloc(sizeof(struct message));
    msg->id = id;
    snprintf(msg->text, BUFFER_SIZE, "%s", message_text);

    int bytes_written = write(pipe_fd, msg, sizeof(struct message));

    if (bytes_written == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    printf("%d bytes written to pipe.\n", bytes_written);

    free(msg);

    close(pipe_fd);

    return 0;
}