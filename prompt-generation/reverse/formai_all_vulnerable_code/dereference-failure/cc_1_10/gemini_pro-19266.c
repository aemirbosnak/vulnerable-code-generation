//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct {
    char *path;
    long size;
} FileInfo;

int compareFileInfo(const void *a, const void *b)
{
    return ((FileInfo *)a)->size - ((FileInfo *)b)->size;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;
    FileInfo *files = NULL;
    int num_files = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char *path = malloc(strlen(argv[1]) + strlen(entry->d_name) + 2);
        strcpy(path, argv[1]);
        strcat(path, "/");
        strcat(path, entry->d_name);

        struct stat st;
        if (lstat(path, &st) == -1) {
            perror("lstat");
            free(path);
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            free(path);
            continue;
        }

        FileInfo *file = realloc(files, (num_files + 1) * sizeof(FileInfo));
        if (file == NULL) {
            perror("realloc");
            free(files);
            free(path);
            closedir(dir);
            return 1;
        }

        files = file;
        files[num_files].path = path;
        files[num_files].size = st.st_size;
        num_files++;
    }

    closedir(dir);

    qsort(files, num_files, sizeof(FileInfo), compareFileInfo);

    for (int i = 0; i < num_files; i++) {
        printf("%ld %s\n", files[i].size, files[i].path);
        free(files[i].path);
    }

    free(files);

    return 0;
}