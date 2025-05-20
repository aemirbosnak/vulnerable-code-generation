//FormAI DATASET v1.0 Category: System process viewer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PID_LENGTH 6
#define MAX_PROC_PATH_LENGTH 1024
#define MAX_LINE_LENGTH 1024

typedef struct {
    char pid[MAX_PID_LENGTH];
    char pname[MAX_LINE_LENGTH];
    char status[MAX_LINE_LENGTH];
} Process;

int isNumeric(char *string) {
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] < 48 || string[i] > 57) {
            return 0;
        }
    }

    return 1;
}

char *loadFile(char *path) {
    FILE *file;
    int fileLength;
    char *buffer;

    file = fopen(path, "r");
    if (file == NULL) {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    fileLength = ftell(file);
    fseek(file, 0, SEEK_SET);

    buffer = (char *) malloc(fileLength + 1);

    if (buffer) {
        fread(buffer, 1, fileLength, file);
        buffer[fileLength] = '\0';
    }

    fclose(file);

    return buffer;
}

Process parseProcess(char *pid) {
    Process process;

    strcpy(process.pid, pid);
    memset(process.pname, 0, sizeof(process.pname));
    memset(process.status, 0, sizeof(process.status));

    char procPath[MAX_PROC_PATH_LENGTH];
    strcpy(procPath, "/proc/");
    strcat(procPath, pid);

    char *statPath = (char *) malloc(strlen(procPath) + 6);
    strcpy(statPath, procPath);
    strcat(statPath, "/stat");

    char *statusPath = (char *) malloc(strlen(procPath) + 8);
    strcpy(statusPath, procPath);
    strcat(statusPath, "/status");

    char *statContents = loadFile(statPath);
    char *statusContents = loadFile(statusPath);

    if (statContents != NULL) {
        char *start = strchr(statContents, '(');
        char *end = strchr(statContents, ')');

        if (start != NULL && end != NULL) {
            *end = '\0';
            strcpy(process.pname, start + 1);
        }

        char *token = strtok(statContents, " ");
        for (int i = 1; i <= 3 && token != NULL; i++) {
            if (i == 3) {
                strcpy(process.status, token);
            }
            token = strtok(NULL, " ");
        }
    }

    if (statusContents != NULL) {
        char *pointer = statusContents;
        char line[MAX_LINE_LENGTH];

        while (fgets(line, MAX_LINE_LENGTH, pointer)) {
            if (strstr(line, "State:")) {
                char *start = strstr(line, "State:") + 7;
                char *end = start + 1;
                while (*end != '\n') {
                    end++;
                }

                *end = '\0';
                strcpy(process.status, start);
            }
        }
    }

    free(statContents);
    free(statusContents);
    free(statPath);
    free(statusPath);

    return process;
}

char **getProcesses() {
    DIR *dir;
    struct dirent *ent;
    char **pids = (char **) malloc(1 * sizeof(char *));

    int index = 0;
    if ((dir = opendir("/proc")) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (isNumeric(ent->d_name)) {
                char *pid = (char *) malloc(MAX_PID_LENGTH * sizeof(char));
                strcpy(pid, ent->d_name);
                pids[index++] = pid;
                pids = (char **) realloc(pids,(index + 1) * sizeof(char *));
            }
        }

        closedir(dir);
    } else {
        return NULL;
    }

    pids[index] = NULL;

    return pids;
}

int main() {
    char **pids = getProcesses();

    if (pids == NULL) {
        printf("Error: Could not retrieve list of processes\n");
        return 1;
    }

    printf("%-6s %-50s %s\n", "PID", "PROCESS NAME", "STATUS");

    char **pid = pids;
    while (*pid != NULL) {
        Process process = parseProcess(*pid);
        printf("%-6s %-50s %s\n", process.pid, process.pname, process.status);
        pid++;
    }

    return 0;
}