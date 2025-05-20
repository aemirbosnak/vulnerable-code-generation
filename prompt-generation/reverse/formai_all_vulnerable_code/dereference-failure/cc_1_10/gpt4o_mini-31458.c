//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILES 1000
#define FILENAME_SIZE 256

// File structure to hold file information
typedef struct {
    char name[FILENAME_SIZE];
    long size;
} FileInfo;

// Function to display collected file data
void displayFiles(FileInfo files[], int count) {
    printf("\n--- Retrieved Files ---\n");
    for (int i = 0; i < count; i++) {
        printf("File: %s | Size: %ld bytes\n", files[i].name, files[i].size);
    }
    printf("\nTotal files recovered: %d\n", count);
}

// Function to search for files in the directory
int recoverData(const char *dirPath, FileInfo files[], int *index) {
    struct dirent *entry;
    struct stat fileStat;
    DIR *dp = opendir(dirPath);
    
    if (dp == NULL) {
        perror("Unable to access directory");
        return -1;
    }
    
    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;  // Skip the current and parent directory
        }
        
        char filePath[FILENAME_SIZE];
        snprintf(filePath, sizeof(filePath), "%s/%s", dirPath, entry->d_name);
        
        if (stat(filePath, &fileStat) == -1) {
            perror("Error retrieving file stats");
            continue;
        }
        
        // If it's a regular file, save its info
        if (S_ISREG(fileStat.st_mode)) {
            strncpy(files[*index].name, filePath, FILENAME_SIZE);
            files[*index].size = fileStat.st_size;
            (*index)++;
            if (*index >= MAX_FILES) {
                printf("Max file limit reached!\n");
                break;
            }
        }
    }
    
    closedir(dp);
    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Excitement begins here!
    printf("🎉 Welcome to the Ultimate Data Recovery Tool! 🎉\n");
    printf("🚀 Let's get ready to dig deep and recover your lost files from: %s\n", argv[1]);

    FileInfo recoveredFiles[MAX_FILES];
    int fileCount = 0;

    // Start the recovery process
    if (recoverData(argv[1], recoveredFiles, &fileCount) == 0) {
        // Successfully retrieved files, let's show them off!
        displayFiles(recoveredFiles, fileCount);
    } else {
        // An error occurred
        printf("🔧 Oops! Something went wrong while accessing the directory. Please try again.\n");
        return EXIT_FAILURE;
    }

    printf("✨ Data recovery process completed! Good luck with your files! ✨\n");
    return EXIT_SUCCESS;
}