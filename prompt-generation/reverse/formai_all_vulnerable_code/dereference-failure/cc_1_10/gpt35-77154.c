//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

/* Function to calculate directory and file size */
long long int calculateSize(const char* path)
{
    struct stat statbuf;
    if (stat(path, &statbuf) == -1)
        return 0;

    // Check if the path is a directory
    if (S_ISDIR(statbuf.st_mode))
    {
        long long int size = 0;
        DIR *dir;
        struct dirent *ent;

        if ((dir = opendir(path)) != NULL)
        {
            while ((ent = readdir(dir)) != NULL)
            {
                if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0)
                {
                    char *newPath = malloc(sizeof(char)*(strlen(path)+strlen(ent->d_name)+2));
                    sprintf(newPath, "%s/%s", path, ent->d_name);
                    size += calculateSize(newPath);
                    free(newPath);
                }
            }
            closedir(dir);
            return size;
        }
        else
            return 0;
    }

    // Path is a file
    return statbuf.st_size;
}

/* Function to print the size of the given path */
void printSize(const char* path)
{
    long long int size = calculateSize(path);

    printf("%s: %lld bytes\n", path, size);
}

/* Main function */
int main(int argc, char *argv[])
{
    if (argc == 1)
        printSize(".");

    // Loop through all given paths
    for (int i = 1; i < argc; i++)
        printSize(argv[i]);

    return 0;
}