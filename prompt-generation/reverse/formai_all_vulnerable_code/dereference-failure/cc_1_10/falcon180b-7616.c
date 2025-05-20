//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/time.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024

typedef struct {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
    int status;
    int exit_code;
    struct timeval start_time;
    struct timeval end_time;
} Process;

void print_processes(Process processes[], int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("%d - %s (%d)\n", processes[i].pid, processes[i].command, processes[i].exit_code);
    }
}

int compare_processes(const void *a, const void *b) {
    const Process *p1 = a;
    const Process *p2 = b;
    return strcmp(p1->command, p2->command);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [process name]\n", argv[0]);
        return 1;
    }

    char command[MAX_COMMAND_LENGTH];
    strcpy(command, argv[1]);

    pid_t pid = fork();
    if (pid == -1) {
        printf("Error forking process\n");
        return 1;
    } else if (pid == 0) {
        execlp(command, command, NULL);
        printf("Error executing process\n");
        return 1;
    } else {
        int status;
        waitpid(pid, &status, 0);
        printf("Process %d finished with status %d\n", pid, status);
        return 0;
    }
}