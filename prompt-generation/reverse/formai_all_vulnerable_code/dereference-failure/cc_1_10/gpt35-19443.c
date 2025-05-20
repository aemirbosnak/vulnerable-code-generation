//FormAI DATASET v1.0 Category: System process viewer ; Style: real-life
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_SIZE 1024

int isNumber(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (!isdigit(str[i++])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    DIR *dir = opendir("/proc");
    if (!dir) {
        perror("Failed to open /proc directory");
        return EXIT_FAILURE;
    }

    struct dirent *entry;
    char pid[MAX_SIZE];
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR && isNumber(entry->d_name)) {
            strcpy(pid, entry->d_name);
            char path[MAX_SIZE];
            sprintf(path, "/proc/%s/status", pid);
            FILE *f = fopen(path, "r");
            if (f == NULL) {
                continue;
            }

            char line[MAX_SIZE];
            char name[MAX_SIZE];
            int ppid = 0;
            int pgrp = 0;
            int sid = 0;
            int tty_nr = 0;
            int utime = 0;
            int stime = 0;

            while (fgets(line, MAX_SIZE, f)) {
                char *token = strtok(line, ":");
                if (strcmp(token, "Name") == 0) {
                    token = strtok(NULL, ":");
                    strcpy(name, token);
                    strtok(name, "\n");
                }
                else if (strcmp(token, "PPid") == 0) {
                    token = strtok(NULL, ":");
                    ppid = atoi(token);
                }
                else if (strcmp(token, "PGRP") == 0) {
                    token = strtok(NULL, ":");
                    pgrp = atoi(token);
                }
                else if (strcmp(token, "Session ID") == 0) {
                    token = strtok(NULL, ":");
                    sid = atoi(token);
                }
                else if (strcmp(token, "tty_nr") == 0) {
                    token = strtok(NULL, ":");
                    tty_nr = atoi(token);
                }
                else if (strcmp(token, "utime") == 0) {
                    token = strtok(NULL, ":");
                    utime = atoi(token);
                }
                else if (strcmp(token, "stime") == 0) {
                    token = strtok(NULL, ":");
                    stime = atoi(token);
                }
            }

            fclose(f);

            char state_path[MAX_SIZE];
            sprintf(state_path, "/proc/%s/stat", pid);
            f = fopen(state_path, "r");
            if (f == NULL) {
                continue;
            }

            char state[MAX_SIZE];
            char dummy;
            int ppid2;
            int pgrp2;
            int sid2;
            int tty_nr2;
            int utime2;
            int stime2;
            int num_threads;

            fscanf(f, "%s %c %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", 
                state, &dummy, &ppid2, &pgrp2, &sid2, &tty_nr2, &dummy, 
                &dummy, &dummy, &dummy, &dummy, &dummy, &dummy, &dummy, 
                &dummy, &dummy, &dummy, &num_threads);
                
            utime2 = utime / sysconf(_SC_CLK_TCK);
            stime2 = stime / sysconf(_SC_CLK_TCK);

            printf("Process ID: %s\n", pid);
            printf("Name: %s\n", name);
            printf("State: %s\n", state);
            printf("Parent Process ID: %d\n", ppid);
            printf("Group ID: %d\n", pgrp);
            printf("Session ID: %d\n", sid);
            printf("Controlling Terminal: tty%d\n", tty_nr);
            printf("Threads: %d\n", num_threads);
            printf("User CPU Time: %d seconds\n", utime2);
            printf("System CPU Time: %d seconds\n", stime2);

            fclose(f);
        }
    }

    closedir(dir);

    return EXIT_SUCCESS;
}