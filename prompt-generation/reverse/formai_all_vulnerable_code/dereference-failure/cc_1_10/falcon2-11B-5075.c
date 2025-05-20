//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>

typedef struct file_info {
    char *file_path;
    int file_size;
} file_info_t;

int compare_file_info(const void *a, const void *b) {
    const file_info_t *fa = a;
    const file_info_t *fb = b;
    return strcmp(fa->file_path, fb->file_path);
}

int main() {
    DIR *dir_handle;
    struct dirent *entry;
    file_info_t *file_list;
    int num_files, i;

    if ((dir_handle = opendir(".")) == NULL) {
        perror("opendir");
        exit(1);
    }

    if ((file_list = malloc(sizeof(file_info_t) * 1000)) == NULL) {
        perror("malloc");
        exit(1);
    }

    while ((entry = readdir(dir_handle))!= NULL) {
        if (strcmp(entry->d_name, ".")!= 0 && strcmp(entry->d_name, "..")!= 0) {
            struct stat file_stat;
            char file_path[100];
            snprintf(file_path, sizeof(file_path), "%s/%s", ".", entry->d_name);

            if (stat(file_path, &file_stat)!= 0) {
                perror("stat");
                exit(1);
            }

            file_info_t file_info = {.file_path = strdup(file_path),.file_size = file_stat.st_size };
            qsort(file_list, num_files, sizeof(file_info_t), compare_file_info);
            file_list[num_files++] = file_info;
        }
    }

    closedir(dir_handle);

    for (i = 0; i < num_files; i++) {
        printf("%s\n", file_list[i].file_path);
    }

    free(file_list);

    return 0;
}