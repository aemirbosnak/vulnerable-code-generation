//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

typedef struct {
    char path[1024];
    unsigned long long size;
} file_t;

void add_file(file_t *files, int count, const char *path) {
    if (count >= 1024) {
        printf("Error: Too many files.\n");
        exit(1);
    }

    strcpy(files[count].path, path);
    struct statvfs fs;
    if (statvfs(path, &fs) == 0) {
        files[count].size = fs.f_blocks * fs.f_frsize;
    } else {
        files[count].size = 0;
    }

    count++;
}

void print_files(file_t *files, int count) {
    printf("Files:\n");
    for (int i = 0; i < count; i++) {
        printf("%s (%llu bytes)\n", files[i].path, files[i].size);
    }
}

void analyze_dir(const char *path) {
    DIR *d;
    struct dirent *dir;
    d = opendir(path);

    if (d) {
        int count = 0;
        file_t files[1024];

        while ((dir = readdir(d))!= NULL) {
            if (strcmp(dir->d_name, ".")!= 0 && strcmp(dir->d_name, "..")!= 0) {
                char full_path[1024];
                sprintf(full_path, "%s/%s", path, dir->d_name);

                add_file(files, count, full_path);
            }
        }

        closedir(d);

        print_files(files, count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    analyze_dir(argv[1]);

    return 0;
}