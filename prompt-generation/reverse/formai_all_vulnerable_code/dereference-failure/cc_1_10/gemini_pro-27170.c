//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PATH 256
#define MAX_FILES 100

// Structure to store file information
typedef struct FileInfo {
    char *name;
    char *path;
    size_t size;
    time_t mtime;
} FileInfo;

// Function to recursively traverse a directory and list all files
int list_files(char *dir, FileInfo *files[], int *num_files) {
    DIR *dp;
    struct dirent *entry;
    struct stat st;
    char path[MAX_PATH];

    if ((dp = opendir(dir)) == NULL) {
        return -1;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(path, sizeof(path), "%s/%s", dir, entry->d_name);

        if (lstat(path, &st) == -1) {
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            list_files(path, files, num_files);
        } else {
            files[(*num_files)++] = malloc(sizeof(FileInfo));
            files[(*num_files) - 1]->name = strdup(entry->d_name);
            files[(*num_files) - 1]->path = strdup(path);
            files[(*num_files) - 1]->size = st.st_size;
            files[(*num_files) - 1]->mtime = st.st_mtime;
        }
    }

    closedir(dp);

    return 0;
}

// Function to compare two files based on their mtime
int compare_files(const void *a, const void *b) {
    const FileInfo *fa = *(const FileInfo **)a;
    const FileInfo *fb = *(const FileInfo **)b;

    return fb->mtime - fa->mtime;
}

// Function to backup a file
int backup_file(char *src, char *dst) {
    FILE *src_fp, *dst_fp;
    char buf[BUFSIZ];
    size_t nread;

    if ((src_fp = fopen(src, "rb")) == NULL) {
        return -1;
    }

    if ((dst_fp = fopen(dst, "wb")) == NULL) {
        fclose(src_fp);
        return -1;
    }

    while ((nread = fread(buf, sizeof(char), sizeof(buf), src_fp)) > 0) {
        fwrite(buf, sizeof(char), nread, dst_fp);
    }

    fclose(src_fp);
    fclose(dst_fp);

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    char *src_dir, *dst_dir;
    FileInfo *files[MAX_FILES];
    int num_files = 0;
    int i;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <src_dir> <dst_dir>\n", argv[0]);
        return EXIT_FAILURE;
    }

    src_dir = argv[1];
    dst_dir = argv[2];

    // Recursively list all files in the source directory
    if (list_files(src_dir, files, &num_files) == -1) {
        perror("list_files");
        return EXIT_FAILURE;
    }

    // Sort the files based on their mtime
    qsort(files, num_files, sizeof(FileInfo *), compare_files);

    // Backup the files
    for (i = 0; i < num_files; i++) {
        char dst_path[MAX_PATH];

        snprintf(dst_path, sizeof(dst_path), "%s/%s", dst_dir, files[i]->name);

        if (backup_file(files[i]->path, dst_path) == -1) {
            perror("backup_file");
            return EXIT_FAILURE;
        }
    }

    // Free the allocated memory
    for (i = 0; i < num_files; i++) {
        free(files[i]->name);
        free(files[i]->path);
        free(files[i]);
    }

    return EXIT_SUCCESS;
}