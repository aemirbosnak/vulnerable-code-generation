//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Define constants for file sizes
const float KB = 1024.0;
const float MB = 1024.0 * 1024.0;
const float GB = 1024.0 * 1024.0 * 1024.0;

// Struct to hold file information
typedef struct {
    char *name;
    float size;
} FileInfo;

// Recursive function to analyze directory contents
void analyzeDirectory(char *path, FileInfo *files, int *numFiles) {
    DIR *dir = opendir(path);
    struct dirent *entry;
    struct stat fileStat;
    
    if (dir == NULL) { // Error opening directory
        printf("Error opening directory %s\n", path);
        perror("opendir");
        return;
    }
    
    while ((entry = readdir(dir)) != NULL) {
        char filePath[1000];
        sprintf(filePath, "%s/%s", path, entry->d_name); // Construct full file path
        
        if (stat(filePath, &fileStat) == -1) { // Error getting file info
            printf("Error getting file info for %s\n", filePath);
            perror("stat");
            continue;
        }
        
        if (S_ISREG(fileStat.st_mode)) { // File is a regular file
            float fileSize = (float) fileStat.st_size;
            FileInfo newFile;
            newFile.name = strdup(entry->d_name);
            newFile.size = fileSize;
            
            // Add file to array of files
            files[*numFiles] = newFile;
            *numFiles += 1;
        } else if (S_ISDIR(fileStat.st_mode) && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) { // File is a directory (but not . or ..)
            analyzeDirectory(filePath, files, numFiles); // Recursively analyze directory contents
        }
    }
    
    closedir(dir); // Close directory
}

// Comparator function for sorting files by size (descending order)
int compareFiles(const void *a, const void *b) {
    FileInfo *fileA = (FileInfo *) a;
    FileInfo *fileB = (FileInfo *) b;
    
    if (fileA->size > fileB->size) {
        return -1;
    } else if (fileA->size < fileB->size) {
        return 1;
    } else {
        return strcmp(fileA->name, fileB->name);
    }
}

int main() {
    char path[1000];
    printf("Enter directory path to analyze:\n");
    fgets(path, sizeof(path), stdin);
    path[strcspn(path, "\n")] = '\0'; // Remove newline from input
    
    // Allocate memory for array of FileInfo structs
    FileInfo *files = (FileInfo *) malloc(sizeof(FileInfo) * 1000);
    int numFiles = 0;
    
    analyzeDirectory(path, files, &numFiles); // Analyze directory contents recursively
    
    qsort(files, numFiles, sizeof(FileInfo), compareFiles); // Sort files by size
    
    printf("\nDisk space used by files in %s:\n", path);
    
    for (int i = 0; i < numFiles; i++) {
        FileInfo file = files[i];
        printf("%s (%.1f ", file.name, file.size);
        
        // Determine units for file size
        if (file.size > GB) {
            printf("GB)\n");
        } else if (file.size > MB) {
            printf("MB)\n");
        } else if (file.size > KB) {
            printf("KB)\n");
        } else {
            printf("bytes)\n");
        }
        
        free(file.name); // Free memory allocated for file name
    }
    
    free(files); // Free memory allocated for array of FileInfo structs
    
    return 0;
}