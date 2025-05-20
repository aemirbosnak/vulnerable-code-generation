//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH 1024

/* declare function prototypes */
int get_dir_size(char *path);
void print_size(long);

int main(int argc, char **argv)
{
    char *path;
    int total_size;

    /* get the directory path from command-line argument */
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <directory path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    else
    {
        path = argv[1];
    }

    printf("Calculating disk space usage for %s...\n", path);

    /* call get_dir_size function to get the total size of the directory */
    total_size = get_dir_size(path);

    /* print the total size in human-readable format */
    printf("Total Size: ");
    print_size(total_size);
    printf("\n");

    return EXIT_SUCCESS;
}

/* function to get the size of directories or files */
int get_dir_size(char *path)
{
    DIR *dir;
    struct dirent *entry;
    struct stat info;
    char subpath[MAX_PATH];
    int size = 0;

    /* open the directory for reading */
    if ((dir = opendir(path)) == NULL)
    {
        return size;
    }

    /* loop through all entries in the directory */
    while ((entry = readdir(dir)) != NULL)
    {
        /* skip hidden files and directories */
        if (entry->d_name[0] == '.')
        {
            continue;
        }

        /* construct the full path of the entry */
        strcpy(subpath, path);
        strcat(subpath, "/");
        strcat(subpath, entry->d_name);

        /* get the information of the entry */
        if (stat(subpath, &info) == -1)
        {
            fprintf(stderr, "Failed to stat %s\n", subpath);
            continue;
        }

        /* check if the entry is a directory */
        if (S_ISDIR(info.st_mode))
        {
            size += get_dir_size(subpath); /* recursively call the function */
        }
        else
        {
            size += info.st_size; /* add the size of the file */
        }
    }

    /* close the directory and return the total size */
    closedir(dir);
    return size;
}

/* function to print the size in human-readable format */
void print_size(long size)
{
    if (size < 1024)
    {
        printf("%ld B", size);
    }
    else if (size < 1024 * 1024)
    {
        printf("%.2f KB", (float)size / 1024);
    }
    else if (size < 1024 * 1024 * 1024)
    {
        printf("%.2f MB", (float)size / (1024 * 1024));
    }
    else
    {
        printf("%.2f GB", (float)size / (1024 * 1024 * 1024));
    }
}