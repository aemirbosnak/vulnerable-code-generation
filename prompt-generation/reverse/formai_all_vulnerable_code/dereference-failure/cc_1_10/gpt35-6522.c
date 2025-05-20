//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

// function to convert file size from bytes to human-readable format
void convertSize(long int sizeBytes, char *sizeHuman){
    const int unitDivisor = 1024;
    if (sizeBytes < unitDivisor){
        sprintf(sizeHuman, "%ld B", sizeBytes);
    } else {
        const char units[] = {'K', 'M', 'G', 'T', 'P', 'E', 'Z', 'Y'};
        int i = 0;
        double size = sizeBytes;
        while (size >= unitDivisor){
            size /= unitDivisor;
            i++;
        }
        sprintf(sizeHuman, "%.1f %cB", size, units[i-1]);
    }
}

// recursive function that calculates and prints disk usage of a directory
void calculateDirectorySize(char *dirPath, int level, long int *totalSize){
    DIR *dir;
    struct dirent *entry;
    struct stat fStat;
    char fileName[1000], filePath[1000], sizeHuman[10];
    long int sizeBytes = 0;
    if ((dir = opendir(dirPath)) != NULL){
        while ((entry = readdir(dir)) != NULL){
            if (entry->d_type == DT_DIR){
                if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0){
                    // recursively call this function for inner directories
                    sprintf(filePath, "%s/%s", dirPath, entry->d_name);
                    calculateDirectorySize(filePath, level + 1, totalSize);
                }
            } else {
                sprintf(fileName, "%s/%s", dirPath, entry->d_name);
                if (stat(fileName, &fStat) == 0){
                    sizeBytes += fStat.st_size;
                }
            }
        }
        convertSize(sizeBytes, sizeHuman);
        printf("%*sTotal size: %s\n", level*4, "", sizeHuman);
        *totalSize += sizeBytes;
        closedir(dir);
    }
}

int main(int argc, char const *argv[]){
    int i;
    long int totalSize = 0;
    // loop through all arguments
    for (i = 1; i < argc; i++){
        printf("%s:\n", argv[i]);
        calculateDirectorySize((char *)argv[i], 1, &totalSize);
    }
    char totalSizeHuman[10];
    convertSize(totalSize, totalSizeHuman);
    printf("\nTotal disk usage: %s\n", totalSizeHuman);
    return 0;
}