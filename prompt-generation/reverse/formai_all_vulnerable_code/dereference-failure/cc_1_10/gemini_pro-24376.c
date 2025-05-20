//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_PATH 1024

typedef struct {
    char *path;
    long long size;
} file_info;

int compare_file_info(const void *a, const void *b) {
    const file_info *fa = (const file_info *)a;
    const file_info *fb = (const file_info *)b;
    return (fa->size - fb->size);
}

int main() {
    char path[MAX_PATH];
    char *p;
    struct stat st;
    int max_files = 1000;
    file_info *files = malloc(sizeof(file_info) * max_files);
    int num_files = 0;

    while (fgets(path, MAX_PATH, stdin) != NULL) {
        p = path + strlen(path) - 1;
        while (p >= path && (*p == '\n' || *p == '\r')) {
            *p-- = '\0';
        }

        if (*path == '\0') {
            continue;
        }

        if (stat(path, &st) != 0) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            continue;
        }

        if (num_files >= max_files) {
            max_files *= 2;
            files = realloc(files, sizeof(file_info) * max_files);
        }

        files[num_files].path = strdup(path);
        files[num_files].size = st.st_size;
        num_files++;
    }

    qsort(files, num_files, sizeof(file_info), compare_file_info);

    for (int i = 0; i < num_files; i++) {
        printf("%lld\t%s\n", files[i].size, files[i].path);
        free(files[i].path);
    }

    free(files);
    return 0;
}