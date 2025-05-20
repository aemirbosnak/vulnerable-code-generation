//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE_SIZE 1024
#define MAX_PROCESSES 100

typedef struct process {
    pid_t pid;
    char name[MAX_LINE_SIZE];
    int status;
} Process;

int get_processes(Process *processes, int num_processes) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    FILE *file = popen("ps -ax", "r");

    if (file == NULL) {
        printf("Failed to run 'ps -ax'\n");
        return 1;
    }

    while ((read = getline(&line, &len, file))!= -1) {
        int i = 0;
        char *token;
        Process process;

        token = strtok(line, " ");
        process.pid = atoi(token);

        token = strtok(NULL, " ");
        strncpy(process.name, token, MAX_LINE_SIZE);

        token = strtok(NULL, " ");
        process.status = atoi(token);

        if (i < num_processes) {
            processes[i] = process;
            i++;
        }
    }

    pclose(file);

    return 0;
}

void print_processes(Process *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("%d - %s - %d\n", processes[i].pid, processes[i].name, processes[i].status);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    if (get_processes(processes, MAX_PROCESSES)!= 0) {
        return 1;
    }

    num_processes = get_processes(processes, MAX_PROCESSES);

    printf("Process Viewer\n");
    printf("================\n");
    print_processes(processes, num_processes);

    return 0;
}