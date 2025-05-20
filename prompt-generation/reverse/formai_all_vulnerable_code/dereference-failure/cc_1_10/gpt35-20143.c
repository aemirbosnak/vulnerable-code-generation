//FormAI DATASET v1.0 Category: System process viewer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

struct ProcessListing {
    int pid;
    char name[255];
    char status;
    int memUsage; // in KBs
};

void printListing(struct ProcessListing pl) {
    printf("%-8d %-10s %-10c %-10d\n", pl.pid, pl.name, pl.status, pl.memUsage);
}

void getProcessListings(struct ProcessListing *plArr, int *numProcesses) {
    DIR *procDir;
    struct dirent *entry;
    char procPath[255], buffer[255], *end;

    procDir = opendir("/proc");
    if (procDir == NULL) {
        printf("Error opening /proc directory.\n");
        exit(1);
    }

    // loop through /proc directory
    while ((entry = readdir(procDir)) != NULL) {
        // check if entry is a directory whose name is all numbers (i.e., a process directory)
        int isDigitDir = 1;
        for (int i = 0; entry->d_name[i] != '\0'; i++) {
            if (!isdigit(entry->d_name[i])) {
                isDigitDir = 0;
                break;
            }
        }

        if (isDigitDir == 1) {
            strcpy(procPath, "/proc/");
            strcat(procPath, entry->d_name);
            strcat(procPath, "/");

            // get PID
            int pid = atoi(entry->d_name);

            // get process status
            strcpy(buffer, procPath);
            strcat(buffer, "status");
            FILE *statusFile = fopen(buffer, "r");
            if (statusFile != NULL) {
                while (fgets(buffer, 255, statusFile)) {
                    if (strncmp(buffer, "State:", 6) == 0) {
                        char status = buffer[7];
                        plArr[*numProcesses].status = status;
                        break;
                    }
                }
                fclose(statusFile);
            }

            // get process name
            strcpy(buffer, procPath);
            strcat(buffer, "comm");
            FILE *commFile = fopen(buffer, "r");
            if (commFile != NULL) {
                fgets(plArr[*numProcesses].name, 255, commFile);
                fclose(commFile);
            }

            // get process memory usage (in KBs)
            strcpy(buffer, procPath);
            strcat(buffer, "statm");
            FILE *statmFile = fopen(buffer, "r");
            if (statmFile != NULL) {
                fgets(buffer, 255, statmFile);
                end = strrchr(buffer, ' ') + 1;
                plArr[*numProcesses].memUsage = atoi(end);
                fclose(statmFile);
            }

            // add PID to struct
            plArr[*numProcesses].pid = pid;

            // increment number of processes
            (*numProcesses)++;
        }
    }

    closedir(procDir);
}

int main() {
    struct ProcessListing *procListings = malloc(sizeof(struct ProcessListing) * 1000);
    int numProcesses = 0;

    getProcessListings(procListings, &numProcesses);

    printf("%-8s %-10s %-10s %-10s\n", "PID", "NAME", "STATUS", "MEMORY");
    for (int i = 0; i < numProcesses; i++) {
        printListing(procListings[i]);
    }

    free(procListings);
    return 0;
}