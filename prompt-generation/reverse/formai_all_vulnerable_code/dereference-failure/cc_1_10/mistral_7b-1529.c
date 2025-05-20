//MISTRAL-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/select.h>
#include <fcntl.h>

#define MAX_FD 1024
#define BUF_SIZE 1024

struct Input {
    int fd;
    char buffer[BUF_SIZE];
};

void handle_input(struct Input *input) {
    memset(input->buffer, 0, BUF_SIZE);
    ssize_t bytes_read = read(input->fd, input->buffer, BUF_SIZE);
    if (bytes_read <= 0) {
        close(input->fd);
        free(input);
        return;
    }

    // Process user input
    printf("User: %s", input->buffer);
    // ...
}

int main() {
    int master_fd = STDIN_FILENO;
    int max_fd = master_fd;
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(master_fd, &read_fds);

    while (1) {
        int ready_fds = select(max_fd + 1, &read_fds, NULL, NULL, NULL);
        if (ready_fds < 0) {
            perror("Error in select()");
            return 1;
        }

        if (FD_ISSET(master_fd, &read_fds)) {
            struct Input *input = malloc(sizeof(struct Input));
            input->fd = accept(master_fd, NULL, NULL);
            FD_SET(input->fd, &read_fds);
            handle_input(input);
        }

        int i;
        for (i = 0; i <= max_fd && i < MAX_FD; i++) {
            if (FD_ISSET(i, &read_fds)) {
                struct Input *input = (struct Input *) malloc(sizeof(struct Input));
                input->fd = i;
                handle_input(input);
                free(input);
                close(i);
            }
        }
    }

    return 0;
}