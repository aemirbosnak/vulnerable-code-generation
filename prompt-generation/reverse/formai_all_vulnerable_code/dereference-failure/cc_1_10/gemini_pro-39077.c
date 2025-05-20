//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

// Custom error handling macro
#define HANDLE_ERROR(msg)                                                   \
    do {                                                                    \
        perror(msg);                                                        \
        exit(EXIT_FAILURE);                                                 \
    } while (0)

// Function to compare the modification times of two files
int compare_timestamps(const char *file1, const char *file2) {
    struct stat st1, st2;

    if (stat(file1, &st1) == -1) {
        HANDLE_ERROR("stat");
    }

    if (stat(file2, &st2) == -1) {
        HANDLE_ERROR("stat");
    }

    return st1.st_mtime - st2.st_mtime;
}

// Function to copy a file
void copy_file(const char *src, const char *dest) {
    FILE *in = fopen(src, "rb");
    if (in == NULL) {
        HANDLE_ERROR("fopen");
    }

    FILE *out = fopen(dest, "wb");
    if (out == NULL) {
        HANDLE_ERROR("fopen");
    }

    char buffer[BUFSIZ];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, BUFSIZ, in)) > 0) {
        fwrite(buffer, 1, bytes_read, out);
    }

    fclose(in);
    fclose(out);
}

// Function to synchronize two directories
void sync_directories(const char *dir1, const char *dir2) {
    DIR *d1 = opendir(dir1);
    if (d1 == NULL) {
        HANDLE_ERROR("opendir");
    }

    DIR *d2 = opendir(dir2);
    if (d2 == NULL) {
        HANDLE_ERROR("opendir");
    }

    struct dirent *ent1;
    while ((ent1 = readdir(d1)) != NULL) {
        if (strcmp(ent1->d_name, ".") == 0 || strcmp(ent1->d_name, "..") == 0) {
            continue;
        }

        char path1[1024];
        snprintf(path1, sizeof(path1), "%s/%s", dir1, ent1->d_name);

        struct stat st1;
        if (stat(path1, &st1) == -1) {
            HANDLE_ERROR("stat");
        }

        char path2[1024];
        snprintf(path2, sizeof(path2), "%s/%s", dir2, ent1->d_name);

        struct stat st2;
        if (stat(path2, &st2) == -1) {
            // File doesn't exist in dir2, so copy it from dir1
            printf("Copying %s to %s\n", path1, path2);
            copy_file(path1, path2);
        } else {
            // File exists in both directories, compare timestamps
            int cmp = compare_timestamps(path1, path2);
            if (cmp > 0) {
                // File in dir1 is newer, so copy it to dir2
                printf("Copying %s to %s\n", path1, path2);
                copy_file(path1, path2);
            } else if (cmp < 0) {
                // File in dir2 is newer, so copy it to dir1
                printf("Copying %s to %s\n", path2, path1);
                copy_file(path2, path1);
            }
        }
    }

    closedir(d1);
    closedir(d2);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dir1> <dir2>\n", argv[0]);
        return EXIT_FAILURE;
    }

    sync_directories(argv[1], argv[2]);

    printf("Synchronization complete!\n");
    return EXIT_SUCCESS;
}