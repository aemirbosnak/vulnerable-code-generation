//FormAI DATASET v1.0 Category: System process viewer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

// function to parse and extract values from "/proc/<pid>/stat" file
void parse_proc_stat_file(const char* path, int* pid, char* name, char* state, char* command) {
    FILE* fp;
    char buf[1024];

    fp = fopen(path, "r");
    fgets(buf, 1024, fp);

    fclose(fp);

    char* pch;
    pch = strtok(buf, " ");

    *pid = atoi(pch);
    pch = strtok(NULL, " ");

    strcpy(name, pch);
    pch = strtok(NULL, " ");

    strcpy(state, pch);
    pch = strtok(NULL, " ");

    for (int i = 0; i < 18; i++) {
        pch = strtok(NULL, " ");
    }

    strcpy(command, pch);
}

// function to print the process list
void print_process_list() {
    DIR* dir;
    struct dirent* entry;
    char path[1024], state[10], name[256], command[256];
    int pid;

    printf("%-5s %-20s %-10s %-50s\n", "PID", "NAME", "STATE", "COMMAND");
    dir = opendir("/proc");
    if (!dir) {
        printf("Failed to open /proc directory.\n");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] < '0' || entry->d_name[0] > '9') {
            continue;
        }

        snprintf(path, 1024, "/proc/%s/stat", entry->d_name);
        parse_proc_stat_file(path, &pid, name, state, command);

        // filter out kernel threads
        if (pid == getpid() || strcmp(command, "systemd") == 0) {
            continue;
        }

        printf("%-5d %-20s %-10s %-50s\n", pid, name, state, command);
    }

    closedir(dir);
}

// main function
int main() {
    printf("Process Viewer\n");
    printf("============================\n");
    printf("PID   NAME                 STATE     COMMAND\n");
    printf("-----------------------------------------------\n");
    print_process_list();
    
    return 0;
}