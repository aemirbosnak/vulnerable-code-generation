//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 1024

typedef struct {
    int pid;
    char name[1024];
    int cpu_usage;
    int memory_usage;
} process_t;

int get_process_info(process_t *processes, int count) {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    char *token;
    int i = 0;

    fp = popen("ps aux", "r");

    if (fp == NULL) {
        return -1;
    }

    while (fgets(buffer, BUFFER_SIZE, fp)!= NULL) {
        if (i >= count) {
            break;
        }

        token = strtok(buffer, " ");
        processes[i].pid = atoi(token);

        token = strtok(NULL, " ");
        strcpy(processes[i].name, token);

        token = strtok(NULL, " ");
        processes[i].cpu_usage = atoi(token);

        token = strtok(NULL, " ");
        processes[i].memory_usage = atoi(token);

        i++;
    }

    pclose(fp);

    return i;
}

void print_processes(process_t *processes, int count) {
    int i;

    for (i = 0; i < count; i++) {
        printf("%d. %s\n", processes[i].pid, processes[i].name);
        printf("\tCPU Usage: %d%%\n", processes[i].cpu_usage);
        printf("\tMemory Usage: %d KB\n\n", processes[i].memory_usage);
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int count;

    count = get_process_info(processes, MAX_PROCESSES);
    print_processes(processes, count);

    return 0;
}