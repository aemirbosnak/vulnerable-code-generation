//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

// Function to recursively traverse the directory
void traverse_directory(char *path, int depth)
{
    DIR *dir = opendir(path);
    struct dirent *dp;
    struct stat stbuf;
    int total_size = 0;

    if (!dir)
    {
        printf("Error opening directory %s\n", path);
        exit(EXIT_FAILURE);
    }

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            char file_path[1000];
            sprintf(file_path, "%s/%s", path, dp->d_name);

            // Get the size of the current file/directory
            stat(file_path, &stbuf);

            if (S_ISDIR(stbuf.st_mode))
            {
                // The current file is a directory, so we recursively traverse this directory
                printf("%*s%s/\n", depth * 4, "", dp->d_name);
                traverse_directory(file_path, depth + 1);
            }
            else
            {
                // The current file is a file, so we output its name and size
                printf("%*s%s: %ld bytes\n", depth * 4, "", dp->d_name, stbuf.st_size);
                total_size += stbuf.st_size;
            }
        }
    }

    closedir(dir);

    // Output the total size of the current directory
    printf("%*sTotal size: %d bytes\n", depth * 4, "", total_size);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *path = argv[1];

    traverse_directory(path, 0);

    return 0;
}