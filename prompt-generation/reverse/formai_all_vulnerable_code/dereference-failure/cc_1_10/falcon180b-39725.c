//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define BUF_LEN 1024

typedef struct {
    char name[100];
    int size;
} file_t;

void add_file(file_t *files, int count, const char *name, int size) {
    if (count >= 100) {
        printf("Error: Too many files.\n");
        exit(1);
    }
    strcpy(files[count].name, name);
    files[count].size = size;
    count++;
}

void sort_files(file_t *files, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (files[j].size > files[i].size) {
                file_t temp = files[i];
                files[i] = files[j];
                files[j] = temp;
            }
        }
    }
}

void print_files(file_t *files, int count) {
    printf("Name\tSize\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%d\n", files[i].name, files[i].size);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    DIR *d;
    struct dirent *dir;
    d = opendir(argv[1]);

    if (d) {
        int count = 0;
        file_t files[100];

        while ((dir = readdir(d))!= NULL) {
            char path[100];
            sprintf(path, "%s/%s", argv[1], dir->d_name);
            struct stat st;
            if (stat(path, &st) == 0) {
                if (S_ISREG(st.st_mode)) {
                    add_file(files, count, dir->d_name, st.st_size);
                }
            }
        }

        closedir(d);
        sort_files(files, count);
        print_files(files, count);
    } else {
        perror("");
    }

    return 0;
}