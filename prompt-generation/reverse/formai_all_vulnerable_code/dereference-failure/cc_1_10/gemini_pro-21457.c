//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

struct file_info {
    char *path;
    long size;
};

struct file_info *files;
int num_files = 0;

void add_file(char *path, long size) {
    files = realloc(files, sizeof(struct file_info) * (num_files + 1));
    files[num_files].path = malloc(strlen(path) + 1);
    strcpy(files[num_files].path, path);
    files[num_files].size = size;
    num_files++;
}

void free_files() {
    for (int i = 0; i < num_files; i++) {
        free(files[i].path);
    }
    free(files);
}

void print_files() {
    for (int i = 0; i < num_files; i++) {
        printf("%s: %ld bytes\n", files[i].path, files[i].size);
    }
}

void analyze_directory(char *path) {
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

        char *full_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
        strcpy(full_path, path);
        strcat(full_path, "/");
        strcat(full_path, entry->d_name);

        struct stat statbuf;
        if (stat(full_path, &statbuf) == 0) {
            if (S_ISDIR(statbuf.st_mode)) {
                analyze_directory(full_path);
            } else {
                add_file(full_path, statbuf.st_size);
            }
        }
        free(full_path);
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    analyze_directory(argv[1]);
    print_files();

    free_files();

    return 0;
}