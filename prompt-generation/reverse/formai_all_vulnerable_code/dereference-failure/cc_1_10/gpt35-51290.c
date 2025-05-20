//FormAI DATASET v1.0 Category: File Synchronizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

int file_exists(char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

void sync_files(char *source_dir, char *dest_dir) {
    DIR *dir = opendir(source_dir);
    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue;
        }

        char source_path[256];
        strcpy(source_path, source_dir);
        strcat(source_path, "/");
        strcat(source_path, entry->d_name);

        char dest_path[256];
        strcpy(dest_path, dest_dir);
        strcat(dest_path, "/");
        strcat(dest_path, entry->d_name);

        struct stat source_stat, dest_stat;
        int source_exists = stat(source_path, &source_stat) == 0;
        int dest_exists = stat(dest_path, &dest_stat) == 0;

        if (source_exists && dest_exists) {
            if (source_stat.st_mtime > dest_stat.st_mtime) {
                FILE *source_file = fopen(source_path, "rb");
                if (source_file == NULL) {
                    printf("Failed to open %s\n", source_path);
                    continue;
                }

                FILE *dest_file = fopen(dest_path, "wb");
                if (dest_file == NULL) {
                    printf("Failed to open %s\n", dest_path);
                    continue;
                }

                char buffer[1024];
                size_t nread;
                while ((nread = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
                    fwrite(buffer, 1, nread, dest_file);
                }

                fclose(source_file);
                fclose(dest_file);

                printf("Synced %s to %s\n", source_path, dest_path);
            }
        } else if (source_exists && !dest_exists) {
            FILE *source_file = fopen(source_path, "rb");
            if (source_file == NULL) {
                printf("Failed to open %s\n", source_path);
                continue;
            }

            FILE *dest_file = fopen(dest_path, "wb");
            if (dest_file == NULL) {
                printf("Failed to open %s\n", dest_path);
                continue;
            }

            char buffer[1024];
            size_t nread;
            while ((nread = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
                fwrite(buffer, 1, nread, dest_file);
            }

            fclose(source_file);
            fclose(dest_file);

            printf("Copied %s to %s\n", source_path, dest_path);
        } else {
            printf("File not found: %s\n", source_path);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: sync_files [source_dir] [dest_dir]\n");
        exit(1);
    }

    if (!file_exists(argv[1]) || !file_exists(argv[2])) {
        printf("Source or destination directory does not exist\n");
        exit(1);
    }

    sync_files(argv[1], argv[2]);

    printf("Finished syncing files\n");

    return 0;
}