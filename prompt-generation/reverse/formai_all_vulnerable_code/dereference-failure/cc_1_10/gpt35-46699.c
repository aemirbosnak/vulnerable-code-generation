//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

/* Function declarations */
unsigned long long get_file_size(const char*);
unsigned long long calculate_directory_size(const char*);

/* Main function */
int main(int argc, char *argv[]) {
    /* Error handling - must provide directory to scan */
    if(argc != 2) {
        printf("Please provide a directory to scan\n");
        return 1;
    }

    /* Call the function */
    unsigned long long total_size = calculate_directory_size(argv[1]);

    /* Output the result */
    printf("Total directory size: %llu bytes\n", total_size);

    return 0;
}

/* Function to recursively calculate the size of directories */
unsigned long long calculate_directory_size(const char* path) {
    /* Open the directory */
    DIR* directory = opendir(path);

    /* Initialize total size to zero */
    unsigned long long total_size = 0;

    /* Iterate through all files and directories in the directory */
    struct dirent* entry;
    while((entry = readdir(directory)) != NULL) {
        /* Ignore . and .. directories */
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        /* Concatenate the file path */
        char file_path[512];
        strcpy(file_path, path);
        strcat(file_path, "/");
        strcat(file_path, entry->d_name);

        /* Check if the entry is a file or directory */
        struct stat statbuf;
        if(stat(file_path, &statbuf) < 0) {
            printf("Error: Unable to stat file: %s\n", file_path);
            continue;
        }

        if(S_ISDIR(statbuf.st_mode)) {
            /* Recursively call the function again on the sub-directory */
            total_size += calculate_directory_size(file_path);
        }
        else {
            /* Get the size of the file and add to total */
            unsigned long long file_size = get_file_size(file_path);
            total_size += file_size;
        }
    }

    /* Close the directory and return total size */
    closedir(directory);
    return total_size;
}

/* Function to get the size of a file */
unsigned long long get_file_size(const char* file_path) {
    struct stat statbuf;
    if(stat(file_path, &statbuf) < 0) {
        printf("Error: Unable to stat file: %s\n", file_path);
        return 0;
    }

    return statbuf.st_size;
}