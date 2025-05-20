//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_DIR_LEN 1024

typedef struct DiskStat
{
    char dir_name[MAX_DIR_LEN];
    long long int size;
} DiskStat;

int compare(const void * a, const void * b)
{
    DiskStat *stat1 = (DiskStat *) a;
    DiskStat *stat2 = (DiskStat *) b;
    return (stat2->size - stat1->size);
}

void analyze_dir(const char *dir_path, DiskStat stats[], int *index, int max_stats)
{
    DIR *dir = opendir(dir_path);
    if (dir == NULL)
    {
        printf("Error opening directory %s\n", dir_path);
        return;
    }

    struct dirent *dir_entry;
    while ((dir_entry = readdir(dir)) != NULL)
    {
        if (strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0)
        {
            continue;
        }

        char new_path[MAX_DIR_LEN];
        snprintf(new_path, MAX_DIR_LEN, "%s/%s", dir_path, dir_entry->d_name);

        struct stat dir_stat;
        if (stat(new_path, &dir_stat) == -1)
        {
            printf("Error getting file stats for %s\n", new_path);
            continue;
        }

        if (S_ISDIR(dir_stat.st_mode))
        {
            // Recurse into sub-directory.
            analyze_dir(new_path, stats, index, max_stats);
        }
        else if (S_ISREG(dir_stat.st_mode) && *index < max_stats)
        {
            // Add file to list of stats.
            DiskStat *file_stat = &stats[(*index)++];
            strncpy(file_stat->dir_name, new_path, MAX_DIR_LEN);
            file_stat->size = dir_stat.st_size;
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: analyzer <directory>\n");
        return 1;
    }

    const char *dir_path = argv[1];

    DiskStat stats[MAX_DIR_LEN];
    int stat_count = 0;
    analyze_dir(dir_path, stats, &stat_count, MAX_DIR_LEN);

    // Sort stats by size (in descending order).
    qsort(stats, stat_count, sizeof(DiskStat), compare);

    printf("Top Files In %s\n", dir_path);
    printf("-----------------\n");
    for (int i = 0; i < stat_count; i++)
    {
        DiskStat *stat = &stats[i];
        printf("%-30s %10lld bytes\n", stat->dir_name, stat->size);
    }

    return 0;
}