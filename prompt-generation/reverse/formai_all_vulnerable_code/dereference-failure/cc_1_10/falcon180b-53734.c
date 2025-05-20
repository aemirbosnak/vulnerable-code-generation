//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Dennis Ritchie
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <ctype.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <sys/statvfs.h>

#define MAX_PROCESSES 1024
#define MAX_COMMAND_LENGTH 1024

typedef struct {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
    int status;
} Process;

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0)
        ;
}

void print_processes(Process processes[], int num_processes) {
    printf("PID\tCommand\tStatus\n");
    for (int i = 0; i < num_processes; i++) {
        if (processes[i].status == -1) {
            printf("%d\t%s\tZombie\n", processes[i].pid, processes[i].command);
        } else {
            printf("%d\t%s\t%d\n", processes[i].pid, processes[i].command, processes[i].status);
        }
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    signal(SIGCHLD, sigchld_handler);

    while (1) {
        printf("Current Processes:\n");
        print_processes(processes, num_processes);

        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            char input[MAX_COMMAND_LENGTH];
            printf("Enter command: ");
            fgets(input, MAX_COMMAND_LENGTH, stdin);

            char *token = strtok(input, " ");
            strcpy(processes[num_processes].command, token);

            processes[num_processes].pid = getpid();
            processes[num_processes].status = 0;

            num_processes++;

            execlp("/bin/bash", "bash", "-c", input, NULL);
            perror("execlp");
            exit(1);
        } else {
            int status;
            waitpid(pid, &status, WUNTRACED);

            for (int i = 0; i < num_processes; i++) {
                if (processes[i].pid == pid) {
                    processes[i].status = status;
                    break;
                }
            }
        }
    }

    return 0;
}