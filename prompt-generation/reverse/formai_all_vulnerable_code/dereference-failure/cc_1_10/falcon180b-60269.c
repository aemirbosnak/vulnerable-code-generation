//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: beginner-friendly
// C System Boot Optimizer Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE_LEN 1024
#define MAX_PROCESSES 10
#define MAX_COMMAND_LEN 256

typedef struct {
    char command[MAX_COMMAND_LEN];
    int priority;
} process_t;

void read_config_file(char* filename, process_t* processes, int* num_processes) {
    FILE* fp;
    char line[MAX_LINE_LEN];
    char* token;
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open config file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        token = strtok(line, " ");
        strcpy(processes[i].command, token);
        processes[i].priority = atoi(strtok(NULL, " "));
        i++;
    }

    fclose(fp);

    *num_processes = i;
}

int launch_process(char* command, int priority) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error: could not fork process for command '%s'\n", command);
        return -1;
    } else if (pid == 0) {
        if (nice(priority) == -1) {
            fprintf(stderr, "Error: could not set priority for process '%s'\n", command);
            exit(1);
        }
        execlp(command, command, NULL);
        fprintf(stderr, "Error: could not execute process '%s'\n", command);
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        return 0;
    }
}

int main(int argc, char* argv[]) {
    process_t processes[MAX_PROCESSES];
    int num_processes;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <config_file>\n", argv[0]);
        exit(1);
    }

    read_config_file(argv[1], processes, &num_processes);

    for (int i = 0; i < num_processes; i++) {
        launch_process(processes[i].command, processes[i].priority);
    }

    return 0;
}