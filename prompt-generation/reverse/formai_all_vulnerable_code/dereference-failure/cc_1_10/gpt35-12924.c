//FormAI DATASET v1.0 Category: File Synchronizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>
#include <sys/stat.h>

void sync_files(const char* source_dir, const char* dest_dir) {
    DIR* source = opendir(source_dir);
    struct dirent* entry;

    if (!source) {
        printf("Failed to open directory: %s\n", source_dir);
        return;
    }

    while ((entry = readdir(source))) {
        // Ignore hidden files and directories
        if (entry->d_name[0] == '.') {
            continue;
        }

        // construct full file paths for source and destination files
        char source_path[256];
        sprintf(source_path, "%s/%s", source_dir, entry->d_name);

        char dest_path[256];
        sprintf(dest_path, "%s/%s", dest_dir, entry->d_name);

        // get stats for the source file
        struct stat source_stat;
        if (stat(source_path, &source_stat) == -1) {
            printf("Failed to get stats for: %s\n", source_path);
            continue;
        }

        // check if the file already exists in the destination directory
        struct stat dest_stat;
        int exists = (stat(dest_path, &dest_stat) == 0);
        int is_dir = S_ISDIR(source_stat.st_mode);

        // if the file is a directory, create it in the destination directory
        if (is_dir) {
            if (!exists) {
                int res = mkdir(dest_path, 0755);
                if (res == -1) {
                    printf("Failed to create directory: %s\n", dest_path);
                }
                else {
                    printf("Created directory: %s\n", dest_path);
                }
            }

            // recursively sync files in the sub-directory
            sync_files(source_path, dest_path);
        }
        else {
            // if the file already exists in the destination directory, check if it needs to be updated
            if (exists) {
                time_t source_time = source_stat.st_mtime;
                time_t dest_time = dest_stat.st_mtime;

                if (difftime(source_time, dest_time) > 0) {
                    // update the file in the destination directory
                    FILE* source_file = fopen(source_path, "r");
                    FILE* dest_file = fopen(dest_path, "w");

                    if (!source_file) {
                        printf("Failed to open source file: %s\n", source_path);
                        continue;
                    }

                    if (!dest_file) {
                        printf("Failed to create destination file: %s\n", dest_path);
                        continue;
                    }

                    char buf[4096];
                    size_t size;

                    while ((size = fread(buf, 1, sizeof(buf), source_file)) > 0) {
                        fwrite(buf, 1, size, dest_file);
                    }

                    fclose(source_file);
                    fclose(dest_file);

                    printf("Updated file: %s\n", dest_path);
                }
            }
            else {
                // copy the file to the destination directory
                FILE* source_file = fopen(source_path, "r");
                FILE* dest_file = fopen(dest_path, "w");

                if (!source_file) {
                    printf("Failed to open source file: %s\n", source_path);
                    continue;
                }

                if (!dest_file) {
                    printf("Failed to create destination file: %s\n", dest_path);
                    continue;
                }

                char buf[4096];
                size_t size;

                while ((size = fread(buf, 1, sizeof(buf), source_file)) > 0) {
                    fwrite(buf, 1, size, dest_file);
                }

                fclose(source_file);
                fclose(dest_file);

                printf("Copied file: %s\n", dest_path);
            }
        }
    }

    closedir(source);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
        return 1;
    }

    const char* source_dir = argv[1];
    const char* dest_dir = argv[2];

    sync_files(source_dir, dest_dir);

    return 0;
}