//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_CHAR 256
#define MAX_LINES 10

void reverse(char *str, int start, int end) {
    char temp;
    for (; start < end; start++, end--) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
    }
}

void read_file(char *filename) {
    int fd;
    char filecontent[MAX_CHAR];
    char line[MAX_CHAR];

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        printf("Error opening file.\n");
        return;
    }

    int i = 0;
    while (fgets(line, sizeof(line), fd) != NULL) {
        strcpy(filecontent + i, line);
        i += strlen(line) + 1;
    }

    close(fd);

    reverse(filecontent, 0, i - 1);

    fd = open(filename, O_WRONLY);
    write(fd, filecontent, i);
    close(fd);
}

void main() {
    char *args[] = {"./reverser", "--file", "input.txt"};
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        printf("Error forking process.\n");
        exit(1);
    } else if (pid > 0) {
        wait(NULL);
        remove("input.txt");
    } else {
        read_file("input.txt");
        exit(0);
    }

    execvp(args[0], args);
    printf("Error executing %s.\n", args[0]);
    exit(1);
}