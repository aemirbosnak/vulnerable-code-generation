//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 8192

void copy_file(const char *src, const char *dest) {
    FILE *source = fopen(src, "rb");
    FILE *destination = fopen(dest, "wb");
    if (source == NULL || destination == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) != 0) {
        fwrite(buffer, 1, bytes, destination);
    }

    fclose(source);
    fclose(destination);
}

void recover_file(const char *filepath) {
    char *filename = strrchr(filepath, '/');
    if (filename != NULL) {
        filename++; // move past the '/' character
    } else {
        filename = (char *)filepath; // no '/' found, take the whole path
    }

    char recovery_path[256];
    snprintf(recovery_path, sizeof(recovery_path), "recovered_%s", filename);

    copy_file(filepath, recovery_path);
    printf("Recovered: %s -> %s\n", filepath, recovery_path);
}

int is_deleted_file(const char *filepath) {
    struct stat file_info;
    if (stat(filepath, &file_info) == -1) {
        return 0; // file doesn't exist, assume it's deleted
    }
    return !S_ISREG(file_info.st_mode);
}

void scan_directory(const char *dirname) {
    DIR *dir = opendir(dirname);
    if (dir == NULL) {
        perror("Could not open directory");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip current and parent directory entries
        }

        char fullpath[512];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", dirname, entry->d_name);

        if (is_deleted_file(fullpath)) {
            recover_file(fullpath);
        }
    }

    closedir(dir);
}

void print_usage() {
    fprintf(stderr, "Usage: ./data_recovery_tool <directory_to_scan>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *directory = argv[1];
    scan_directory(directory);

    return EXIT_SUCCESS;
}