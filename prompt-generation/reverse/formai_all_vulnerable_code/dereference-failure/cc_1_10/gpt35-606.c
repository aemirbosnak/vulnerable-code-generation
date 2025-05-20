//FormAI DATASET v1.0 Category: System administration ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void print_directory_content(char* path, int depth)
{
    DIR* dir;
    struct dirent* entry;
    struct stat file_stat;
    char full_path[1024];

    if(!(dir = opendir(path)))
    {
        printf("Failed to open directory: %s\n", path);
        return;
    }

    while((entry = readdir(dir)) != NULL)
    {
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        sprintf(full_path, "%s/%s", path, entry->d_name);

        if(stat(full_path, &file_stat) < 0)
        {
            continue;
        }

        for(int i = 0; i < depth; i++)
        {
            printf("|  ");
        }

        printf("|--%s\n", entry->d_name);

        if(S_ISDIR(file_stat.st_mode))
        {
            print_directory_content(full_path, depth + 1);
        }
    }

    closedir(dir);
}

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        printf("Usage: %s directory\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* path = argv[1];

    printf("Printing directory content of: %s\n", path);
    print_directory_content(path, 0);

    return EXIT_SUCCESS;
}