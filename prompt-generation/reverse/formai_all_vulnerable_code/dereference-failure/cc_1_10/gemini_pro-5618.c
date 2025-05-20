//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 256

struct file_info {
    char *name;
    unsigned long long size;
};

struct file_info *files;
size_t num_files = 0;

void add_file(const char *path, unsigned long long size) {
    files = realloc(files, (num_files + 1) * sizeof(*files));
    files[num_files].name = strdup(path);
    files[num_files].size = size;
    num_files++;
}

void analyze_directory(const char *path) {
    DIR *dir = opendir(path);
    if (!dir) {
        perror("opendir");
        return;
    }

    struct dirent *dirent;
    while ((dirent = readdir(dir)) != NULL) {
        if (!strcmp(dirent->d_name, ".") || !strcmp(dirent->d_name, "..")) {
            continue;
        }

        char subpath[MAX_PATH];
        snprintf(subpath, MAX_PATH, "%s/%s", path, dirent->d_name);

        struct stat statbuf;
        if (lstat(subpath, &statbuf) == -1) {
            perror("lstat");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            analyze_directory(subpath);
        } else if (S_ISREG(statbuf.st_mode)) {
            add_file(subpath, statbuf.st_size);
        }
    }

    closedir(dir);
}

int compare_files(const void *a, const void *b) {
    const struct file_info *fa = a;
    const struct file_info *fb = b;
    return fb->size - fa->size;
}

void print_results() {
    qsort(files, num_files, sizeof(*files), compare_files);

    for (size_t i = 0; i < num_files; i++) {
        printf("%10llu %s\n", files[i].size, files[i].name);
    }
}

int main() {
    analyze_directory("/Users/jdoe/Documents");
    print_results();
    free(files);
    return 0;
}