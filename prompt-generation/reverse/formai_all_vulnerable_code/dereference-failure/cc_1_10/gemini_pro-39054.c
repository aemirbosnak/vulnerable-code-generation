//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <dirent.h>

#define MAX_BUF 512

// Function to get process information
void get_process_info(int pid, char *buf) {
    FILE *fp;
    char path[MAX_BUF];
    sprintf(path, "/proc/%d/stat", pid);
    fp = fopen(path, "r");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }
    fgets(buf, MAX_BUF, fp);
    fclose(fp);
}

// Function to parse process information
void parse_process_info(char *buf, int *pid, char *name, int *state, int *ppid) {
    // Parse the process ID
    *pid = atoi(strtok(buf, " "));

    // Parse the process name
    strcpy(name, strtok(NULL, " "));

    // Parse the process state
    char *state_str = strtok(NULL, " ");
    switch (state_str[0]) {
        case 'R':
            *state = 0; // Running
            break;
        case 'S':
            *state = 1; // Sleeping
            break;
        case 'D':
            *state = 2; // Uninterruptible sleep
            break;
        case 'Z':
            *state = 3; // Zombie
            break;
        default:
            *state = -1; // Unknown
            break;
    }

    // Parse the parent process ID
    *ppid = atoi(strtok(NULL, " "));
}

int main() {
    // Get system information
    struct sysinfo info;
    sysinfo(&info);

    // Print system information
    printf("System Information:\n");
    printf("Total RAM: %ld MB\n", info.totalram / 1024);
    printf("Free RAM: %ld MB\n", info.freeram / 1024);
    printf("Total processes: %d\n", info.procs);
    printf("\n");

    // Get process list
    DIR *dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir");
        exit(1);
    }

    // Loop through process list
    struct dirent *ent;
    while ((ent = readdir(dir)) != NULL) {
        // Check if the entry is a directory
        if (ent->d_type == DT_DIR) {
            // Get process ID
            int pid = atoi(ent->d_name);

            // Get process information
            char buf[MAX_BUF];
            get_process_info(pid, buf);

            // Parse process information
            int state, ppid;
            char name[MAX_BUF];
            parse_process_info(buf, &pid, name, &state, &ppid);

            // Print process information
            printf("Process ID: %d\n", pid);
            printf("Process Name: %s\n", name);
            printf("Process State: ");
            switch (state) {
                case 0:
                    printf("Running\n");
                    break;
                case 1:
                    printf("Sleeping\n");
                    break;
                case 2:
                    printf("Uninterruptible sleep\n");
                    break;
                case 3:
                    printf("Zombie\n");
                    break;
                default:
                    printf("Unknown\n");
                    break;
            }
            printf("Parent Process ID: %d\n", ppid);
            printf("\n");
        }
    }

    closedir(dir);

    return 0;
}