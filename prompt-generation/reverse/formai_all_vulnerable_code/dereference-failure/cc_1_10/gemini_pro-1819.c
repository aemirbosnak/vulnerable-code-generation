//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

struct FileInfo {
    char *name;
    long long size;
};

struct FileInfoList {
    struct FileInfo *files;
    size_t num_files;
    size_t capacity;
};

void init_file_info_list(struct FileInfoList *list) {
    list->files = NULL;
    list->num_files = 0;
    list->capacity = 0;
}

void free_file_info_list(struct FileInfoList *list) {
    for (size_t i = 0; i < list->num_files; i++) {
        free(list->files[i].name);
    }
    free(list->files);
}

int compare_file_info(const void *a, const void *b) {
    const struct FileInfo *fa = a;
    const struct FileInfo *fb = b;
    return fb->size - fa->size;
}

void add_file_info_to_list(struct FileInfoList *list, const char *name, long long size) {
    if (list->num_files >= list->capacity) {
        size_t new_capacity = list->capacity * 2 + 1;
        struct FileInfo *new_files = realloc(list->files, new_capacity * sizeof(struct FileInfo));
        if (new_files == NULL) {
            perror("realloc");
            exit(EXIT_FAILURE);
        }
        list->files = new_files;
        list->capacity = new_capacity;
    }
    list->files[list->num_files].name = strdup(name);
    list->files[list->num_files].size = size;
    list->num_files++;
}

void print_file_info_list(const struct FileInfoList *list) {
    for (size_t i = 0; i < list->num_files; i++) {
        printf("%lld\t%s\n", list->files[i].size, list->files[i].name);
    }
}

void analyze_directory(const char *dir, struct FileInfoList *list) {
    DIR *d = opendir(dir);
    if (d == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }
    struct dirent *entry;
    while ((entry = readdir(d)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char *path = malloc(strlen(dir) + strlen(entry->d_name) + 2);
        if (path == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        sprintf(path, "%s/%s", dir, entry->d_name);
        struct stat st;
        if (lstat(path, &st) == -1) {
            perror("lstat");
            exit(EXIT_FAILURE);
        }
        if (S_ISDIR(st.st_mode)) {
            analyze_directory(path, list);
        } else if (S_ISREG(st.st_mode)) {
            add_file_info_to_list(list, path, st.st_size);
        }
        free(path);
    }
    closedir(d);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    struct FileInfoList list;
    init_file_info_list(&list);
    analyze_directory(argv[1], &list);
    qsort(list.files, list.num_files, sizeof(struct FileInfo), compare_file_info);
    print_file_info_list(&list);
    free_file_info_list(&list);
    return EXIT_SUCCESS;
}