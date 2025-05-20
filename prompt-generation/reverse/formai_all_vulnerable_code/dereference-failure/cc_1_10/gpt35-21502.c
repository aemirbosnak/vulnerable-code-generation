//FormAI DATASET v1.0 Category: System process viewer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

void printTable(int* pidArr, int* ppidArr, char** nameArr, int* runningArr, int len) {
    // Print header
    printf("	 PID	 	PPID	 	NAME    	  RUNNING\n");
    printf("==============================================================\n");

    // Print process info
    for (int i = 0; i < len; i++) {
        printf("	%4d		%4d		%10s     %3s\n", pidArr[i], ppidArr[i], nameArr[i], runningArr[i] ? "YES" : "NO");
    }
}

int main() {
    DIR *dir;
    struct dirent *ent;
    char path[] = "/proc";
    char statusPath[256];
    int pid, ppid, running;
    char name[256];
    int pidArr[1000], ppidArr[1000], runningArr[1000];
    char* nameArr[1000];
    int i = 0;

    // Read proc directory
    if ((dir = opendir(path)) != NULL) {

        // Read all directory entries
        while ((ent = readdir(dir)) != NULL) {

            // Check if entry is a process directory
            if ((pid = atoi(ent->d_name))) {

                // Read process status file
                sprintf(statusPath, "%s/%d/status", path, pid);
                FILE* statusFile = fopen(statusPath, "r");

                if (statusFile) {

                    // Read status file line by line
                    char line[256], name[256];
                    while (fgets(line, sizeof(line), statusFile)) {

                        // Parse process name
                        if (sscanf(line, "Name:\t%s", name) == 1) {
                            nameArr[i] = strdup(name);
                        }

                        // Parse process parent PID
                        if (sscanf(line, "PPid:\t%d", &ppid) == 1) {
                            ppidArr[i] = ppid;
                        }
                    }

                    fclose(statusFile);

                    // Check if process is running
                    sprintf(statusPath, "%s/%d/stat", path, pid);
                    FILE* statFile = fopen(statusPath, "r");

                    if (statFile) {

                        fgets(line, sizeof(line), statFile);

                        // Parse running status
                        running = 0;
                        char* c = line;
                        int count = 0;
                        while (*c) {
                            if (*c == '(' || count == 1) {
                                count = 1;
                                if (*c == ')') {
                                    break;
                                }
                            } else if (count == 0 && isdigit(*c)) {
                                running = 1;
                                break;
                            }
                            c++;
                        }
                        runningArr[i] = running;

                        fclose(statFile);
                    }

                    // Add to process table
                    pidArr[i++] = pid;
                }
            }
        }

        closedir(dir);

        // Print process table
        printTable(pidArr, ppidArr, nameArr, runningArr, i);

    } else {
        perror ("Cannot open directory");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}