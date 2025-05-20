//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

struct file {
    char filename[100];
    size_t size;
};

int compare(const void* a, const void* b) {
    return ((*(struct file*)b).size - (*(struct file*)a).size);
}

void analyze_directory(char* path, struct file* files, int* num_files) {
    DIR* dir;
    struct dirent* dir_entry;
    struct stat file_stat;

    dir = opendir(path);

    if (!dir) {
        fprintf(stderr, "Error opening directory %s!\n", path);
        exit(EXIT_FAILURE);
    }

    while ((dir_entry = readdir(dir)) != NULL) {
        char filepath[300];

        if (dir_entry->d_type == DT_DIR) {
            if (strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0) {
                continue;
            }

            sprintf(filepath, "%s/%s", path, dir_entry->d_name);

            analyze_directory(filepath, files, num_files);
        } else {
            sprintf(filepath, "%s/%s", path, dir_entry->d_name);

            if (stat(filepath, &file_stat) < 0) {
                continue;
            }

            struct file new_file;
            
            strncpy(new_file.filename, filepath, 99);
            new_file.filename[99] = '\0';

            new_file.size = file_stat.st_size;

            files[*num_files] = new_file;
            (*num_files)++;
        }
    }

    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* path = argv[1];

    printf("Analyzing disk space of %s...\n", path);

    struct file* files = malloc(sizeof(struct file) * 1000);
    int num_files = 0;

    analyze_directory(path, files, &num_files);

    qsort(files, num_files, sizeof(struct file), compare);

    printf("%-100s\t%s\n", "Filename", "Size");

    for (int i = 0; i < num_files; i++) {
        printf("%-100s\t%ld bytes\n", files[i].filename, files[i].size);
    }

    free(files);

    return EXIT_SUCCESS;
}