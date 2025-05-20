//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 256

typedef struct {
    char *name;
    size_t size;
    struct dirent *d_ent;
} File;

void print_files(File *files, int num_files) {
    for (int i = 0; i < num_files; i++) {
        printf("%s (%zu bytes)\n", files[i].name, files[i].size);
    }
}

void delete_files(File *files, int num_files) {
    for (int i = 0; i < num_files; i++) {
        if (files[i].d_ent->d_type == DT_DIR) {
            delete_files(files, num_files);
        }
        free(files[i].name);
        free(files[i].d_ent);
    }
    free(files);
}

void analyze_directory(const char *dir_path, int depth) {
    DIR *dir;
    struct dirent *ent;
    File *files = NULL;
    int num_files = 0;

    dir = opendir(dir_path);
    if (!dir) {
        printf("Error opening directory: %s\n", dir_path);
        return;
    }

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_name[0] == '.') {
            continue;
        }

        char full_path[MAX_FILE_NAME_LEN];
        sprintf(full_path, "%s/%s", dir_path, ent->d_name);

        struct stat st;
        stat(full_path, &st);

        if (S_ISDIR(st.st_mode)) {
            if (depth > 0) {
                analyze_directory(full_path, depth - 1);
            }
        } else {
            File *file = malloc(sizeof(File));
            file->name = strdup(ent->d_name);
            file->size = st.st_size;
            file->d_ent = ent;

            files = realloc(files, sizeof(File) * ++num_files);
            files[num_files - 1] = *file;
        }
    }

    closedir(dir);

    if (files) {
        print_files(files, num_files);
        delete_files(files, num_files);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    analyze_directory(argv[1], 10);

    return 0;
}