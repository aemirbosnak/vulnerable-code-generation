//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_BUF 1024
#define PROC_DIR "/proc"

void display_process_info(const char *pid) {
    char path[MAX_BUF];
    char line[MAX_BUF];
    FILE *status_file;
    char name[MAX_BUF];
    int pid_num;

    // Construct the path to the status file
    snprintf(path, sizeof(path), "%s/%s/status", PROC_DIR, pid);
    
    // Open the status file for reading
    status_file = fopen(path, "r");
    if (status_file) {
        while (fgets(line, sizeof(line), status_file)) {
            if (strncmp(line, "Name:", 5) == 0) {
                sscanf(line + 5, "%s", name);
            } else if (strncmp(line, "Pid:", 4) == 0) {
                sscanf(line + 4, "%d", &pid_num);
            }
        }
        fclose(status_file);
        printf("PID: %d, Name: %s\n", pid_num, name);
    }
}

void list_processes() {
    struct dirent *entry;
    DIR *dir = opendir(PROC_DIR);

    if (dir == NULL) {
        perror("Could not open /proc directory");
        exit(EXIT_FAILURE);
    }

    printf("Listing all running processes:\n");
    
    while ((entry = readdir(dir)) != NULL) {
        // Check if the entry is a number (pid)
        if (isdigit(entry->d_name[0])) {
            display_process_info(entry->d_name);
        }
    }

    closedir(dir);
}

void print_usage() {
    printf("Usage: proc_viewer [options]\n");
    printf("Options:\n");
    printf("  -h, --help    Display this help message\n");
    printf("  -v, --version Show version information\n");
}

void print_version() {
    printf("Process Viewer Version 1.0\n");
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            print_usage();
            return 0;
        } else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
            print_version();
            return 0;
        }
    }

    list_processes();
    return 0;
}