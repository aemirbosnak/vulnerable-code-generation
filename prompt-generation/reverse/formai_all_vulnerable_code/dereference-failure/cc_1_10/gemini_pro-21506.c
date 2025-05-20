//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

#define MAX_PATH 256
#define MAX_FILES 1000

typedef struct file_info_t {
    char path[MAX_PATH];
    char name[MAX_PATH];
    time_t last_modified;
    size_t size;
} file_info_t;

file_info_t files[MAX_FILES];
int num_files = 0;

void scan_directory(const char *path) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[MAX_PATH];
        snprintf(full_path, MAX_PATH, "%s/%s", path, entry->d_name);

        struct stat statbuf;
        if (stat(full_path, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            scan_directory(full_path);
        } else if (S_ISREG(statbuf.st_mode)) {
            file_info_t file_info;
            strcpy(file_info.path, full_path);
            strcpy(file_info.name, entry->d_name);
            file_info.last_modified = statbuf.st_mtime;
            file_info.size = statbuf.st_size;
            files[num_files++] = file_info;
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    scan_directory(argv[1]);

    for (int i = 0; i < num_files; i++) {
        printf("%s (%ld bytes, last modified: %s)\n", files[i].path, files[i].size, ctime(&files[i].last_modified));
    }

    return EXIT_SUCCESS;
}