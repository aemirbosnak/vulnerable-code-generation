//Falcon-180B DATASET v1.0 Category: System administration ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_DIR_PATH 1024
#define MAX_FILE_NAME 1024

typedef struct dirent dirent;

void print_file_info(const char *dir_path, const char *file_name) {
    printf("File name: %s\n", file_name);
    printf("File size: %d bytes\n", strlen(file_name));
    printf("\n");
}

void print_dir_info(const char *dir_path) {
    DIR *dir;
    struct dirent *ent;
    dir = opendir(dir_path);

    if (dir!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_REG) {
                print_file_info(dir_path, ent->d_name);
            }
        }
        closedir(dir);
    }
}

void list_files_in_directory(const char *dir_path) {
    DIR *dir;
    struct dirent *ent;
    dir = opendir(dir_path);

    if (dir!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                char sub_dir_path[MAX_DIR_PATH];
                sprintf(sub_dir_path, "%s/%s", dir_path, ent->d_name);
                list_files_in_directory(sub_dir_path);
            } else if (ent->d_type == DT_REG) {
                print_file_info(dir_path, ent->d_name);
            }
        }
        closedir(dir);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s directory_path\n", argv[0]);
        return 1;
    }

    char dir_path[MAX_DIR_PATH];
    strcpy(dir_path, argv[1]);

    list_files_in_directory(dir_path);

    return 0;
}