//FormAI DATASET v1.0 Category: System process viewer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

int is_number(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

void get_process_info(const char *pid) {
    char path[BUFFER_SIZE];
    sprintf(path, "/proc/%s/status", pid);

    FILE *fp = fopen(path, "r");

    if (fp == NULL) {
        printf("Error: process %s does not exist\n", pid);
        return;
    }

    char line[BUFFER_SIZE];
    char uid[BUFFER_SIZE], gid[BUFFER_SIZE], vmsize[BUFFER_SIZE], vmrss[BUFFER_SIZE];

    while (fgets(line, BUFFER_SIZE, fp)) {
        if (strstr(line, "Uid:")) {
            sscanf(line, "Uid:\t%s", uid);
        } else if (strstr(line, "Gid:")) {
            sscanf(line, "Gid:\t%s", gid);
        } else if (strstr(line, "VmSize:")) {
            sscanf(line, "VmSize:\t%s", vmsize);
        } else if (strstr(line, "VmRSS:")) {
            sscanf(line, "VmRSS:\t%s", vmrss);
        }
    }

    fclose(fp);

    char username[BUFFER_SIZE];
    char *lineptr = NULL;
    size_t n = 0;
    sprintf(path, "/etc/passwd");

    fp = fopen(path, "r");

    while (getline(&lineptr, &n, fp) > 0) {
        char *tok = strtok(lineptr, ":");
        if (strcmp(tok, uid) == 0) {
            strcpy(username, strtok(NULL, ":"));
            break;
        }
    }

    fclose(fp);
    free(lineptr);

    printf("%7s %16s %16s %10s %10s\n", pid, username, gid, vmsize, vmrss);
}

int main() {
    DIR *dir = opendir("/proc");
    if (dir == NULL) {
        printf("Error: Cannot open /proc directory\n");
        return 1;
    }

    printf("%7s %16s %16s %10s %10s\n", "PID", "USERNAME", "GID", "VMSIZE", "VMRSS");

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (is_number(entry->d_name)) {
            get_process_info(entry->d_name);
        }
    }

    closedir(dir);

    return 0;
}