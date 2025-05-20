//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_PATH 1024
#define MAX_FILES 1000

typedef struct {
    char path[MAX_PATH];
    time_t mtime;
} File;

File files[MAX_FILES];
int num_files = 0;

void add_file(char *path, time_t mtime) {
    if (num_files >= MAX_FILES) {
        fprintf(stderr, "Error: Too many files.\n");
        exit(1);
    }

    strcpy(files[num_files].path, path);
    files[num_files].mtime = mtime;
    num_files++;
}

void sort_files() {
    qsort(files, num_files, sizeof(File),
          (int (*)(const void *, const void *))strcmp);
}

void print_files() {
    for (int i = 0; i < num_files; i++) {
        printf("%s %ld\n", files[i].path, files[i].mtime);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <dir1> <dir2>\n", argv[0]);
        exit(1);
    }

    // Scan the first directory
    DIR *dir1 = opendir(argv[1]);
    if (dir1 == NULL) {
        fprintf(stderr, "Error: Could not open directory %s.\n", argv[1]);
        exit(1);
    }

    struct dirent *ent1;
    while ((ent1 = readdir(dir1)) != NULL) {
        if (strcmp(ent1->d_name, ".") == 0 || strcmp(ent1->d_name, "..") == 0) {
            continue;
        }

        char path1[MAX_PATH];
        snprintf(path1, MAX_PATH, "%s/%s", argv[1], ent1->d_name);

        struct stat stat1;
        if (stat(path1, &stat1) < 0) {
            fprintf(stderr, "Error: Could not stat file %s.\n", path1);
            exit(1);
        }

        add_file(path1, stat1.st_mtime);
    }

    closedir(dir1);

    // Scan the second directory
    DIR *dir2 = opendir(argv[2]);
    if (dir2 == NULL) {
        fprintf(stderr, "Error: Could not open directory %s.\n", argv[2]);
        exit(1);
    }

    struct dirent *ent2;
    while ((ent2 = readdir(dir2)) != NULL) {
        if (strcmp(ent2->d_name, ".") == 0 || strcmp(ent2->d_name, "..") == 0) {
            continue;
        }

        char path2[MAX_PATH];
        snprintf(path2, MAX_PATH, "%s/%s", argv[2], ent2->d_name);

        struct stat stat2;
        if (stat(path2, &stat2) < 0) {
            fprintf(stderr, "Error: Could not stat file %s.\n", path2);
            exit(1);
        }

        add_file(path2, stat2.st_mtime);
    }

    closedir(dir2);

    // Sort the files
    sort_files();

    // Print the files
    print_files();

    return 0;
}