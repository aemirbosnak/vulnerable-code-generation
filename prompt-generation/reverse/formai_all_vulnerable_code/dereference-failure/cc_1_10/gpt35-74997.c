//FormAI DATASET v1.0 Category: File Synchronizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    const char* sourceDir = argv[1];
    const char* destinationDir = argv[2];

    DIR* source = opendir(sourceDir);
    if (source == NULL) {
        printf("Error opening source directory.\n");
        return 1;
    }

    DIR* destination = opendir(destinationDir);
    if (destination == NULL) {
        printf("Error opening destination directory.\n");
        return 1;
    }

    struct dirent* sourceEntry;
    struct dirent* destEntry;

    while ((sourceEntry = readdir(source)) != NULL) {
        if (strcmp(sourceEntry->d_name, ".") != 0 && strcmp(sourceEntry->d_name, "..") != 0) {

            // Check if file exists in destination directory
            int found = 0;
            rewinddir(destination);
            while ((destEntry = readdir(destination)) != NULL) {
                if (strcmp(destEntry->d_name, sourceEntry->d_name) == 0) {
                    found = 1;
                    break;
                }
            }

            // If file exists, check if same size
            // If same size, skip (file is already synced)
            if (found) {
                struct stat sourceStat;
                struct stat destStat;

                char sourcePath[1024];
                sprintf(sourcePath, "%s/%s", sourceDir, sourceEntry->d_name);

                char destPath[1024];
                sprintf(destPath, "%s/%s", destinationDir, destEntry->d_name);

                stat(sourcePath, &sourceStat);
                stat(destPath, &destStat);

                if (sourceStat.st_size == destStat.st_size) {
                    continue;
                }
            }

            // Copy file from source directory to destination directory
            char command[1024];
            sprintf(command, "cp %s/%s %s", sourceDir, sourceEntry->d_name, destinationDir);
            system(command);
        }
    }

    printf("File synchronization complete.\n");

    closedir(source);
    closedir(destination);

    return 0;
}