//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_NAME_LEN 256
#define MAX_DEPTH 5

// Structure to hold file information
typedef struct {
    char name[MAX_NAME_LEN];
    char parent_name[MAX_NAME_LEN];
    int depth;
} file_info_t;

// Function to traverse the directory tree
void traverse_directory(char *path, file_info_t *info) {
    // Check if the path is a directory
    struct stat stat_buf;
    if (stat(path, &stat_buf) == 0) {
        if (S_ISDIR(stat_buf.st_mode)) {
            // Traverse the directory
            char *dir_name = basename(path);
            strcpy(info->name, dir_name);
            info->depth = 1;
            traverse_directory(path, info);
        }
    }
}

int main() {
    // Set the current directory
    char current_dir[MAX_NAME_LEN];
    getcwd(current_dir, MAX_NAME_LEN);

    // Create a list of file information
    file_info_t info;
    info.name[0] = '\0';
    info.parent_name[0] = '\0';
    info.depth = 0;

    // Traverse the directory tree
    traverse_directory(current_dir, &info);

    // Print the file information
    printf("File Information:\n");
    printf("Name: %s\n", info.name);
    printf("Parent: %s\n", info.parent_name);
    printf("Depth: %d\n", info.depth);

    return 0;
}