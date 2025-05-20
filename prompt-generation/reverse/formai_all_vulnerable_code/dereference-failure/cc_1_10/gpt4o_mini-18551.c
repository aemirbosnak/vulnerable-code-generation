//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 512

void usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <source> <destination>\n", prog_name);
    fprintf(stderr, "Synchronizes files from source to destination.\n");
}

int is_directory(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) != 0) {
        perror("stat");
        return 0;
    }
    return S_ISDIR(statbuf.st_mode);
}

void copy_file(const char *src, const char *dest) {
    FILE *source_file = fopen(src, "rb");
    if (!source_file) {
        perror("fopen");
        return;
    }

    FILE *dest_file = fopen(dest, "wb");
    if (!dest_file) {
        perror("fopen");
        fclose(source_file);
        return;
    }

    char buffer[1024];
    size_t size;

    while ((size = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
        fwrite(buffer, 1, size, dest_file);
    }

    fclose(source_file);
    fclose(dest_file);
}

void sync_directories(const char *src, const char *dest) {
    DIR *dir = opendir(src);
    struct dirent *entry;

    if (!dir) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char src_path[MAX_PATH];
        char dest_path[MAX_PATH];

        snprintf(src_path, sizeof(src_path), "%s/%s", src, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest, entry->d_name);

        if (is_directory(src_path)) {
            mkdir(dest_path, 0755); // create directory if not exist
            sync_directories(src_path, dest_path);
        } else {
            // Check if the file exists in destination and copy if not 
            if (access(dest_path, F_OK) == -1) {
                printf("Copying: %s -> %s\n", src_path, dest_path);
                copy_file(src_path, dest_path);
            }
        }
    }
    
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *src = argv[1];
    const char *dest = argv[2];

    if (!is_directory(src)) {
        fprintf(stderr, "Source path is not a directory.\n");
        return EXIT_FAILURE;
    }

    mkdir(dest, 0755); // create the destination directory if not exist
    
    sync_directories(src, dest);

    printf("Synchronization complete!\n");

    return EXIT_SUCCESS;
}