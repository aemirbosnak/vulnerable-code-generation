//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: Ada Lovelace
// C program to analyze disk space usage in the Ada Lovelace style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to calculate the size of a file
long long int file_size(char *filename)
{
    struct stat st;
    stat(filename, &st);
    return st.st_size;
}

// Function to calculate the size of a directory
long long int directory_size(char *dirname)
{
    DIR *dir;
    struct dirent *ent;
    long long int size = 0;

    dir = opendir(dirname);
    if (dir == NULL)
    {
        perror("opendir");
        return -1;
    }

    while ((ent = readdir(dir)) != NULL)
    {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
            continue;

        char *path = malloc(strlen(dirname) + strlen(ent->d_name) + 2);
        strcpy(path, dirname);
        strcat(path, "/");
        strcat(path, ent->d_name);

        struct stat st;
        stat(path, &st);

        if (S_ISDIR(st.st_mode))
            size += directory_size(path);
        else
            size += file_size(path);

        free(path);
    }

    closedir(dir);

    return size;
}

// Main function
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *dirname = argv[1];

    long long int size = directory_size(dirname);

    printf("The size of the directory %s is %lld bytes.\n", dirname, size);

    return EXIT_SUCCESS;
}