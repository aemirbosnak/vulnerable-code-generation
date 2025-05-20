//FormAI DATASET v1.0 Category: File Synchronizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void copyFile(const char *srcPath, const char *dstPath) {
    FILE *srcFile, *dstFile;
    char buffer[1024];
    size_t bytesRead;

    srcFile = fopen(srcPath, "rb");
    if (!srcFile) {
        printf("Failed to open file: %s\n", srcPath);
        return;
    }

    dstFile = fopen(dstPath, "wb");
    if (!dstFile) {
        printf("Failed to create file: %s\n", dstPath);
        fclose(srcFile);
        return;
    }

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), srcFile))) {
        fwrite(buffer, 1, bytesRead, dstFile);
    }

    fclose(srcFile);
    fclose(dstFile);
}

void synchronizeDirectory(const char *srcDir, const char *dstDir) {
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(srcDir))) {
        while ((ent = readdir(dir))) {
            char srcPath[1024];
            char dstPath[1024];
            struct stat srcStat, dstStat;

            if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, "..")) {
                continue;
            }

            snprintf(srcPath, sizeof(srcPath), "%s/%s", srcDir, ent->d_name);
            snprintf(dstPath, sizeof(dstPath), "%s/%s", dstDir, ent->d_name);

            if (lstat(srcPath, &srcStat) == 0) {
                if (lstat(dstPath, &dstStat) == 0) {
                    if (S_ISDIR(srcStat.st_mode)) {
                        if (S_ISDIR(dstStat.st_mode)) {
                            synchronizeDirectory(srcPath, dstPath);
                        } else {
                            printf("Error: Source is directory, but destination is not.\n");
                        }
                    } else {
                        if (S_ISDIR(dstStat.st_mode)) {
                            printf("Error: Source is file, but destination is directory.\n");
                        } else {
                            if (srcStat.st_mtime > dstStat.st_mtime) {
                                printf("Updating file: %s\n", dstPath);
                                copyFile(srcPath, dstPath);
                            }
                        }
                    }
                } else {
                    if (S_ISDIR(srcStat.st_mode)) {
                        printf("Creating directory: %s\n", dstPath);
                        mkdir(dstPath, srcStat.st_mode);
                        synchronizeDirectory(srcPath, dstPath);
                    } else {
                        printf("Copying file: %s\n", dstPath);
                        copyFile(srcPath, dstPath);
                    }
                }
            }
        }

        closedir(dir);
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
        return 1;
    }

    printf("Synchronizing directories: %s -> %s\n", argv[1], argv[2]);
    synchronizeDirectory(argv[1], argv[2]);
    printf("Done.\n");

    return 0;
}