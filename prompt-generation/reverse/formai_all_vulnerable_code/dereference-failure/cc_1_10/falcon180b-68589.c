//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *name;
    unsigned long long size;
} File;

void read_directory(const char *path, void (*callback)(File *file)) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        fprintf(stderr, "Error opening directory '%s'\n", path);
        exit(1);
    }

    struct dirent *ent;
    while ((ent = readdir(dir))!= NULL) {
        char *full_path = malloc(strlen(path) + strlen(ent->d_name) + 2);
        if (full_path == NULL) {
            fprintf(stderr, "Error allocating memory\n");
            exit(1);
        }

        strcpy(full_path, path);
        strcat(full_path, "/");
        strcat(full_path, ent->d_name);

        struct stat st;
        if (stat(full_path, &st)!= 0) {
            fprintf(stderr, "Error getting file status for '%s'\n", full_path);
            exit(1);
        }

        File file = {
           .name = ent->d_name,
           .size = st.st_size,
        };
        callback(&file);
    }

    closedir(dir);
}

void print_file(File *file) {
    printf("%-50s %10llu bytes\n", file->name, file->size);
}

void print_total(unsigned long long total) {
    printf("\nTotal disk space used: %10llu bytes\n", total);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    unsigned long long total_size = 0;
    read_directory(argv[1], &print_file);
    print_total(total_size);

    return 0;
}