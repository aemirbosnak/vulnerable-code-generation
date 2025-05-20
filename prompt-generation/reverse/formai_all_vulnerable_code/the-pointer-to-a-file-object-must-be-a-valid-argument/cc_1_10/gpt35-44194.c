//FormAI DATASET v1.0 Category: System process viewer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

void showProcessInfo(pid_t pid) {
    char path[50], line[100];
    FILE *file;
    sprintf(path, "/proc/%d/status", pid);
    file = fopen(path, "r");
    printf("\nProcess Information for Process ID: %d\n\n", pid);
    while (fgets(line, 100, file)) {
        if (strncmp(line, "Name:", 5) == 0) {
            printf("Process Name: %s\n", &line[6]);
        }
        else if (strncmp(line, "State:", 6) == 0) {
            printf("Process State: %s", &line[7]);
        }
        else if (strncmp(line, "VmSize:", 7) == 0) {
            printf("Virtual Memory Size: %s", &line[8]);
        }
    }
    fclose(file);
}

int main() {
    DIR *dir;
    struct dirent *dirEntry;
    int pid, count = 0;
    char statusPath[50];
    printf("List of Running Processes on System:\n\n");
    dir = opendir("/proc/");
    if (!dir) {
        printf("Error: Unable to access '/proc' directory.\n");
        return 0;
    }
    while ((dirEntry = readdir(dir)) != NULL) {
        if (isdigit(dirEntry->d_name[0])) {
            pid = atoi(dirEntry->d_name);
            sprintf(statusPath, "/proc/%d/status", pid);
            if (access(statusPath, F_OK) != -1) {
                showProcessInfo(pid);
                count++;
            }
        }
    }
    printf("\nTotal Number of Running Processes: %d\n", count);
    closedir(dir);
    return 0;
}