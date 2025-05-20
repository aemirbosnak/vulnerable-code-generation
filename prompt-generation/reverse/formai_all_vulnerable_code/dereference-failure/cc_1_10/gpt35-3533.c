//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void extract_metadata(char *filename) {
    FILE *f = fopen(filename, "r");

    if (f == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    char line[256];
    char *key;
    char *value;

    while (fgets(line, sizeof(line), f)) {
        key = strtok(line, ":");
        value = strtok(NULL, ":");

        if (value != NULL) {
            value = strtok(value, "\r\n");
            printf("%s : %s\n", key, value);
        } else {
            printf("%s\n", key);
        }
    }

    fclose(f);
}

void crawl_directory(char *dir_name) {
    DIR *dir = opendir(dir_name);
    if (dir == NULL) {
        printf("Error: Could not open directory %s\n", dir_name);
        return;
    }

    struct dirent *entry;
    char path[512];
    while (entry = readdir(dir)) {
        // skip over . and ..
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // construct full path
        snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);
        if (entry->d_type == DT_DIR) {
            crawl_directory(path);
        } else {
            extract_metadata(path);
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s directory_name\n", argv[0]);
        exit(1);
    }

    char *dir_name = argv[1];

    crawl_directory(dir_name);

    return 0;
}