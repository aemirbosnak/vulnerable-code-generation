//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

#define MAX_LOG_SIZE 1024

// Function to log intrusion attempts
void log_intrusion(const char* message) {
    FILE* logFile = fopen("intrusion_log.txt", "a");
    if (logFile == NULL) {
        perror("Could not open log file");
        return;
    }
    fprintf(logFile, "%s: %s\n", message, ctime(&(time_t){time(NULL)}));
    fclose(logFile);
}

// Function to scan files for suspicious content
int scan_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        return 0;
    }

    char line[MAX_LOG_SIZE];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "malicious_pattern") != NULL) { // Replace with actual patterns
            fclose(file);
            return 1; // Suspicious content found
        }
    }

    fclose(file);
    return 0; // No suspicious content
}

// Function to recursively scan a directory
void scan_directory(const char* dirName) {
    struct dirent* entry;
    DIR* dir = opendir(dirName);
    
    if (dir == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char path[MAX_LOG_SIZE];
            snprintf(path, sizeof(path), "%s/%s", dirName, entry->d_name);

            if (entry->d_type == DT_DIR) {
                // Recursive call for directories
                scan_directory(path);
            } else {
                // Scan file for suspicious content
                if (scan_file(path)) {
                    log_intrusion(path);
                    printf("Intrusion detected in file: %s\n", path);
                }
            }
        }
    }
    closedir(dir);
}

// Function to monitor a specific directory
void monitor_directory(const char* dirName) {
    while (1) {
        printf("Scanning directory: %s\n", dirName);
        scan_directory(dirName);
        sleep(10); // Scan every 10 seconds
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_monitor>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Monitor the provided directory
    printf("Starting intrusion detection system...\n");
    monitor_directory(argv[1]);

    return EXIT_SUCCESS;
}