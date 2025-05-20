//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void printUsage()
{
    printf("Usage: ./diskanalyzer [directory path]\n");
}

int fileSize(const char *filename)
{
    struct stat st;
    if(stat(filename, &st) == 0)
    {
        return st.st_size;
    }
    return -1; 
}

void analyzeDirectory(const char *dirPath, int depth, int *totalSize)
{
    DIR *directory = opendir(dirPath);

    if(!directory)
    {
        perror(dirPath);
        return;
    }

    struct dirent *entry;
    while((entry = readdir(directory)) != NULL)
    {
        if(entry->d_type == DT_DIR)
        {
            // Ignore . and .. directories
            if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            {
                continue;
            }

            char *subdirPath = malloc(strlen(dirPath) + strlen(entry->d_name) + 2);
            sprintf(subdirPath, "%s/%s", dirPath, entry->d_name);

            analyzeDirectory(subdirPath, depth+1, totalSize);

            free(subdirPath);
        }
        else
        {
            char *filename = malloc(strlen(dirPath) + strlen(entry->d_name) + 2);
            sprintf(filename, "%s/%s", dirPath, entry->d_name);

            int file_size = fileSize(filename);
            if(file_size >= 0)
            {
                *totalSize += file_size;
            }

            free(filename);
        }
    }

    closedir(directory);
}

int main(int argc, char *argv[])
{
    printf("Disk space analyzer\n");

    if(argc != 2)
    {
        printUsage();
        return 1;
    }

    const char *dirPath = argv[1];
    printf("Analyzing directory: %s\n", dirPath);

    int totalSize = 0;

    analyzeDirectory(dirPath, 0, &totalSize);

    printf("Total size of directory: %d bytes\n", totalSize);

    return 0;
}