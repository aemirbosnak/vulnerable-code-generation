//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void usage(const char* prog_name) {
    fprintf(stderr, "Usage: %s <source_dir> <dest_dir>\n", prog_name);
    exit(EXIT_FAILURE);
}

int is_newer(const char* src_file, const char* dest_file) {
    struct stat src_stat, dest_stat;
    if (stat(src_file, &src_stat) == -1) {
        perror("stat");
        return 1; // Return true if src_file cannot be accessed
    }
    if (stat(dest_file, &dest_stat) == -1) {
        return 1; // If dest_file doesn't exist, src_file is newer
    }
    return src_stat.st_mtime > dest_stat.st_mtime;
}

void sync_files(const char* src_dir, const char* dest_dir) {
    DIR* dir = opendir(src_dir);
    struct dirent* entry;

    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files

        char src_filepath[512];
        char dest_filepath[512];

        snprintf(src_filepath, sizeof(src_filepath), "%s/%s", src_dir, entry->d_name);
        snprintf(dest_filepath, sizeof(dest_filepath), "%s/%s", dest_dir, entry->d_name);

        struct stat src_stat;
        if (stat(src_filepath, &src_stat) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(src_stat.st_mode)) {
            // Create directory if it does not exist
            mkdir(dest_filepath, 0755);
            // Recursively sync files in the subdirectory
            sync_files(src_filepath, dest_filepath);
        } else if (S_ISREG(src_stat.st_mode)) {
            // Check if the file should be copied
            if (!access(dest_filepath, F_OK) || is_newer(src_filepath, dest_filepath)) {
                FILE* src_file = fopen(src_filepath, "rb");
                FILE* dest_file = fopen(dest_filepath, "wb");

                if (!src_file || !dest_file) {
                    perror("fopen");
                    if (src_file) fclose(src_file);
                    continue;
                }

                char buffer[1024];
                size_t bytes;
                while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                    fwrite(buffer, 1, bytes, dest_file);
                }

                fclose(src_file);
                fclose(dest_file);
                printf("Copied: %s to %s\n", src_filepath, dest_filepath);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        usage(argv[0]);
    }

    const char* source_dir = argv[1];
    const char* dest_dir = argv[2];

    struct stat st;
    if (stat(source_dir, &st) != 0 || !S_ISDIR(st.st_mode)) {
        fprintf(stderr, "Source directory does not exist or is not a directory: %s\n", source_dir);
        exit(EXIT_FAILURE);
    }

    if (stat(dest_dir, &st) != 0 || !S_ISDIR(st.st_mode)) {
        fprintf(stderr, "Destination directory does not exist or is not a directory: %s\n", dest_dir);
        exit(EXIT_FAILURE);
    }

    sync_files(source_dir, dest_dir);

    return 0;
}