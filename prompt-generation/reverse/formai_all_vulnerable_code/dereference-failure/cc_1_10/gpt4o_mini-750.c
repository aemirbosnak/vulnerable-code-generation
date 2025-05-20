//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

void copy_file(const char *src, const char *dst) {
    FILE *source = fopen(src, "rb");
    FILE *dest = fopen(dst, "wb");
    char buf[BUFSIZ];
    size_t n;

    if (source && dest) {
        while ((n = fread(buf, 1, sizeof(buf), source)) > 0) {
            fwrite(buf, 1, n, dest);
        }
    }

    if (source) fclose(source);
    if (dest) fclose(dest);
}

int files_equal(const char *file1, const char *file2) {
    struct stat stat1, stat2;

    if (stat(file1, &stat1) == -1 || stat(file2, &stat2) == -1) return 0;
    return (stat1.st_size == stat2.st_size && stat1.st_mtime == stat2.st_mtime);
}

void sync_directory(const char *src_dir, const char *dst_dir) {
    struct dirent *entry;
    DIR *dp = opendir(src_dir);
  
    if (!dp) {
        perror("opendir");
        return;
    }

    char src_path[MAX_PATH];
    char dst_path[MAX_PATH];

    while ((entry = readdir(dp))) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files

        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dst_path, sizeof(dst_path), "%s/%s", dst_dir, entry->d_name);

        if (entry->d_type == DT_REG) { // Regular file
            if (access(dst_path, F_OK) == -1 || !files_equal(src_path, dst_path)) {
                printf("Copying '%s' to '%s'\n", src_path, dst_path);
                copy_file(src_path, dst_path);
            }
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source directory> <target directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    sync_directory(argv[1], argv[2]);

    return EXIT_SUCCESS;
}