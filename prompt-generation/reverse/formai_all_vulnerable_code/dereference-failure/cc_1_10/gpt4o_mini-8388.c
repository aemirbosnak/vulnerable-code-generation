//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_PATH 1024
#define MAX_FILES 1024

typedef struct {
    char name[MAX_PATH];
    time_t mod_time;
} FileEntry;

void copy_file(const char *src, const char *dest) {
    FILE *source = fopen(src, "rb");
    if (source == NULL) {
        perror("Error opening source file");
        return;
    }

    FILE *destination = fopen(dest, "wb");
    if (destination == NULL) {
        perror("Error opening destination file");
        fclose(source);
        return;
    }

    char buffer[4096];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes, destination);
    }

    fclose(source);
    fclose(destination);
}

int get_file_list(const char *directory, FileEntry *files, int *count) {
    struct dirent *entry;
    DIR *dp = opendir(directory);
    if (dp == NULL) {
        perror("Could not open directory");
        return -1;
    }

    struct stat file_stat;
    int index = 0;

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) {
            char filepath[MAX_PATH];
            snprintf(filepath, sizeof(filepath), "%s/%s", directory, entry->d_name);
            if (stat(filepath, &file_stat) == 0) {
                strncpy(files[index].name, entry->d_name, MAX_PATH);
                files[index].mod_time = file_stat.st_mtime;
                index++;
            }
        }
    }

    closedir(dp);
    *count = index;
    return 0;
}

void synchronize_directories(const char *src_dir, const char *dst_dir) {
    FileEntry src_files[MAX_FILES];
    FileEntry dst_files[MAX_FILES];
    int src_count = 0, dst_count = 0;

    if (get_file_list(src_dir, src_files, &src_count) < 0) {
        return;
    }

    if (get_file_list(dst_dir, dst_files, &dst_count) < 0) {
        return;
    }

    for (int i = 0; i < src_count; i++) {
        int found = 0;

        for (int j = 0; j < dst_count; j++) {
            if (strcmp(src_files[i].name, dst_files[j].name) == 0) {
                if (src_files[i].mod_time > dst_files[j].mod_time) {
                    found = 1;  // Newer version in source
                }
                break;
            }
        }

        if (!found) {
            char src_path[MAX_PATH];
            char dst_path[MAX_PATH];
            snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, src_files[i].name);
            snprintf(dst_path, sizeof(dst_path), "%s/%s", dst_dir, src_files[i].name);
            copy_file(src_path, dst_path);
            printf("Copied: %s -> %s\n", src_path, dst_path);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *src_dir = argv[1];
    const char *dst_dir = argv[2];

    synchronize_directories(src_dir, dst_dir);

    return EXIT_SUCCESS;
}