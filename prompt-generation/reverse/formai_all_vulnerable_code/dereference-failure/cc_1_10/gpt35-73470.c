//FormAI DATASET v1.0 Category: File Backup System ; Style: optimized
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>
#include<time.h>

int main()
{
    // open source directory
    DIR *sourceDir = opendir("./source");

    // check if source directory exists
    if (sourceDir == NULL)
    {
        printf("Error: cannot open directory\n");
        return 0;
    }

    struct dirent *entry;
    char sourcePath[100];
    char backupPath[100];
    char timeStr[20];

    // get current time to add timestamp to backup directory name
    time_t currentTime;
    struct tm *timeInfo;
    time(&currentTime);
    timeInfo = localtime(&currentTime);
    strftime(timeStr, 20, "%Y-%m-%d_%H-%M-%S", timeInfo);

    // create backup directory
    sprintf(backupPath, "./backup/%s", timeStr);
    mkdir(backupPath, 0777);

    // loop through all files in source directory
    while ((entry = readdir(sourceDir)) != NULL)
    {
        // ignore hidden files and current/parent directory files
        if (entry->d_name[0] == '.')
            continue;

        // construct file paths
        sprintf(sourcePath, "./source/%s", entry->d_name);
        sprintf(backupPath, "%s/%s", backupPath, entry->d_name);

        // open source file
        FILE *sourceFile = fopen(sourcePath, "rb");

        if (sourceFile == NULL)
        {
            printf("Error: cannot open file '%s'\n", sourcePath);
            continue;
        }

        // open backup file
        FILE *backupFile = fopen(backupPath, "wb");

        if (backupFile == NULL)
        {
            printf("Error: cannot create file '%s'\n", backupPath);
            fclose(sourceFile);
            continue;
        }

        // copy data from source file to backup file
        char buffer[1024];
        size_t bytesRead;
        while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0)
        {
            fwrite(buffer, 1, bytesRead, backupFile);
        }

        // close files
        fclose(sourceFile);
        fclose(backupFile);
    }

    // close source directory
    closedir(sourceDir);

    printf("Backup successfully created at '%s'\n", backupPath);

    return 0;
}