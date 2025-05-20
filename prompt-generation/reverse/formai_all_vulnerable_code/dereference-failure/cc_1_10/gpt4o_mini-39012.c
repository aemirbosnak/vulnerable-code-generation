//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include <unistd.h>

void print_metadata(const char *filepath) {
    struct stat file_stat;

    if (stat(filepath, &file_stat) != 0) {
        perror("Error retrieving file metadata");
        return;
    }

    printf("File: %s\n", filepath);
    printf("Size: %lld bytes\n", (long long) file_stat.st_size);
    printf("Owner UID: %u\n", file_stat.st_uid);
    printf("Owner GID: %u\n", file_stat.st_gid);
    printf("Permissions: %o\n", file_stat.st_mode & 0777);
    printf("Last access time: %s", ctime(&file_stat.st_atime));
    printf("Last modification time: %s", ctime(&file_stat.st_mtime));
    printf("Creation time: %s", ctime(&file_stat.st_ctime));
    printf("\n");
}

void extract_metadata_from_directory(const char *dirpath) {
    struct dirent *entry;
    DIR *dp = opendir(dirpath);

    if (dp == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) { // Only regular files
            char filepath[1024];
            snprintf(filepath, sizeof(filepath), "%s/%s", dirpath, entry->d_name);
            print_metadata(filepath);
        }
    }

    closedir(dp);
}

void display_usage() {
    printf("Usage: metadata_extractor <directory_path>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        display_usage();
        return EXIT_FAILURE;
    }

    const char *dirpath = argv[1];
    extract_metadata_from_directory(dirpath);

    return EXIT_SUCCESS;
}