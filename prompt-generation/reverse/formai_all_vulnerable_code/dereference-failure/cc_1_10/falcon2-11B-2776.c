//Falcon2-11B DATASET v1.0 Category: Disk space analyzer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_DIR_NAME_LEN 100

int main()
{
    DIR *dp;
    struct dirent *dirp;
    struct stat st;
    char buf[MAX_DIR_NAME_LEN];
    char *file_name;
    int file_size;
    int dir_size;

    dp = opendir(".");
    if (dp == NULL)
    {
        perror("Error opening directory");
        return 1;
    }

    while ((dirp = readdir(dp))!= NULL)
    {
        if (strcmp(dirp->d_name, ".")!= 0 && strcmp(dirp->d_name, "..")!= 0)
        {
            if (lstat(dirp->d_name, &st) == -1)
            {
                perror("Error getting directory size");
                continue;
            }
            dir_size += st.st_size;

            file_name = strdup(dirp->d_name);
            file_name[strlen(file_name) - 1] = '\0';
            file_size = getFileSize(file_name);
            printf("%s : %ld bytes\n", file_name, file_size);
            free(file_name);
        }
    }
    closedir(dp);

    printf("Total Directory Size : %ld bytes\n", dir_size);

    return 0;
}

int getFileSize(char *file_name)
{
    FILE *fp;
    int size = 0;

    fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return -1;
    }
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fclose(fp);
    return size;
}