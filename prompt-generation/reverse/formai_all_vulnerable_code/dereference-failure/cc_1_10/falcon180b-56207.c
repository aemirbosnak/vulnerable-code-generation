//Falcon-180B DATASET v1.0 Category: System administration ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 80
#define MAX_COMMAND_LENGTH 1024

char* read_line(int fd) {
    char* line = malloc(MAX_LINE_LENGTH);
    char ch;
    int count = 0;

    while ((ch = getc(fd))!= '\n' && ch!= EOF) {
        if (count >= MAX_LINE_LENGTH) {
            printf("Error: Line too long.\n");
            exit(1);
        }
        line[count++] = ch;
    }
    line[count] = '\0';

    return line;
}

int main() {
    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1) {
        printf("Error creating pipe.\n");
        exit(1);
    }

    pid = fork();

    if (pid == -1) {
        printf("Error forking.\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        execlp("ls", "ls", "-l", NULL);
        printf("Error executing ls.\n");
        exit(1);
    } else {
        // Parent process
        close(fd[1]);
        char* line;
        while ((line = read_line(fd[0]))!= NULL) {
            printf("%s", line);
        }
        close(fd[0]);
        wait(NULL);
    }

    return 0;
}