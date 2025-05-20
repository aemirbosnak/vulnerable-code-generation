//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>

#define PROC_DIR "/proc"
#define STATUS_FILE "status"

typedef struct {
    pid_t pid;
    char name[256];
    char state[16];
} ProcessInfo;

void parse_status_file(const char *filename, ProcessInfo *info) {
    FILE *file = fopen(filename, "r");
    if (!file) return;
    
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "Pid:\t%d", &info->pid) == 1) continue;
        if (sscanf(line, "Name:\t%s", info->name) == 1) continue;
        if (sscanf(line, "State:\t%s", info->state) == 1) continue;
    }
    fclose(file);
}

void display_process_info(ProcessInfo *info) {
    printf("PID: %d\n", info->pid);
    printf("Name: %s\n", info->name);
    printf("State: %s\n", info->state);
    printf("------------------------------------\n");
}

void fetch_processes() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(PROC_DIR);
    if (!dir) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            ProcessInfo info = {0};
            char path[512];
            snprintf(path, sizeof(path), "%s/%s/%s", PROC_DIR, entry->d_name, STATUS_FILE);
            parse_status_file(path, &info);
            display_process_info(&info);
        }
    }

    closedir(dir);
}

int main() {
    printf("=== Linux Process Viewer ===\n");
    printf("Collecting process information...\n");
    fetch_processes();
    return 0;
}