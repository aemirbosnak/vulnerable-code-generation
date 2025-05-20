//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

// Function to display file metadata
void displayFileMetadata(const char *fileName) {
    struct stat fileStat;

    // Get the file status
    if (stat(fileName, &fileStat) < 0) {
        perror("Could not retrieve file statistics");
        return;  // Exit if unable to get file stats
    }

    // Display filename
    printf("File Name: %s\n", fileName);
    
    // Display file size in bytes
    printf("File Size: %ld bytes\n", fileStat.st_size);
    
    // Display last modified time
    char timeBuffer[80];
    struct tm *timeInfo;
    timeInfo = localtime(&fileStat.st_mtime);
    strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", timeInfo);
    printf("Last Modified: %s\n\n", timeBuffer);
}

// Function to scan a directory and display metadata for each file
void scanDirectory(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);
    
    // Check if directory opened successfully
    if (dp == NULL) {
        perror("Unable to open directory");
        return;  // Exit if unable to open the directory
    }

    // Loop through directory entries
    while ((entry = readdir(dp))) {
        // Ignore the '.' and '..' entries
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            // Construct full file path
            char filePath[256];
            snprintf(filePath, sizeof(filePath), "%s/%s", directory, entry->d_name);
            
            // Display metadata for the file
            displayFileMetadata(filePath);
        }
    }

    closedir(dp);  // Close directory stream
}

int main(int argc, char *argv[]) {
    // Check for valid command line argument
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);  // Exit if no directory provided
    }

    // Scan the specified directory
    scanDirectory(argv[1]);
    return 0;  // Successful completion
}