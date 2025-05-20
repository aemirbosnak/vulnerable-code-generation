//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024

typedef struct {
    pid_t pid;
    int status;
    char command[MAX_COMMAND_LENGTH];
} Process;

int num_processes = 0;
Process processes[MAX_PROCESSES];

void launch_process(const char* command) {
    int fd[2];
    if (pipe(fd) == -1) {
        fprintf(stderr, "Failed to create pipe: %s\n", strerror(errno));
        return;
    }

    pid_t pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Failed to fork: %s\n", strerror(errno));
        close(fd[0]);
        close(fd[1]);
        return;
    } else if (pid == 0) {
        // Child process
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);

        execlp(command, command, NULL);
        fprintf(stderr, "Failed to execute '%s': %s\n", command, strerror(errno));
        exit(1);
    } else {
        // Parent process
        close(fd[1]);
        processes[num_processes].pid = pid;
        strncpy(processes[num_processes].command, command, MAX_COMMAND_LENGTH);
        num_processes++;
    }
}

void wait_for_processes() {
    for (int i = 0; i < num_processes; i++) {
        waitpid(processes[i].pid, &processes[i].status, 0);
    }
}

void print_process_info() {
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d: %s\n", processes[i].pid, processes[i].command);
        printf("Exit status: %d\n", processes[i].status);
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    launch_process("ls");
    launch_process("sleep 1");
    launch_process("sleep 2");
    launch_process("sleep 3");

    wait_for_processes();

    print_process_info();

    return 0;
}