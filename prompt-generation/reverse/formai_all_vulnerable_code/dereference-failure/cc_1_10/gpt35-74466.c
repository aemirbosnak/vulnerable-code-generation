//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

void analyze_disk_space(const char *path)
{
    DIR *dir = opendir(path);

    if (dir == NULL)
    {
        printf("Failed to open directory '%s'.\n", path);
        return;
    }

    struct dirent *entry;
    struct stat file_stats;
    long long total_size = 0;

    while ((entry = readdir(dir)) != NULL)
    {
        char file_path[1024];
        snprintf(file_path, sizeof(file_path), "%s/%s", path, entry->d_name);

        if (lstat(file_path, &file_stats) == -1)
        {
            printf("Failed to get stats for file '%s'.\n", file_path);
            continue;
        }

        if (S_ISDIR(file_stats.st_mode))
        {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            {
                continue;
            }

            analyze_disk_space(file_path);
        }
        else if (S_ISREG(file_stats.st_mode))
        {
            total_size += file_stats.st_size;
        }
    }

    closedir(dir);

    printf("Total size of '%s': %lld bytes\n", path, total_size);
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s path\n", argv[0]);
        return EXIT_FAILURE;
    }

    analyze_disk_space(argv[1]);

    return EXIT_SUCCESS;
}