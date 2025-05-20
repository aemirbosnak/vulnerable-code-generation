//FormAI DATASET v1.0 Category: System process viewer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define STATM_PATH "/proc/%d/statm"

void printProcessInfo(const char *pid) {
    char path[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];
    struct dirent *entry = NULL;
    DIR *dir = opendir("/proc");
    int pidInt = atoi(pid);
    sprintf(path, STATM_PATH, pidInt);
    FILE *statmFile = fopen(path, "r");
     
    if (statmFile == NULL) {
        printf("Process %s does not exist\n", pid);
        return;
    }

    long long size, resident, shared;
    fscanf(statmFile, "%lld %lld %lld", &size, &resident, &shared);
    fclose(statmFile);

    printf("Process %s:\n", pid);
    printf("  Size: %lld\n", size);
    printf("  Resident: %lld\n", resident);
    printf("  Shared: %lld\n", shared);

    while ((entry = readdir(dir)) != NULL) {
        if (!isdigit(entry->d_name[0])) {
            continue;
        }

        int pidValue = atoi(entry->d_name);
        if (pidValue != pidInt) {
            continue;
        }

        sprintf(path, "/proc/%s/status", entry->d_name);
        FILE *statusFile = fopen(path, "r");

        if (statusFile == NULL) {
            continue;
        }

        int nameLength = 0;
        while (fgets(buffer, BUFFER_SIZE, statusFile)) {
            if (strncmp(buffer, "Name:", 5) == 0) {
                nameLength = strlen(buffer + 5) - 1;
            }

            if (strncmp(buffer, "State:", 6) == 0) {
                printf("  State: %s\n", buffer + 6);
            } else if (strncmp(buffer, "VmSize:", 7) == 0) {
                int vmSize = atoi(buffer + 7) / 1024;
                printf("  Virtual Memory Size: %d MB\n", vmSize);
            } else if (strncmp(buffer, "VmRSS:", 6) == 0) {
                int vmRSS = atoi(buffer + 6) / 1024;
                printf("  Resident Set Size: %d MB\n", vmRSS);
            } else if (strncmp(buffer, "Threads:", 8) == 0) {
                printf("  Threads: %s", buffer + 8);
            }
        }

        printf("  Name: %*s", nameLength, "");
        rewind(statusFile);
        while (fgets(buffer, BUFFER_SIZE, statusFile)) {
            if (strncmp(buffer, "Name:", 5) == 0) {
                printf("%s", buffer + 5);
            }
        }

        fclose(statusFile);
        break;
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <pid>\n", argv[0]);
        return 0;
    }

    printProcessInfo(argv[1]);

    return 0;
}