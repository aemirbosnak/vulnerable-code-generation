//FormAI DATASET v1.0 Category: System process viewer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

void printProcDetails(char *pid) {
    char filename[512];
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *p;
    FILE *fp;

    snprintf(filename, sizeof(filename), "/proc/%s/status", pid);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        return;
    }

    printf("PID: %s\n", pid);
    while ((read = getline(&line, &len, fp)) != -1) {
        if (strncmp(line, "Name:", 5) == 0) {
            p = line + 6;
            while (*p && isspace(*p)) ++p;
            printf("Name: %s", p);
        } else if (strncmp(line, "State:", 6) == 0) {
            p = line + 7;
            while (*p && isspace(*p)) ++p;
            printf("State: %s", p);
        } else if (strncmp(line, "PPid:", 5) == 0) {
            p = line + 6;
            while (*p && isspace(*p)) ++p;
            printf("Parent PID: %s", p);
        }
    }

    fclose(fp);
    if (line) {
        free(line);
    }
}

void printAllProc() {
    DIR *dir;
    struct dirent *ent;
    char *pid;

    dir = opendir("/proc");
    if (dir == NULL) {
        printf("Error reading /proc directory");
        return;
    }

    while ((ent = readdir(dir))) {
        pid = ent->d_name;
        if (!isdigit(*pid)) {
            continue;
        }
        printProcDetails(pid);
        printf("\n");
    }

    closedir(dir);
}

int main() {
    printf("Process Details:\n");
    printAllProc();
    return 0;
}