//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_PROCESSES 100

typedef struct {
    int pid;
    char name[64];
    int status;
} process_t;

process_t processes[MAX_PROCESSES];
int num_processes = 0;

void add_process(int pid, char *name) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Maximum processes reached\n");
        return;
    }
    processes[num_processes].pid = pid;
    strncpy(processes[num_processes].name, name, 64);
    processes[num_processes].status = 0;
    num_processes++;
}

void remove_process(int pid) {
    int i;
    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            processes[i] = processes[--num_processes];
            break;
        }
    }
}

void update_process_status(int pid, int status) {
    int i;
    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            processes[i].status = status;
            break;
        }
    }
}

void print_processes() {
    int i;
    for (i = 0; i < num_processes; i++) {
        printf("%d - %s - %d\n", processes[i].pid, processes[i].name, processes[i].status);
    }
}

int main() {
    char input[1024];
    while (1) {
        printf("> ");
        fgets(input, 1024, stdin);
        if (strcmp(input, "exit\n") == 0) {
            break;
        }
        char *token = strtok(input, " ");
        int pid = atoi(token);
        token = strtok(NULL, " ");
        strcpy(processes[pid].name, token);
        add_process(pid, processes[pid].name);
    }
    return 0;
}