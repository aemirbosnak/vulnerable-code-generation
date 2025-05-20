//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_PATTERN_LENGTH 50
#define MAX_FILES_TO_SCAN 100
#define LOG_FILE "scan_log.txt"

// Function to read a file and search for malware patterns
int scan_file(const char *file_path, const char *pattern) {
    FILE *file = fopen(file_path, "r");
    
    if (!file) {
        perror("Error opening file");
        return 0; // File could not be opened (possibly binary file)
    }
    
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file)) {
        if (strstr(buffer, pattern) != NULL) {
            fclose(file);
            return 1; // Pattern found
        }
    }
    
    fclose(file);
    return 0; // Pattern not found
}

// Function to log the results of scanning
void log_scan_result(const char *file_name, int infected) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (!log_file) {
        perror("Unable to open log file.");
        return;
    }
    
    if (infected) {
        fprintf(log_file, "Infected: %s\n", file_name);
    } else {
        fprintf(log_file, "Clean: %s\n", file_name);
    }

    fclose(log_file);
}

// Function to scan all files in the target directory
void scan_directory(const char *dir_name, const char *pattern) {
    struct dirent *entry;
    DIR *dp = opendir(dir_name);
    
    if (!dp) {
        perror("Unable to read directory");
        return;
    }
    
    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Check if it's a regular file
            char file_path[PATH_MAX];
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_name, entry->d_name);
            
            printf("Scanning: %s\n", file_path);
            int infected = scan_file(file_path, pattern);
            log_scan_result(entry->d_name, infected);
        }
    }
    
    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <directory> <pattern>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *target_directory = argv[1];
    const char *malware_pattern = argv[2];

    // Clear log file each time the scan starts
    FILE *log_file = fopen(LOG_FILE, "w");
    if (log_file) {
        fclose(log_file);
    } else {
        perror("Unable to initialize log file.");
    }
    
    printf("Starting scan in directory: %s\n", target_directory);
    printf("Looking for pattern: %s\n", malware_pattern);

    scan_directory(target_directory, malware_pattern);

    printf("Scan completed. Please check %s for results.\n", LOG_FILE);
    return EXIT_SUCCESS;
}