//FormAI DATASET v1.0 Category: File Synchronizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

//Function to check if a file exists
bool fileExists(const char* fileName) {
    FILE* file;
    if ((file = fopen(fileName, "r"))) {
        fclose(file);
        return true;
    }
    return false;
}

//Function to get the size of a file
long int fileSize(const char* fileName) {
    struct stat st;
    if (stat(fileName, &st) == 0)
        return (long int)st.st_size;
    return -1;
}

//Function to compare two files and update the destination file if necessary
void synchronizeFiles(const char* source, const char* destination) {
    //Check if the source file exists
    if (!fileExists(source)) {
        printf("The file %s does not exist.\n", source);
        return;
    }
    //Check if the destination file exists
    if (!fileExists(destination)) {
        printf("The file %s does not exist.\n", destination);
        return;
    }
    //Compare the sizes of the files
    long int sourceSize = fileSize(source);
    long int destinationSize = fileSize(destination);
    if (sourceSize != destinationSize) {
        //If the sizes are different, update the destination file
        FILE* sourceFile = fopen(source, "rb");
        FILE* destinationFile = fopen(destination, "wb");
        char byte;
        while ((byte = fgetc(sourceFile)) != EOF)
            fputc(byte, destinationFile);
        fclose(sourceFile);
        fclose(destinationFile);
        printf("The file %s has been updated.\n", destination);
    }
    else
        printf("The files %s and %s are already synchronized.\n", source, destination);
}

//Function to synchronise all files in a directory recursively
void synchronizeDirectory(const char* sourceDir, const char* destinationDir) {
    //Open the source directory and scan its contents
    DIR* dir = opendir(sourceDir);
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        //Create the source and destination file paths
        char sourcePath[strlen(sourceDir) + strlen(entry->d_name) + 2];
        snprintf(sourcePath, strlen(sourceDir) + strlen(entry->d_name) + 2, "%s/%s", sourceDir, entry->d_name);
        char destinationPath[strlen(destinationDir) + strlen(entry->d_name) + 2];
        snprintf(destinationPath, strlen(destinationDir) + strlen(entry->d_name) + 2, "%s/%s", destinationDir, entry->d_name);
        //Check if the entry is a file or a directory
        if (entry->d_type == DT_REG)
            synchronizeFiles(sourcePath, destinationPath);
        else if (entry->d_type == DT_DIR)
            synchronizeDirectory(sourcePath, destinationPath);
    }
    closedir(dir);
}

int main(int argc, char** argv) {
    //Check the number of arguments
    if (argc < 3) {
        printf("Usage: %s source destination\n", argv[0]);
        return 1;
    }
    //Check if the source and destination directories exist
    if (access(argv[1], F_OK) == -1) {
        printf("The directory %s does not exist.\n", argv[1]);
        return 1;
    }
    if (access(argv[2], F_OK) == -1) {
        printf("The directory %s does not exist.\n", argv[2]);
        return 1;
    }
    //Synchronize the directories recursively
    synchronizeDirectory(argv[1], argv[2]);
    return 0;
}