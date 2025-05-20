//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>

#define MB (1024*1024)

typedef struct {
    char path[1024];
    int size;
} File;

int compare_files(const void *a, const void *b) {
    return (*(File *)b).size - (*(File *)a).size;
}

void get_files(char* path, File* files, int* count) {
    DIR *dir;
    struct dirent *ent;
    dir = opendir(path);
    if (dir!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                char new_path[strlen(path) + strlen(ent->d_name) + 2];
                strcpy(new_path, path);
                strcat(new_path, "/");
                strcat(new_path, ent->d_name);
                get_files(new_path, files, count);
            } else {
                File file;
                strcpy(file.path, path);
                strcat(file.path, "/");
                strcat(file.path, ent->d_name);
                file.size = ent->d_reclen;
                files[*count] = file;
                (*count)++;
            }
        }
        closedir(dir);
    }
}

void print_files(File* files, int count) {
    qsort(files, count, sizeof(File), compare_files);
    for (int i = 0; i < count; i++) {
        printf("%s - %d bytes\n", files[i].path, files[i].size);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }
    char path[1024];
    strcpy(path, argv[1]);
    File files[1000];
    int count = 0;
    get_files(path, files, &count);
    print_files(files, count);
    return 0;
}