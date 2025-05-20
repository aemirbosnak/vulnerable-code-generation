//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>

#define MAX_DIR_LENGTH 256
#define MAX_FILE_LENGTH 256

typedef struct {
    char dir[MAX_DIR_LENGTH];
    char file[MAX_FILE_LENGTH];
    int size;
} file_info;

void print_usage() {
    printf("Usage:./program <directory>\n");
}

int is_file(char* path) {
    struct stat st;
    stat(path, &st);
    return (st.st_mode & S_IFMT) == S_IFREG;
}

int is_dir(char* path) {
    struct stat st;
    stat(path, &st);
    return (st.st_mode & S_IFMT) == S_IFDIR;
}

void print_file_info(file_info* file_info) {
    printf("%s (%d bytes)\n", file_info->file, file_info->size);
}

void print_file_info_table(file_info* file_info, int num_files) {
    printf("File Size\n");
    printf("--------\n");
    for (int i = 0; i < num_files; i++) {
        print_file_info(&file_info[i]);
    }
}

void get_file_info(char* dir, file_info* file_info, int* num_files) {
    DIR* d;
    struct dirent* dirp;
    d = opendir(dir);
    if (d == NULL) {
        printf("Error opening directory %s\n", dir);
        exit(1);
    }
    *num_files = 0;
    while ((dirp = readdir(d))!= NULL) {
        if (is_file(dirp->d_name)) {
            strcpy(file_info[*num_files].file, dirp->d_name);
            strcpy(file_info[*num_files].dir, dir);
            file_info[*num_files].size = dirp->d_reclen;
            (*num_files)++;
        }
    }
    closedir(d);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        print_usage();
        return 1;
    }
    char dir[MAX_DIR_LENGTH];
    strcpy(dir, argv[1]);
    file_info file_info[MAX_FILE_LENGTH];
    int num_files = 0;
    get_file_info(dir, file_info, &num_files);
    if (num_files == 0) {
        printf("Directory %s is empty\n", dir);
    } else {
        print_file_info_table(file_info, num_files);
    }
    return 0;
}