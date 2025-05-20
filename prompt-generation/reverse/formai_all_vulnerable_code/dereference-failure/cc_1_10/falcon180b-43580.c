//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

#define MAX_PROCESSES 100
#define MAX_LINE_LENGTH 1024
#define MAX_COMMAND_LENGTH 4096

typedef struct {
    int pid;
    char command[MAX_COMMAND_LENGTH];
} process_t;

void print_processes(process_t *processes, int num_processes) {
    printf("PID\tCommand\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <interval>\n", argv[0]);
        return 1;
    }

    int interval = atoi(argv[1]);
    int num_processes = 0;
    process_t *processes = malloc(MAX_PROCESSES * sizeof(process_t));

    while (1) {
        num_processes = 0;
        processes[num_processes++] = (process_t) {.pid = 0,.command = "System Idle Process" };
        char *line = NULL;
        size_t len = 0;
        FILE *file = popen("ps aux", "r");
        if (file == NULL) {
            perror("popen");
            exit(1);
        }

        while (getline(&line, &len, file)!= -1) {
            if (num_processes >= MAX_PROCESSES) {
                break;
            }

            char *token = strtok(line, " ");
            int pid = atoi(token);
            char *command = strtok(NULL, "\n");

            if (command == NULL) {
                continue;
            }

            strncpy(processes[num_processes].command, command, MAX_COMMAND_LENGTH - 1);
            processes[num_processes].command[MAX_COMMAND_LENGTH - 1] = 0;
            processes[num_processes++].pid = pid;
        }

        pclose(file);
        print_processes(processes, num_processes);
        sleep(interval);
    }

    free(processes);
    return 0;
}