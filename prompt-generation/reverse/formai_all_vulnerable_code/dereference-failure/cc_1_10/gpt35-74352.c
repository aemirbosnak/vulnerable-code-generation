//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH_LEN 1024 // set max path length to 1024 for safe handling

// Function to handle traversing through all folders and files inside a given path
void traverse_path(char *path, int *total_size)
{
    DIR *dir;
    struct dirent *current_file;
    char full_path[MAX_PATH_LEN];

    // Open directory stream for given path
    dir = opendir(path);

    if (dir == NULL)
    {
        fprintf(stderr, "Error: cannot open directory %s\n", path);
        return;
    }

    while ((current_file = readdir(dir)) != NULL)
    {
        // Ignore current and parent directories
        if (strcmp(current_file->d_name, ".") == 0 || strcmp(current_file->d_name, "..") == 0)
        {
            continue;
        }

        // Construct full path to current file/folder
        snprintf(full_path, MAX_PATH_LEN, "%s/%s", path, current_file->d_name);

        // If current file/folder is a directory, call traverse_path function recursively
        if (current_file->d_type == DT_DIR)
        {
            traverse_path(full_path, total_size);
        }
        else // Otherwise, add current file size to total_size variable
        {
            FILE *file = fopen(full_path, "rb");
            if (file == NULL)
            {
                fprintf(stderr, "Error: cannot open file %s\n", full_path);
                continue;
            }
            fseek(file, 0L, SEEK_END);
            int file_size = ftell(file);
            fclose(file);

            *total_size += file_size;
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return 1;
    }

    char *path = argv[1]; // Get path from command line argument
    int total_size = 0;

    traverse_path(path, &total_size); // Call traverse_path function to traverse through all files and folders in given path

    printf("Total size of %s is %d bytes.\n", path, total_size);

    return 0;
}