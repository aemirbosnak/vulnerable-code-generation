//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 4096

// A whimsical function that sounds like a storytelling moment.
void theFileSyncJourney(const char *source, const char *destination) {
    printf("As the sun rises over the digital landscape, our brave sync function prepares for its quest...\n");
}

// A magical function, checking if the source exists.
int doesFileExist(const char *path) {
    struct stat buffer;
    return (stat(path, &buffer) == 0);
}

// The art of copying a file, portraying the connection between source and destination.
void copyFile(const char *source, const char *destination) {
    int srcFile = open(source, O_RDONLY);
    int destFile = open(destination, O_WRONLY | O_CREAT | O_EXCL, 0644);
    
    if (srcFile < 0 || destFile < 0) {
        perror("Failed to open file");
        return;
    }
    
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;
    
    while ((bytesRead = read(srcFile, buffer, sizeof(buffer))) > 0) {
        write(destFile, buffer, bytesRead);
    }
    
    close(srcFile);
    close(destFile);
    printf("Successfully traversed the path from '%s' to '%s'. A tale of data written!\n", source, destination);
}

// Dance of directories, seeking their contents.
void syncDirectories(const char *sourceDir, const char *destDir) {
    DIR *dir = opendir(sourceDir);
    struct dirent *entry;
    
    if (!dir) {
        perror("Could not open source directory");
        return;
    }
    
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char sourcePath[MAX_PATH];
            char destinationPath[MAX_PATH];
            
            snprintf(sourcePath, sizeof(sourcePath), "%s/%s", sourceDir, entry->d_name);
            snprintf(destinationPath, sizeof(destinationPath), "%s/%s", destDir, entry->d_name);
            
            if (entry->d_type == DT_DIR) {
                // Create destination directory if it doesn't exist
                mkdir(destinationPath, 0755);
                syncDirectories(sourcePath, destinationPath); // Recursing deeper into the forest of files
            } else {
                // Experience the dance of synchronization
                if (doesFileExist(destinationPath)) {
                    printf("Skipping existing file: %s\n", destinationPath);
                } else {
                    copyFile(sourcePath, destinationPath);
                }
            }
        }
    }
    
    closedir(dir);
    printf("The journey through '%s' is complete! What an adventure!\n", sourceDir);
}

// The orchestrator of synchronization, bound to the calling.
void synchronize(const char *source, const char *destination) {
    theFileSyncJourney(source, destination);
    
    // Check if source exists
    if (!doesFileExist(source)) {
        printf("Source directory '%s' does not exist. Unable to commence the epic voyage!\n", source);
        return;
    }
    
    // Create destination directory if it doesn't exist
    mkdir(destination, 0755);
    
    syncDirectories(source, destination); // The grand synchronization begins
}

// The main function, where our symphony commences.
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *source = argv[1];
    const char *destination = argv[2];
    
    synchronize(source, destination); // The saga begins!
    
    return EXIT_SUCCESS;
}