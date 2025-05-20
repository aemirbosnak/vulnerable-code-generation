//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define MAX_FILES 1000

// File comparison function
int compareFiles(const char* file1, const char* file2) {
    FILE* f1 = fopen(file1, "rb");
    FILE* f2 = fopen(file2, "rb");
    if (!f1 || !f2) {
        return -1;
    }

    int result = 0;
    char buf1[MAX_PATH], buf2[MAX_PATH];
    while (!feof(f1) && !feof(f2)) {
        size_t len = fread(buf1, 1, MAX_PATH, f1);
        len = fread(buf2, 1, MAX_PATH, f2);
        if (len != fread(buf2, 1, MAX_PATH, f2)) {
            result = -1;
            break;
        }
        if (memcmp(buf1, buf2, len) != 0) {
            result = -1;
            break;
        }
    }

    fclose(f1);
    fclose(f2);

    return result;
}

// File synchronizer function
void syncFiles(const char* src, const char* dest) {
    DIR* srcDir = opendir(src);
    DIR* destDir = opendir(dest);

    if (!srcDir || !destDir) {
        printf("Error opening directories\n");
        return;
    }

    // Get files in source directory
    char srcFiles[MAX_FILES][MAX_PATH];
    int numSrcFiles = 0;
    struct dirent* dp;
    while ((dp = readdir(srcDir)) != NULL) {
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        }

        snprintf(srcFiles[numSrcFiles++], MAX_PATH, "%s/%s", src, dp->d_name);
    }

    // Get files in destination directory
    char destFiles[MAX_FILES][MAX_PATH];
    int numDestFiles = 0;
    while ((dp = readdir(destDir)) != NULL) {
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        }

        snprintf(destFiles[numDestFiles++], MAX_PATH, "%s/%s", dest, dp->d_name);
    }

    // Compare files
    for (int i = 0; i < numSrcFiles; i++) {
        int found = 0;
        for (int j = 0; j < numDestFiles; j++) {
            if (strcmp(srcFiles[i], destFiles[j]) == 0) {
                if (compareFiles(srcFiles[i], destFiles[j]) == 0) {
                    printf("Files %s and %s are identical\n", srcFiles[i], destFiles[j]);
                } else {
                    printf("Files %s and %s are different\n", srcFiles[i], destFiles[j]);
                    printf("Replacing %s with %s\n", destFiles[j], srcFiles[i]);
                    if (remove(destFiles[j]) == 0 && copyFile(srcFiles[i], destFiles[j]) == 0) {
                        printf("File replaced successfully\n");
                    } else {
                        printf("Error replacing file\n");
                    }
                }
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("File %s not found in destination directory\n", srcFiles[i]);
            printf("Copying %s to %s\n", srcFiles[i], dest);
            if (copyFile(srcFiles[i], dest) == 0) {
                printf("File copied successfully\n");
            } else {
                printf("Error copying file\n");
            }
        }
    }

    closedir(srcDir);
    closedir(destDir);
}

// File copy function
int copyFile(const char* src, const char* dest) {
    FILE* fsrc = fopen(src, "rb");
    FILE* fdest = fopen(dest, "wb");
    if (!fsrc || !fdest) {
        return -1;
    }

    char buf[MAX_PATH];
    size_t len;
    while ((len = fread(buf, 1, MAX_PATH, fsrc)) > 0) {
        if (fwrite(buf, 1, len, fdest) != len) {
            return -1;
        }
    }

    fclose(fsrc);
    fclose(fdest);

    return 0;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
        return 1;
    }

    syncFiles(argv[1], argv[2]);

    return 0;
}