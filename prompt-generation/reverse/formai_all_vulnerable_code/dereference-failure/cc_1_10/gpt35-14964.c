//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_FILE_PATH_LEN 1024

void extract_metadata(char *file_path);
void extract_metadata_recursive(char *path);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s directory_path\n", argv[0]);
        return 1;
    }

    extract_metadata_recursive(argv[1]);

    return 0;
}

void extract_metadata_recursive(char *path) {
    struct dirent *entry;
    DIR *dir;

    if ((dir = opendir(path)) == NULL) {
        perror("opendir");
        exit(1);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char sub_path[MAX_FILE_PATH_LEN];
                snprintf(sub_path, MAX_FILE_PATH_LEN, "%s/%s", path, entry->d_name);
                extract_metadata_recursive(sub_path);
            }
        } else {
            char file_path[MAX_FILE_PATH_LEN];
            snprintf(file_path, MAX_FILE_PATH_LEN, "%s/%s", path, entry->d_name);
            extract_metadata(file_path);
        }
    }

    closedir(dir);
}

void extract_metadata(char *file_path) {
    // TODO: extract metadata from file at file_path
    printf("Extracted metadata from file: %s\n", file_path);
}