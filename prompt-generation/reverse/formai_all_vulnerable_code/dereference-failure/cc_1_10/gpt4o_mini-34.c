//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define BUFFER_SIZE 1024
#define SCAN_PATH "/path/to/scan"  // Modify this path for the target directory

// Function prototypes
void scan_directory(const char *basePath);
int is_infected(const char *filePath);

int main() {
    printf("Surprise! An unexpected visitor has entered your system...\n");
    printf("Let's find out if there are any malicious files lurking around!\n");

    // Start scanning the designated path
    scan_directory(SCAN_PATH);
    
    printf("Scanning complete. Stay safe, and keep your system protected!\n");
    return 0;
}

// A function to scan the directory for files
void scan_directory(const char *basePath) {
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    // If the directory can't be opened, print an error and return
    if (!dir) {
        printf("Error: Unable to open directory: %s\n", basePath);
        return;
    }

    // Read each entry in the directory
    while ((dp = readdir(dir)) != NULL) {
        char path[BUFFER_SIZE];
        
        // Skip the "." and ".." entries
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
            // Form the full path for the entry
            snprintf(path, sizeof(path), "%s/%s", basePath, dp->d_name);
            printf("Scanning %s...\n", path);

            // Check if the path is a directory
            if (dp->d_type == DT_DIR) {
                // Recursively scan the directory
                scan_directory(path);
            } else {
                // Check if the file is infected
                if (is_infected(path)) {
                    printf("⚠️  Infected file found: %s\n", path);
                } else {
                    printf("✅  File is clean: %s\n", path);
                }
            }
        }
    }

    closedir(dir);
}

// A mock function that checks if a file is infected (You can implement actual logic)
int is_infected(const char *filePath) {
    // For demonstration, let's assume any file with the name "virus" is infected
    const char *virus_signature = "virus";
    if (strstr(filePath, virus_signature) != NULL) {
        return 1; // Infected
    }
    return 0; // Not infected
}