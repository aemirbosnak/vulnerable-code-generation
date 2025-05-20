//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

void synchronize(const char *src, const char *dest);
int file_exists(const char *filepath);
int is_directory(const char *path);
void copy_file(const char *src, const char *dest);
void create_directory(const char *path);
void print_usage();

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *source = argv[1];
    const char *destination = argv[2];

    synchronize(source, destination);

    printf("Synchronization complete from '%s' to '%s'\n", source, destination);
    return EXIT_SUCCESS;
}

void synchronize(const char *src, const char *dest) {
    struct stat stat_src, stat_dest;

    // Check if src exists
    if (stat(src, &stat_src) != 0) {
        perror("Source path does not exist");
        return;
    }

    // If it's a directory, synchronize the contents
    if (is_directory(src)) {
        create_directory(dest);

        DIR *dir = opendir(src);
        struct dirent *entry;

        while ((entry = readdir(dir)) != NULL) {
            // Skip "." and ".."
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            char src_path[1024], dest_path[1024];
            snprintf(src_path, sizeof(src_path), "%s/%s", src, entry->d_name);
            snprintf(dest_path, sizeof(dest_path), "%s/%s", dest, entry->d_name);

            // Recursively synchronize subdirectories and files
            synchronize(src_path, dest_path);
        }
        closedir(dir);
    } else {
        // If it's a file, check if it exists in the destination
        if (file_exists(dest)) {
            stat(dest, &stat_dest);

            // Check if the file sizes are different
            if (stat_src.st_size != stat_dest.st_size) {
                printf("Copying (size mismatch): %s to %s\n", src, dest);
                copy_file(src, dest);
            }
        } else {
            // File does not exist in the destination, copy it
            printf("Copying (file doesn't exist): %s to %s\n", src, dest);
            copy_file(src, dest);
        }
    }
}

int file_exists(const char *filepath) {
    struct stat st;
    return (stat(filepath, &st) == 0);
}

int is_directory(const char *path) {
    struct stat st;
    if (stat(path, &st) != 0) {
        return 0; // Path does not exist or cannot be accessed
    }
    return S_ISDIR(st.st_mode);
}

void copy_file(const char *src, const char *dest) {
    int src_fd = open(src, O_RDONLY);
    if (src_fd < 0) {
        perror("Error opening source file");
        return;
    }

    int dest_fd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0) {
        perror("Error opening destination file");
        close(src_fd);
        return;
    }

    char buffer[4096];
    ssize_t bytes_read;

    while ((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0) {
        write(dest_fd, buffer, bytes_read);
    }

    close(src_fd);
    close(dest_fd);
}

void create_directory(const char *path) {
    if (!is_directory(path)) {
        if (mkdir(path, 0755) == -1) {
            perror("Error creating directory");
        }
    }
}

void print_usage() {
    fprintf(stderr, "Usage: file_sync <source_directory> <destination_directory>\n");
}