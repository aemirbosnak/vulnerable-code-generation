//FormAI DATASET v1.0 Category: File Synchronizer ; Style: detailed
/*
    * Program: File Synchronizer
    * Author: [Your Name]
    * Description: This program synchronizes two directories, copying any files from the source
    *              directory to the target directory that do not already exist, or are newer in the source.
    */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>

#define MAX_PATH_LENGTH 256

void syncDirectories(char* source, char* target);
void syncFiles(char* source, char* target, char* filename);

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("Usage: %s <source_directory> <target_directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    syncDirectories(argv[1], argv[2]);

    return 0;
}

void syncDirectories(char* source, char* target)
{
    DIR* dir;
    struct dirent* entry;

    if((dir = opendir(source)) == NULL)
    {
        fprintf(stderr, "Error: Could not open directory %s: %s\n", source, strerror(errno));
        exit(EXIT_FAILURE);
    }

    while((entry = readdir(dir)) != NULL)
    {
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        char sourceFile[MAX_PATH_LENGTH], targetFile[MAX_PATH_LENGTH];

        snprintf(sourceFile, MAX_PATH_LENGTH, "%s/%s", source, entry->d_name);
        snprintf(targetFile, MAX_PATH_LENGTH, "%s/%s", target, entry->d_name);

        struct stat sourceStat, targetStat;

        if(stat(sourceFile, &sourceStat) == -1)
        {
            fprintf(stderr, "Error: Could not stat file %s: %s\n", sourceFile, strerror(errno));
            continue;
        }

        if(stat(targetFile, &targetStat) == -1 && errno != ENOENT)
        {
            fprintf(stderr, "Error: Could not stat file %s: %s\n", targetFile, strerror(errno));
            continue;
        }

        if(S_ISDIR(sourceStat.st_mode))
        {
            if(mkdir(targetFile, sourceStat.st_mode) == -1)
            {
                fprintf(stderr, "Error: Could not create directory %s: %s\n", targetFile, strerror(errno));
            }
            else
            {
                syncDirectories(sourceFile, targetFile);
            }
        }
        else if(S_ISREG(sourceStat.st_mode))
        {
            if(S_ISREG(targetStat.st_mode))
            {
                if(difftime(sourceStat.st_mtime, targetStat.st_mtime) > 0)
                {
                    syncFiles(sourceFile, targetFile, entry->d_name);
                }
            }
            else if(errno == ENOENT)
            {
                syncFiles(sourceFile, targetFile, entry->d_name);
            }
        }
    }

    closedir(dir);
}

void syncFiles(char* source, char* target, char* filename)
{
    FILE* sourceFile, * targetFile;
    char buffer[1024];
    size_t bytesRead;

    if((sourceFile = fopen(source, "rb")) == NULL)
    {
        fprintf(stderr, "Error: Could not open file %s: %s\n", source, strerror(errno));
        return;
    }

    if((targetFile = fopen(target, "wb")) == NULL)
    {
        fprintf(stderr, "Error: Could not create file %s: %s\n", target, strerror(errno));
        fclose(sourceFile);
        return;
    }

    while((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0)
    {
        fwrite(buffer, 1, bytesRead, targetFile);
    }

    fclose(sourceFile);
    fclose(targetFile);

    printf("Synchronized file %s\n", filename);
}