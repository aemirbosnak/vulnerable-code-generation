//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>

#define PARANOID_MODE 1

void analyze_directory(char *path, int level);

int main()
{
    char path[100];

    printf("Enter path of directory to analyze (e.g. C:\\Users\\John\\Desktop): ");
    scanf("%s", path);

    printf("\nAnalyzing directory %s...\n", path);
    analyze_directory(path, 0);

    return 0;
}

void analyze_directory(char *path, int level)
{
    DIR *directory = opendir(path);

    if(!directory)
    {
        if(PARANOID_MODE)
        {
            printf("Error opening directory %s: %s\n", path, strerror(errno));
        }
        return;
    }

    struct dirent *entry;

    while((entry = readdir(directory)) != NULL)
    {
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        char file_path[500];
        sprintf(file_path, "%s/%s", path, entry->d_name);

        struct stat statbuf;

        if(stat(file_path, &statbuf) == -1)
        {
            if(PARANOID_MODE)
            {
                printf("Error getting file stats for %s: %s\n", file_path, strerror(errno));
            }
            continue;
        }

        if(S_ISDIR(statbuf.st_mode))
        {
            printf("%*s%s/  (%.2f MB)\n", level*4, "", entry->d_name, (float)statbuf.st_size/(1024*1024));
            analyze_directory(file_path, level+1);
        }
        else if(S_ISREG(statbuf.st_mode))
        {
            printf("%*s%s  (%.2f MB)\n", level*4, "", entry->d_name, (float)statbuf.st_size/(1024*1024));
        }
        else
        {
            if(PARANOID_MODE)
            {
                printf("Unknown file type for %s. Skipping...\n", file_path);
            }
        }
    }

    if(closedir(directory) == -1)
    {
        if(PARANOID_MODE)
        {
            printf("Error closing directory %s: %s\n", path, strerror(errno));
        }
    }
}