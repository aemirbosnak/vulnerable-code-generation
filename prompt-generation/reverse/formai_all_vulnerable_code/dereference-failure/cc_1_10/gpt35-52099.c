//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void process_metadata_file(char *file_path);

void process_directory(char *dir_path) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(dir_path);
    if (dir == NULL) {
        fprintf(stderr, "Error: Cannot open directory %s\n", dir_path);
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char file_path[1024];
        snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            process_directory(file_path);
        }
        else if (entry->d_type == DT_REG) {
            process_metadata_file(file_path);
        }
    }

    closedir(dir);
}

void process_metadata_file(char *file_path) {
    FILE *file;
    char line[1024];

    file = fopen(file_path, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open file %s\n", file_path);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "metadata")) {
            printf("%s\n", line);
        }
    }

    fclose(file);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *dir_path = argv[1];
    process_directory(dir_path);

    return 0;
}