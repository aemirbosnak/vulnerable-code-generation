//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void copy_file(const char *src, const char *dest) {
    FILE *source, *destination;
    char buffer[BUFFER_SIZE];
    size_t bytes;

    source = fopen(src, "rb");
    if (source == NULL) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }
    
    destination = fopen(dest, "wb");
    if (destination == NULL) {
        fclose(source);
        perror("Error creating destination file");
        exit(EXIT_FAILURE);
    }

    while ((bytes = fread(buffer, 1, BUFFER_SIZE, source)) > 0) {
        fwrite(buffer, 1, bytes, destination);
    }

    fclose(source);
    fclose(destination);
}

int file_exists(const char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

long get_file_size(const char *filename) {
    struct stat st;
    if (stat(filename, &st) == 0) {
        return st.st_size;
    }
    return -1;  // Error in getting file size
}

void synchronize_directories(const char *src_dir, const char *dest_dir) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(src_dir);
    if (dir == NULL) {
        perror("Unable to open source directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {  // Skip hidden files and directories
            continue;
        }

        char src_file[PATH_MAX];
        char dest_file[PATH_MAX];

        snprintf(src_file, sizeof(src_file), "%s/%s", src_dir, entry->d_name);
        snprintf(dest_file, sizeof(dest_file), "%s/%s", dest_dir, entry->d_name);

        if (!file_exists(dest_file) || 
            get_file_size(src_file) != get_file_size(dest_file)) {
            printf("Copying %s to %s\n", src_file, dest_file);
            copy_file(src_file, dest_file);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *src_dir = argv[1];
    const char *dest_dir = argv[2];

    synchronize_directories(src_dir, dest_dir);
    
    printf("Synchronization complete.\n");
    return EXIT_SUCCESS;
}