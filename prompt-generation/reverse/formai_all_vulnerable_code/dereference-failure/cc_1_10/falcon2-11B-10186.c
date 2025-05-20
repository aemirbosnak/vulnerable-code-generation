//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>

#define MAX_DIR_SIZE 100
#define MAX_FILE_SIZE 100

void backup(const char* source, const char* destination) {
    DIR* dir = opendir(source);
    if (!dir) {
        fprintf(stderr, "Error opening directory '%s': %s\n", source, strerror(errno));
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        char filename[MAX_DIR_SIZE];
        strncpy(filename, entry->d_name, MAX_DIR_SIZE - 1);
        if (entry->d_type == DT_DIR) {
            backup(source, filename);
        } else {
            char full_path[MAX_FILE_SIZE];
            sprintf(full_path, "%s/%s", source, entry->d_name);
            char destination_path[MAX_FILE_SIZE];
            sprintf(destination_path, "%s/%s", destination, entry->d_name);
            if (lstat(full_path, NULL) == 0) {
                if (link(full_path, destination_path)!= 0) {
                    fprintf(stderr, "Error linking '%s': %s\n", full_path, strerror(errno));
                }
            } else {
                char new_file_path[MAX_FILE_SIZE];
                sprintf(new_file_path, "%s/%s", destination, entry->d_name);
                if (rename(full_path, new_file_path)!= 0) {
                    fprintf(stderr, "Error renaming '%s': %s\n", full_path, strerror(errno));
                }
            }
        }
    }
    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <source_dir> <destination_dir>\n", argv[0]);
        return 1;
    }
    const char* source = argv[1];
    const char* destination = argv[2];
    if (access(source, F_OK) == -1) {
        fprintf(stderr, "Error accessing source directory '%s': %s\n", source, strerror(errno));
        return 1;
    }
    if (access(destination, F_OK) == -1) {
        fprintf(stderr, "Error accessing destination directory '%s': %s\n", destination, strerror(errno));
        return 1;
    }
    backup(source, destination);
    return 0;
}