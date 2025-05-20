//FormAI DATASET v1.0 Category: File Synchronizer ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

int createDir(const char* path) {
    DIR* directory = opendir(path);
    if (directory) {
        closedir(directory);
        return 0;
    }
    else if (mkdir(path, 0700) == -1) {
        fprintf(stderr, "Error creating directory: %s\n", path);
        return 1;
    }
    else {
        printf("Directory created: %s\n", path);
        return 0;
    }
}

void syncFiles(const char* source, const char* destination) {
    DIR* sourceDir = opendir(source);
    struct dirent* file;
    char sourcePath[300], destinationPath[300];
    while ((file = readdir(sourceDir)) != NULL) {
        if (file->d_type == DT_REG) { // File
            sprintf(sourcePath, "%s/%s", source, file->d_name);
            sprintf(destinationPath, "%s/%s", destination, file->d_name);
            FILE* sourceFile = fopen(sourcePath, "rb");
            FILE* destinationFile = fopen(destinationPath, "rb");
            struct stat sourceStat, destinationStat;
            stat(sourcePath, &sourceStat);
            stat(destinationPath, &destinationStat);
            if (sourceStat.st_mtime > destinationStat.st_mtime) {
                if (destinationFile) {
                    fclose(destinationFile);
                }
                destinationFile = fopen(destinationPath, "wb");
                if (!destinationFile) {
                    fprintf(stderr, "Error opening file: %s\n", destinationPath);
                    return;
                }
                char buffer[1024];
                int bytesRead;
                while ((bytesRead = fread(&buffer, 1, sizeof(buffer), sourceFile)) > 0) {
                    fwrite(buffer, 1, bytesRead, destinationFile);
                }
                printf("File updated: %s\n", destinationPath);
            }
            fclose(sourceFile);
            fclose(destinationFile);
        }
        else if (file->d_type == DT_DIR) { // Directory
            if (strcmp(file->d_name, ".") != 0 && strcmp(file->d_name, "..") != 0) {
                sprintf(sourcePath, "%s/%s", source, file->d_name);
                sprintf(destinationPath, "%s/%s", destination, file->d_name);
                createDir(destinationPath);
                syncFiles(sourcePath, destinationPath);
            }
        }
    }
    closedir(sourceDir);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s [source directory] [destination directory]\n", argv[0]);
        return 1;
    }
    if (access(argv[1], F_OK) == -1) {
        fprintf(stderr, "Error: source directory does not exist.\n");
        return 1;
    }
    if (access(argv[2], F_OK) == -1) {
        fprintf(stderr, "Warning: destination directory does not exist. Creating...\n");
        if (createDir(argv[2]) != 0) {
            return 1;
        }
    }
    syncFiles(argv[1], argv[2]);
    return 0;
}