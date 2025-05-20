//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

#define BUFFER_SIZE 4096
#define HASH_SIZE 64

void compute_hash(const char *filename, char *output) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file for hashing");
        exit(EXIT_FAILURE);
    }
    
    unsigned char hash[HASH_SIZE];
    memset(hash, 0, HASH_SIZE);

    // Simple hash calculation
    char buffer[BUFFER_SIZE];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), file))) {
        for (size_t i = 0; i < bytes; i++) {
            hash[i % HASH_SIZE] ^= buffer[i];
        }
    }
    fclose(file);

    for (size_t i = 0; i < HASH_SIZE; i++) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
}

int file_exists(const char *path) {
    struct stat buffer;
    return (stat(path, &buffer) == 0);
}

void sync_files(const char *source_path, const char *dest_path) {
    DIR *dir = opendir(source_path);
    if (!dir) {
        perror("Could not open source directory");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        char src_file[PATH_MAX], dest_file[PATH_MAX];
        snprintf(src_file, sizeof(src_file), "%s/%s", source_path, entry->d_name);
        snprintf(dest_file, sizeof(dest_file), "%s/%s", dest_path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                if (!file_exists(dest_file)) {
                    // Create directory if it does not exist
                    mkdir(dest_file, 0755);
                }
                sync_files(src_file, dest_file);
            }
        } else {
            if (!file_exists(dest_file)) {
                // File does not exist, copy it
                FILE *src_fp = fopen(src_file, "rb");
                FILE *dest_fp = fopen(dest_file, "wb");
                if (!src_fp || !dest_fp) {
                    perror("Could not open file for copying");
                    exit(EXIT_FAILURE);
                }
                char buffer[BUFFER_SIZE];
                size_t bytes;
                while ((bytes = fread(buffer, 1, sizeof(buffer), src_fp))) {
                    fwrite(buffer, 1, bytes, dest_fp);
                }
                fclose(src_fp);
                fclose(dest_fp);
                printf("Copied: %s to %s\n", src_file, dest_file);
            } else {
                // Check hash for existing files
                char src_hash[HASH_SIZE * 2 + 1], dest_hash[HASH_SIZE * 2 + 1];
                compute_hash(src_file, src_hash);
                compute_hash(dest_file, dest_hash);

                if (strcmp(src_hash, dest_hash) != 0) {
                    // Different hash, so copy updated file
                    FILE *src_fp = fopen(src_file, "rb");
                    FILE *dest_fp = fopen(dest_file, "wb");
                    if (!src_fp || !dest_fp) {
                        perror("Could not open file for copying");
                        exit(EXIT_FAILURE);
                    }
                    char buffer[BUFFER_SIZE];
                    size_t bytes;
                    while ((bytes = fread(buffer, 1, sizeof(buffer), src_fp))) {
                        fwrite(buffer, 1, bytes, dest_fp);
                    }
                    fclose(src_fp);
                    fclose(dest_fp);
                    printf("Updated: %s to %s\n", src_file, dest_file);
                }
            }
        }
    }
    closedir(dir);
}

void usage(const char *progname) {
    fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", progname);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        usage(argv[0]);
    }

    const char *source_directory = argv[1];
    const char *destination_directory = argv[2];

    printf("Synchronizing files from %s to %s...\n", source_directory, destination_directory);
    sync_files(source_directory, destination_directory);
    printf("Synchronization completed successfully.\n");

    return 0;
}