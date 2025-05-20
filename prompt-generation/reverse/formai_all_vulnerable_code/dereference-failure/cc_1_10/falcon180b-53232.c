//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILE_NAME_LEN 256
#define MAX_DIR_PATH_LEN 1024

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    unsigned long long file_size;
    int is_file;
} FileInfo;

void get_files_in_dir(const char *dir_path, int is_file, void (*file_callback)(FileInfo *)) {
    DIR *d;
    struct dirent *dir;
    d = opendir(dir_path);

    if (d) {
        while ((dir = readdir(d))!= NULL) {
            if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0) {
                continue;
            }

            char full_path[MAX_DIR_PATH_LEN];
            snprintf(full_path, MAX_DIR_PATH_LEN, "%s/%s", dir_path, dir->d_name);

            struct stat st;
            stat(full_path, &st);

            FileInfo file_info;
            strncpy(file_info.file_name, dir->d_name, MAX_FILE_NAME_LEN);
            file_info.file_size = st.st_size;
            file_info.is_file = is_file;

            (*file_callback)(&file_info);
        }

        closedir(d);
    }
}

void print_file_info(FileInfo *file_info) {
    printf("%s (%llu bytes)\n", file_info->file_name, file_info->file_size);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s directory_path\n", argv[0]);
        return 1;
    }

    char directory_path[MAX_DIR_PATH_LEN];
    strncpy(directory_path, argv[1], MAX_DIR_PATH_LEN);

    get_files_in_dir(directory_path, 1, &print_file_info);

    return 0;
}