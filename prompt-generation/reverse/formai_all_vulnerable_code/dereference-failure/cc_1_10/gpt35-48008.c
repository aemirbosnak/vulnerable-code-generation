//FormAI DATASET v1.0 Category: File Synchronizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

void synchronizeFiles(char *sourceDir, char *destinationDir);

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: ./sync <source_directory> <destination_directory>\n");
        exit(EXIT_FAILURE);
    }

    synchronizeFiles(argv[1], argv[2]);

    printf("Files synchronized successfully!\n");
    return 0;
}

void synchronizeFiles(char *sourceDir, char *destinationDir) {
    DIR *dir = opendir(sourceDir);
    struct dirent *entry;
    while((entry = readdir(dir)) != NULL) {
        // Ignore current and parent directory and hidden files
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0
            || entry->d_name[0] == '.') {
            continue;
        }
        
        char sourcePath[1024], destPath[1024];
        sprintf(sourcePath, "%s/%s", sourceDir, entry->d_name);
        sprintf(destPath, "%s/%s", destinationDir, entry->d_name);
        
        struct stat statSource;
        lstat(sourcePath, &statSource);
        
        if(S_ISREG(statSource.st_mode)) {
            // Source file is a regular file
            struct stat statDest;
            int destExists = !lstat(destPath, &statDest);
            if(destExists) {
                // Destination file already exists
                if(statSource.st_mtime > statDest.st_mtime) {
                    // Source file is more recent than destination file
                    printf("Updating %s\n", destPath);
                    FILE *sourceFile = fopen(sourcePath, "rb");
                    FILE *destFile = fopen(destPath, "wb");
                    char buffer[1024];
                    size_t size;
                    while((size = fread(buffer, 1, sizeof(buffer), sourceFile))) {
                        fwrite(buffer, 1, size, destFile);
                    }
                    fclose(sourceFile);
                    fclose(destFile);
                }
            } else {
                // Destination file does not exist
                printf("Creating %s\n", destPath);
                FILE *sourceFile = fopen(sourcePath, "rb");
                FILE *destFile = fopen(destPath, "wb");
                char buffer[1024];
                size_t size;
                while((size = fread(buffer, 1, sizeof(buffer), sourceFile))) {
                    fwrite(buffer, 1, size, destFile);
                }
                fclose(sourceFile);
                fclose(destFile);
            }
        } else if(S_ISDIR(statSource.st_mode)) {
            // Source file is a directory
            struct stat statDest;
            int destExists = !lstat(destPath, &statDest);
            if(!destExists) {
                // Destination directory does not exist
                printf("Creating %s\n", destPath);
                mkdir(destPath, statSource.st_mode);
            }
            // Recurse into sub-directory
            synchronizeFiles(sourcePath, destPath);
        }
    }
    closedir(dir);
}