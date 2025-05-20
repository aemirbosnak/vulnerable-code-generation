//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_RESPONSE_LENGTH 1024
#define DELAY 100000 // 100ms delay

char *command_buffer;
char *response_buffer;

void init() {
    command_buffer = malloc(MAX_COMMAND_LENGTH);
    response_buffer = malloc(MAX_RESPONSE_LENGTH);
    memset(command_buffer, 0, MAX_COMMAND_LENGTH);
    memset(response_buffer, 0, MAX_RESPONSE_LENGTH);
}

void execute_command(char *command) {
    pid_t pid;
    int fd[2];

    if (pipe(fd) == -1) {
        strcpy(response_buffer, "Error: Failed to create pipe\n");
        return;
    }

    pid = fork();

    if (pid == -1) {
        strcpy(response_buffer, "Error: Failed to fork\n");
        return;
    } else if (pid == 0) {
        dup2(fd[0], 0);
        close(fd[0]);
        close(fd[1]);
        execlp(command, command, NULL);
        exit(1);
    } else {
        close(fd[0]);
        write(fd[1], command, strlen(command));
        close(fd[1]);
        waitpid(pid, NULL, 0);
    }

    read(fd[0], response_buffer, MAX_RESPONSE_LENGTH);
    close(fd[0]);
}

int main() {
    init();

    while (1) {
        printf("Enter command: ");
        fgets(command_buffer, MAX_COMMAND_LENGTH, stdin);

        execute_command(command_buffer);

        printf("%s", response_buffer);
        memset(response_buffer, 0, MAX_RESPONSE_LENGTH);

        usleep(DELAY);
    }

    return 0;
}