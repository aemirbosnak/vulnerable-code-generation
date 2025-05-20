//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>

#define BUFFSIZE 1024

void print_usage(char *argv[]) {
    printf("Usage: %s <pid>\n", argv[0]);
    printf("Example: %s 1234\n", argv[0]);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv);
        return EXIT_FAILURE;
    }

    pid_t pid = atoi(argv[1]);
    char path[BUFFSIZE];
    snprintf(path, sizeof(path), "/proc/%d/stat", pid);

    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    char buf[BUFFSIZE];
    ssize_t bytes_read = read(fd, buf, sizeof(buf));
    if (bytes_read == -1) {
        perror("read");
        close(fd);
        return EXIT_FAILURE;
    }

    close(fd);

    char *fields[100];
    int num_fields = 0;

    char *field = strtok(buf, " ");
    while (field != NULL) {
        fields[num_fields++] = field;
        field = strtok(NULL, " ");
    }

    printf("Process %s:\n", fields[0]);
    printf("State: %s\n", fields[2]);
    printf("PPID: %s\n", fields[3]);
    printf("Memory: %s kB\n", fields[23]);
    printf("CPU time: %s s\n", fields[14]);

    return EXIT_SUCCESS;
}