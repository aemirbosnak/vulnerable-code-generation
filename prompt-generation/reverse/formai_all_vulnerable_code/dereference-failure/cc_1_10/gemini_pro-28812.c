//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdbool.h>

#define BUFSIZE 1024

struct file_data {
    char *name;
    size_t size;
};

typedef struct dirent *(*readdir_func_t)(DIR *);

static int compare_file_data(const void *a, const void *b) {
    const struct file_data *fa = a;
    const struct file_data *fb = b;

    return fa->size - fb->size;
}

static void free_file_data(struct file_data *data) {
    free(data->name);
    free(data);
}

static void analyze_directory(const char *path, const char *prefix, size_t *total_size, readdir_func_t readdir_func) {
    DIR *dir;
    struct dirent *entry;
    struct stat st;
    size_t path_len;
    char *full_path;

    path_len = strlen(path);
    full_path = malloc(path_len + BUFSIZE);
    if (!full_path) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    dir = opendir(path);
    if (!dir) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir_func(dir))) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(full_path, path_len + BUFSIZE, "%s/%s", path, entry->d_name);

        if (lstat(full_path, &st) == -1) {
            perror("lstat");
            free(full_path);
            closedir(dir);
            exit(EXIT_FAILURE);
        }

        if (S_ISDIR(st.st_mode)) {
            analyze_directory(full_path, prefix, total_size, readdir_func);
        } else if (S_ISREG(st.st_mode)) {
            struct file_data *data = malloc(sizeof(struct file_data));
            if (!data) {
                perror("malloc");
                free(full_path);
                closedir(dir);
                exit(EXIT_FAILURE);
            }

            data->name = strdup(entry->d_name);
            if (!data->name) {
                perror("strdup");
                free(full_path);
                closedir(dir);
                exit(EXIT_FAILURE);
            }

            data->size = st.st_size;

            printf("%s%s: %lu bytes\n", prefix, entry->d_name, data->size);
            *total_size += data->size;
        }
    }

    free(full_path);
    closedir(dir);
}

static void analyze_disk_space(const char *path) {
    size_t total_size = 0;
    bool use_scandir = true;

#ifdef _SC_XOPEN_VERSION
    long open_version = sysconf(_SC_XOPEN_VERSION);
    if (open_version >= 5) {
        use_scandir = false;
    }
#endif

    if (use_scandir) {
        analyze_directory(path, "", &total_size, scandir);
    } else {
        analyze_directory(path, "", &total_size, readdir);
    }

    printf("Total size: %lu bytes\n", total_size);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    analyze_disk_space(argv[1]);

    return EXIT_SUCCESS;
}