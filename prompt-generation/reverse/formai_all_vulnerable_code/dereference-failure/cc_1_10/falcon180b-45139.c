//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_SIZE 100
#define MAX_PROCESSES 5

int main() {
    int fd[2];
    pid_t child_pid;
    int status;
    pid_t pids[MAX_PROCESSES];
    int i;
    for (i = 0; i < MAX_PROCESSES; i++) {
        pids[i] = 0;
    }

    if (pipe(fd) == -1) {
        printf("Pipe Failed\n");
        return 1;
    }

    pid_t parent_pid = getpid();

    // create child processes
    for (i = 0; i < MAX_PROCESSES; i++) {
        child_pid = fork();
        if (child_pid == 0) {
            close(fd[0]);
            break;
        } else if (child_pid > 0) {
            pids[i] = child_pid;
            close(fd[1]);
        } else {
            printf("Fork Failed\n");
            return 1;
        }
    }

    // parent writes to pipe
    char buffer[MAX_SIZE];
    sprintf(buffer, "Hello from parent process %d\n", parent_pid);
    write(fd[1], buffer, strlen(buffer));
    close(fd[1]);

    // parent reads from pipe
    char read_buffer[MAX_SIZE];
    read(fd[0], read_buffer, MAX_SIZE);
    printf("Parent received: %s", read_buffer);

    for (i = 0; i < MAX_PROCESSES; i++) {
        if (pids[i] > 0) {
            waitpid(pids[i], &status, 0);
        }
    }

    return 0;
}