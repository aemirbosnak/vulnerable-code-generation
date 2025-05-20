//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <math.h>

#define GB 1073741824.0
#define MB 1048576.0
#define KB 1024.0

struct File
{
    char name[256];
    double size;
};

void getDirectorySize(char *directory, double *total_size)
{
    DIR *dir = opendir(directory);

    if (dir == NULL)
    {
        return;
    }

    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
        {
            char path[256];
            snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);
            getDirectorySize(path, total_size);
        }
        else if (entry->d_type == DT_REG)
        {
            *total_size += entry->d_reclen;
        }
    }

    closedir(dir);
}

void getFiles(char *directory, struct File **files, int *num_files)
{
    DIR *dir = opendir(directory);

    if (dir == NULL)
    {
        return;
    }

    struct dirent *entry;
    struct File *current_files = *files;

    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
        {
            char path[256];
            snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);
            getFiles(path, files, num_files);
        }
        else if (entry->d_type == DT_REG)
        {
            current_files[*num_files].size = entry->d_reclen;
            strcpy(current_files[*num_files].name, entry->d_name);
            (*num_files)++;
        }
    }

    closedir(dir);
}

int compare(const void *file1, const void *file2)
{
    const struct File *f1 = file1;
    const struct File *f2 = file2;

    if (f1->size > f2->size)
    {
        return -1;
    }
    else if (f1->size < f2->size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void printFiles(struct File *files, int num_files, double total_size)
{
    printf("\n%-30s %-15s %-15s %-15s\n\n", "Filename", "Size", "Percentage", "Bar");

    for (int i = 0; i < num_files; i++)
    {
        double percentage = (files[i].size / total_size) * 100.0;

        printf("%-30s ", files[i].name);
        printf("%-15.2f ", files[i].size);

        if (percentage < 1.0)
        {
            printf("%-15.2f%% ", percentage);
        }
        else
        {
            printf("%-15.0f%% ", percentage);
        }

        int bars = nearbyint(percentage);

        for (int j = 0; j < bars; j++)
        {
            putchar('#');
        }

        putchar('\n');
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: disk-space-analyzer <directory>\n");
        return 1;
    }

    double total_size = 0.0;
    getDirectorySize(argv[1], &total_size);

    double size_gb = total_size / GB;
    double size_mb = total_size / MB;
    double size_kb = total_size / KB;

    printf("Total size: %.2f ", total_size);

    if (size_gb >= 1.0)
    {
        printf("(%.2f GB)\n", size_gb);
    }
    else if (size_mb >= 1.0)
    {
        printf("(%.2f MB)\n", size_mb);
    }
    else if (size_kb >= 1.0)
    {
        printf("(%.2f KB)\n", size_kb);
    }
    else
    {
        printf("(%.2f bytes)\n", total_size);
    }

    struct File *files = malloc(total_size * sizeof(struct File));
    int num_files = 0;
    getFiles(argv[1], &files, &num_files);

    qsort(files, num_files, sizeof(struct File), compare);

    printFiles(files, num_files, total_size);

    free(files);

    return 0;
}