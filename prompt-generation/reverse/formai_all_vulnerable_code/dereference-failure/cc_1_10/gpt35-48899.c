//FormAI DATASET v1.0 Category: System process viewer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_PATH_SIZE 1024
#define MAX_ARGS_SIZE 1024
#define MAX_LINE_SIZE 4096

typedef struct process {
    char pid[10];
    char name[MAX_ARGS_SIZE];
    char state[5];
    char ppid[10];
} Process;

void printHeader() {
    printf("%-10s %-20s %-10s %-10s\n", "PID", "NAME", "STATE", "PPID");
}

void printProcess(Process* process) {
    printf("%-10s %-20s %-10s %-10s\n", process->pid, process->name, process->state, process->ppid);
}

void trim(char* s) {
    int i;

    i = strlen(s) - 1;
    while (isspace(s[i])) {
        i--;
    }
    s[i + 1] = '\0';

    i = 0;
    while (isspace(s[i])) {
        i++;
    }
    memmove(s, &s[i], strlen(&s[i]) + 1);
}

void parseCmdLine(char* cmdLine, Process* process) {
    char* token = strtok(cmdLine, " ");

    int count = 0;
    while (token != NULL) {
        if (count == 0) {
            strcpy(process->name, token);
        } else if (count == 1) {
            trim(token);
            strcpy(process->state, token);
        }
        token = strtok(NULL, " ");
        count++;
    }
}

void getProcessInfo(char* pid, Process* process) {
    char path[MAX_PATH_SIZE];
    sprintf(path, "/proc/%s/status", pid);

    FILE* file = fopen(path, "r");
    char line[MAX_LINE_SIZE];

    while (fgets(line, MAX_LINE_SIZE, file) != NULL) {
        if (strncmp(line, "Name:", 5) == 0) {
            trim(&line[5]);
            strcpy(process->name, &line[5]);
        } else if (strncmp(line, "State:", 6) == 0) {
            trim(&line[6]);
            strcpy(process->state, &line[6]);
        } else if (strncmp(line, "PPid:", 5) == 0) {
            trim(&line[5]);
            strcpy(process->ppid, &line[5]);
        }
    }

    fclose(file);
}

void listProcesses() {
    DIR* dir;
    struct dirent* ent;

    dir = opendir("/proc");

    if (dir == NULL) {
        perror("Could not open /proc directory");
        return;
    }

    printHeader();

    while ((ent = readdir(dir)) != NULL) {
        if (isdigit(*ent->d_name)) {
            char pid[10];
            strcpy(pid, ent->d_name);

            Process process;
            strcpy(process.pid, pid);

            getProcessInfo(pid, &process);
            printProcess(&process);
        }
    }

    closedir(dir);
}

int main(int argc, char* argv[]) {
    pid_t pid;
    pid = getpid();

    printf("Process viewer (PID: %d)\n", pid);

    listProcesses();

    return 0;
}