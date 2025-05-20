//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <wait.h>
#include <signal.h>

#define MAX_PROCESSES 50

typedef struct {
    int pid;
    int status;
    char *name;
    char *cmdline;
} process_t;

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0) {
        printf("A process has terminated.\n");
    }
}

void print_processes(process_t *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("%d - %s (%s)\n", processes[i].pid, processes[i].name, processes[i].cmdline);
    }
}

int main() {
    signal(SIGCHLD, sigchld_handler);

    int num_processes = 0;
    process_t *processes = malloc(MAX_PROCESSES * sizeof(process_t));

    while (num_processes < MAX_PROCESSES) {
        int status;
        pid_t pid;
        struct stat st;
        char *cmdline = NULL;
        size_t bufsize = 0;

        pid = waitpid(-1, &status, WNOHANG);
        if (pid == 0) {
            break;
        }

        if (pid < 0) {
            perror("waitpid");
            exit(1);
        }

        if (WIFEXITED(status)) {
            printf("Process %d terminated with exit code %d.\n", pid, WEXITSTATUS(status));
            num_processes--;
            continue;
        }

        snprintf(processes[num_processes].name, 32, "Process %d", pid);
        if (stat(processes[num_processes].name, &st) == -1) {
            perror("stat");
            exit(1);
        }

        bufsize = st.st_size + 1;
        cmdline = malloc(bufsize);
        if (readlink(processes[num_processes].name, cmdline, bufsize) == -1) {
            perror("readlink");
            exit(1);
        }

        processes[num_processes].cmdline = cmdline;
        num_processes++;
    }

    print_processes(processes, num_processes);

    free(processes);
    return 0;
}