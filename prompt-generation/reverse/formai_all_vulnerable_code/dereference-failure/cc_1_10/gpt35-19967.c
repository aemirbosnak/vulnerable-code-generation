//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

//function to analyze disk space
void analyzeDiskSpace(char *path, int depth) {
    struct stat fileStat;
    long long size, totalSize = 0;
    DIR *dir;
    struct dirent *entry;
    char filePath[1024], fileName[1024];

    //open the directory
    if (!(dir = opendir(path)))
        return;
    if (!(entry = readdir(dir)))
        return;

    //loop through all the files and directories in the given path
    do {
        //get file path and name
        snprintf(filePath, sizeof(filePath), "%s/%s", path, entry->d_name);
        snprintf(fileName, sizeof(fileName),"%s", entry->d_name);

        //skip current and parent directory
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        //get file stats
        if (lstat(filePath, &fileStat) < 0)
            continue;

        //if directory, recursively analyze its contents
        if (S_ISDIR(fileStat.st_mode)) {
            size = 0;
            analyzeDiskSpace(filePath, depth + 1);
            printf("%*s- %s/\n", depth, "", fileName);
        }
        else {
            size = fileStat.st_size;
            printf("%*s- %s\n", depth, "", fileName);
        }

        totalSize += size;
    } while (entry = readdir(dir));

    //print total size of current directory
    printf("%*sTotal Size: %lldbytes\n", depth, "", totalSize);
    closedir(dir);
}

//main function
int main() {
    printf("Enter the path of the directory to analyze: ");
    char path[1024];
    scanf("%s", path);

    printf("Analyzing disk space...\n");

    //call disk space analysis function
    analyzeDiskSpace(path, 0);

    printf("Disk space analysis complete!\n");

    return 0;
}