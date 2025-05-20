//Falcon-180B DATASET v1.0 Category: System administration ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_LINE_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    char log_file[256];
    strcpy(log_file, argv[1]);

    int log_fd = open(log_file, O_RDONLY);
    if (log_fd == -1) {
        perror("open");
        return 1;
    }

    char buffer[MAX_LINE_SIZE];
    while (fgets(buffer, MAX_LINE_SIZE, log_fd)!= NULL) {
        char *line = strtok(buffer, "\n");
        if (line == NULL) {
            continue;
        }

        char *ip = strtok(line, " ");
        if (ip == NULL) {
            continue;
        }

        char *date = strtok(NULL, " ");
        if (date == NULL) {
            continue;
        }

        char *time = strtok(NULL, " ");
        if (time == NULL) {
            continue;
        }

        char *request = strtok(NULL, " ");
        if (request == NULL) {
            continue;
        }

        printf("%s - - [%s %s] \"%s\" %d\n", ip, date, time, request, strlen(request));
    }

    close(log_fd);
    return 0;
}