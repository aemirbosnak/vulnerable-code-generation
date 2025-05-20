//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    double size;
} file_t;

void add_file(file_t *list, int count, const char *path) {
    if (count >= MAX_PATH) {
        printf("Error: Maximum path limit reached.\n");
        exit(1);
    }
    strcpy(list[count].path, path);
    struct stat file_stat;
    if (stat(path, &file_stat) == -1) {
        printf("Error: Unable to retrieve file information for %s.\n", path);
        exit(1);
    }
    list[count].size = file_stat.st_size;
    count++;
}

void print_files(file_t *list, int count) {
    printf("File\tSize\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%.2f MB\n", list[i].path, list[i].size / (1024 * 1024));
    }
}

void analyze_directory(const char *path) {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(path))!= NULL) {
        int count = 0;
        file_t files[MAX_PATH];
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_REG) {
                add_file(files, count, ent->d_name);
            }
        }
        closedir(dir);
        print_files(files, count);
    } else {
        printf("Error: Unable to open directory %s.\n", path);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(1);
    }
    analyze_directory(argv[1]);
    return 0;
}