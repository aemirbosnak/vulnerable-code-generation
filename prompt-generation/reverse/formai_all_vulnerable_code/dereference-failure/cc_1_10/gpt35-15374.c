//FormAI DATASET v1.0 Category: File Synchronizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void copy_file(const char* src_file, const char* dest_file) {
    // Open source and destination files
    FILE* src = fopen(src_file, "rb");
    FILE* dest = fopen(dest_file, "wb");

    // Copy contents of source file to destination file
    int buf_size = 1024;
    char* buffer = malloc(buf_size);
    size_t num_read = 0;
    while ((num_read = fread(buffer, 1, buf_size, src)) > 0) {
        fwrite(buffer, 1, num_read, dest);
    }

    // Close files and free buffer
    fclose(src);
    fclose(dest);
    free(buffer);
}

void sync_files(const char* src_dir, const char* dest_dir) {
    // Open source directory
    DIR* dirp = opendir(src_dir);
    struct dirent* dp;

    // Process each file in source directory
    while ((dp = readdir(dirp)) != NULL) {
        // Ignore . and ..
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        }

        // Build full path to source file
        char src_file[PATH_MAX];
        sprintf(src_file, "%s/%s", src_dir, dp->d_name);

        // Build full path to destination file
        char dest_file[PATH_MAX];
        sprintf(dest_file, "%s/%s", dest_dir, dp->d_name);

        // Stat source and destination files
        struct stat src_st, dest_st;
        stat(src_file, &src_st);
        stat(dest_file, &dest_st);

        // If source file is a directory, recursively sync it
        if (S_ISDIR(src_st.st_mode)) {
            if (!S_ISDIR(dest_st.st_mode)) {
                // If destination is a file, remove it
                remove(dest_file);
            }
            // Create destination directory if it doesn't exist
            if (access(dest_file, F_OK) == -1) {
                mkdir(dest_file, 0755);
            }
            sync_files(src_file, dest_file);
        } else {
            // If destination file does not exist, copy it
            if (access(dest_file, F_OK) == -1) {
                copy_file(src_file, dest_file);
            } else {
                // If destination file has different size or modification time, copy it
                if (src_st.st_size != dest_st.st_size ||
                    src_st.st_mtime > dest_st.st_mtime) {
                    copy_file(src_file, dest_file);
                }
            }
        }
    }

    // Close directory
    closedir(dirp);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <source_dir> <dest_dir>\n", argv[0]);
        return 1;
    }

    printf("Synchronizing files in %s\n", argv[1]);
    printf("To destination directory %s\n", argv[2]);

    sync_files(argv[1], argv[2]);

    printf("Done.\n");

    return 0;
}