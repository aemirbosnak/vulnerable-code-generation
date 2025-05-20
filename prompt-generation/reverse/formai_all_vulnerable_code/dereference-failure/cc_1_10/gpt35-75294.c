//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>

#define MAX_PATH_LENGTH 100

void analyzeDirectory(char *path)
{
    DIR *dir;
    struct dirent *dp;
    struct stat fileStat;
    long int total_size = 0;
    char filePath[MAX_PATH_LENGTH+1];

    dir = opendir(path);

    if(dir == NULL)
    {
        fprintf(stderr, "Error: Cannot open directory '%s' - %s\n", path, strerror(errno));
        return;
    }

    printf("\nPath: %s\n", path);
    printf("---------------------------------------------------\n");
    printf("%-20s\t%-10s\t%-10s\n", "Filename", "Size", "Type");
    printf("---------------------------------------------------\n");
    
    while((dp = readdir(dir)) != NULL)
    {
        snprintf(filePath, MAX_PATH_LENGTH+1, "%s/%s", path, dp->d_name);
        
        if(lstat(filePath, &fileStat) < 0)
        {
            fprintf(stderr, "Error: Cannot get file stat - %s\n", strerror(errno));
            continue;
        }

        if(S_ISDIR(fileStat.st_mode))
        {
            if(strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
            {
                continue;
            }
            
            analyzeDirectory(filePath);
        }
        else
        {
            printf("%-20s\t%-10ld\t%-10s\n", dp->d_name, fileStat.st_size, "File");
            total_size += fileStat.st_size;
        }
    }

    printf("---------------------------------------------------\n");
    printf("%-20s\t%-10ld\t%-10s\n", "Total", total_size, "Directory");
    printf("---------------------------------------------------\n");

    closedir(dir);
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Error: Invalid arguments\n");
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *path = argv[1];

    analyzeDirectory(path);

    return 0;
}