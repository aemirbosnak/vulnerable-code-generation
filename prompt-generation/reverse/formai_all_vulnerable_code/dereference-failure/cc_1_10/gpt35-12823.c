//FormAI DATASET v1.0 Category: System process viewer ; Style: future-proof
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

#define PROCESS_SIZE 1024

typedef struct Process {
    char *pid;
    char *ppid;
    char *state;
    char *name;
} Process;

Process* read_process_info(char* pid) {
    Process* process = malloc(sizeof(Process));
    char fileInfo[100];
    snprintf(fileInfo, sizeof fileInfo, "/proc/%s/stat", pid);
    FILE* fp = fopen(fileInfo, "r");
    if (fp == NULL) {
        printf("Failed to open file for reading process information\n");
        exit(1);
    }
    fscanf(fp, "%s %s %s", process->pid, process->name, process->state);
    fclose(fp);
    process->ppid = malloc(sizeof(char));
    snprintf(fileInfo, sizeof fileInfo, "/proc/%s/status", pid);
    fp = fopen(fileInfo, "r");
    if (fp == NULL) {
        printf("Failed to open file for reading process information\n");
        exit(1);
    }
    char line[1024];
    while (fgets(line, sizeof line, fp) != NULL) {
        if (strncmp(line, "PPid:", 5) == 0) {
            char* ppidStart = &line[5];
            while (isspace(*ppidStart)) ppidStart++;
            char* ppidEnd = ppidStart;
            while (isdigit(*ppidEnd)) ppidEnd++;
            *ppidEnd = '\0';
            process->ppid = realloc(process->ppid, strlen(ppidStart) + 1);
            strcpy(process->ppid, ppidStart);
            break;
        }
    }
    fclose(fp);
    return process;
}

void display_process_info(Process* processes[], int processCount) {
    printf("\tPID   PPID  STATE   NAME\n");
    for (int i = 0; i < processCount; ++i) {
        printf("\t%s\t%s\t%s\t%s\n", processes[i]->pid,
               processes[i]->ppid,
               processes[i]->state,
               processes[i]->name);
    }
}

int main() {
    DIR* dir;
    struct dirent* ent;
    Process* processes[PROCESS_SIZE];
    int processCount = 0;
    if ((dir = opendir("/proc")) != NULL) {
        while ((ent = readdir(dir)) != NULL && processCount < PROCESS_SIZE) {
            if (isdigit(*ent->d_name)) {
                processes[processCount++] = read_process_info(ent->d_name);
            }
        }
        closedir(dir);
        display_process_info(processes, processCount);
    } else {
        printf("Failed to open /proc directory\n");
        exit(1);
    }
    for (int i = 0; i < processCount; ++i) {
        free(processes[i]->pid);
        free(processes[i]->ppid);
        free(processes[i]->state);
        free(processes[i]->name);
        free(processes[i]);
    }
    return 0;
}