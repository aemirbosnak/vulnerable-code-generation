//LLAMA2-13B DATASET v1.0 Category: Data recovery tool ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_NAME_LEN 256
#define MAX_DEPTH 5

// Structure to store file information
typedef struct {
    char name[MAX_NAME_LEN];
    char path[MAX_NAME_LEN];
    bool isDir;
} file_info;

// Function to print file information
void print_file_info(file_info *file);

// Function to recover files and directories
void recover_files(const char *dir_path);

int main() {
    // Set the current working directory
    if (chdir("./") != 0) {
        perror("Failed to set current working directory");
        return 1;
    }

    // Recover files and directories
    recover_files(".");

    return 0;
}

// Function to recover files and directories
void recover_files(const char *dir_path) {
    DIR *dir;
    struct dirent *ent;
    file_info *file;

    // Open the directory
    if ((dir = opendir(dir_path)) == NULL) {
        perror("Failed to open directory");
        return;
    }

    // Loop through the directory entries
    while ((ent = readdir(dir)) != NULL) {
        // Check if the entry is a directory or a file
        if (ent->d_type == DT_DIR) {
            // Recover files and directories in the current directory
            recover_files(ent->d_name);
        } else {
            // Get the file information
            file = (file_info *) malloc(sizeof(file_info));
            strcpy(file->name, ent->d_name);
            strcpy(file->path, dir_path);
            file->isDir = false;

            // Print the file information
            print_file_info(file);
        }
    }

    // Close the directory
    closedir(dir);
}

// Function to print file information
void print_file_info(file_info *file) {
    printf("%s (%s) is a %s file\n", file->name, file->path, file->isDir ? "directory" : "file");
}