//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

#define KB 1024
#define MB 1024 * KB
#define GB 1024 * MB

struct file_info {
    char *name;
    long long size;
};

struct file_info *files;
int num_files;

int compare_files(const void *a, const void *b) {
    struct file_info *fa = (struct file_info *)a;
    struct file_info *fb = (struct file_info *)b;

    return fa->size - fb->size;
}

void free_files() {
    for (int i = 0; i < num_files; i++) {
        free(files[i].name);
    }
    free(files);
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
        sprintf(full_path, "%s/%s", path, entry->d_name);

        struct stat statbuf;
        if (lstat(full_path, &statbuf) == -1) {
            perror("lstat");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            analyze_directory(full_path);
        } else {
            files = realloc(files, (num_files + 1) * sizeof(struct file_info));
            files[num_files].name = strdup(entry->d_name);
            files[num_files].size = statbuf.st_size;
            num_files++;
        }

        free(full_path);
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    analyze_directory(argv[1]);

    qsort(files, num_files, sizeof(struct file_info), compare_files);

    printf("Total files: %d\n", num_files);

    long long total_size = 0;
    for (int i = 0; i < num_files; i++) {
        total_size += files[i].size;
    }

    printf("Total size: %lld bytes (%lld KB, %lld MB, %lld GB)\n",
            total_size, total_size / KB, total_size / MB, total_size / GB);

    printf("\nTop 10 largest files:\n");
    for (int i = num_files - 1; i >= num_files - 10 && i >= 0; i--) {
        printf("%s: %lld bytes (%lld KB, %lld MB, %lld GB)\n",
                files[i].name, files[i].size,
                files[i].size / KB, files[i].size / MB, files[i].size / GB);
    }

    free_files();

    return EXIT_SUCCESS;
}