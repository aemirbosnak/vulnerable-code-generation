//FormAI DATASET v1.0 Category: System process viewer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void printHeader() {
    printf("%-20s %-10s %-15s\n", "PROCESS NAME", "PID", "MEMORY");
    printf("----------------------------------------\n");
}

void printProcessInfo(char* procName, int pid, float memory) {
    printf("%-20s %-10d %-15.2fMB\n", procName, pid, memory);
}

int main() {

    printHeader();

    DIR* procdir = opendir("/proc");

    if (procdir == NULL) {
        printf("Error opening /proc directory\n");
        exit(1);
    }

    struct dirent* ent;

    while ((ent = readdir(procdir))) {
        // Check if the entry is a directory and its name is a number (i.e. it's a process)
        if (ent->d_type == DT_DIR && atoi(ent->d_name)) {
            char procPath[50];
            sprintf(procPath, "/proc/%s/status", ent->d_name);

            FILE* procfile = fopen(procPath, "r");

            if (procfile == NULL) {
                printf("Error opening file /proc/%s/status\n", ent->d_name);
                continue;
            }

            char line[256];
            char procName[50];
            int pid = atoi(ent->d_name);
            float memory;

            while (fgets(line, sizeof(line), procfile)) {

                // Get process name
                if (strncmp(line, "Name:", 5) == 0) {
                    strcpy(procName, line + 6);
                    procName[strlen(procName) - 1] = '\0'; // Remove trailing newline
                }

                // Get memory usage
                if (strncmp(line, "VmRSS:", 6) == 0) {
                    char* memString = line + 7;
                    memory = atoi(memString) / 1024.0; // Convert from KB to MB
                }

            }

            fclose(procfile);

            printProcessInfo(procName, pid, memory);
        }
    }

    closedir(procdir);

    return 0;
}