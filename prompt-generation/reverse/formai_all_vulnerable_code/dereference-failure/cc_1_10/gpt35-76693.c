//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void printSize(double size)
{
    char* suffix = "Bytes";

    if (size >= 1024)
    {
        suffix = "KB";
        size /= 1024;
    }

    if (size >= 1024)
    {
        suffix = "MB";
        size /= 1024;
    }

    if (size >= 1024)
    {
        suffix = "GB";
        size /= 1024;
    }

    printf("%.2lf %s\n", size, suffix);
}

double getDirectorySize(char* path)
{
    DIR* dir = opendir(path);

    if (dir == NULL)
    {
        printf("Error: Could not open directory!\n");
        return -1;
    }

    double totalSize = 0;

    struct dirent* entry;

    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
        {
            char dirPath[1024];

            snprintf(dirPath, sizeof(dirPath), "%s/%s", path, entry->d_name);

            double dirSize = getDirectorySize(dirPath);

            if (dirSize == -1)
            {
                closedir(dir);
                return -1;
            }

            totalSize += dirSize;
        }
        else
        {
            char filePath[1024];

            snprintf(filePath, sizeof(filePath), "%s/%s", path, entry->d_name);

            FILE* file = fopen(filePath, "rb");

            if (file == NULL)
            {
                printf("Error: Could not open file %s!\n", filePath);
                closedir(dir);
                return -1;
            }

            fseek(file, 0L, SEEK_END);
            double fileSize = ftell(file);
            fclose(file);

            if (fileSize == -1)
            {
                printf("Error: Could not get size of file %s!\n", filePath);
                closedir(dir);
                return -1;
            }

            totalSize += fileSize;
        }
    }

    closedir(dir);

    return totalSize;
}

int main()
{
    char path[1024];

    printf("Enter path to directory: ");
    scanf("%s", path);

    double size = getDirectorySize(path);

    if (size != -1)
    {
        printf("Total Size: ");
        printSize(size);
    }

    return 0;
}