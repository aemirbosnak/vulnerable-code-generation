//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define KB (1024)
#define MB (1024 * KB)
#define GB (1024 * MB)

typedef struct {
    char *name;
    off_t size;
} file_t;

int compare_files(const void *a, const void *b) {
    const file_t *file1 = (const file_t *)a;
    const file_t *file2 = (const file_t *)b;
    return file2->size - file1->size;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *path = argv[1];

    struct dirent *entry;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    int count = 0;
    off_t total_size = 0;
    file_t *files = NULL;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char *filepath = malloc(strlen(path) + strlen(entry->d_name) + 2);
        sprintf(filepath, "%s/%s", path, entry->d_name);

        struct stat st;
        if (stat(filepath, &st) == -1) {
            perror("stat");
            return EXIT_FAILURE;
        }

        if (S_ISDIR(st.st_mode)) {
            continue;
        }

        count++;
        total_size += st.st_size;

        files = realloc(files, sizeof(file_t) * count);
        files[count - 1].name = strdup(filepath);
        files[count - 1].size = st.st_size;

        free(filepath);
    }

    closedir(dir);

    qsort(files, count, sizeof(file_t), compare_files);

    printf("Total files: %d\n", count);
    printf("Total size: %.2f GB\n", (double)total_size / GB);

    for (int i = 0; i < count; i++) {
        printf("%s %.2f MB\n", files[i].name, (double)files[i].size / MB);
        free(files[i].name);
    }

    free(files);

    return EXIT_SUCCESS;
}