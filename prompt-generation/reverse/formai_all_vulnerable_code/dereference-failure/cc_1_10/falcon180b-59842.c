//Falcon-180B DATASET v1.0 Category: System administration ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_PROCESSES 10

int process_count = 0;
int process_id[MAX_PROCESSES];

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0) {
        for (int i = 0; i < MAX_PROCESSES; i++) {
            if (process_id[i] == -1) {
                process_id[i] = waitpid(-1, NULL, WNOHANG);
                break;
            }
        }
    }
}

int launch_process(char *command) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        char **args = NULL;
        args = malloc(sizeof(char *));
        args[0] = command;
        execvp(args[0], args);
        perror("execvp");
        exit(1);
    } else {
        process_id[process_count] = pid;
        process_count++;
        return pid;
    }
}

int main() {
    signal(SIGCHLD, sigchld_handler);

    char *commands[] = {"ls", "-l", "/", NULL};

    for (int i = 0; i < MAX_PROCESSES; i++) {
        process_id[i] = -1;
    }

    for (int i = 0; i < MAX_PROCESSES; i++) {
        int pid = launch_process(commands[i]);
        printf("Launched process with id %d\n", pid);
    }

    while (process_count > 0) {
        sleep(1);
    }

    return 0;
}