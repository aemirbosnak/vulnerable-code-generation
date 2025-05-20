//FormAI DATASET v1.0 Category: File Synchronizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void createDirectory(char* path) {
    DIR* dir = opendir(path);
    if(dir == NULL) {
        mkdir(path, 0777);
    }
    else {
        closedir(dir);
    }
}

void copyFile(char* sourcePath, char* destinationPath) {
    FILE* source = fopen(sourcePath, "r");
    FILE* destination = fopen(destinationPath, "w");

    if(source == NULL || destination == NULL) {
        printf("\nError: Could not open file!\n\n");
        exit(1);
    }

    char buffer[1024];
    size_t bytes;

    while((bytes = fread(buffer, 1, sizeof(buffer), source)) != 0) {
        fwrite(buffer, 1, bytes, destination);
    }

    printf("\nFile copied successfully!\n\n");

    fclose(source);
    fclose(destination);
}

void synchronizeDirectories(char *sourceDirectory, char *destinationDirectory) {
    DIR *dir;
    struct dirent *entry;

    // Open source directory
    if((dir = opendir(sourceDirectory)) == NULL) {
        printf("\nError: Could not open directory %s\n\n", sourceDirectory);
        exit(1);
    }
    else {
        createDirectory(destinationDirectory);
        while((entry = readdir(dir)) != NULL) {
            char sourcePath[1024], destinationPath[1024];

            if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;

            sprintf(sourcePath, "%s/%s", sourceDirectory, entry->d_name);
            sprintf(destinationPath, "%s/%s", destinationDirectory, entry->d_name);

            struct stat statbuf;
            if(stat(sourcePath, &statbuf) == -1) {
                printf("\nError: Could not get file information\n\n");
                exit(1);
            }

            if(S_ISDIR(statbuf.st_mode)) {
                synchronizeDirectories(sourcePath, destinationPath);
            }
            else if(S_ISREG(statbuf.st_mode)) {
                copyFile(sourcePath, destinationPath);
            }
            else {
                printf("\nWarning: Unsupported file type %s\n\n", entry->d_name);
            }
        }

        closedir(dir);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [Source Directory] [Destination Directory]\n\n", argv[0]);
        exit(1);
    }

    synchronizeDirectories(argv[1], argv[2]);

    printf("\nSync completed successfully!\n\n");

    return 0;
}