//Falcon2-11B DATASET v1.0 Category: Antivirus scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_PATH_SIZE 256

// function to scan file for virus signatures
void scanFile(char* fileName) {
    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        return;
    }

    char buffer[MAX_PATH_SIZE];
    while (fgets(buffer, sizeof(buffer), fp)!= NULL) {
        if (strstr(buffer, "virus_signature1")!= NULL || 
            strstr(buffer, "virus_signature2")!= NULL || 
            strstr(buffer, "virus_signature3")!= NULL) {
            printf("Virus found in file: %s\n", fileName);
            fclose(fp);
            return;
        }
    }

    fclose(fp);
}

// function to recursively scan directories for virus signatures
void scanDirectory(char* dirName) {
    DIR* dp;
    struct dirent* de;

    dp = opendir(dirName);
    if (dp == NULL) {
        printf("Error opening directory: %s\n", strerror(errno));
        return;
    }

    while ((de = readdir(dp))!= NULL) {
        if (de->d_type == DT_DIR) {
            char fullPath[MAX_PATH_SIZE];
            sprintf(fullPath, "%s/%s", dirName, de->d_name);
            scanDirectory(fullPath);
        } else {
            char fullPath[MAX_PATH_SIZE];
            sprintf(fullPath, "%s/%s", dirName, de->d_name);
            scanFile(fullPath);
        }
    }

    closedir(dp);
}

// main function
int main(int argc, char* argv[]) {
    char* fileName = argv[1];
    scanFile(fileName);

    char* dirName = argv[2];
    scanDirectory(dirName);

    return 0;
}