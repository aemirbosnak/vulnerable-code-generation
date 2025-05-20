//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Ada Lovelace
/*
 * C File Synchronizer - An Ada Lovelace Style Program
 *
 * This program synchronizes files between two directories to ensure that they are the same.
 * If any files are different, the program will update the files in both directories to match.
 *
 * Written by Ada Lovelace, 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 256
#define MAX_FILE_SIZE 1024

void synchronize_files(char *dir1, char *dir2);
void copy_file(char *src_file, char *dst_file);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <directory 1> <directory 2>\n", argv[0]);
        return 1;
    }

    synchronize_files(argv[1], argv[2]);

    return 0;
}

/**
 * Synchronizes the files in two directories to ensure that they are the same.
 *
 * @param dir1 The path to the first directory
 * @param dir2 The path to the second directory
 */
void synchronize_files(char *dir1, char *dir2) {
    DIR *dir1_ptr, *dir2_ptr;
    struct dirent *ent1, *ent2;
    struct stat st1, st2;
    char file1[MAX_PATH_LENGTH], file2[MAX_PATH_LENGTH];
    char buffer1[MAX_FILE_SIZE], buffer2[MAX_FILE_SIZE];
    FILE *f1, *f2;
    size_t bytes_read1, bytes_read2;

    dir1_ptr = opendir(dir1);
    if (dir1_ptr == NULL) {
        printf("Error: Could not open directory '%s'\n", dir1);
        exit(1);
    }

    dir2_ptr = opendir(dir2);
    if (dir2_ptr == NULL) {
        printf("Error: Could not open directory '%s'\n", dir2);
        exit(1);
    }

    while ((ent1 = readdir(dir1_ptr)) != NULL) {
        if (strcmp(ent1->d_name, ".") == 0 || strcmp(ent1->d_name, "..") == 0)
            continue;

        sprintf(file1, "%s/%s", dir1, ent1->d_name);
        sprintf(file2, "%s/%s", dir2, ent1->d_name);

        if (stat(file1, &st1) == -1) {
            printf("Error: Could not get file statistics for '%s'\n", file1);
            continue;
        }

        if (stat(file2, &st2) == -1) {
            printf("Error: Could not get file statistics for '%s'\n", file2);
            continue;
        }

        if (S_ISDIR(st1.st_mode)) {
            if (!S_ISDIR(st2.st_mode)) {
                printf("Error: '%s' is a directory but '%s' is not\n", file1, file2);
                continue;
            }

            synchronize_files(file1, file2);
        } else {
            if (S_ISDIR(st2.st_mode)) {
                printf("Error: '%s' is a file but '%s' is a directory\n", file1, file2);
                continue;
            }

            f1 = fopen(file1, "rb");
            if (f1 == NULL) {
                printf("Error: Could not open file '%s'\n", file1);
                continue;
            }

            f2 = fopen(file2, "rb");
            if (f2 == NULL) {
                printf("Error: Could not open file '%s'\n", file2);
                fclose(f1);
                continue;
            }

            bytes_read1 = fread(buffer1, sizeof(char), MAX_FILE_SIZE, f1);
            bytes_read2 = fread(buffer2, sizeof(char), MAX_FILE_SIZE, f2);

            if (bytes_read1 != bytes_read2 || memcmp(buffer1, buffer2, bytes_read1) != 0) {
                printf("Updating '%s' and '%s'\n", file1, file2);
                copy_file(file1, file2);
            }

            fclose(f1);
            fclose(f2);
        }
    }

    while ((ent2 = readdir(dir2_ptr)) != NULL) {
        if (strcmp(ent2->d_name, ".") == 0 || strcmp(ent2->d_name, "..") == 0)
            continue;

        sprintf(file1, "%s/%s", dir1, ent2->d_name);
        sprintf(file2, "%s/%s", dir2, ent2->d_name);

        if (stat(file1, &st1) == -1)
            continue;

        if (stat(file2, &st2) == -1) {
            printf("Error: Could not get file statistics for '%s'\n", file2);
            continue;
        }

        if (S_ISDIR(st2.st_mode))
            continue;

        if (S_ISDIR(st1.st_mode)) {
            printf("Error: '%s' is a directory but '%s' is a file\n", file2, file1);
            continue;
        }

        printf("Copying '%s' to '%s'\n", file1, file2);
        copy_file(file1, file2);
    }

    closedir(dir1_ptr);
    closedir(dir2_ptr);
}

/**
 * Copies a file from one location to another.
 *
 * @param src_file The path to the source file
 * @param dst_file The path to the destination file
 */
void copy_file(char *src_file, char *dst_file) {
    FILE *src, *dst;
    char buffer[MAX_FILE_SIZE];
    size_t bytes_read;

    src = fopen(src_file, "rb");
    if (src == NULL) {
        printf("Error: Could not open file '%s'\n", src_file);
        return;
    }

    dst = fopen(dst_file, "wb");
    if (dst == NULL) {
        printf("Error: Could not open file '%s'\n", dst_file);
        fclose(src);
        return;
    }

    while ((bytes_read = fread(buffer, sizeof(char), MAX_FILE_SIZE, src)) > 0)
        fwrite(buffer, sizeof(char), bytes_read, dst);

    fclose(src);
    fclose(dst);
}