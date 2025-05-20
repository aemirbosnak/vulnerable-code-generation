//FormAI DATASET v1.0 Category: System process viewer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PROCESS_NAME 1024

struct Process {
    int pid;
    char name[MAX_PROCESS_NAME];
    char state;
    int memory;
};

void display_process_info(struct Process process) {
    printf("\nPID: %d\nName: %s\nState: %c\nMemory: %d KB\n", process.pid, process.name, process.state, process.memory);
}

int main() {
    DIR *dir;
    struct dirent *dir_entry;
    char path[1024], line[1024], *end;

    printf("\n\nListing Running Processes...\n\n");

    dir = opendir("/proc");
    if (!dir) {
        printf("Error opening /proc directory!\n");
        exit(1);
    }

    while ((dir_entry = readdir(dir)) != NULL) {
        if (!(atoi(dir_entry->d_name))) {
            continue;
        }
        struct Process process;

        process.pid = atoi(dir_entry->d_name);

        sprintf(path, "/proc/%s/status", dir_entry->d_name);
        FILE *status_file = fopen(path, "r");
        if (!status_file) {
            printf("Error opening file %s\n", path);
            continue;
        }

        while (fgets(line, 1024, status_file)) {
            if (strncmp(line, "Name:", 5) == 0) {
                strcpy(process.name, line + 6);
                strtok(process.name, "\n");
            } 
            else if (strncmp(line, "State:", 6) == 0) {
                process.state = line[7];
            }
            else if (strncmp(line, "VmSize:", 7) == 0) {
                process.memory = strtol(line + 8, &end, 10);
            }
        }
        fclose(status_file);
        display_process_info(process);    
    }
    closedir(dir);
    return 0;
}