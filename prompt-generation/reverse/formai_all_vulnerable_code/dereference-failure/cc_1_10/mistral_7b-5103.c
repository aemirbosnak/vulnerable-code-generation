//MISTRAL-7B DATASET v1.0 Category: Terminal Based Game ; Style: asynchronous
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <time.h>

#define BUF_SIZE 1024
#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

int random_number;
int guess;
int game_over = 0;

fd_set read_fds;
int max_fd;

void generate_random_number() {
    srand(time(NULL));
    random_number = rand() % 100 + 1;
}

void print_message(int message) {
    write(STDOUT_FILENO, message, strlen(message));
}

int main() {
    generate_random_number();

    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds);
    max_fd = STDIN_FILENO;

    while (!game_over) {
        struct timeval tv;
        int ret;

        tv.tv_usec = 0;
        tv.tv_sec = 1;

        ret = select(max_fd + 1, &read_fds, NULL, NULL, &tv);

        if (ret < 0) {
            if (errno != EINTR) {
                perror("select");
                exit(EXIT_FAILURE);
            }
            continue;
        }

        if (FD_ISSET(STDIN_FILENO, &read_fds)) {
            int bytes_read = read(STDIN_FILENO, &guess, sizeof(guess));

            if (bytes_read < 0) {
                perror("read");
                exit(EXIT_FAILURE);
            }

            if (bytes_read > 0) {
                if (guess > random_number) {
                    print_message("Too High\n");
                } else if (guess < random_number) {
                    print_message("Too Low\n");
                } else {
                    print_message("Congratulations! You guessed the number correctly.\n");
                    game_over = 1;
                }
            }
        }
    }

    return EXIT_SUCCESS;
}