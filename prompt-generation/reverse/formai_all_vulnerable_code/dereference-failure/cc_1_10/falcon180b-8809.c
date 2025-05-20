//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 1000
#define MAX_PROCESS_NAME 20

typedef struct {
    int pid;
    char process_name[MAX_PROCESS_NAME];
    int ram_usage;
} Process;

int get_process_count() {
    FILE *fp;
    char line[100];
    int count = 0;

    fp = popen("ps aux | grep -v grep | wc -l", "r");

    if (fp == NULL) {
        return -1;
    }

    if (fgets(line, sizeof(line), fp)!= NULL) {
        count = atoi(line);
    }

    pclose(fp);

    return count;
}

int get_process_info(int pid, char *process_name, int *ram_usage) {
    FILE *fp;
    char line[100];
    char *token;

    sprintf(line, "ps -p %d -o %%mem=", pid);

    fp = popen(line, "r");

    if (fp == NULL) {
        return -1;
    }

    if (fgets(line, sizeof(line), fp)!= NULL) {
        *ram_usage = atoi(line);
    } else {
        return -1;
    }

    token = strtok(line, " ");
    strcpy(process_name, token);

    pclose(fp);

    return 0;
}

void print_process_info(Process *processes, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d | %s | %d%%\n", processes[i].pid, processes[i].process_name, processes[i].ram_usage);
    }
}

int main() {
    int count;
    Process processes[MAX_PROCESSES];

    count = get_process_count();

    if (count < 0) {
        printf("Error: Cannot get process count.\n");
        return 1;
    }

    if (count > MAX_PROCESSES) {
        printf("Error: Too many processes.\n");
        return 1;
    }

    printf("Process ID | Process Name | RAM Usage\n");
    for (int i = 0; i < count; i++) {
        get_process_info(i, processes[i].process_name, &processes[i].ram_usage);
    }

    print_process_info(processes, count);

    return 0;
}