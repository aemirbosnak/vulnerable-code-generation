//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define PROC_DIR "/proc"
#define STATUS_FILE_SIZE 4096
#define LINE_BUFFER_SIZE 256

void print_process_info(pid_t pid) {
    char status_file_path[LINE_BUFFER_SIZE];
    snprintf(status_file_path, sizeof(status_file_path), "%s/%d/status", PROC_DIR, pid);

    FILE *file = fopen(status_file_path, "r");
    if (!file) {
        return;
    }

    char line[LINE_BUFFER_SIZE];
    printf("Process ID: %d\n", pid);
    while (fgets(line, sizeof(line), file)) {
        // Print relevant lines. Add filtering to retrieve only specific info.
        if (strncmp(line, "Name:", 5) == 0 || 
            strncmp(line, "State:", 6) == 0 || 
            strncmp(line, "VmSize:", 7) == 0 ||
            strncmp(line, "Uid:", 4) == 0) {
            printf("%s", line);
        }
    }
    fclose(file);
    printf("-------------------------------------------------------\n");
}

void list_processes() {
    DIR *dir = opendir(PROC_DIR);
    struct dirent *entry;

    if (!dir) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    printf("List of running processes:\n");
    printf("-------------------------------------------------------\n");

    while ((entry = readdir(dir)) != NULL) {
        // Check if the directory name is a number, which corresponds to a PID
        if (entry->d_type == DT_DIR) {
            pid_t pid = atoi(entry->d_name);
            if (pid > 0) {
                print_process_info(pid);
            }
        }
    }

    closedir(dir);
}

void display_usage() {
    printf("Usage: process_viewer\n");
    printf("This tool lists all currently running processes with their details.\n");
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        display_usage();
        return EXIT_FAILURE;
    }

    list_processes();
    return EXIT_SUCCESS;
}