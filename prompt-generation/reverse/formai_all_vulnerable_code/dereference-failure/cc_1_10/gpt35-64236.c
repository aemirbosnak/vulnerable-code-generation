//FormAI DATASET v1.0 Category: File Synchronizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

// Define buffer size for file read/write operations
#define BUFFER_SIZE 1024

int file_exists(const char *filename) {
    // Checks if file exists
    struct stat buffer;   
    return (stat(filename, &buffer) == 0);
}

int file_is_directory(const char *path) {
    // Checks if file is a directory
    struct stat path_stat;
    if (stat(path, &path_stat) != 0) {
        return 0;
    }
    return S_ISDIR(path_stat.st_mode);
}

void copy_file(const char *src_path, const char *dest_path) {
    // Copies file from source path to destination path
    char buffer[BUFFER_SIZE];
    FILE *src_file = fopen(src_path, "rb");
    FILE *dest_file = fopen(dest_path, "wb");
    size_t bytes;

    while ((bytes = fread(buffer, sizeof(char), BUFFER_SIZE, src_file)) > 0) {
        fwrite(buffer, sizeof(char), bytes, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
}

void sync_directory(const char *src_dir, const char *dest_dir) {
    // Syncs the files in given source and destination directories
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(src_dir))) {
        fprintf(stderr, "Error: Cannot open directory '%s': %s\n", src_dir, strerror(errno));
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            // Recursively sync sub directories
            char src_subdir_path[strlen(src_dir) + strlen(entry->d_name) + 2];
            sprintf(src_subdir_path, "%s/%s", src_dir, entry->d_name);

            char dest_subdir_path[strlen(dest_dir) + strlen(entry->d_name) + 2];
            sprintf(dest_subdir_path, "%s/%s", dest_dir, entry->d_name);

            if (!file_is_directory(dest_subdir_path)) {
                // If destination subdir does not exist, create it
                mkdir(dest_subdir_path, 0777);
            }
            sync_directory(src_subdir_path, dest_subdir_path);

        } else {
            char src_path[strlen(src_dir) + strlen(entry->d_name) + 2];
            sprintf(src_path, "%s/%s", src_dir, entry->d_name);

            char dest_path[strlen(dest_dir) + strlen(entry->d_name) + 2];
            sprintf(dest_path, "%s/%s", dest_dir, entry->d_name);

            if (file_exists(dest_path)) {
                // If destination file exists, check if it is different from source file
                FILE *src_file = fopen(src_path, "rb");
                FILE *dest_file = fopen(dest_path, "rb");

                if (src_file != NULL && dest_file != NULL) {
                    if (fseek(src_file, 0L, SEEK_END) == 0 && fseek(dest_file, 0L, SEEK_END) == 0) {
                        long src_size = ftell(src_file);
                        long dest_size = ftell(dest_file);

                        if (src_size == dest_size) {
                            // Source and destination files are of same size, check if content is different
                            rewind(src_file);
                            rewind(dest_file);

                            char src_buffer[BUFFER_SIZE];
                            char dest_buffer[BUFFER_SIZE];

                            size_t n_read_src;
                            size_t n_read_dest;

                            while ((n_read_src = fread(src_buffer, 1, sizeof(src_buffer), src_file)) > 0
                                    && (n_read_dest = fread(dest_buffer, 1, sizeof(dest_buffer), dest_file)) > 0) {
                                if (memcmp(src_buffer, dest_buffer, n_read_src) != 0) {
                                    // Content is different, copy source file to destination file
                                    fclose(src_file);
                                    fclose(dest_file);
                                    copy_file(src_path, dest_path);
                                    printf("Synced file '%s'\n", dest_path);
                                    break;
                                }
                            }
                        }
                    }
                }
                fclose(src_file);
                fclose(dest_file);

            } else {
                // File does not exist in destination directory, copy it from source directory
                copy_file(src_path, dest_path);
                printf("Copied file '%s' to '%s'\n", src_path, dest_path);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <source_dir> <destination_dir>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    sync_directory(argv[1], argv[2]);
    printf("Directory synchronization complete\n");

    exit(EXIT_SUCCESS);
}