//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/stat.h>

// Global variable to track total directory size
long long total_dir_size = 0;

// Function to print size in human-readable format
void print_size(long long size)
{
    char* units[] = {"B", "KB", "MB", "GB", "TB"};
    int i;

    for (i = 0; i < 5 && size > 1024; i++)
    {
        size /= 1024;
    }

    printf("%lld %s\n", size, units[i]);
}

// Function to calculate directory size
void calculate_dir_size(char* dirname)
{
    DIR* dir;
    struct dirent* entry;
    struct stat statbuf;
    char filepath[256];

    if ((dir = opendir(dirname)) == NULL)
    {
        fprintf(stderr, "Could not open directory: %s\n", dirname);
        return;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        // Ignore hidden files
        if (entry->d_name[0] == '.')
        {
            continue;
        }

        sprintf(filepath, "%s/%s", dirname, entry->d_name);

        if (stat(filepath, &statbuf) == -1)
        {
            fprintf(stderr, "Could not stat file: %s\n", filepath);
            continue;
        }

        // If directory, recursively calculate size
        if (S_ISDIR(statbuf.st_mode))
        {
            calculate_dir_size(filepath);
        }
        else
        {
            total_dir_size += statbuf.st_size;
        }
    }

    closedir(dir);
}

int main(int argc, char* argv[])
{
    char* dirname;

    if (argc < 2)
    {
        printf("Usage: %s [directory path]\n", argv[0]);
        exit(1);
    }

    dirname = argv[1];

    // Check if directory exists
    struct stat dir_stat;
    if (stat(dirname, &dir_stat) == -1 || !S_ISDIR(dir_stat.st_mode))
    {
        fprintf(stderr, "%s is not a valid directory\n", dirname);
        exit(1);
    }

    calculate_dir_size(dirname);

    printf("Total size of directory %s: ", dirname);
    print_size(total_dir_size);

    return 0;
}