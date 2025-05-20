//FormAI DATASET v1.0 Category: File Synchronizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#define MAX_FILENAME 256

/* function to check if a file exists or not */
int fileExists(char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

/* function to check if a directory exists or not */
int dirExists(char *dirName) {
    DIR* dir = opendir(dirName);
    if (dir) {
        closedir(dir);
        return 1;
    } else if (ENOENT == errno) {
        return 0;
    } else {
        printf("Error opening directory %s\n", dirName);
        return -1;
    }
}

/* function to copy a file from source to destination */
int copyFile(char *src, char *dest) {
    FILE *fsrc, *fdest;
    char byte;

    /* open source file */
    if ((fsrc = fopen(src, "rb")) == NULL) {
        printf("Error opening file %s\n", src);
        return -1;
    }

    /* open destination file */
    if ((fdest = fopen(dest, "wb")) == NULL) {
        printf("Error opening file %s\n", dest);
        fclose(fsrc);
        return -1;
    }

    /* copy file byte by byte */
    while (!feof(fsrc)) {
        fread(&byte, sizeof(char), 1, fsrc);
        fwrite(&byte, sizeof(char), 1, fdest);
    }

    fclose(fsrc);
    fclose(fdest);

    return 0;
}

/* function to synchronize files */
int syncFiles(char *srcDir, char *destDir) {
    struct dirent *dirEntry;
    DIR *dir;
    char srcPath[MAX_FILENAME], destPath[MAX_FILENAME];
    int res = 0;

    /* open source directory */
    if ((dir = opendir(srcDir)) == NULL) {
        printf("Error opening directory %s\n", srcDir);
        return -1;
    }

    /* iterate over entries in source directory */
    while ((dirEntry = readdir(dir)) != NULL) {
        /* skip . and .. directory entries */
        if ((strcmp(dirEntry->d_name, ".") == 0) || (strcmp(dirEntry->d_name, "..") == 0)) {
            continue;
        }

        /* compose source file and destination file paths */
        sprintf(srcPath, "%s/%s", srcDir, dirEntry->d_name);
        sprintf(destPath, "%s/%s", destDir, dirEntry->d_name);

        /* if source is a file and destination file exists and is newer, copy over */
        if (dirEntry->d_type == DT_REG) {
            if (fileExists(destPath)) {
                struct stat srcStat, destStat;
                if (stat(srcPath, &srcStat) == 0 && stat(destPath, &destStat) == 0) {
                    if (srcStat.st_mtime > destStat.st_mtime) {
                        if (copyFile(srcPath, destPath) != 0) {
                            printf("Error copying file %s to %s\n", srcPath, destPath);
                            res = -1;
                        } else {
                            printf("File %s copied successfully to %s\n", srcPath, destPath);
                        }
                    }
                } else {
                    printf("Error fetching file stats for %s or %s\n", srcPath, destPath);
                }
            } else {
                /* destination file does not exist, copy over */
                if (copyFile(srcPath, destPath) != 0) {
                    printf("Error copying file %s to %s\n", srcPath, destPath);
                    res = -1;
                } else {
                    printf("File %s copied successfully to %s\n", srcPath, destPath);
                }
            }
        } else if (dirEntry->d_type == DT_DIR) {
            /* source is a directory, recursively synchronize */
            if (dirExists(destPath)) {
                if (syncFiles(srcPath, destPath) != 0) {
                    printf("Error synchronizing directory %s\n", srcPath);
                    res = -1;
                }
            } else {
                /* destination directory does not exist, create it */
                if (mkdir(destPath, 0777) != 0) {
                    printf("Error creating directory %s\n", destPath);
                    res = -1;
                } else {
                    printf("Directory %s created successfully\n", destPath);
                    if (syncFiles(srcPath, destPath) != 0) {
                        printf("Error synchronizing directory %s\n", srcPath);
                        res = -1;
                    }
                }
            }
        } else {
            printf("Unknown file type for %s\n", srcPath);
            res = -1;
        }
    }

    closedir(dir);
    return res;
}

/* main function */
int main(int argc, char **argv) {
    char *srcDir, *destDir;

    /* check command-line arguments */
    if (argc != 3) {
        printf("Usage: %s <source-dir> <destination-dir>\n", argv[0]);
        return -1;
    }

    srcDir = argv[1];
    destDir = argv[2];

    /* check if directories exist */
    if (!dirExists(srcDir)) {
        printf("Source directory %s does not exist\n", srcDir);
        return -1;
    }

    if (!dirExists(destDir)) {
        printf("Destination directory %s does not exist\n", destDir);
        return -1;
    }

    /* synchronize files */
    printf("Synchronizing files from %s to %s\n", srcDir, destDir);
    if (syncFiles(srcDir, destDir) != 0) {
        printf("Error synchronizing files\n");
        return -1;
    } else {
        printf("Files synchronized successfully\n");
        return 0;
    }
}