//FormAI DATASET v1.0 Category: File Synchronizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILENAME_LENGTH 255
#define MAX_PATH_LENGTH 4096

// Structure to hold necessary file info
struct FileInfo {
    char name[MAX_FILENAME_LENGTH]; // name of the file
    long size; // size of the file in bytes
};

// Function to retrieve file info
struct FileInfo getFileInfo(char* filepath) {
    struct FileInfo fileInfo;
    struct stat stbuf;

    stat(filepath, &stbuf); // get file's status

    strcpy(fileInfo.name, filepath); // copy file name
    fileInfo.size = stbuf.st_size; // store file size

    return fileInfo;
}

// Function to check if file exists
int fileExists(char* filepath) {
    FILE *file;

    file = fopen(filepath, "r"); // attempt to open file

    if (file) {
        fclose(file); // close file if opened successfully
        return 1;
    }

    return 0;
}

// Function to create a directory if it doesn't exist
void createDirectory(char* path) {
    // Check if directory exists
    DIR* dir = opendir(path);

    if (!dir) { // If directory doesn't exist
        mkdir(path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH); // Create directory
    } else {
        closedir(dir); // Close directory
    }
}

// Function to copy a file
void copyFile(char* source, char* destination) {
    FILE *srcFile, *destFile;
    char buffer[1024];

    srcFile = fopen(source, "r"); // open source file
    destFile = fopen(destination, "w"); // create destination file for writing

    if (srcFile && destFile) { // proceed if both files opened successfully
        size_t n;
        while ((n = fread(buffer, sizeof(char), sizeof(buffer), srcFile)) > 0) { // read data from source file and write to destination file
            fwrite(buffer, sizeof(char), n, destFile);
        }
    }

    if (srcFile) fclose(srcFile); // close source file if opened
    if (destFile) fclose(destFile); // close destination file if opened
}

// Function to synchronize files in two directories
void syncDirectories(char* sourceDir, char* destinationDir) {
    struct dirent *de;

    // Open source directory
    DIR *source = opendir(sourceDir);
    if (source == NULL)
        return;

    // Open destination directory and create if not exists
    createDirectory(destinationDir);
    DIR *destination = opendir(destinationDir);

    // Loop through files in source directory
    while ((de = readdir(source)) != NULL) {
        char filename[MAX_FILENAME_LENGTH];
        snprintf(filename, MAX_FILENAME_LENGTH, "%s/%s", sourceDir, de->d_name);

        if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0) // Ignore "." and ".." directories
            continue;

        struct FileInfo fileInfo = getFileInfo(filename);
        char destinationPath[MAX_PATH_LENGTH];
        snprintf(destinationPath, MAX_PATH_LENGTH, "%s/%s", destinationDir, de->d_name);
        int destinationExists = fileExists(destinationPath);

        if (!destinationExists || fileInfo.size != getFileInfo(destinationPath).size) { // Copy file if it doesn't exist or sizes differ
            copyFile(filename, destinationPath);
        }
    }

    closedir(source); // Close directory streams
    closedir(destination);
}

// Sample usage
int main() {
    syncDirectories("/home/user/documents", "/home/user/backups/documents");

    return 0;
}