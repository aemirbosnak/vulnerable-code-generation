//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define LOG_FILE "antivirus_log.txt"

// Function to check if a file extension matches the ones we consider dangerous
int is_dangerous_file(const char *filename) {
    // Dangerous file types
    const char *dangerous_extensions[] = { ".exe", ".bat", NULL };
    
    // Check the file extension
    for (int i = 0; dangerous_extensions[i] != NULL; i++) {
        if (strstr(filename, dangerous_extensions[i]) != NULL) {
            return 1; // dangerous file found
        }
    }
    return 0; // safe file
}

// Function to log detected dangerous files to a log file
void log_dangerous_file(const char *filename) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        printf("Unable to open log file.\n");
        return;
    }
    fprintf(log_file, "Detected dangerous file: %s\n", filename);
    fclose(log_file);
}

// Function to scan a directory for dangerous files
void scan_directory(const char *directory) {
    DIR *dir = opendir(directory);
    struct dirent *entry;
    struct stat file_stat;
    char full_path[MAX_PATH];

    if (dir == NULL) {
        printf("Could not open directory: %s\n", directory);
        return;
    }

    // Read entries in the directory
    while ((entry = readdir(dir)) != NULL) {
        // Skip current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        // Build full path
        snprintf(full_path, sizeof(full_path), "%s/%s", directory, entry->d_name);
        
        // Get file status
        if (stat(full_path, &file_stat) == 0) {
            // Check if it's a file (not a directory)
            if (S_ISREG(file_stat.st_mode)) {
                // Check if it's a dangerous file
                if (is_dangerous_file(entry->d_name)) {
                    printf("Warning: Dangerous file detected: %s\n", full_path);
                    log_dangerous_file(full_path);
                }
            } else if (S_ISDIR(file_stat.st_mode)) {
                // Recursively scan subdirectories
                scan_directory(full_path);
            }
        } else {
            printf("Could not get file status for: %s\n", full_path);
        }
    }
    
    closedir(dir);
}

int main(int argc, char *argv[]) {
    // Check for correct usage
    if (argc != 2) {
        printf("Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Clear log file before scanning
    FILE *log_file = fopen(LOG_FILE, "w");
    if (log_file != NULL) {
        fclose(log_file);
    }

    // Start scanning the given directory
    printf("Scanning directory: %s\n", argv[1]);
    scan_directory(argv[1]);

    printf("Scan completed. Check %s for the log of detections.\n", LOG_FILE);
    return EXIT_SUCCESS;
}