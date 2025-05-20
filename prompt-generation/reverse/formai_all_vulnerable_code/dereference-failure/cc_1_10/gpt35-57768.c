//FormAI DATASET v1.0 Category: System process viewer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_PROC_PATH_LENGTH 1024

typedef struct {
    char *pid;
    char *name;
    char *state;
    char *mem;
} ProcessInfo;

void printProcessInfo(ProcessInfo *info);
void parseStatFile(char *statFilePath, ProcessInfo *info);
char *trimWhitespace(char *str);

int main() {
    DIR *procDir;
    struct dirent *entry;
    char procPath[MAX_PROC_PATH_LENGTH];
    ProcessInfo info;
    memset(&info, 0, sizeof(info));

    printf("%-10s %-20s %-10s %-10s\n", "PID", "NAME", "STATE", "MEMORY");

    procDir = opendir("/proc");
    while ((entry = readdir(procDir))) {
        if (isdigit(*entry->d_name)) {
            sprintf(procPath, "/proc/%s/stat", entry->d_name);
            parseStatFile(procPath, &info);
            if (info.pid != NULL) {
                printProcessInfo(&info);
                free(info.pid);
                free(info.name);
                free(info.state);
                free(info.mem);
            }
            memset(&info, 0, sizeof(info));
        }
    }
    closedir(procDir);
    return 0;
}

void printProcessInfo(ProcessInfo *info) {
    printf("%-10s %-20s %-10s %-10s\n", info->pid, info->name, info->state, info->mem);
}

void parseStatFile(char *statFilePath, ProcessInfo *info) {
    FILE *statFile;
    char lineBuffer[MAX_BUFFER_SIZE];
    char *token;
    int tokenCount = 0;
    char *pid, *name, *state, *mem;

    statFile = fopen(statFilePath, "r");
    if (statFile == NULL) {
        return;
    }

    fgets(lineBuffer, MAX_BUFFER_SIZE, statFile);
    fclose(statFile);

    // extract pid, name, state, mem
    token = strtok(lineBuffer, " ");
    while (token != NULL && tokenCount < 23) {
        tokenCount++;
        switch (tokenCount) {
            case 1:
                pid = strdup(token);
                break;
            case 2:
                name = strdup(token);
                break;
            case 3:
                state = strdup(token);
                break;
            case 23:
                mem = strdup(token);
                break;
        }
        token = strtok(NULL, " ");
    }

    // trim whitespace for name and state
    name = trimWhitespace(name);
    state = trimWhitespace(state);

    // set values in info struct
    info->pid = pid;
    info->name = name;
    info->state = state;
    info->mem = mem;
}

char *trimWhitespace(char *str) {
    char *end;
    while (isspace(*str)) {
        str++;
    }
    if (*str == 0) {
        return str;
    }
    end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) {
        end--;
    }
    *(end + 1) = 0;
    return str;
}