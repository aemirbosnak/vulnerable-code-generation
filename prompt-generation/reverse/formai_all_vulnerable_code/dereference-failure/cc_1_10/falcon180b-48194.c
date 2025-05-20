//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024
#define DELAY_TIME 100000 // 100ms

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    int pid;
    int status;
    int exit_code;
} process_t;

int num_processes = 0;
process_t processes[MAX_PROCESSES];

void launch_process(char* command) {
    int pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        execlp(command, command, NULL);
        perror("execlp");
        exit(1);
    } else {
        processes[num_processes].pid = pid;
        strcpy(processes[num_processes].command, command);
        num_processes++;
    }
}

void monitor_processes() {
    while (num_processes > 0) {
        sleep(DELAY_TIME);

        for (int i = 0; i < num_processes; i++) {
            if (waitpid(processes[i].pid, &processes[i].status, WNOHANG) > 0) {
                processes[i].exit_code = WEXITSTATUS(processes[i].status);
                num_processes--;
                i--;
            }
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s command [command...]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        launch_process(argv[i]);
    }

    monitor_processes();

    return 0;
}