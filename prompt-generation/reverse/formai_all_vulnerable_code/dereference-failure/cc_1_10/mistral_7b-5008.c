//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define LOG_FILE "error.log"

void log_error(const char *msg, int errnum) {
    FILE *log_fp = fopen(LOG_FILE, "a");
    if (log_fp == NULL) {
        perror("Failed to open error.log for writing");
        exit(EXIT_FAILURE);
    }

    fprintf(log_fp, "%s: Error %d - %s\n", msg, errnum, strerror(errnum));
    fclose(log_fp);
}

void handler_sigsegv(int signal) {
    log_error("Received SIGSEGV", errno);
    write(STDOUT_FILENO, "Caught SIGSEGV, terminating...\n", strlen("Caught SIGSEGV, terminating...\n"));
    exit(EXIT_FAILURE);
}

int main() {
    char input[MAX_INPUT_SIZE];
    int fd, status;
    pid_t pid;
    struct stat st;

    signal(SIGSEGV, handler_sigsegv);

    if (strlen(getenv("INPUT")) > MAX_INPUT_SIZE) {
        log_error("Input is too long", EINVAL);
        exit(EXIT_FAILURE);
    }

    strcpy(input, getenv("INPUT"));

    if (strcmp(input, "echo") != 0) {
        fd = open("echo", O_RDONLY);
        if (fd < 0) {
            log_error("Failed to open echo as read-only binary", errno);
            exit(EXIT_FAILURE);
        }

        pid = fork();

        if (pid < 0) {
            log_error("Fork failed", errno);
            exit(EXIT_FAILURE);
        }

        if (pid > 0) {
            close(fd);
            wait(&status);
            exit(EXIT_SUCCESS);
        }

        if (dup2(fd, STDIN_FILENO) < 0) {
            log_error("Failed to duplicate file descriptor for echo input", errno);
            exit(EXIT_FAILURE);
        }

        close(fd);

        execlp("echo", "echo", NULL);

        log_error("Failed to execute echo", errno);
        exit(EXIT_FAILURE);
    }

    printf("You entered 'echo'\n");

    fd = open("/dev/random", O_RDONLY);
    if (fd < 0) {
        log_error("Failed to open /dev/random for reading", errno);
        exit(EXIT_FAILURE);
    }

    read(fd, input, MAX_INPUT_SIZE);

    printf("You entered: %s\n", input);

    close(fd);

    exit(EXIT_SUCCESS);
}