//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>

struct file_info {
    char *path;
    struct stat st;
};

struct file_info *file_info_new(const char *path) {
    struct file_info *info = malloc(sizeof(struct file_info));
    if (!info) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    info->path = strdup(path);
    if (!info->path) {
        perror("strdup");
        exit(EXIT_FAILURE);
    }
    if (stat(path, &info->st) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }
    return info;
}

void file_info_free(struct file_info *info) {
    free(info->path);
    free(info);
}

int file_info_compare(const void *a, const void *b) {
    struct file_info *info_a = (struct file_info *)a;
    struct file_info *info_b = (struct file_info *)b;
    return info_a->st.st_size - info_b->st.st_size;
}

void print_file_info(struct file_info *info) {
    printf("%3u ", info->st.st_blocks);

    struct passwd *pw = getpwuid(info->st.st_uid);
    if (pw) {
        printf("%s ", pw->pw_name);
    } else {
        printf("%u ", info->st.st_uid);
    }

    struct group *gr = getgrgid(info->st.st_gid);
    if (gr) {
        printf("%s ", gr->gr_name);
    } else {
        printf("%u ", info->st.st_gid);
    }

    printf("%5llu ", info->st.st_size);
    printf("%s\n", info->path);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    DIR *dir = opendir(argv[1]);
    if (!dir) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    struct file_info **files = NULL;
    size_t files_size = 0;
    size_t files_capacity = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char path[PATH_MAX];
        snprintf(path, sizeof(path), "%s/%s", argv[1], entry->d_name);

        struct file_info *info = file_info_new(path);
        if (info) {
            if (files_size >= files_capacity) {
                files_capacity = files_capacity ? files_capacity * 2 : 16;
                files = realloc(files, files_capacity * sizeof(struct file_info *));
                if (!files) {
                    perror("realloc");
                    exit(EXIT_FAILURE);
                }
            }
            files[files_size++] = info;
        }
    }
    closedir(dir);

    qsort(files, files_size, sizeof(struct file_info *), file_info_compare);

    printf("%3s %s %-5s %s %s\n", "Blks", "User", "Group", "Size", "Path");
    for (size_t i = 0; i < files_size; i++) {
        print_file_info(files[i]);
        file_info_free(files[i]);
    }
    free(files);

    return EXIT_SUCCESS;
}