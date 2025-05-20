//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct {
    long long int size;
    char *path;
} FileSize;

int compare_file_sizes(const void *a, const void *b) {
    FileSize *fa = (FileSize *)a;
    FileSize *fb = (FileSize *)b;
    return fb->size - fa->size;
}

int main(int argc, char **argv) {
    char *root_directory = argv[1];
    DIR *dir = opendir(root_directory);
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    // Create an array to store the file size data.
    int num_files = 100;
    FileSize *file_sizes = malloc(sizeof(FileSize) * num_files);
    if (file_sizes == NULL) {
        perror("malloc");
        closedir(dir);
        return EXIT_FAILURE;
    }

    // Iterate over the files in the directory.
    int num_files_found = 0;
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char *file_path = malloc(strlen(root_directory) + strlen(entry->d_name) + 2);
        if (file_path == NULL) {
            perror("malloc");
            closedir(dir);
            free(file_sizes);
            return EXIT_FAILURE;
        }

        sprintf(file_path, "%s/%s", root_directory, entry->d_name);
        struct stat file_stat;
        if (stat(file_path, &file_stat) == -1) {
            perror("stat");
            closedir(dir);
            free(file_sizes);
            free(file_path);
            return EXIT_FAILURE;
        }

        if (num_files_found == num_files) {
            num_files *= 2;
            file_sizes = realloc(file_sizes, sizeof(FileSize) * num_files);
            if (file_sizes == NULL) {
                perror("realloc");
                closedir(dir);
                free(file_sizes);
                free(file_path);
                return EXIT_FAILURE;
            }
        }

        file_sizes[num_files_found].size = file_stat.st_size;
        file_sizes[num_files_found].path = file_path;
        num_files_found++;
    }

    closedir(dir);

    // Sort the file sizes in descending order.
    qsort(file_sizes, num_files_found, sizeof(FileSize), compare_file_sizes);

    // Print the file sizes.
    for (int i = 0; i < num_files_found; i++) {
        printf("%lld bytes: %s\n", file_sizes[i].size, file_sizes[i].path);
    }

    // Free the memory allocated for the file size data.
    for (int i = 0; i < num_files_found; i++) {
        free(file_sizes[i].path);
    }
    free(file_sizes);

    return EXIT_SUCCESS;
}