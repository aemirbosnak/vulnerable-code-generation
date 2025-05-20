//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PATH 256

// Function to get the file size
long get_file_size(const char *file_path) {
    struct stat st;
    stat(file_path, &st);
    return st.st_size;
}

// Function to copy a file
void copy_file(const char *src_path, const char *dest_path) {
    FILE *src = fopen(src_path, "rb");
    if (src == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    FILE *dest = fopen(dest_path, "wb");
    if (dest == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    long file_size = get_file_size(src_path);
    char *buffer = malloc(file_size);
    if (buffer == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    fread(buffer, 1, file_size, src);
    fwrite(buffer, 1, file_size, dest);

    fclose(src);
    fclose(dest);
    free(buffer);
}

// Function to compare two files
int compare_files(const char *file1_path, const char *file2_path) {
    long size1 = get_file_size(file1_path);
    long size2 = get_file_size(file2_path);

    if (size1 != size2) {
        return 0;
    }

    FILE *file1 = fopen(file1_path, "rb");
    if (file1 == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    FILE *file2 = fopen(file2_path, "rb");
    if (file2 == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char buffer1[MAX_PATH];
    char buffer2[MAX_PATH];
    while (fgets(buffer1, MAX_PATH, file1) != NULL && fgets(buffer2, MAX_PATH, file2) != NULL) {
        if (strcmp(buffer1, buffer2) != 0) {
            fclose(file1);
            fclose(file2);
            return 0;
        }
    }

    fclose(file1);
    fclose(file2);
    return 1;
}

// Function to synchronize two directories
void sync_directories(const char *src_dir, const char *dest_dir) {
    DIR *src = opendir(src_dir);
    if (src == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    DIR *dest = opendir(dest_dir);
    if (dest == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    struct dirent *src_entry;
    struct dirent *dest_entry;

    while ((src_entry = readdir(src)) != NULL && (dest_entry = readdir(dest)) != NULL) {
        if (strcmp(src_entry->d_name, dest_entry->d_name) != 0) {
            printf("File %s not found in destination directory. Copying file...\n", src_entry->d_name);
            copy_file(src_entry->d_name, dest_entry->d_name);
        } else {
            if (!compare_files(src_entry->d_name, dest_entry->d_name)) {
                printf("File %s has changed. Updating file...\n", src_entry->d_name);
                copy_file(src_entry->d_name, dest_entry->d_name);
            }
        }
    }

    closedir(src);
    closedir(dest);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *src_dir = argv[1];
    const char *dest_dir = argv[2];

    sync_directories(src_dir, dest_dir);

    return EXIT_SUCCESS;
}