//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define MAX_FILES 512


long long directory_size(const char *dir_path, long *num_files, long *num_dirs)
{
    struct stat stat_buf;
    long long total_size = 0;
    int num_entries = 0;
    *num_files = 0;
    *num_dirs = 0;

    DIR *dir = opendir(dir_path);
    if (dir == NULL)
    {
        return 0;
    }

    struct dirent *entry;
    char file_path[MAX_PATH];

    while ((entry = readdir(dir)) != NULL)
    {
        sprintf(file_path, "%s/%s", dir_path, entry->d_name);
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        if (lstat(file_path, &stat_buf) < 0)
        {
            continue;
        }

        if (S_ISDIR(stat_buf.st_mode))
        {
            long long dir_size = directory_size(file_path, num_files, num_dirs);
            total_size += dir_size;
            (*num_dirs)++;
        }
        else
        {
            total_size += stat_buf.st_size;
            (*num_files)++;
        }

        num_entries++;
        if (num_entries >= MAX_FILES)
        {
            break;
        }
    }

    closedir(dir);

    return total_size;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s directory\n", argv[0]);
        return 1;
    }

    char *dir_path = argv[1];

    long num_files = 0;
    long num_dirs = 0;
    long long size_in_bytes = directory_size(dir_path, &num_files, &num_dirs);

    printf("Size: %lld bytes\n", size_in_bytes);
    printf("Files: %ld\n", num_files);
    printf("Directories: %ld\n", num_dirs);

    return 0;
}