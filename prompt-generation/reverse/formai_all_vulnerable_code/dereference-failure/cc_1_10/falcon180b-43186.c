//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <ftw.h>

#define MAX_PATH_LEN 1024

typedef struct {
    char path[MAX_PATH_LEN];
    int is_file;
    time_t last_modified;
} file_t;

static int compare_file_last_modified(const void *a, const void *b) {
    file_t *file_a = (file_t *) a;
    file_t *file_b = (file_t *) b;

    if (file_a->last_modified > file_b->last_modified) {
        return -1;
    } else if (file_a->last_modified < file_b->last_modified) {
        return 1;
    } else {
        return 0;
    }
}

static int file_callback(const char *fpath, const struct stat *sb, int typeflag, void *userdata) {
    file_t *file = (file_t *) userdata;

    if (typeflag == FTW_F) {
        strcpy(file->path, fpath);
        file->is_file = 1;
        file->last_modified = sb->st_mtime;
    } else if (typeflag == FTW_D) {
        strcpy(file->path, fpath);
        file->is_file = 0;
        file->last_modified = 0;
    }

    return 0;
}

static void print_file_list(file_t *file_list, int num_files) {
    qsort(file_list, num_files, sizeof(file_t), compare_file_last_modified);

    for (int i = 0; i < num_files; i++) {
        printf("%s\n", file_list[i].path);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s source_path destination_path\n", argv[0]);
        return 1;
    }

    char source_path[MAX_PATH_LEN] = {0};
    char dest_path[MAX_PATH_LEN] = {0};

    strcpy(source_path, argv[1]);
    strcpy(dest_path, argv[2]);

    file_t file_list[1000];
    int num_files = 0;

    nftw(source_path, file_callback, 20, file_list);

    print_file_list(file_list, num_files);

    return 0;
}