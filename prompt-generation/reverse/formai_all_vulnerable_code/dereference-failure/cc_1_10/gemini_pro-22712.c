//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <limits.h>

#define KB 1024
#define MB (KB * KB)
#define GB (MB * KB)
#define TB (GB * KB)

typedef struct {
    char *path;
    int num_files;
    long long total_size;
} DiskUsage;

int compare_disk_usage(DiskUsage *a, DiskUsage *b) {
    return strcmp(a->path, b->path);
}

void print_disk_usage(DiskUsage *usage, int num_usages) {
    qsort(usage, num_usages, sizeof(DiskUsage), (int (*)(const void *, const void *))compare_disk_usage);

    for (int i = 0; i < num_usages; i++) {
        printf("%s: %lld bytes (%lld files)\n", usage[i].path, usage[i].total_size, usage[i].num_files);
    }
}

void free_disk_usage(DiskUsage *usage, int num_usages) {
    for (int i = 0; i < num_usages; i++) {
        free(usage[i].path);
    }
    free(usage);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *path = argv[1];

    DIR *dirp = opendir(path);
    if (dirp == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    int num_usages = 0;
    DiskUsage *usage = NULL;

    struct dirent *dp;
    while ((dp = readdir(dirp)) != NULL) {
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        }

        char *full_path = malloc(strlen(path) + strlen(dp->d_name) + 2);
        if (full_path == NULL) {
            perror("malloc");
            closedir(dirp);
            free_disk_usage(usage, num_usages);
            return EXIT_FAILURE;
        }

        sprintf(full_path, "%s/%s", path, dp->d_name);

        struct stat statbuf;
        if (lstat(full_path, &statbuf) == -1) {
            perror("lstat");
            free(full_path);
            closedir(dirp);
            free_disk_usage(usage, num_usages);
            return EXIT_FAILURE;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            usage = realloc(usage, (num_usages + 1) * sizeof(DiskUsage));
            if (usage == NULL) {
                perror("realloc");
                free(full_path);
                closedir(dirp);
                free_disk_usage(usage, num_usages);
                return EXIT_FAILURE;
            }

            usage[num_usages].path = full_path;
            usage[num_usages].num_files = 0;
            usage[num_usages].total_size = 0;

            num_usages++;
        } else {
            for (int i = 0; i < num_usages; i++) {
                if (strncmp(full_path, usage[i].path, strlen(usage[i].path)) == 0) {
                    usage[i].num_files++;
                    usage[i].total_size += statbuf.st_size;
                    break;
                }
            }
        }

        free(full_path);
    }

    closedir(dirp);

    print_disk_usage(usage, num_usages);
    free_disk_usage(usage, num_usages);

    return EXIT_SUCCESS;
}