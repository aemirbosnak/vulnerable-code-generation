//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to check if the file is a regular file
int is_regular_file(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

// Function to extract metadata from a file
void extract_metadata(const char *file_path) {
    struct stat info;
    if (stat(file_path, &info) < 0) {
        perror("stat");
        return;
    }

    printf("Metadata for file: %s\n", file_path);
    printf("Size: %ld bytes\n", info.st_size);
    printf("Owner UID: %d\n", info.st_uid);
    printf("Owner GID: %d\n", info.st_gid);
    printf("Permissions: %o\n", info.st_mode & 0777);
    printf("Last accessed: %ld\n", info.st_atime);
    printf("Last modified: %ld\n", info.st_mtime);
    printf("Last status change: %ld\n", info.st_ctime);
}

// Function to list files in a directory and extract their metadata
void list_files(const char *dir_path) {
    struct dirent *entry;
    DIR *dir = opendir(dir_path);

    if (!dir) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') { // Ignore hidden files
            char full_path[1024];
            snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
            if (is_regular_file(full_path)) {
                extract_metadata(full_path); // Extract metadata of the regular file
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *dir_path = argv[1];
    list_files(dir_path); // List files and extract metadata

    return EXIT_SUCCESS;
}