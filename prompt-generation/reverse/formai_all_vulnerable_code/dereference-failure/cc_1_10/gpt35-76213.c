//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

// Define constants
#define BYTES_IN_GB 1073741824
#define BYTES_IN_MB 1048576
#define BYTES_IN_KB 1024

// Define struct to hold information for each directory
struct Dir {
    char name[256];
    long long totalSize;
    struct Dir* subDirs[256];
    int numSubDirs;
};

// Function to initialize a new directory struct
struct Dir* newDir(char* name) {
    struct Dir* dir = (struct Dir*) malloc(sizeof(struct Dir));
    dir->totalSize = 0;
    dir->numSubDirs = 0;
    strcpy(dir->name, name);
    return dir;
}

// Function to add a subdirectory to a directory struct
void addSubDir(struct Dir* dir, struct Dir* subDir) {
    dir->subDirs[dir->numSubDirs] = subDir;
    dir->numSubDirs++;
}

// Function to calculate the size of a directory and all its subdirectories
long long calculateDirSize(char* folderPath) {
    DIR* dir = opendir(folderPath);
    if (dir == NULL) {
        fprintf(stderr, "Error opening directory %s", folderPath);
        exit(1);
    }

    long long totalSize = 0;

    struct dirent* dentry;
    while ((dentry = readdir(dir)) != NULL) {
        if (dentry->d_type == 4) {  // Check if entry is a directory
            if (strcmp(dentry->d_name, ".") == 0 || strcmp(dentry->d_name, "..") == 0) {
                continue;
            }
            char subDirPath[512];
            sprintf(subDirPath, "%s/%s", folderPath, dentry->d_name);
            totalSize += calculateDirSize(subDirPath);  // Recursively calculate size of subdirectory
        }
        else {
            char filePath[512];
            sprintf(filePath, "%s/%s", folderPath, dentry->d_name);
            struct stat fileStat;
            if (stat(filePath, &fileStat)) {
                fprintf(stderr, "Error getting file information for %s", filePath);
                exit(1);
            }
            totalSize += fileStat.st_size;  // Add the file's size to the directory's total size
        }
    }
    closedir(dir);
    return totalSize;
}

// Function to print out the disk usage for a directory struct and its subdirectories
void printDir(struct Dir* dir, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }

    printf("%s\n", dir->name);

    for (int i = 0; i < dir->numSubDirs; i++) {
        printDir(dir->subDirs[i], depth+1);
    }

    if (dir->totalSize > BYTES_IN_GB) {
        printf("  %lld GB\n", dir->totalSize / BYTES_IN_GB);
    }
    else if (dir->totalSize > BYTES_IN_MB) {
        printf("  %lld MB\n", dir->totalSize / BYTES_IN_MB);
    }
    else if (dir->totalSize > BYTES_IN_KB) {
        printf("  %lld KB\n", dir->totalSize / BYTES_IN_KB);
    }
    else {
        printf("  %lld bytes\n", dir->totalSize);
    }

}

int main(int argc, char** argv) {

    // Ensure the user inputs a directory path
    if (argc < 2) {
        printf("Please enter a directory path\n");
        exit(1);
    }

    char* dirPath = argv[1];

    // Initialize the root directory struct
    struct Dir* rootDir = newDir(dirPath);

    // Recursively populate the directory struct with subdirectory information
    DIR* dir = opendir(dirPath);
    if (dir == NULL) {
        fprintf(stderr, "Error opening directory %s", dirPath);
        exit(1);
    }

    struct dirent* dentry;
    while ((dentry = readdir(dir)) != NULL) {
        if (dentry->d_type == 4) {  // Check if entry is a directory
            if (strcmp(dentry->d_name, ".") == 0 || strcmp(dentry->d_name, "..") == 0) {
                continue;
            }
            char subDirPath[512];
            sprintf(subDirPath, "%s/%s", dirPath, dentry->d_name);
            struct Dir* subDir = newDir(dentry->d_name);
            subDir->totalSize = calculateDirSize(subDirPath);
            addSubDir(rootDir, subDir);
        }
        else {
            char filePath[512];
            sprintf(filePath, "%s/%s", dirPath, dentry->d_name);
            struct stat fileStat;
            if (stat(filePath, &fileStat)) {
                fprintf(stderr, "Error getting file information for %s", filePath);
                exit(1);
            }
            rootDir->totalSize += fileStat.st_size;
        }
    }
    closedir(dir);

    // Print out the directory information
    printDir(rootDir, 0);

    return 0;
}