//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_PATH 1024
#define MAX_FILES 1000

struct File {
    char path[MAX_PATH];
    size_t size;
    time_t mtime;
};

struct FileList {
    struct File files[MAX_FILES];
    int count;
};

void get_file_info(const char *path, struct File *file) {
    struct stat st;
    if (stat(path, &st) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }
    file->size = st.st_size;
    file->mtime = st.st_mtime;
    strcpy(file->path, path);
}

void get_file_list(const char *dir, struct FileList *files) {
    DIR *dp;
    struct dirent *entry;
    if ((dp = opendir(dir)) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }
    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        char path[MAX_PATH];
        snprintf(path, sizeof(path), "%s/%s", dir, entry->d_name);
        struct File file;
        get_file_info(path, &file);
        files->files[files->count++] = file;
    }
    closedir(dp);
}

int compare_files(const struct File *a, const struct File *b) {
    return strcmp(a->path, b->path);
}

void sort_files(struct FileList *files) {
    qsort(files->files, files->count, sizeof(struct File), (int (*)(const void *, const void *))compare_files);
}

void sync_files(const char *src, const char *dst) {
    struct FileList src_files;
    get_file_list(src, &src_files);
    struct FileList dst_files;
    get_file_list(dst, &dst_files);
    sort_files(&src_files);
    sort_files(&dst_files);
    int i, j;
    for (i = 0, j = 0; i < src_files.count && j < dst_files.count;) {
        int cmp = compare_files(&src_files.files[i], &dst_files.files[j]);
        if (cmp == 0) {
            if (src_files.files[i].mtime > dst_files.files[j].mtime) {
                // Update file in dst
                char path[MAX_PATH];
                snprintf(path, sizeof(path), "%s/%s", dst, src_files.files[i].path);
                int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
                if (fd == -1) {
                    perror("open");
                    exit(EXIT_FAILURE);
                }
                char buffer[4096];
                int n;
                snprintf(path, sizeof(path), "%s/%s", src, src_files.files[i].path);
                int fd_src = open(path, O_RDONLY);
                if (fd_src == -1) {
                    perror("open");
                    exit(EXIT_FAILURE);
                }
                while ((n = read(fd_src, buffer, sizeof(buffer))) > 0) {
                    if (write(fd, buffer, n) != n) {
                        perror("write");
                        exit(EXIT_FAILURE);
                    }
                }
                if (n == -1) {
                    perror("read");
                    exit(EXIT_FAILURE);
                }
                close(fd);
                close(fd_src);
            }
            i++;
            j++;
        } else if (cmp < 0) {
            // Copy file from src to dst
            char path[MAX_PATH];
            snprintf(path, sizeof(path), "%s/%s", dst, src_files.files[i].path);
            int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd == -1) {
                perror("open");
                exit(EXIT_FAILURE);
            }
            char buffer[4096];
            int n;
            snprintf(path, sizeof(path), "%s/%s", src, src_files.files[i].path);
            int fd_src = open(path, O_RDONLY);
            if (fd_src == -1) {
                perror("open");
                exit(EXIT_FAILURE);
            }
            while ((n = read(fd_src, buffer, sizeof(buffer))) > 0) {
                if (write(fd, buffer, n) != n) {
                    perror("write");
                    exit(EXIT_FAILURE);
                }
            }
            if (n == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            }
            close(fd);
            close(fd_src);
            i++;
        } else {
            // Delete file from dst
            char path[MAX_PATH];
            snprintf(path, sizeof(path), "%s/%s", dst, dst_files.files[j].path);
            if (unlink(path) == -1) {
                perror("unlink");
                exit(EXIT_FAILURE);
            }
            j++;
        }
    }
    while (i < src_files.count) {
        // Copy remaining files from src to dst
        char path[MAX_PATH];
        snprintf(path, sizeof(path), "%s/%s", dst, src_files.files[i].path);
        int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        char buffer[4096];
        int n;
        snprintf(path, sizeof(path), "%s/%s", src, src_files.files[i].path);
        int fd_src = open(path, O_RDONLY);
        if (fd_src == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        while ((n = read(fd_src, buffer, sizeof(buffer))) > 0) {
            if (write(fd, buffer, n) != n) {
                perror("write");
                exit(EXIT_FAILURE);
            }
        }
        if (n == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        close(fd);
        close(fd_src);
        i++;
    }
    while (j < dst_files.count) {
        // Delete remaining files from dst
        char path[MAX_PATH];
        snprintf(path, sizeof(path), "%s/%s", dst, dst_files.files[j].path);
        if (unlink(path) == -1) {
            perror("unlink");
            exit(EXIT_FAILURE);
        }
        j++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <src> <dst>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    const char *src = argv[1];
    const char *dst = argv[2];
    sync_files(src, dst);
    return EXIT_SUCCESS;
}