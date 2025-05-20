//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

# define MAX_SIZE 1024 * 1024 * 10

// Helper function to get the file size
long long getFileSize(const char* filename) {
    struct stat st;
    if (stat(filename, &st) == 0)
        return st.st_size;
    return -1;
}

// Helper function to check if the file exists
int fileExists(const char* filename) {
    return access(filename, F_OK) != -1;
}

// Helper function to copy the file
int copyFile(const char* src, const char* dst) {
    FILE* fsrc = fopen(src, "rb");
    if (fsrc == NULL)
        return -1;
    FILE* fdst = fopen(dst, "wb");
    if (fdst == NULL) {
        fclose(fsrc);
        return -1;
    }
    char buffer[MAX_SIZE];
    size_t nread;
    while ((nread = fread(buffer, 1, MAX_SIZE, fsrc)) > 0) {
        fwrite(buffer, 1, nread, fdst);
    }
    fclose(fsrc);
    fclose(fdst);
    return 0;
}

// Helper function to compare two files
int compareFiles(const char* file1, const char* file2) {
    long long size1 = getFileSize(file1);
    long long size2 = getFileSize(file2);
    if (size1 != size2)
        return -1;
    FILE* f1 = fopen(file1, "rb");
    FILE* f2 = fopen(file2, "rb");
    char buffer1[MAX_SIZE];
    char buffer2[MAX_SIZE];
    size_t nread1;
    size_t nread2;
    while ((nread1 = fread(buffer1, 1, MAX_SIZE, f1)) > 0) {
        nread2 = fread(buffer2, 1, nread1, f2);
        if (nread1 != nread2 || memcmp(buffer1, buffer2, nread1) != 0) {
            fclose(f1);
            fclose(f2);
            return -1;
        }
    }
    fclose(f1);
    fclose(f2);
    return 0;
}

// Main function
int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
        return 1;
    }
    char* src_dir = argv[1];
    char* dst_dir = argv[2];
    DIR* src = opendir(src_dir);
    if (src == NULL) {
        perror("opendir");
        return 1;
    }
    DIR* dst = opendir(dst_dir);
    if (dst == NULL) {
        perror("opendir");
        return 1;
    }
    struct dirent* src_ent;
    while ((src_ent = readdir(src)) != NULL) {
        if (strcmp(src_ent->d_name, ".") == 0 || strcmp(src_ent->d_name, "..") == 0)
            continue;
        char* src_path = malloc(strlen(src_dir) + strlen(src_ent->d_name) + 2);
        strcpy(src_path, src_dir);
        strcat(src_path, "/");
        strcat(src_path, src_ent->d_name);
        char* dst_path = malloc(strlen(dst_dir) + strlen(src_ent->d_name) + 2);
        strcpy(dst_path, dst_dir);
        strcat(dst_path, "/");
        strcat(dst_path, src_ent->d_name);
        if (fileExists(dst_path) && compareFiles(src_path, dst_path) == 0) {
            printf("File %s is already up to date.\n", src_ent->d_name);
            continue;
        }
        printf("Copying file %s to %s...\n", src_ent->d_name, dst_path);
        if (copyFile(src_path, dst_path) == -1) {
            perror("copyFile");
            continue;
        }
        printf("File %s copied successfully.\n", src_ent->d_name);
        free(src_path);
        free(dst_path);
    }
    closedir(src);
    closedir(dst);
    return 0;
}