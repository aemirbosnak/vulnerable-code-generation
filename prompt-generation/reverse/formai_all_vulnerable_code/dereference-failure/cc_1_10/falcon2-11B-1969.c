//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

void create_backup(const char* path) {
    if (path == NULL) {
        fprintf(stderr, "Error: path is NULL\n");
        return;
    }

    const char* backup_path = malloc(strlen(path) + 8);
    strcpy(backup_path, path);
    strcat(backup_path, "_backup");

    char* current_directory = malloc(strlen(path) + 1);
    strcpy(current_directory, path);
    char* directory = malloc(strlen(path) + 1);
    strcpy(directory, path);
    strcat(directory, "/");
    strcat(directory, path);

    DIR* dir = opendir(directory);
    if (dir == NULL) {
        fprintf(stderr, "Error: could not open directory %s\n", directory);
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        char* file_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
        strcpy(file_path, path);
        strcat(file_path, "/");
        strcat(file_path, entry->d_name);

        FILE* file = fopen(file_path, "r");
        if (file == NULL) {
            fprintf(stderr, "Error: could not open file %s\n", file_path);
            free(file_path);
            continue;
        }

        size_t size = 0;
        char* buffer = malloc(1024);
        while (fread(buffer, 1, 1024, file) > 0) {
            size += strlen(buffer);
            buffer = realloc(buffer, size);
        }

        fclose(file);

        FILE* backup_file = fopen(backup_path, "w");
        if (backup_file == NULL) {
            fprintf(stderr, "Error: could not open file %s\n", backup_path);
            free(file_path);
            free(buffer);
            continue;
        }

        size_t written = 0;
        while (written < size) {
            size_t to_write = size - written;
            if (to_write > 1024) {
                to_write = 1024;
            }
            fwrite(buffer + written, 1, to_write, backup_file);
            written += to_write;
        }

        fclose(backup_file);
        free(buffer);
        free(file_path);
    }

    free(current_directory);
    free(backup_path);
    closedir(dir);
}

int main() {
    create_backup(".");
    return 0;
}