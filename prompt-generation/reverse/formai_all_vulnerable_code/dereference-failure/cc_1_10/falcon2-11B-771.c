//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to compare two files
int compareFiles(const char* file1, const char* file2) {
    int size = 0;
    FILE* fp1 = fopen(file1, "rb");
    FILE* fp2 = fopen(file2, "rb");
    if (fp1 == NULL || fp2 == NULL) {
        return 1;
    }
    char buf1[256];
    char buf2[256];
    while (fread(buf1, sizeof(char), 256, fp1)!= 0) {
        fread(buf2, sizeof(char), 256, fp2);
        if (memcmp(buf1, buf2, strlen(buf1))!= 0) {
            printf("Files '%s' and '%s' are not identical\n", file1, file2);
            return 1;
        }
        size++;
    }
    fclose(fp1);
    fclose(fp2);
    return size;
}

// Function to synchronize files
int syncFiles(const char* srcDir, const char* dstDir) {
    DIR* srcDirPtr = opendir(srcDir);
    DIR* dstDirPtr = opendir(dstDir);
    if (srcDirPtr == NULL || dstDirPtr == NULL) {
        return 1;
    }
    struct dirent* srcEntry;
    struct dirent* dstEntry;
    while ((srcEntry = readdir(srcDirPtr))!= NULL) {
        char srcPath[1024];
        sprintf(srcPath, "%s/%s", srcDir, srcEntry->d_name);
        if (strcmp(srcEntry->d_name, ".") == 0 || strcmp(srcEntry->d_name, "..") == 0) {
            continue;
        }
        if (strcmp(srcEntry->d_name, ".DS_Store") == 0) {
            continue;
        }
        char dstPath[1024];
        sprintf(dstPath, "%s/%s", dstDir, srcEntry->d_name);
        if (strcmp(srcEntry->d_name, ".") == 0 || strcmp(srcEntry->d_name, "..") == 0) {
            continue;
        }
        if (strcmp(srcEntry->d_name, ".DS_Store") == 0) {
            continue;
        }
        int size = 0;
        FILE* fp1 = fopen(srcPath, "rb");
        FILE* fp2 = fopen(dstPath, "rb");
        if (fp1 == NULL || fp2 == NULL) {
            printf("Error opening file: %s\n", srcPath);
            return 1;
        }
        char buf1[256];
        char buf2[256];
        while (fread(buf1, sizeof(char), 256, fp1)!= 0) {
            fread(buf2, sizeof(char), 256, fp2);
            if (memcmp(buf1, buf2, strlen(buf1))!= 0) {
                printf("File '%s' is different from file '%s'\n", srcPath, dstPath);
                return 1;
            }
            size++;
        }
        fclose(fp1);
        fclose(fp2);
        if (compareFiles(srcPath, dstPath) == size) {
            printf("File '%s' is identical to file '%s'\n", srcPath, dstPath);
        } else {
            printf("File '%s' is different from file '%s'\n", srcPath, dstPath);
            return 1;
        }
    }
    closedir(srcDirPtr);
    closedir(dstDirPtr);
    return 0;
}

int main() {
    const char* srcDir = "source_directory";
    const char* dstDir = "destination_directory";
    int result = syncFiles(srcDir, dstDir);
    if (result == 0) {
        printf("Files synchronized successfully!\n");
    } else {
        printf("Error synchronizing files\n");
    }
    return 0;
}