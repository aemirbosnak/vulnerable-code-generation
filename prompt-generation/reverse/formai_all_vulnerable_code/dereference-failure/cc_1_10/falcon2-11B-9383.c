//Falcon2-11B DATASET v1.0 Category: Disk space analyzer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 1024
#define MAX_DIRECTORIES 50

struct directory_info {
    char path[MAX_PATH_LENGTH];
    unsigned long long size;
    unsigned long long files;
    unsigned long long dirs;
};

struct directory_info *get_directory_info(char *path) {
    struct stat st;
    struct dirent *ep;
    struct directory_info *info = NULL;

    info = malloc(sizeof(struct directory_info));
    if (info == NULL) {
        perror("malloc failed");
        return NULL;
    }

    if (stat(path, &st) < 0) {
        perror("stat failed");
        free(info);
        return NULL;
    }

    info->size = st.st_size;
    info->files = 0;
    info->dirs = 0;

    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir failed");
        free(info);
        return NULL;
    }

    while ((ep = readdir(dir))!= NULL) {
        char *name = ep->d_name;
        if (strcmp(name, ".")!= 0 && strcmp(name, "..")!= 0) {
            if (name[0] == '.' && name[1] == '.') {
                continue;
            }

            struct stat st;
            char *new_path = malloc(sizeof(char) * (strlen(path) + strlen(name) + 2));
            if (new_path == NULL) {
                perror("malloc failed");
                closedir(dir);
                free(info);
                return NULL;
            }
            sprintf(new_path, "%s/%s", path, name);

            if (stat(new_path, &st) < 0) {
                perror("stat failed");
                closedir(dir);
                free(info);
                free(new_path);
                return NULL;
            }

            if (S_ISDIR(st.st_mode)) {
                info->dirs++;
                struct directory_info *new_info = get_directory_info(new_path);
                if (new_info!= NULL) {
                    info->dirs += new_info->dirs;
                    free(new_info);
                }
            } else {
                info->files++;
                info->size += st.st_size;
            }

            free(new_path);
        }
    }

    closedir(dir);
    return info;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return 1;
    }

    struct directory_info *info = get_directory_info(argv[1]);
    if (info == NULL) {
        return 1;
    }

    printf("Directory path: %s\n", info->path);
    printf("Directory size: %llu\n", info->size);
    printf("Directory files: %llu\n", info->files);
    printf("Directory directories: %llu\n", info->dirs);

    free(info);
    return 0;
}