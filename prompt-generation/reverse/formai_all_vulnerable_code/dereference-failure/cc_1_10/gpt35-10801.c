//FormAI DATASET v1.0 Category: File Synchronizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILEPATH_LENGTH 256

int sync_files(const char* source_dir, const char* dest_dir);

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <source_dir> <dest_dir>\n", argv[0]);
        return 1;
    }
    const char* source_dir = argv[1];
    const char* dest_dir = argv[2];
    int result = sync_files(source_dir, dest_dir);
    return result;
}

int sync_files(const char* source_dir, const char* dest_dir) {
    DIR* dir = opendir(source_dir);
    if (dir == NULL) {
        printf("Could not open directory %s\n", source_dir);
        return 1;
    }
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue;
        }
        char source_filepath[MAX_FILEPATH_LENGTH];
        snprintf(source_filepath, MAX_FILEPATH_LENGTH, "%s/%s", source_dir, entry->d_name);
        char dest_filepath[MAX_FILEPATH_LENGTH];
        snprintf(dest_filepath, MAX_FILEPATH_LENGTH, "%s/%s", dest_dir, entry->d_name);
        struct stat source_stat;
        if (stat(source_filepath, &source_stat) != 0) {
            printf("Could not get file info for %s\n", source_filepath);
            return 1;
        }
        struct stat dest_stat;
        if (stat(dest_filepath, &dest_stat) != 0) {
            // File does not exist in destination, so copy it over
            printf("Copying file %s to %s\n", source_filepath, dest_filepath);
            FILE* source_file = fopen(source_filepath, "r");
            FILE* dest_file = fopen(dest_filepath, "w");
            if (source_file == NULL || dest_file == NULL) {
                printf("Could not open source or destination file for %s\n", source_filepath);
                return 1;
            }
            char buffer[1024];
            int bytes_read;
            while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
                fwrite(buffer, 1, bytes_read, dest_file);
            }
            fclose(source_file);
            fclose(dest_file);
        } else {
            // File exists in destination, so check if it needs to be updated
            if (source_stat.st_mtime > dest_stat.st_mtime) {
                printf("Updating file %s\n", dest_filepath);
                FILE* source_file = fopen(source_filepath, "r");
                FILE* dest_file = fopen(dest_filepath, "w");
                if (source_file == NULL || dest_file == NULL) {
                    printf("Could not open source or destination file for %s\n", source_filepath);
                    return 1;
                }
                char buffer[1024];
                int bytes_read;
                while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
                    fwrite(buffer, 1, bytes_read, dest_file);
                }
                fclose(source_file);
                fclose(dest_file);
            }
        }
    }
    closedir(dir);
    return 0;
}