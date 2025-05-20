//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_PROCESSES 50

typedef struct {
    int pid;
    char name[64];
    int state;
} Process;

void print_processes(Process *processes, int num_processes) {
    printf("PID\tName\tState\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].state);
    }
}

int get_process_info(Process *processes, int num_processes) {
    FILE *fp;
    char line[128];
    int count = 0;

    fp = popen("ps aux", "r");
    if (fp == NULL) {
        printf("Error: Failed to run ps command.\n");
        return -1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (count >= num_processes) {
            break;
        }

        char *token = strtok(line, " ");
        int pid = atoi(token);
        strcpy(processes[count].name, token);
        processes[count].pid = pid;
        processes[count].state = 0;

        count++;
    }

    pclose(fp);

    return count;
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    while (1) {
        num_processes = get_process_info(processes, MAX_PROCESSES);
        if (num_processes < 0) {
            exit(1);
        }

        print_processes(processes, num_processes);
        sleep(5);
    }

    return 0;
}