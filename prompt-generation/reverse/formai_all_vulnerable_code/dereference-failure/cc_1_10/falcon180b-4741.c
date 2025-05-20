//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAX_PROCESSES 1024
#define MAX_COMMAND_LENGTH 256

typedef struct {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
    int status;
} process_t;

process_t processes[MAX_PROCESSES];
int num_processes = 0;

void add_process(pid_t pid, char* command) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Too many processes\n");
        return;
    }

    process_t* new_process = &processes[num_processes];
    new_process->pid = pid;
    strncpy(new_process->command, command, MAX_COMMAND_LENGTH);
    new_process->status = -1;

    num_processes++;
}

void remove_process(pid_t pid) {
    int i;
    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            memmove(&processes[i], &processes[i+1], sizeof(process_t) * (num_processes - i - 1));
            num_processes--;
            break;
        }
    }
}

void update_process_status(pid_t pid, int status) {
    int i;
    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            processes[i].status = status;
            break;
        }
    }
}

void print_processes() {
    printf("PID\tCommand\tStatus\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].command, processes[i].status);
    }
}

int main() {
    FILE* fp;
    char line[1024];
    char* token;

    fp = popen("ps aux", "r");
    if (fp == NULL) {
        printf("Error: Failed to execute ps\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, " ");
        pid_t pid = atoi(token);
        token = strtok(NULL, " ");
        char* command = strdup(token);

        add_process(pid, command);
    }

    pclose(fp);

    while (1) {
        print_processes();
        sleep(1);
    }

    return 0;
}