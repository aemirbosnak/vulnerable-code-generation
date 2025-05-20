//FormAI DATASET v1.0 Category: System process viewer ; Style: authentic
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESS_NAME_LEN 255
#define MAX_STAT_FILE_LINE_LEN 1024

struct ProcessInfo {
    int pid;
    char name[MAX_PROCESS_NAME_LEN];
};

void parseStatFile(const char *fileName, struct ProcessInfo *process) {
    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        perror("Error opening stat file");
        exit(1);
    }

    char line[MAX_STAT_FILE_LINE_LEN];

    if (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d (%[^)])", &(process->pid), process->name);
    }

    fclose(file);
}

void getProcessList(struct ProcessInfo *processList, int *numProcesses) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir("/proc");

    if (dir == NULL) {
        perror("opendir() failed");
        exit(1);
    }

    *numProcesses = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            int pid = atoi(entry->d_name);
            if (pid != 0) {
                char fileName[512];
                snprintf(fileName, sizeof(fileName), "/proc/%d/stat", pid);
                parseStatFile(fileName, &(processList[*numProcesses]));
                (*numProcesses)++;
            }
        }
    }

    closedir(dir);
}

int main() {
    struct ProcessInfo processList[1024];
    int numProcesses;

    getProcessList(processList, &numProcesses);

    printf("PID\tName\n");
    printf("===\t====\n");

    for (int i = 0; i < numProcesses; i++) {
        printf("%d\t%s\n", processList[i].pid, processList[i].name);
    }

    return 0;
}