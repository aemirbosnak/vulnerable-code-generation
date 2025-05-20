//FormAI DATASET v1.0 Category: System process viewer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PROC_PATH 256
#define MAX_PROC_FILE 1024
#define MAX_BUF_LEN 1024

// Function to check if a string is numeric
int is_numeric(char* str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to extract process info from the proc file
void extract_process_info(char* file_path) {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int pid;
    char comm[MAX_BUF_LEN];
    char state;
    char* ppid;
    char* pgrp;
    char* session;

    fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Could not open file: %s\n", file_path);
        return;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strncmp(line, "Pid:", 4) == 0) {
            pid = atoi(line + 4);
        } else if (strncmp(line, "Name:", 5) == 0) {
            strncpy(comm, line + 5, strlen(line) - 6);
            comm[strlen(line) - 6] = '\0';
            printf("Process Name: %s\n", comm);
        } else if (strncmp(line, "State:", 6) == 0) {
            state = line[7];
            printf("Process State: %c\n", state);
        } else if (strncmp(line, "PPid:", 5) == 0 && is_numeric(line + 5)) {
            ppid = line + 5;
            printf("Parent PID: %s\n", ppid);
        } else if (strncmp(line, "Pgrp:", 5) == 0 && is_numeric(line + 5)) {
            pgrp = line + 5;
            printf("Process Group ID: %s\n", pgrp);
        } else if (strncmp(line, "Session:", 8) == 0 && is_numeric(line + 8)) {
            session = line + 8;
            printf("Session ID: %s\n", session);
        }
    }

    fclose(fp);
    if (line) {
        free(line);
    }
}

// Function to traverse the proc directory and extract process info for each valid process
void process_directory() {
    DIR* proc_dir;
    struct dirent* entry;
    char path[MAX_PROC_PATH];

    proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        printf("Could not open /proc directory.\n");
        return;
    }

    while ((entry = readdir(proc_dir)) != NULL) {
        if (is_numeric(entry->d_name)) {
            sprintf(path, "/proc/%s/status", entry->d_name);
            extract_process_info(path);
        }
    }

    closedir(proc_dir);
}

// Main function
int main() {
    printf("------- Process Viewer -------\n");
    process_directory();
    return 0;
}