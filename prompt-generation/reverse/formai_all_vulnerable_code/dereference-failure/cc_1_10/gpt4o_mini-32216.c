//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_PROCESS_NAME 256
#define MAX_PATH 512

void fetch_process_info(pid_t pid);
void display_processes();

int main() {
    printf("Process Viewer\n");
    printf("===================\n");
    display_processes();
    return 0;
}

void fetch_process_info(pid_t pid) {
    char path[MAX_PATH];
    FILE *status_file;
    char line[256];
    char name[MAX_PROCESS_NAME];
    long state;

    snprintf(path, sizeof(path), "/proc/%d/status", pid);
    status_file = fopen(path, "r");

    if (status_file == NULL) {
        return; // Process may have ended
    }

    while (fgets(line, sizeof(line), status_file)) {
        if (sscanf(line, "Name:\t%s", name) == 1) {
            continue;
        } else if (sscanf(line, "State:\t%d", &state) == 1) {
            break;
        }
    }

    fclose(status_file);
    
    // Display process information
    printf("PID: %d\tName: %s\tState: %ld\n", pid, name, state);
}

void display_processes() {
    DIR *proc_dir;
    struct dirent *entry;

    proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("opendir");
        return;
    }
    
    while ((entry = readdir(proc_dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            pid_t pid = atoi(entry->d_name);
            fetch_process_info(pid);
        }
    }

    closedir(proc_dir);
}