//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include <fcntl.h>
#include <ftw.h>
#include <unistd.h>
#include <stdint.h>

#define KB (1 << 10)
#define MB (1 << 10) * KB
#define GB (1 << 10) * MB

typedef struct {
    uint64_t size;
    char name[256];
} file_info_t;

int compare_file_info(const void *a, const void *b) {
    const file_info_t *fa = a;
    const file_info_t *fb = b;
    return fb->size - fa->size;
}

int main() {
    DIR *dir;
    struct dirent *ent;
    struct stat st;
    char path[256];
    file_info_t *files;
    size_t files_size;
    size_t files_count;
    size_t i;

    if (chdir("/MyDisk") != 0) {
        perror("chdir");
        return 1;
    }

    dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    files_size = 0;
    files_count = 0;

    while ((ent = readdir(dir)) != NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }

        snprintf(path, sizeof(path), "%s", ent->d_name);
        if (stat(path, &st) != 0) {
            perror("stat");
            continue;
        }

        if (!S_ISREG(st.st_mode)) {
            continue;
        }

        files = realloc(files, (files_count + 1) * sizeof(file_info_t));
        if (files == NULL) {
            perror("realloc");
            return 1;
        }

        files[files_count].size = st.st_size;
        strncpy(files[files_count].name, ent->d_name, sizeof(files[files_count].name));
        files_count++;
        files_size += st.st_size;
    }

    closedir(dir);

    qsort(files, files_count, sizeof(file_info_t), compare_file_info);

    printf("Total disk space used: %lu GB\n", files_size / GB);
    printf("\nTop 10 largest files:\n\n");

    for (i = 0; i < 10 && i < files_count; i++) {
        printf("%s: %lu GB\n", files[i].name, files[i].size / GB);
    }

    free(files);
    return 0;
}