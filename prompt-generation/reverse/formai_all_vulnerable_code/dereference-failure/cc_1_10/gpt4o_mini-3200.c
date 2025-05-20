//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define PROC_DIR "/proc"
#define BUF_SIZE 256

void print_process_info(int pid) {
    char path[BUF_SIZE], buffer[BUF_SIZE];
    FILE *status_file;

    // Construct the path to the process's status file
    snprintf(path, sizeof(path), "%s/%d/status", PROC_DIR, pid);
    status_file = fopen(path, "r");
    if (!status_file) {
        return; // Can't open status file, proceed to next pid
    }

    // Read and print the information we are interested in
    printf("PID: %d\n", pid);
    while (fgets(buffer, BUF_SIZE, status_file)) {
        if (strncmp(buffer, "Name:", 5) == 0 ||
            strncmp(buffer, "State:", 6) == 0 ||
            strncmp(buffer, "PPid:", 5) == 0) {
            printf("  %s", buffer);
        }
    }
    printf("\n");
    fclose(status_file);
}

void list_processes() {
    struct dirent *entry;
    DIR *proc_dir = opendir(PROC_DIR);

    if (!proc_dir) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    printf("Current Running Processes:\n");
    while ((entry = readdir(proc_dir)) != NULL) {
        // Check if the entry is a digit, indicating a PID
        if (entry->d_type == DT_DIR && isdigit(entry->d_name[0])) {
            int pid = atoi(entry->d_name);
            print_process_info(pid);
        }
    }
    
    closedir(proc_dir);
}

int main(int argc, char *argv[]) {
    // Optional: Help message
    if (argc > 1 && strcmp(argv[1], "--help") == 0) {
        printf("Usage: %s\n", argv[0]);
        printf("Displays information about running processes.\n");
        return EXIT_SUCCESS;
    }

    list_processes();
    return EXIT_SUCCESS;
}