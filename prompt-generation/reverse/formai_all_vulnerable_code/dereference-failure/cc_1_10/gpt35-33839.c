//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct {
    char name[256];
    off_t size;
} File;

void get_files(char *path, File *files, int *count);
void sort_files(File *files, int count);
char *format_size(off_t size);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *path = argv[1];

    File *files = malloc(sizeof(File) * 1000);
    int count = 0;

    get_files(path, files, &count);
    sort_files(files, count);

    printf("%-50s %s\n", "Name", "Size");

    for (int i = 0; i < count; i++) {
        printf("%-50s %s\n", files[i].name, format_size(files[i].size));
    }

    return 0;
}

void get_files(char *path, File *files, int *count) {
    DIR *dir;
    struct dirent *ent;
    struct stat st;

    dir = opendir(path);

    while ((ent = readdir(dir)) != NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }

        char full_path[256];
        sprintf(full_path, "%s/%s", path, ent->d_name);

        if (stat(full_path, &st) == -1) {
            continue;
        }

        File file;
        strcpy(file.name, ent->d_name);
        file.size = st.st_size;

        files[*count] = file;
        (*count)++;

        if (ent->d_type == DT_DIR) {
            get_files(full_path, files, count);
        }
    }

    closedir(dir);
}

void sort_files(File *files, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (files[j].size < files[j+1].size) {
                File temp = files[j];
                files[j] = files[j+1];
                files[j+1] = temp;
            }
        }
    }
}

char *format_size(off_t size) {
    static char size_str[64];

    if (size < 1024) {
        sprintf(size_str, "%ldB", size);
    } else if (size < 1024 * 1024) {
        sprintf(size_str, "%.2fKB", (double)size / 1024);
    } else if (size < 1024 * 1024 * 1024) {
        sprintf(size_str, "%.2fMB", (double)size / (1024 * 1024));
    } else {
        sprintf(size_str, "%.2fGB", (double)size / (1024 * 1024 * 1024));
    }

    return size_str;
}