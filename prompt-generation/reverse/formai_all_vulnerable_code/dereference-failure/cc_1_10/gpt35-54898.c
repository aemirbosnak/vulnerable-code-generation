//FormAI DATASET v1.0 Category: System process viewer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define PROCESS_DIR "/proc"

int is_number(const char* str) {
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int is_process_dir(const struct dirent* dir) {
    if(dir == NULL || !is_number(dir->d_name)) {
        return 0;
    }

    char path[256];
    snprintf(path, sizeof(path), "%s/%s", PROCESS_DIR, dir->d_name);

    struct stat st;
    if(stat(path, &st) == -1) {
        return 0;
    }

    return S_ISDIR(st.st_mode);
}

void print_process_info(const char* pid) {
    char path[256];
    snprintf(path, sizeof(path), "%s/%s/status", PROCESS_DIR, pid);

    FILE* fp = fopen(path, "r");
    if(fp == NULL) {
        return;
    }

    char line[256];
    printf("\nProcess Information:\n\n");
    while(fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }
    fclose(fp);
}

int main() {
    printf("Paranoid Process Viewer\n");

    while(1) {
        struct dirent** namelist;

        int n = scandir(PROCESS_DIR, &namelist, is_process_dir, alphasort);

        if(n == -1) {
            printf("\nError: Could not open process directory.\n");
            return -1;
        }

        printf("\n\n%-10s %-10s %-25s\n", "PID", "Status", "Name");
        for(int i = 0; i < n; i++) {
            char path[256];
            snprintf(path, sizeof(path), "%s/%s/status", PROCESS_DIR, namelist[i]->d_name);

            FILE* fp = fopen(path, "r");
            if(fp == NULL) {
                continue;
            }

            char line[256];
            char pid[10] = "";
            char status[20] = "";
            char name[100] = "";

            while(fgets(line, sizeof(line), fp) != NULL) {
                if(strncmp(line, "Pid:", 4) == 0) {
                    sscanf(line + 5, "%s", pid);
                }
                else if(strncmp(line, "State:", 6) == 0) {
                    sscanf(line + 7, "%s", status);
                }
                else if(strncmp(line, "Name:", 5) == 0) {
                    sscanf(line + 6, "%s", name);
                }
            }
            fclose(fp);

            printf("%-10s %-10s %-25s\n", pid, status, name);
        }

        printf("\nEnter the PID of the process to view details: ");
        char pid[10];
        fgets(pid, sizeof(pid), stdin);

        pid[strcspn(pid, "\n")] = 0;

        if(!is_number(pid)) {
            printf("\nError: PID must be a number.\n");
            continue;
        }

        print_process_info(pid);
    }

    return 0;
}