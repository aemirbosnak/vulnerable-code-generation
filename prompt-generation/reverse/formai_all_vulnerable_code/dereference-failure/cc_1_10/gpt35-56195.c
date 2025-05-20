//FormAI DATASET v1.0 Category: File Synchronizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 256

void sync_directory(char* source_path, char* dest_path) {
    DIR* source_dir = opendir(source_path);
    DIR* dest_dir = opendir(dest_path);

    if (!source_dir || !dest_dir) {
        printf("Error: Failed to open directories.");
        exit(1);
    }

    struct dirent* source_entry;
    struct dirent* dest_entry;

    while ((source_entry = readdir(source_dir)) != NULL) {
        if (source_entry->d_name[0] == '.') {
            continue; // Ignore hidden files
        }

        char full_source_path[MAX_PATH_LENGTH];
        char full_dest_path[MAX_PATH_LENGTH];
        sprintf(full_source_path, "%s/%s", source_path, source_entry->d_name);
        sprintf(full_dest_path, "%s/%s", dest_path, source_entry->d_name);

        struct stat source_stat;
        if (stat(full_source_path, &source_stat) != 0) {
            printf("Error: Failed to get file stat.");
            exit(1);
        }

        if (S_ISDIR(source_stat.st_mode)) {
            mkdir(full_dest_path, 0777);
            sync_directory(full_source_path, full_dest_path); // Recurse into subdirectories
        } else {
            struct stat dest_stat;
            if (stat(full_dest_path, &dest_stat) == 0 && source_stat.st_mtime < dest_stat.st_mtime) {
                continue; // Don't copy if file is older in destination
            }

            FILE* source_file = fopen(full_source_path, "rb");
            FILE* dest_file = fopen(full_dest_path, "w+");

            if (source_file == NULL || dest_file == NULL) {
                printf("Error: Failed to open files.");
                exit(1);
            }

            char buffer[1024];
            size_t read_size;

            while ((read_size = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
                fwrite(buffer, 1, read_size, dest_file);
            }

            fclose(source_file);
            fclose(dest_file);
        }
    }

    closedir(source_dir);
    closedir(dest_dir);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: ./sync <source_dir> <dest_dir>");
        exit(1);
    }

    sync_directory(argv[1], argv[2]);

    printf("Synchronization complete.\n");
    return 0;
}