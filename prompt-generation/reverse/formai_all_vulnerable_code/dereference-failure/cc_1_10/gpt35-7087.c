//FormAI DATASET v1.0 Category: File Synchronizer ; Style: creative
// C File Synchronizer example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// function declarations
int compare_files(const char *file1, const char *file2);
void sync_files(const char *src_file, const char *dest_file);

int main(int argc, char *argv[]) {
    // check for correct usage
    if (argc < 3) {
        printf("Usage: %s [source directory] [destination directory]\n", argv[0]);
        exit(1);
    }

    // open source directory
    DIR *src_dir = opendir(argv[1]);
    if (src_dir == NULL) {
        printf("Error: Could not open source directory.\n");
        exit(1);
    }

    // open destination directory
    DIR *dest_dir = opendir(argv[2]);
    if (dest_dir == NULL) {
        printf("Error: Could not open destination directory.\n");
        exit(1);
    }

    // loop through files in source directory
    struct dirent *src_dent;
    while ((src_dent = readdir(src_dir)) != NULL) {
        // ignore . and ..
        if (strcmp(src_dent->d_name, ".") == 0 || strcmp(src_dent->d_name, "..") == 0) {
            continue;
        }

        // construct file paths
        char src_path[512];
        char dest_path[512];
        sprintf(src_path, "%s/%s", argv[1], src_dent->d_name);
        sprintf(dest_path, "%s/%s", argv[2], src_dent->d_name);

        // check if file exists in destination directory
        struct stat st;
        if (stat(dest_path, &st) == 0) {
            // file exists in destination, compare last modified times
            int cmp_result = compare_files(src_path, dest_path);
            if (cmp_result == 1) {
                // source file is newer, sync files
                sync_files(src_path, dest_path);
                printf("Syncing %s to %s.\n", src_path, dest_path);
            }
        } else {
            // file does not exist in destination, sync files
            sync_files(src_path, dest_path);
            printf("Syncing %s to %s.\n", src_path, dest_path);
        }
    }

    // close directories
    closedir(src_dir);
    closedir(dest_dir);

    printf("Synchronization complete.\n");
    return 0;
}

// compare last modified times of two files
int compare_files(const char *file1, const char *file2) {
    struct stat st1;
    struct stat st2;
    stat(file1, &st1);
    stat(file2, &st2);
    if (difftime(st1.st_mtime, st2.st_mtime) > 0) {
        return 1;
    } else {
        return 0;
    }
}

// sync contents of one file to another
void sync_files(const char *src_file, const char *dest_file) {
    FILE *src_fp = fopen(src_file, "r");
    FILE *dest_fp = fopen(dest_file, "w");
    if (src_fp == NULL || dest_fp == NULL) {
        printf("Error: Could not open files for synchronization.\n");
        exit(1);
    }
    char buffer[512];
    while (fgets(buffer, sizeof(buffer), src_fp)) {
        fputs(buffer, dest_fp);
    }
    fclose(src_fp);
    fclose(dest_fp);
}