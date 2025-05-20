//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// Define metadata structure
typedef struct {
    char fileName[256];
    char fileType[256];
    off_t fileSize;
    time_t creationTime;
    time_t modificationTime;
} FileMetadata;

// Function to get file type based on extension
const char* getFileType(const char* fileName) {
    char* dot = strrchr(fileName, '.');
    if (!dot || dot == fileName) return "Unknown";

    if (strcmp(dot, ".txt") == 0) return "Text File";
    if (strcmp(dot, ".jpg") == 0 || strcmp(dot, ".jpeg") == 0) return "Image File";
    if (strcmp(dot, ".png") == 0) return "Image File";
    if (strcmp(dot, ".mp3") == 0) return "Audio File";
    if (strcmp(dot, ".mp4") == 0) return "Video File";
    if (strcmp(dot, ".pdf") == 0) return "PDF Document";
    return "Other";
}

// Function to extract file metadata
void extractFileMetadata(const char* filePath, FileMetadata* metadata) {
    struct stat statbuf;

    // Get file stats
    if (stat(filePath, &statbuf) == 0) {
        strcpy(metadata->fileName, filePath);
        strcpy(metadata->fileType, getFileType(filePath));
        metadata->fileSize = statbuf.st_size;
        metadata->creationTime = statbuf.st_ctime;
        metadata->modificationTime = statbuf.st_mtime;
    } else {
        perror("Failed to get file stats");
    }
}

// Function to print metadata
void printFileMetadata(FileMetadata* metadata) {
    printf("File Name: %s\n", metadata->fileName);
    printf("File Type: %s\n", metadata->fileType);
    printf("File Size: %ld bytes\n", metadata->fileSize);
    printf("Creation Time: %s", ctime(&metadata->creationTime));
    printf("Modification Time: %s", ctime(&metadata->modificationTime));
}

// Function to process directory and extract metadata for files
void processDirectory(const char* dirPath) {
    DIR* dir;
    struct dirent* entry;

    if ((dir = opendir(dirPath)) != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            // Skip '.' and '..'
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char filePath[512];
                snprintf(filePath, sizeof(filePath), "%s/%s", dirPath, entry->d_name);
                
                FileMetadata metadata;
                extractFileMetadata(filePath, &metadata);
                printFileMetadata(&metadata);
                printf("\n");
            }
        }
        closedir(dir);
    } else {
        perror("Could not open directory");
    }
}

// Main function
int main(int argc, char* argv[]) {
    // Check for correct number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char* dirPath = argv[1];
    processDirectory(dirPath);

    return EXIT_SUCCESS;
}