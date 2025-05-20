//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <err.h>
#include <ctype.h>

#define MAX_SUBSCRIBERS 1000
#define LINE_LENGTH 256
#define SUBSCRIBERS_FILE "subscribers.txt"

struct subscriber {
    char name[LINE_LENGTH];
    int fd;
};

int main(int argc, char *argv[]) {
    int i, j, k, pid, status, fd, num_subscribers = 0;
    char line[LINE_LENGTH], cmd[LINE_LENGTH];
    struct subscriber subs[MAX_SUBSCRIBERS];

    fd = open(SUBSCRIBERS_FILE, O_RDONLY);
    if (fd < 0) {
        warn("Failed to open subscribers file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, LINE_LENGTH, fd) != NULL) {
        if (num_subscribers >= MAX_SUBSCRIBERS) {
            warn("Maximum number of subscribers reached");
            close(fd);
            exit(EXIT_FAILURE);
        }

        sscanf(line, "%s%n", subs[num_subscribers].name, &i);
        subs[num_subscribers].fd = open(subs[num_subscribers].name, O_WRONLY | O_CREAT, 0644);
        num_subscribers++;
    }

    close(fd);

    for (i = 0; i < num_subscribers; i++) {
        pid = fork();

        if (pid < 0) {
            warn("Fork failed");
            close(subs[i].fd);
            exit(EXIT_FAILURE);
        }

        if (pid == 0) { // Child process
            close(fd);
            execlp("/usr/lib/mailx", "mailx", subs[i].name, (char *)0);
            err(EXIT_FAILURE, "Failed to execute mailx");
        }

        wait(&status);
    }

    for (i = 0; i < num_subscribers; i++) {
        close(subs[i].fd);
    }

    return EXIT_SUCCESS;
}