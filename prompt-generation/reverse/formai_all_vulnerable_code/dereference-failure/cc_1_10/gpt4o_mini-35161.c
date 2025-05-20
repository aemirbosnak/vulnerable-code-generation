//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void print_usage(const char *program_name) {
    printf("Usage: %s <source_directory> <destination_directory>\n", program_name);
}

int file_exists(const char *filepath) {
    struct stat buffer;   
    return (stat(filepath, &buffer) == 0);
}

void copy_file(const char *source, const char *destination) {
    char buffer[BUFFER_SIZE];
    size_t bytes;
    FILE *src_file = fopen(source, "rb");
    FILE *dest_file = fopen(destination, "wb");

    if (!src_file || !dest_file) {
        perror("File open error");
        exit(EXIT_FAILURE);
    }

    while ((bytes = fread(buffer, 1, BUFFER_SIZE, src_file)) > 0) {
        fwrite(buffer, 1, bytes, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
}

void sync_files(const char *src_dir, const char *dest_dir) {
    DIR *directory;
    struct dirent *entry;

    if (!(directory = opendir(src_dir))) {
        perror("Failed to open source directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(directory)) != NULL) {
        if (entry->d_type == DT_REG) {
            char src_path[PATH_MAX];
            char dest_path[PATH_MAX];

            snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
            snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

            if (!file_exists(dest_path) || (stat(src_path, NULL) != stat(dest_path, NULL))) {
                printf("Copying: %s -> %s\n", src_path, dest_path);
                copy_file(src_path, dest_path);
            }
        }
    }

    closedir(directory);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *src_dir = argv[1];
    const char *dest_dir = argv[2];

    struct stat sb;

    if (stat(src_dir, &sb) != 0 || !S_ISDIR(sb.st_mode)) {
        fprintf(stderr, "Error: Source directory is not valid or does not exist.\n");
        return EXIT_FAILURE;
    }

    if (stat(dest_dir, &sb) != 0 || !S_ISDIR(sb.st_mode)) {
        fprintf(stderr, "Error: Destination directory is not valid or does not exist.\n");
        return EXIT_FAILURE;
    }

    sync_files(src_dir, dest_dir);
    printf("Synchronization completed successfully.\n");

    return EXIT_SUCCESS;
}