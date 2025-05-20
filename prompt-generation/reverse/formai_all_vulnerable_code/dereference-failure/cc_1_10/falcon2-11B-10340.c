//Falcon2-11B DATASET v1.0 Category: Disk space analyzer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int main() {
    // Declare variables
    char* dir_name = "/path/to/directory";
    char* file_name = "/path/to/file";
    char* path = "/path/to/directory/";
    struct dirent* dp;
    struct stat file_stat;
    DIR* dir;
    FILE* fp;
    int file_size;

    // Open the directory
    dir = opendir(dir_name);
    if (dir == NULL) {
        printf("Error opening directory\n");
        return 1;
    }

    // Loop through all files in the directory
    while ((dp = readdir(dir))!= NULL) {
        // Check if the file is a directory or a regular file
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
            continue;

        // Get the full path to the file
        sprintf(path, "%s%s", dir_name, dp->d_name);

        // Open the file for reading
        fp = fopen(path, "r");
        if (fp == NULL) {
            printf("Error opening file\n");
            continue;
        }

        // Get the size of the file
        fseek(fp, 0, SEEK_END);
        file_size = ftell(fp);
        fseek(fp, 0, SEEK_SET);

        // Get the current time
        time_t rawtime;
        struct tm * timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        char* time_str = asctime(timeinfo);
        time_str[strlen(time_str) - 1] = '\0';

        // Print the file name, size, and current time
        printf("%s %s %d\n", dp->d_name, time_str, file_size);

        // Close the file
        fclose(fp);
    }

    // Close the directory
    closedir(dir);

    return 0;
}