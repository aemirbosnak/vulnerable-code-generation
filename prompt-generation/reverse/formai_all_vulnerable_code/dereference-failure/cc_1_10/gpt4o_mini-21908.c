//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>

#define PROC_DIR "/proc/"
#define BUF_SIZE 256

void check_file(const char* path) {
    struct stat file_stats;
    if (stat(path, &file_stats) != 0) {
        perror("Failed to get file stats");
        return;
    }
    
    // Check if it's a regular file (like the files in /proc)
    if (!S_ISREG(file_stats.st_mode)) {
        printf("Warning: %s is not a file!\n", path);
        return;
    }
}

void get_process_info(pid_t pid) {
    char path[BUF_SIZE];
    snprintf(path, sizeof(path), PROC_DIR "%d/status", pid);

    FILE* file = fopen(path, "r");
    if (file == NULL) {
        printf("Could not open process file for PID: %d. It might not exist or be inaccessible.\n", pid);
        return;
    }

    char line[BUF_SIZE];
    printf("\nProcess ID: %d\n", pid);
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Name:", 5) == 0 || 
            strncmp(line, "State:", 6) == 0 || 
            strncmp(line, "PPid:", 5) == 0 ||
            strncmp(line, "VmSize:", 7) == 0) {
            printf("%s", line);
        }
    }
    
    fclose(file);
}

void list_processes() {
    DIR* dir = opendir(PROC_DIR);
    if (dir == NULL) {
        perror("Failed to open /proc directory");
        exit(EXIT_FAILURE);
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            pid_t pid = atoi(entry->d_name);
            get_process_info(pid);
        }
    }

    closedir(dir);
}

void paranoid_mode() {
    printf("Warning! This program is running in paranoid mode.\n");
    printf("Only accessing safe, legitimate process files in /proc...\n");
    
    list_processes();
    
    printf("Continuing to monitor and audit processes... Run time checks may indicate unauthorized access!\n");
}

int main() {
    printf("=== Paranoid Process Viewer ===\n");
    paranoid_mode();
    
    return 0;
}