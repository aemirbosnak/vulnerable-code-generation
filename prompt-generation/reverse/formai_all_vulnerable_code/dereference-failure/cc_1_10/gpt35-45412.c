//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024
#define PAGE_SIZE 4096

char buffer[BUFFER_SIZE];
int pid;

void sigHandler(int signum) {
    printf("\nCaught signal %d\n", signum);
    printf("Killing process with pid %d\n", pid);
    kill(pid, SIGKILL);
    exit(1);
}

void printMemoryUsage() {
    char *path = (char *) malloc(sizeof(char) * 20);
    sprintf(path, "/proc/%d/statm", pid);
    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        printf("Error opening file\n");
        return;
    }
    read(fd, buffer, BUFFER_SIZE);
    close(fd);

    int current = atoi(strtok(buffer, " "));
    int rss = atoi(strtok(NULL, " ")) * PAGE_SIZE;

    printf("Current Memory Usage: %dKB\n", current * PAGE_SIZE / 1024);
    printf("Resident Set Size: %dKB\n", rss / 1024);

    free(path);
}

int main(int argc, char const *argv[]) {

    if (argc != 2) {
        printf("Usage: ./ram_monitor <pid>\n");
        exit(1);
    }

    pid = atoi(argv[1]);

    signal(SIGINT, sigHandler);
    signal(SIGTERM, sigHandler);
    signal(SIGQUIT, sigHandler);

    while (1) {
        printMemoryUsage();
        sleep(5);
    }

    return 0;
}