//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: mathematical
/*
    C Disk Space Analyzer
    ----------------------
    A program that analyzes the disk space of a given directory and its subdirectories and 
    outputs the size in bytes for each file type in a tabular format.
    
    Author: [Your Name]
    Date: [Current Date]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_FILETYPES 10

// Struct for file type information
typedef struct {
    char ext[10];
    long long size;
} FileType;

// Function to check if a file is a directory
int is_directory(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) != 0) {
        return 0;
    }
    return S_ISDIR(statbuf.st_mode);
}

// Function to get file extension from filename
void get_file_extension(char *filename, char *ext) {
    char *dot = strrchr(filename, '.');
    if (!dot || dot == filename) {
        strcpy(ext, "");
    }
    else {
        strcpy(ext, dot + 1);
    }
}

int main(int argc, char *argv[]) {
    // Create array to store file type information
    FileType filetypes[MAX_FILETYPES] = {0};
    int num_filetypes = 0;

    // Check command line arguments
    if (argc != 2) {
        printf("Invalid number of arguments. Usage: %s [directory_path]\n", argv[0]);
        return 1;
    }

    char path[MAX_FILENAME_LENGTH];
    strcpy(path, argv[1]);

    // Check if path is a directory
    if (!is_directory(path)) {
        printf("Error: %s is not a directory.\n", path);
        return 1;
    }

    // Open directory and read contents
    DIR *dir = opendir(path);
    if (dir == NULL) {
        printf("Error: could not open directory %s.\n", path);
        return 1;
    }

    struct dirent *entry;
    struct stat file_stats;
    char filename[MAX_FILENAME_LENGTH];
    char ext[10];

    while ((entry = readdir(dir)) != NULL) {
        // Construct full path of file within directory
        snprintf(filename, MAX_FILENAME_LENGTH, "%s/%s", path, entry->d_name);

        // Get file stats
        if (stat(filename, &file_stats) != 0) {
            printf("Error: could not read file stats for %s.\n", filename);
            continue;
        }

        // Check if file is a directory or a regular file
        if (S_ISDIR(file_stats.st_mode)) {
            // Recursively analyze subdirectory
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                main(argc, &filename);
            }
        }
        else if (S_ISREG(file_stats.st_mode)) {
            // Get file extension and update size for corresponding file type
            get_file_extension(entry->d_name, ext);
            int i;
            for (i = 0; i < num_filetypes; i++) {
                if (strcmp(filetypes[i].ext, ext) == 0) {
                    filetypes[i].size += file_stats.st_size;
                    break;
                }
            }
            if (i == num_filetypes) {
                if (num_filetypes == MAX_FILETYPES) {
                    printf("Warning: maximum number of file types exceeded.\n");
                    continue;
                }
                strcpy(filetypes[num_filetypes].ext, ext);
                filetypes[num_filetypes].size = file_stats.st_size;
                num_filetypes++;
            }
        }
    }

    closedir(dir);

    // Output table of file type sizes
    printf("File Type\tSize (Bytes)\n");
    printf("--------------------------------------\n");
    int i;
    for (i = 0; i < num_filetypes; i++) {
        printf("%-10s\t%lld\n", filetypes[i].ext, filetypes[i].size);
    }

    return 0;
}