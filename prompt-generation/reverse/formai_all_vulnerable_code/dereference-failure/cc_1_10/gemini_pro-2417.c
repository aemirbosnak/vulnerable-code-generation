//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

typedef struct {
    char *name;
    long long size;
    time_t mtime;
} FileInfo;

int compareFiles(const void *a, const void *b) {
    const FileInfo *fa = (const FileInfo *)a;
    const FileInfo *fb = (const FileInfo *)b;
    return strcmp(fa->name, fb->name);
}

int main() {
    char *path = ".";
    DIR *dir = opendir(path);
    if (!dir) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    struct dirent *entry;
    struct stat st;
    long long totalSize = 0;
    int numFiles = 0;

    while ((entry = readdir(dir))) {
        if (entry->d_type == DT_DIR || entry->d_type == DT_LNK) {
            continue;
        }

        char *fullPath = malloc(strlen(path) + strlen(entry->d_name) + 2);
        sprintf(fullPath, "%s/%s", path, entry->d_name);

        if (stat(fullPath, &st) != 0) {
            perror("stat");
            return EXIT_FAILURE;
        }

        FileInfo *file = malloc(sizeof(FileInfo));
        file->name = strdup(entry->d_name);
        file->size = st.st_size;
        file->mtime = st.st_mtime;

        totalSize += file->size;
        numFiles++;

        free(fullPath);
    }

    closedir(dir);

    FileInfo *files = malloc(sizeof(FileInfo) * numFiles);
    int i = 0;

    while ((entry = readdir(dir))) {
        if (entry->d_type == DT_DIR || entry->d_type == DT_LNK) {
            continue;
        }

        char *fullPath = malloc(strlen(path) + strlen(entry->d_name) + 2);
        sprintf(fullPath, "%s/%s", path, entry->d_name);

        if (stat(fullPath, &st) != 0) {
            perror("stat");
            return EXIT_FAILURE;
        }

        FileInfo *file = &files[i++];
        file->name = strdup(entry->d_name);
        file->size = st.st_size;
        file->mtime = st.st_mtime;

        totalSize += file->size;
        numFiles++;

        free(fullPath);
    }

    closedir(dir);

    qsort(files, numFiles, sizeof(FileInfo), compareFiles);

    for (i = 0; i < numFiles; i++) {
        printf("%s %lld %s\n", files[i].name, files[i].size, ctime(&files[i].mtime));
        free(files[i].name);
    }

    free(files);

    printf("Total size: %lld\n", totalSize);

    return EXIT_SUCCESS;
}