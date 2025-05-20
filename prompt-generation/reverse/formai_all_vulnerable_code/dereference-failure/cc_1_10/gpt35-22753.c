//FormAI DATASET v1.0 Category: System administration ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 1024

void print_usage();
void list_files(char* directory_path, int depth);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        print_usage();
        exit(1);
    }

    char* directory_path = argv[1];
    printf("Recursive file listing for directory: %s\n", directory_path);

    // Check if the directory path exists
    DIR* dir = opendir(directory_path);
    if (dir == NULL) {
        printf("Error opening directory %s\n", directory_path);
        exit(1);
    }
    closedir(dir);

    // Recursively list all files in the directory
    list_files(directory_path, 0);

    return 0;
}

void print_usage() {
    printf("Usage: ./recursive_file_listing <directory_path>\n");
}

void list_files(char* directory_path, int depth) {
    // Open the directory
    DIR* dir = opendir(directory_path);
    if (dir == NULL) {
        printf("Error opening directory %s\n", directory_path);
        exit(1);
    }

    // Iterate over the directory entries
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        // Check if the entry is a directory
        if (entry->d_type == DT_DIR) {
            // Check if the directory is not "." or ".."
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {

                // Print the directory name with indentation
                for (int i = 0; i < depth; i++) {
                    printf("\t");
                }
                printf("%s/\n", entry->d_name);

                // Call the function recursively for the subdirectory
                char subdirectory_path[MAX_PATH_LENGTH];
                snprintf(subdirectory_path, MAX_PATH_LENGTH, "%s/%s", directory_path, entry->d_name);
                list_files(subdirectory_path, depth + 1);
            }
        } else {
            // Print the file name with indentation
            for (int i = 0; i < depth; i++) {
                printf("\t");
            }
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dir);
}