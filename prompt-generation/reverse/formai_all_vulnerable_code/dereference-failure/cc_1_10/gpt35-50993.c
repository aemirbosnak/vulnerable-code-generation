//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void analyze(const char* path);

int main(int argc, char* argv[])
{
    const char* path;
    if (argc > 1)
        path = argv[1];
    else
        path = ".";

    analyze(path);

    return 0;
}

void analyze(const char* path)
{
    DIR* dir = opendir(path);
    if (!dir)
    {
        printf("Could not open directory: %s", path);
        return;
    }

    int total_size = 0;
    int file_count = 0;
    struct dirent* file;
    while ((file = readdir(dir)) != NULL)
    {
        char file_path[PATH_MAX];
        sprintf(file_path, "%s/%s", path, file->d_name);

        struct stat file_stat;
        if (stat(file_path, &file_stat) == -1)
        {
            printf("Could not stat file: %s", file_path);
            continue;
        }

        if (S_ISREG(file_stat.st_mode))
        {
            total_size += file_stat.st_size;
            file_count++;
        }
        else if (S_ISDIR(file_stat.st_mode))
        {
            if (strcmp(file->d_name, ".") != 0 && strcmp(file->d_name, "..") != 0)
                analyze(file_path);
        }
    }

    printf("Directory: %s\n", path);
    printf("Total size of all files: %d bytes\n", total_size);
    printf("Number of files: %d\n\n", file_count);

    closedir(dir);
}