//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

#define BUF_SIZE (1024*1024)

typedef struct {
    char *path;
    uint64_t size;
} file_info_t;

static int compare_file_info(const void *a, const void *b) {
    file_info_t *fa = (file_info_t *)a;
    file_info_t *fb = (file_info_t *)b;
    return (fb->size - fa->size);
}

static int get_dir_size(char *dir_path, file_info_t **file_infos, uint64_t *total_size) {
    DIR *dir;
    struct dirent *dirent;
    char buf[BUF_SIZE];
    struct stat statbuf;
    file_info_t *new_file_infos;
    uint64_t new_total_size;
    int ret = 0;

    dir = opendir(dir_path);
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }

    new_file_infos = malloc(sizeof(file_info_t) * (*total_size + 1));
    if (new_file_infos == NULL) {
        perror("malloc");
        ret = -1;
        goto end;
    }
    memcpy(new_file_infos, *file_infos, sizeof(file_info_t) * *total_size);
    free(*file_infos);
    *file_infos = new_file_infos;

    new_total_size = *total_size;

    while ((dirent = readdir(dir)) != NULL) {
        if (strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0) {
            continue;
        }

        snprintf(buf, BUF_SIZE, "%s/%s", dir_path, dirent->d_name);

        if (stat(buf, &statbuf) == -1) {
            perror("stat");
            ret = -1;
            goto end;
        }

        if (S_ISREG(statbuf.st_mode)) {
            (*file_infos)[new_total_size].path = strdup(buf);
            (*file_infos)[new_total_size].size = statbuf.st_size;
            new_total_size++;
        } else if (S_ISDIR(statbuf.st_mode)) {
            ret = get_dir_size(buf, file_infos, &new_total_size);
            if (ret != 0) {
                goto end;
            }
        }
    }

end:
    closedir(dir);
    *total_size = new_total_size;
    return ret;
}

int main(int argc, char **argv) {
    char *dir_path;
    file_info_t *file_infos;
    uint64_t total_size;
    uint64_t i;
    int ret;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <dir_path>\n", argv[0]);
        return -1;
    }

    dir_path = argv[1];

    file_infos = malloc(sizeof(file_info_t));
    if (file_infos == NULL) {
        perror("malloc");
        return -1;
    }
    total_size = 0;

    ret = get_dir_size(dir_path, &file_infos, &total_size);
    if (ret != 0) {
        return ret;
    }

    qsort(file_infos, total_size, sizeof(file_info_t), compare_file_info);

    for (i = 0; i < total_size; i++) {
        printf("%s: %lu bytes\n", file_infos[i].path, file_infos[i].size);
        free(file_infos[i].path);
    }
    free(file_infos);

    return 0;
}