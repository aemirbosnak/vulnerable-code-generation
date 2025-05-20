//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>

#define PROC_DIR "/proc"
#define BUFFER_SIZE 256

void display_process_info(pid_t pid) {
    char path[BUFFER_SIZE];
    char line[BUFFER_SIZE];
    FILE *file;

    snprintf(path, sizeof(path), "/proc/%d/stat", pid);
    file = fopen(path, "r");
    
    if (!file) {
        perror("fopen");
        return;
    }
    
    fscanf(file, "%d %s", &pid, line);
    printf("PID: %d | Command: %s\n", pid, line);
    fclose(file);
}

void scan_processes() {
    struct dirent *entry;
    DIR *dp = opendir(PROC_DIR);
    
    if (!dp) {
        perror("opendir");
        return;
    }
    
    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_DIR) {
            pid_t pid = atoi(entry->d_name);
            if (pid > 0) { // valid PID found
                display_process_info(pid);
            }
        }
    }
    
    closedir(dp);
}

void show_help() {
    printf("Process Viewer - A Cryptic Insight into Your Processes\n");
    printf("Usage: ./process_viewer [OPTIONS]\n");
    printf("OPTIONS:\n");
    printf("  -h, --help    Show this help message\n");
    printf("  -v, --version Show version info\n");
}

void version_info() {
    printf("Process Viewer v1.0 - An Insightful Glimpse\n");
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            show_help();
            exit(0);
        } else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
            version_info();
            exit(0);
        } else {
            printf("Unknown option: %s\n", argv[1]);
            show_help();
            exit(1);
        }
    }
    
    printf("Scanning Processes...\n");
    scan_processes();
    printf("Done.\n");
    return 0;
}