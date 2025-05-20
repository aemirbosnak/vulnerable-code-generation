//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

//Function to convert Bytes into KB, MB and GB
void convertByteFormat(long long int bytes, char* convertedBytes){

    if (bytes >= 1073741824){
        sprintf(convertedBytes, "%.2f GB", (float)bytes / 1073741824);
    }
    else if (bytes >= 1048576){
        sprintf(convertedBytes, "%.2f MB", (float)bytes / 1048576);
    }
    else if (bytes >= 1024){
        sprintf(convertedBytes, "%.2f KB", (float)bytes / 1024);
    }
    else{
        sprintf(convertedBytes, "%lld Bytes", bytes);
    }
}

//Function to calculate disk space used by a directory recursively
void calculateDiskSpace(char* directory, long long int* totalSize){

    DIR* dir = opendir(directory);
    struct dirent* dirContent;

    while((dirContent = readdir(dir)) != NULL){

        if(strcmp(dirContent->d_name, ".") == 0 || strcmp(dirContent->d_name, "..") == 0){
            continue;
        }

        char path[1000];
        strcpy(path, directory);
        strcat(path, "/");
        strcat(path, dirContent->d_name);

        struct stat pathInfo;

        if(stat(path, &pathInfo) != 0){
            printf("Error! Could not access file/directory.\n");
            exit(1);
        }

        if(S_ISREG(pathInfo.st_mode)){
            *totalSize += pathInfo.st_size;
        }

        else if(S_ISDIR(pathInfo.st_mode)){
            calculateDiskSpace(path, totalSize);
        }
    }
    closedir(dir);
}

//Main function to calculate disk space usage and create report
int main(){

    char directory[100];
    long long int totalSize = 0;
    char convertedTotalSize[20];

    printf("Enter directory: ");
    scanf("%s", directory);

    calculateDiskSpace(directory, &totalSize);
    convertByteFormat(totalSize, convertedTotalSize);

    printf("Total size of %s: %s\n", directory, convertedTotalSize);

    return 0;
}