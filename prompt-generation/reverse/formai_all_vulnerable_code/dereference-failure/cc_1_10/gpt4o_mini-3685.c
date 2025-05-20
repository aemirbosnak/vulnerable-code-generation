//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>

#define PROC_PATH "/proc"
#define BUFFER_SIZE 256

void print_process_info(const char* pid) {
    char path[BUFFER_SIZE];
    snprintf(path, sizeof(path), "%s/%s/stat", PROC_PATH, pid);
    FILE* file = fopen(path, "r");
    if (file == NULL) {
        return; // Process may have exited
    }

    char comm[BUFFER_SIZE];
    char state;
    unsigned long utime, stime;

    // Read required fields from /proc/[pid]/stat
    fscanf(file, "%*d %s %c %*s %*d %*d %*d %*d %*d %*d %*d %*d %*d %lu %lu", comm, &state, &utime, &stime);
    fclose(file);

    // Print process information
    printf("PID: %s\tCommand: %s\tState: %c\tUser Time: %lu\tSystem Time: %lu\n", pid, comm, state, utime, stime);
}

void list_processes() {
    DIR* dir = opendir(PROC_PATH);
    struct dirent* entry;

    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    printf("%-10s %-30s %-10s %-15s %-15s\n", "PID", "Command", "State", "User Time", "System Time");
    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) { // Check if it starts with a digit
            print_process_info(entry->d_name);
        }
    }
    closedir(dir);
}

void print_usage() {
    printf("Usage: proc_viewer [OPTION]\n");
    printf("Options:\n");
    printf("  -h, --help          Show this help message and exit\n");
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            print_usage();
            return EXIT_SUCCESS;
        } else {
            fprintf(stderr, "Invalid option: %s\n", argv[1]);
            print_usage();
            return EXIT_FAILURE;
        }
    }

    printf("Listing all processes:\n");
    list_processes();
    return EXIT_SUCCESS;
}