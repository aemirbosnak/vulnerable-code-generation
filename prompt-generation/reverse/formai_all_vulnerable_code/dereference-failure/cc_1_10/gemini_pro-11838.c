//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

struct file_info {
    char *name;
    off_t size;
};

struct file_info *files;
int num_files = 0;
off_t total_size = 0;

void add_file(char *name, off_t size) {
    files = realloc(files, (num_files + 1) * sizeof(struct file_info));
    files[num_files].name = strdup(name);
    files[num_files].size = size;
    num_files++;
    total_size += size;
}

void scan_dir(char *path) {
    DIR *dir = opendir(path);
    if (!dir) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir))) {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) {
            continue;
        }

        char *full_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
        sprintf(full_path, "%s/%s", path, entry->d_name);

        struct stat st;
        if (lstat(full_path, &st) == -1) {
            perror("lstat");
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            scan_dir(full_path);
        } else {
            add_file(full_path, st.st_size);
        }

        free(full_path);
    }

    closedir(dir);
}

int compare_files(const void *a, const void *b) {
    const struct file_info *fa = a;
    const struct file_info *fb = b;
    return fb->size - fa->size;
}

void print_results() {
    qsort(files, num_files, sizeof(struct file_info), compare_files);

    for (int i = 0; i < num_files; i++) {
        printf("%s: %lld bytes\n", files[i].name, files[i].size);
    }

    printf("Total size: %lld bytes\n", total_size);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    scan_dir(argv[1]);
    print_results();

    for (int i = 0; i < num_files; i++) {
        free(files[i].name);
    }
    free(files);

    return EXIT_SUCCESS;
}