//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

// Define a function to scan a file for viruses
void scan_file(char *filename) {
    // Open the file for reading
    FILE *fp = fopen(filename, "rb");
    if(fp == NULL) {
        printf("Could not open file %s\n", filename);
        return;
    }

    // Read the first 100 bytes to determine file type
    char buffer[100];
    fread(buffer, 1, 100, fp);

    // Check if the file is an executable
    if(buffer[0] == 'M' && buffer[1] == 'Z') {
        printf("Executable file found: %s\n", filename);
    } else {
        printf("Non-executable file found: %s\n", filename);
    }

    // Close the file
    fclose(fp);
}

// Define a function to scan a directory for viruses
void scan_directory(char *dirname) {
    // Open the directory for reading
    DIR *dirp = opendir(dirname);
    if(dirp == NULL) {
        printf("Could not open directory %s\n", dirname);
        return;
    }

    // Loop through each file in the directory
    struct dirent *dp;
    while((dp = readdir(dirp)) != NULL) {
        // Ignore "." and ".." directories
        if(strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        }

        // Construct the full path to the file
        char filepath[1000];
        sprintf(filepath, "%s/%s", dirname, dp->d_name);

        // Scan the file
        scan_file(filepath);
    }

    // Close the directory
    closedir(dirp);
}

int main(int argc, char *argv[]) {
    // Check that a directory was provided
    if(argc < 2) {
        printf("Usage: %s <directory name>\n", argv[0]);
        return 1;
    }

    // Scan the directory for viruses
    scan_directory(argv[1]);

    // Exit with success
    return 0;
}