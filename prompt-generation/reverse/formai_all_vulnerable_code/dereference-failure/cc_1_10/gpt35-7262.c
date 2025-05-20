//FormAI DATASET v1.0 Category: File Synchronizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

/* This is a file synchronizer program that compares two directories and updates them accordingly
using C programming language. */

void synchronizeDirs(const char* sourceDir, const char* destDir);

int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Usage: %s <source_dir> <dest_dir>\n", argv[0]);
        return 1;
    }

    synchronizeDirs(argv[1], argv[2]);

    printf("Directories synchronized successfully!\n");

    return 0;
}

void synchronizeDirs(const char* sourceDir, const char* destDir) {

    DIR* sourceDirPointer = opendir(sourceDir);
    DIR* destDirPointer = opendir(destDir);

    struct dirent *sourceDirEntry, *destDirEntry;

    while ((sourceDirEntry = readdir(sourceDirPointer)) != NULL) {

        if (sourceDirEntry->d_type == DT_DIR) {

            /* If next entry is a directory */
            if(strcmp(sourceDirEntry->d_name, ".") != 0 && strcmp(sourceDirEntry->d_name, "..") != 0) {

                /* Create subdirectories in destination directory if non-existent */
                char buf1[256];
                strncpy(buf1, destDir, sizeof(buf1));
                strncat(buf1, "/", sizeof(buf1));
                strncat(buf1, sourceDirEntry->d_name, sizeof(buf1));

                char buf2[256];
                strncpy(buf2, sourceDir, sizeof(buf2));
                strncat(buf2, "/", sizeof(buf2));
                strncat(buf2, sourceDirEntry->d_name, sizeof(buf2));

                struct stat dirInfo;
                stat(buf1, &dirInfo);

                if (mkdir(buf1, dirInfo.st_mode) != 0) {
                    perror("Error creating directory");
                }

                synchronizeDirs(buf2, buf1);
            }

        } else {

            char buf1[256];
            strncpy(buf1, sourceDir, sizeof(buf1));
            strncat(buf1, "/", sizeof(buf1));
            strncat(buf1, sourceDirEntry->d_name, sizeof(buf1));

            char buf2[256];
            strncpy(buf2, destDir, sizeof(buf2));
            strncat(buf2, "/", sizeof(buf2));
            strncat(buf2, sourceDirEntry->d_name, sizeof(buf2));

            /* Check if file exists in destination directory */
            struct stat fileInfo;
            if(stat(buf2, &fileInfo) == 0){

                /* Check if file in source directory is newer */
                struct stat sourceFileInfo;
                stat(buf1, &sourceFileInfo);

                if(difftime(sourceFileInfo.st_mtime, fileInfo.st_mtime) > 0) {

                    /* Copy file from source directory to destination directory */
                    FILE *sourceFile = fopen(buf1, "rb");
                    if (!sourceFile) {
                        perror("Unable to open source file");
                    }

                    FILE *destFile = fopen(buf2, "wb");
                    if (!destFile) {
                        perror("Unable to open destination file");
                    }

                    char buffer[512];
                    size_t readSize;

                    while ((readSize = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
                        fwrite(buffer, 1, readSize, destFile);
                    }

                    fclose(sourceFile);
                    fclose(destFile);
                }

            } else {

                /* Copy file from source directory to destination directory */
                FILE *sourceFile = fopen(buf1, "rb");
                if (!sourceFile) {
                    perror("Unable to open source file");
                }

                FILE *destFile = fopen(buf2, "wb");
                if (!destFile) {
                    perror("Unable to open destination file");
                }

                char buffer[512];
                size_t readSize;

                while ((readSize = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
                    fwrite(buffer, 1, readSize, destFile);
                }

                fclose(sourceFile);
                fclose(destFile);
            }
        }
    }

    closedir(sourceDirPointer);
    closedir(destDirPointer);
}