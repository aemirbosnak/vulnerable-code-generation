//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_LENGTH 100
#define SCAN_EXTENSION ".exe"
#define INFECTED_SIGNATURE "malware"

// Function declarations
void scan_file(char *filename);
void scan_directory(char *dirname);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: antivirus <directory>\n");
        return 1;
    }
    
    // Get the target directory from the command line arguments
    char dirname[MAX_LENGTH];
    strncpy(dirname, argv[1], MAX_LENGTH);
    
    printf("Starting antivirus scan on directory: %s\n", dirname);
    
    scan_directory(dirname);
    
    printf("Antivirus scan complete.\n");
    
    return 0;
}

// Recursive function to scan a directory for files and subdirectories
void scan_directory(char *dirname) {
    DIR *dir;
    struct dirent *entry;
    char filename[MAX_LENGTH];
    
    dir = opendir(dirname);
    if (!dir) {
        printf("Failed to open directory: %s\n", dirname);
        return;
    }
    
    printf("Scanning directory: %s\n", dirname);
    
    while ((entry = readdir(dir))) {
        // Skip the . and .. directories and any hidden files
        if (entry->d_name[0] == '.') {
            continue;
        }
        
        // Construct the full path to the file or subdirectory
        snprintf(filename, MAX_LENGTH, "%s/%s", dirname, entry->d_name);
        if (entry->d_type == DT_DIR) {
            // Recursively scan subdirectories
            scan_directory(filename);
        } else if (strstr(entry->d_name, SCAN_EXTENSION)) {
            // If the file has the correct extension, call the scan_file function
            scan_file(filename);
        }
    }
    
    closedir(dir);
}

// Function to scan a file for malware signatures
void scan_file(char *filename) {
    FILE *fp;
    char buffer[MAX_LENGTH];
    int infected = 0;
    
    fp = fopen(filename, "r");
    if (!fp) {
        printf("Failed to open file: %s\n", filename);
        return;
    }
    
    while (fgets(buffer, MAX_LENGTH, fp)) {
        if (strstr(buffer, INFECTED_SIGNATURE)) {
            infected = 1;
            break;
        }
    }
    
    fclose(fp);
    
    if (infected) {
        printf("Found malware in file: %s\n", filename);
        // Perform actions to quarantine or remove the infected file
    } else {
        printf("File is clean: %s\n", filename);
    }
}