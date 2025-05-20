//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MB 1024 * 1024

struct dir_data {
    char *name;
    long size;
};

void analyze_dir(char *path, struct dir_data *data)
{
    DIR *dir = opendir(path);
    if (dir == NULL) {
        printf("Failed to open directory %s.\n", path);
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char *entry_path = malloc(sizeof(path) + sizeof(entry->d_name) + 1);
        sprintf(entry_path, "%s/%s", path, entry->d_name);
        struct stat entry_stat;
        if (lstat(entry_path, &entry_stat) == -1) {
            printf("Failed to stat file %s.\n", entry_path);
            free(entry_path);
            continue;
        }
        if (S_ISDIR(entry_stat.st_mode)) {
            analyze_dir(entry_path, data);
        } else if (S_ISREG(entry_stat.st_mode)) {
            data->size += entry_stat.st_size;
        }
        free(entry_path);
    }
    closedir(dir);
}

int compare_size(const void *lhs, const void *rhs)
{
    return ((struct dir_data *) rhs)->size - ((struct dir_data *) lhs)->size;
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *path = argv[1];
    struct dir_data *data = malloc(sizeof(struct dir_data));
    data->name = strdup(path);
    data->size = 0;
    analyze_dir(path, data);

    printf("Disk space usage for directory %s:\n\n", path);
    printf("%16s %s\n", "Size", "Name");
    printf("%16s %s\n", "----", "----");
    printf("%16.2f MB %s\n", (float) data->size / MB, data->name);
    printf("\nTop 10 largest files:\n\n");
    
    int n_files = 0;
    struct dir_data *files = malloc(sizeof(struct dir_data) * n_files);
    DIR *dir = opendir(path);
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL && n_files < 10) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char *entry_path = malloc(sizeof(path) + sizeof(entry->d_name) + 1);
        sprintf(entry_path, "%s/%s", path, entry->d_name);
        struct stat entry_stat;
        if (lstat(entry_path, &entry_stat) == -1) {
            printf("Failed to stat file %s.\n", entry_path);
            free(entry_path);
            continue;
        }
        if (S_ISREG(entry_stat.st_mode)) {
            files[n_files].name = strdup(entry_path);
            files[n_files].size = entry_stat.st_size;
            n_files++;
            files = realloc(files, sizeof(struct dir_data) * (n_files + 1));
        } 
        free(entry_path);
    }
    closedir(dir);
    qsort(files, n_files, sizeof(struct dir_data), compare_size);
    printf("%16s %s\n", "Size", "Name");
    printf("%16s %s\n", "----", "----");
    for (int i = 0; i < n_files; i++) {
        printf("%16.2f MB %s\n", (float) files[i].size / MB, files[i].name);
    }

    free(data->name);
    free(data);
    for (int i = 0; i < n_files; i++) {
        free(files[i].name);
    }
    free(files);

    return EXIT_SUCCESS;
}