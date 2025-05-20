//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void analyzeDirectory(char *basePath, int *totalSize)
{
    char filePath[1000];
    struct dirent *dp;
    struct stat statbuf;
    DIR *dir = opendir(basePath);

    if (!dir)
    {
        printf("Error: Failed to open directory.\n");
        exit(EXIT_FAILURE);
    }

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            sprintf(filePath, "%s/%s", basePath, dp->d_name);

            if (stat(filePath, &statbuf) == -1)
            {
                printf("Error: Failed to get file status.\n");
                exit(EXIT_FAILURE);
            }

            if (S_ISREG(statbuf.st_mode))
            {
                printf("%s\t\t%ld bytes\n", dp->d_name, statbuf.st_size);
                *totalSize += statbuf.st_size;
            }

            if (S_ISDIR(statbuf.st_mode))
            {
                analyzeDirectory(filePath, totalSize);
            }
        }
    }

    closedir(dir);
}

int main()
{
    int totalSize = 0;
    char basePath[100];

    printf("Enter directory path to analyze: ");
    scanf("%s", basePath);

    printf("Filename\t\tSize\n\n");

    analyzeDirectory(basePath, &totalSize);

    printf("\nTotal disk space used: %d bytes", totalSize);

    return 0;
}