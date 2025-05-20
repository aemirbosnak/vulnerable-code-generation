//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define MAX_PROCESSES 100

struct process {
    pid_t pid;
    int status;
    char cmd[1024];
};

int num_processes = 0;
struct process processes[MAX_PROCESSES];

void add_process(pid_t pid) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Maximum number of processes reached.\n");
        return;
    }

    struct stat stat_buf;
    char cmd_link[1024];
    sprintf(cmd_link, "/proc/%d/cmdlink", pid);

    int fd = open(cmd_link, O_RDONLY);
    if (fd == -1) {
        printf("Error opening cmdlink for process %d: %s\n", pid, strerror(errno));
        return;
    }

    if (readlink(cmd_link, processes[num_processes].cmd, sizeof(processes[num_processes].cmd)) == -1) {
        printf("Error reading cmdlink for process %d: %s\n", pid, strerror(errno));
        close(fd);
        return;
    }

    close(fd);

    processes[num_processes].pid = pid;
    processes[num_processes].status = 0;
    num_processes++;
}

void remove_process(pid_t pid) {
    int i;
    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            processes[i].status = 1;
            break;
        }
    }
}

void print_processes() {
    printf("PID\tCommand\n");
    for (int i = 0; i < num_processes; i++) {
        if (processes[i].status == 0) {
            printf("%d\t%s\n", processes[i].pid, processes[i].cmd);
        }
    }
}

int main() {
    int status;
    pid_t pid;

    while (1) {
        print_processes();

        pid = wait(&status);
        if (pid == -1) {
            if (errno == ECHILD) {
                printf("No more processes.\n");
                break;
            } else {
                printf("Error waiting for process: %s\n", strerror(errno));
            }
            continue;
        }

        remove_process(pid);

        if (WIFEXITED(status)) {
            printf("%d exited with status %d.\n", pid, WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("%d killed by signal %d.\n", pid, WTERMSIG(status));
        } else {
            printf("%d stopped by signal %d.\n", pid, WSTOPSIG(status));
        }

        add_process(pid);
    }

    return 0;
}