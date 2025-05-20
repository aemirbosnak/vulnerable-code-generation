//FormAI DATASET v1.0 Category: System administration ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void removeEmptyDirectories(const char *path);
void recursivelyRemoveEmptyDirectories(const char *basePath);

int main(int argc, char *argv[])
{
    char *path = argv[1];

    removeEmptyDirectories(path);

    printf("Empty directories in %s have been successfully removed!\n", path);

    return 0;
}

void removeEmptyDirectories(const char *path)
{
    printf("Removing empty directories in %s...\n", path);

    recursivelyRemoveEmptyDirectories(path);
}

void recursivelyRemoveEmptyDirectories(const char *basePath)
{
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    if (!dir)
    {
        printf("Error: Can't open directory!\n");
        return;
    }

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);

            struct stat st;
            stat(path, &st);

            if (S_ISDIR(st.st_mode))
            {
                recursivelyRemoveEmptyDirectories(path);

                rmdir(path);
                printf("Removed empty directory: %s\n", path);
            }
        }
    }

    closedir(dir);
}