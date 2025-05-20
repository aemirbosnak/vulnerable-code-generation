//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

long int folder_size(const char* folder_path);

int main(int argc, char* argv[])
{
    // Check if command line argument is provided
    if (argc < 2)
    {
        printf("Usage: %s <path to folder>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    long int total_size = folder_size(argv[1]); // Get total size of folder
    printf("Total size of %s is %ld bytes\n", argv[1], total_size);

    return 0;
}

// Recursive function to calculate total size of folder
long int folder_size(const char* folder_path)
{
    DIR* dir = opendir(folder_path);
    struct dirent* entry;
    struct stat file_stat;
    long int total_size = 0;

    if (!dir)
    {
        printf("Unable to open directory %s\n", folder_path);
        exit(EXIT_FAILURE);
    }

    chdir(folder_path);

    while ((entry = readdir(dir)) != NULL)
    {
        lstat(entry->d_name, &file_stat);

        if (S_ISDIR(file_stat.st_mode))
        {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            {
                continue;
            }

            total_size += folder_size(entry->d_name);
        }
        else
        {
            total_size += file_stat.st_size;
        }
    }

    chdir("..");

    closedir(dir);

    return total_size;
}