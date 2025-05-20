//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <time.h>

#define MAX_PATH_LENGTH 1024

struct file_info {
    char *path;
    time_t last_modified;
};

int compare_file_info(const void *a, const void *b) {
    struct file_info *fa = (struct file_info *)a;
    struct file_info *fb = (struct file_info *)b;

    return strcmp(fa->path, fb->path);
}

int main(int argc, char **argv) {
    char *src_dir;
    char *dest_dir;
    char *backup_filename;
    DIR *src_dir_ptr;
    struct dirent *src_dir_entry;
    struct stat file_stat;
    struct file_info *file_list;
    int file_count;
    int i;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <src_dir> <dest_dir> <backup_filename>\n", argv[0]);
        exit(1);
    }

    src_dir = argv[1];
    dest_dir = argv[2];
    backup_filename = argv[3];

    if ((src_dir_ptr = opendir(src_dir)) == NULL) {
        perror("opendir");
        exit(1);
    }

    file_count = 0;
    while ((src_dir_entry = readdir(src_dir_ptr)) != NULL) {
        if (strcmp(src_dir_entry->d_name, ".") == 0 || strcmp(src_dir_entry->d_name, "..") == 0) {
            continue;
        }

        file_count++;
    }

    file_list = (struct file_info *)malloc(sizeof(struct file_info) * file_count);

    rewinddir(src_dir_ptr);
    i = 0;
    while ((src_dir_entry = readdir(src_dir_ptr)) != NULL) {
        if (strcmp(src_dir_entry->d_name, ".") == 0 || strcmp(src_dir_entry->d_name, "..") == 0) {
            continue;
        }

        file_list[i].path = (char *)malloc(MAX_PATH_LENGTH);
        snprintf(file_list[i].path, MAX_PATH_LENGTH, "%s/%s", src_dir, src_dir_entry->d_name);

        if (stat(file_list[i].path, &file_stat) < 0) {
            perror("stat");
            exit(1);
        }

        file_list[i].last_modified = file_stat.st_mtime;

        i++;
    }

    qsort(file_list, file_count, sizeof(struct file_info), compare_file_info);

    FILE *backup_file;
    if ((backup_file = fopen(backup_filename, "w")) == NULL) {
        perror("fopen");
        exit(1);
    }

    for (i = 0; i < file_count; i++) {
        fprintf(backup_file, "%s %ld\n", file_list[i].path, file_list[i].last_modified);
    }

    fclose(backup_file);

    for (i = 0; i < file_count; i++) {
        free(file_list[i].path);
    }
    free(file_list);

    closedir(src_dir_ptr);

    return 0;
}