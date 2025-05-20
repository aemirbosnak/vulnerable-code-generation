//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

#define SIZE 100
#define SEED 1337

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(void) {
    int i, j, k, fd;
    char filename[SIZE];
    char buf[SIZE];
    char *args[] = {"/usr/bin/sh", "-c", "echo", "hello, world!"};
    pid_t pid;

    srand(SEED);

    printf("Generating random file name...\n");
    snprintf(filename, SIZE, "/tmp/%x%x%x.txt", (int)rand() % 16, (int)rand() % 16, (int)rand() % 16);

    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd < 0) die("open");

    printf("Writing to file: %s\n", filename);

    for (i = 0; i < 10; i++) {
        gettimeofday(&(struct timeval){.tv_sec = rand() % 60, .tv_usec = rand() % 1000000}, NULL);
        snprintf(buf, SIZE, "%d-%02d-%02d %02d:%02d:%02d.%06d\n", rand() % 31, rand() % 13, rand() % 12, rand() % 24, rand() % 60, rand() % 60, rand() % 1000000);
        write(fd, buf, strlen(buf));
    }

    close(fd);

    printf("Forking a child process...\n");
    pid = fork();

    if (pid < 0) die("fork");

    if (pid > 0) {
        wait(NULL);
        unlink(filename);
        exit(EXIT_SUCCESS);
    }

    if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}