//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH_LEN 1024

typedef struct {
    char name[MAX_PATH_LEN];
    long size;
} FileInfo;

int compare_files(const void *a, const void *b) {
    FileInfo *fa = (FileInfo *)a;
    FileInfo *fb = (FileInfo *)b;
    return fb->size - fa->size;
}

int main() {
    char path[MAX_PATH_LEN];

    // Get the current working directory.
    if (getcwd(path, sizeof(path)) == NULL) {
        perror("getcwd");
        return EXIT_FAILURE;
    }

    // Create a directory stream for the current working directory.
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    // Allocate an array to store the file information.
    FileInfo *files = malloc(sizeof(FileInfo) * 1024);
    if (files == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    // Iterate over the files in the directory.
    int num_files = 0;
    struct dirent *ent;
    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_REG) {
            // Get the file's size.
            char fullpath[MAX_PATH_LEN];
            snprintf(fullpath, sizeof(fullpath), "%s/%s", path, ent->d_name);
            long size = 0;
            FILE *f = fopen(fullpath, "rb");
            if (f != NULL) {
                fseek(f, 0, SEEK_END);
                size = ftell(f);
                fclose(f);
            }

            // Store the file information.
            strcpy(files[num_files].name, ent->d_name);
            files[num_files].size = size;
            num_files++;
        }
    }

    // Close the directory stream.
    closedir(dir);

    // Sort the files by size.
    qsort(files, num_files, sizeof(FileInfo), compare_files);

    // Print the file information.
    for (int i = 0; i < num_files; i++) {
        printf("%s: %ld bytes\n", files[i].name, files[i].size);
    }

    // Free the memory allocated for the file information.
    free(files);

    return EXIT_SUCCESS;
}