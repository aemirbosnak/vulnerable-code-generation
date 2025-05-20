//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <sys/stat.h>

#define BUF_SIZE 1024

typedef struct {
    char name[100];
    int size;
} file_t;

void read_dir(const char *path, file_t *files, int count) {
    DIR *dir = opendir(path);
    struct dirent *ent;

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) {
            if (count < 100) {
                strncpy(files[count].name, ent->d_name, strlen(ent->d_name));
                files[count].size = 0;
                count++;
            }
        }
    }

    closedir(dir);
}

int get_file_size(const char *path, file_t *file) {
    struct stat st;

    if (stat(path, &st) == 0) {
        file->size = st.st_size;
        return 1;
    }

    return 0;
}

void print_files(file_t *files, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s %d bytes\n", files[i].name, files[i].size);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    file_t files[100];
    int count = 0;

    read_dir(argv[1], files, count);

    for (int i = 0; i < count; i++) {
        get_file_size(files[i].name, &files[i]);
    }

    print_files(files, count);

    return 0;
}