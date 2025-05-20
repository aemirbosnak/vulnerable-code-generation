//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// function to calculate folder size
long int calculateSize(char *folder_path)
{
    DIR *dir = opendir(folder_path);

    if (dir == NULL)
        return -1;

    struct dirent *entry;
    struct stat file_stat;
    long int total_size = 0;

    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type != DT_DIR)
        {
            char path[1024];
            sprintf(path, "%s/%s", folder_path, entry->d_name);
            if (stat(path, &file_stat) == 0)
                total_size += file_stat.st_size;
        }
        else if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
        {
            char path[1024];
            sprintf(path, "%s/%s", folder_path, entry->d_name);

            long int folder_size = calculateSize(path);
            if (folder_size < 0)
                return -1;
            else
                total_size += folder_size;
        }
    }

    closedir(dir);
    return total_size;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Error: Please provide a path to a folder.\n");
        return 1;
    }

    long int folder_size = calculateSize(argv[1]);

    if (folder_size < 0)
    {
        printf("Error: Invalid folder path.\n");
        return 1;
    }

    printf("%s : %ld bytes\n", argv[1], folder_size);

    return 0;
}