//FormAI DATASET v1.0 Category: Browser Plugin ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 1024

void process_file(const char *file_path) {
    FILE *fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Failed to open file %s\n", file_path);
        return;
    }

    char line[1024];
    int line_number = 1;

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "brave")) {
            printf("Found 'brave' on line %d in file %s\n", line_number, file_path);
        }
        line_number++;
    }

    fclose(fp);
}

void process_directory(const char *dir_path) {
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        printf("Failed to open directory %s\n", dir_path);
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir))) {
        if (entry->d_type == DT_DIR) {
            char child_dir_path[MAX_PATH_LENGTH];
            snprintf(child_dir_path, sizeof(child_dir_path), "%s/%s", dir_path, entry->d_name);

            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            printf("Processing directory %s\n", child_dir_path);
            process_directory(child_dir_path);
        } else if (entry->d_type == DT_REG) {
            char file_path[MAX_PATH_LENGTH];
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);

            printf("Processing file %s\n", file_path);
            process_file(file_path);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s directory_path\n", argv[0]);
        return -1;
    }

    const char *directory_path = argv[1];
    process_directory(directory_path);

    return 0;
}