//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>

#define MAX_PATH_LEN 1024
#define MAX_FILE_LEN 1024

typedef struct {
    char name[MAX_FILE_LEN];
    time_t mtime;
    size_t size;
} FileInfo;

typedef struct {
    char name[MAX_PATH_LEN];
    size_t num_files;
    FileInfo files[MAX_FILE_LEN];
} DirInfo;

int compare_files(const void *a, const void *b) {
    const FileInfo *fa = (const FileInfo *)a;
    const FileInfo *fb = (const FileInfo *)b;

    return strcmp(fa->name, fb->name);
}

int compare_dirs(const void *a, const void *b) {
    const DirInfo *da = (const DirInfo *)a;
    const DirInfo *db = (const DirInfo *)b;

    return strcmp(da->name, db->name);
}

int get_file_info(const char *path, FileInfo *info) {
    struct stat buf;

    if (stat(path, &buf) == -1) {
        perror("stat");
        return -1;
    }

    strcpy(info->name, path);
    info->mtime = buf.st_mtime;
    info->size = buf.st_size;

    return 0;
}

int get_dir_info(const char *path, DirInfo *info) {
    DIR *dir;
    struct dirent *entry;
    char fullpath[MAX_PATH_LEN];
    FileInfo file_info;

    strcpy(info->name, path);
    info->num_files = 0;

    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(fullpath, MAX_PATH_LEN, "%s/%s", path, entry->d_name);
        if (get_file_info(fullpath, &file_info) == -1) {
            closedir(dir);
            return -1;
        }

        info->files[info->num_files++] = file_info;
    }

    closedir(dir);

    qsort(info->files, info->num_files, sizeof(FileInfo), compare_files);

    return 0;
}

int synchronize_dirs(const char *src_path, const char *dst_path) {
    DirInfo src_info, dst_info;
    FileInfo *src_file, *dst_file;
    char fullpath[MAX_PATH_LEN];

    if (get_dir_info(src_path, &src_info) == -1) {
        return -1;
    }

    if (get_dir_info(dst_path, &dst_info) == -1) {
        return -1;
    }

    qsort(&src_info, 1, sizeof(DirInfo), compare_dirs);
    qsort(&dst_info, 1, sizeof(DirInfo), compare_dirs);

    for (src_file = src_info.files, dst_file = dst_info.files; ; src_file++, dst_file++) {
        if (src_file == &src_info.files[src_info.num_files]) {
            break;
        }

        if (dst_file == &dst_info.files[dst_info.num_files]) {
            snprintf(fullpath, MAX_PATH_LEN, "%s/%s", dst_path, src_file->name);
            if (symlink(src_file->name, fullpath) == -1) {
                perror("symlink");
                return -1;
            }

            continue;
        }

        if (strcmp(src_file->name, dst_file->name) != 0) {
            snprintf(fullpath, MAX_PATH_LEN, "%s/%s", dst_path, src_file->name);
            if (symlink(src_file->name, fullpath) == -1) {
                perror("symlink");
                return -1;
            }

            continue;
        }

        if (src_file->mtime != dst_file->mtime || src_file->size != dst_file->size) {
            snprintf(fullpath, MAX_PATH_LEN, "%s/%s", dst_path, src_file->name);
            if (unlink(fullpath) == -1) {
                perror("unlink");
                return -1;
            }

            if (symlink(src_file->name, fullpath) == -1) {
                perror("symlink");
                return -1;
            }

            continue;
        }
    }

    for (; dst_file < &dst_info.files[dst_info.num_files]; dst_file++) {
        snprintf(fullpath, MAX_PATH_LEN, "%s/%s", dst_path, dst_file->name);
        if (unlink(fullpath) == -1) {
            perror("unlink");
            return -1;
        }
    }

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "usage: %s src_dir dst_dir\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (synchronize_dirs(argv[1], argv[2]) == -1) {
        perror("synchronize_dirs");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}