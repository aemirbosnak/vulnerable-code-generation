//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 2000

int sync_files(char* src_dir, char* dst_dir);
int sync_file(char* src_file, char* dst_file);
int make_dir_path(char* path, char* file_path);
int same_contents(char* file1, char* file2);

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
        return 1;
    }
    if (sync_files(argv[1], argv[2]) == -1) {
        printf("Error syncing files: %s\n", strerror(errno));
        return 1;
    }
    return 0;
}

int sync_files(char* src_dir, char* dst_dir) {
    DIR* src = opendir(src_dir);
    if (src == NULL) {
        return -1;
    }
    DIR* dst = opendir(dst_dir);
    if (dst == NULL) {
        if (mkdir(dst_dir, 0777) == -1) {
            return -1;
        }
        dst = opendir(dst_dir);
        if (dst == NULL) {
            return -1;
        }
    }
    struct dirent* entry;
    char src_file_path[MAX_PATH_LENGTH];
    char dst_file_path[MAX_PATH_LENGTH];
    while ((entry = readdir(src)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue;
        }
        make_dir_path(src_file_path, src_dir);
        strcat(src_file_path, "/");
        strcat(src_file_path, entry->d_name);
        make_dir_path(dst_file_path, dst_dir);
        strcat(dst_file_path, "/");
        strcat(dst_file_path, entry->d_name);
        if (entry->d_type == DT_DIR) {
            if (sync_files(src_file_path, dst_file_path) == -1) {
                return -1;
            }
        } else {
            if (sync_file(src_file_path, dst_file_path) == -1) {
                return -1;
            }
        }
    }
    closedir(src);
    closedir(dst);
    return 0;
}

int sync_file(char* src_file, char* dst_file) {
    struct stat src_stat;
    if (stat(src_file, &src_stat) == -1) {
        return -1;
    }
    struct stat dst_stat;
    if (stat(dst_file, &dst_stat) == -1) {
        if (errno == ENOENT) {
            int src_fd = open(src_file, O_RDONLY);
            if (src_fd == -1) {
                return -1;
            }
            int dst_fd = open(dst_file, O_WRONLY | O_CREAT, src_stat.st_mode);
            if (dst_fd == -1) {
                close(src_fd);
                return -1;
            }
            char buf[1024];
            int n;
            while ((n = read(src_fd, buf, sizeof(buf))) > 0) {
                if (write(dst_fd, buf, n) != n) {
                    close(src_fd);
                    close(dst_fd);
                    return -1;
                }
            }
            close(src_fd);
            close(dst_fd);
            return 0;
        } else {
            return -1;
        }
    }
    if (src_stat.st_mtime > dst_stat.st_mtime) {
        if (same_contents(src_file, dst_file) == 0) {
            int src_fd = open(src_file, O_RDONLY);
            if (src_fd == -1) {
                return -1;
            }
            int dst_fd = open(dst_file, O_WRONLY | O_TRUNC);
            if (dst_fd == -1) {
                close(src_fd);
                return -1;
            }
            char buf[1024];
            int n;
            while ((n = read(src_fd, buf, sizeof(buf))) > 0) {
                if (write(dst_fd, buf, n) != n) {
                    close(src_fd);
                    close(dst_fd);
                    return -1;
                }
            }
            close(src_fd);
            close(dst_fd);
            return 0;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

int make_dir_path(char* path, char* file_path) {
    strcpy(path, file_path);
    int len = strlen(path);
    while (len > 0 && path[len-1] != '/') {
        len--;
    }
    path[len] = '\0';
    return 0;
}

int same_contents(char* file1, char* file2) {
    FILE* f1 = fopen(file1, "rb");
    if (f1 == NULL) {
        return -1;
    }
    FILE* f2 = fopen(file2, "rb");
    if (f2 == NULL) {
        fclose(f1);
        return -1;
    }
    char buf1[1024];
    char buf2[1024];
    int n1, n2;
    while ((n1 = fread(buf1, 1, sizeof(buf1), f1)) > 0) {
        n2 = fread(buf2, 1, sizeof(buf2), f2);
        if (n1 != n2 || memcmp(buf1, buf2, n1) != 0) {
            fclose(f1);
            fclose(f2);
            return 0;
        }
    }
    n2 = fread(buf2, 1, sizeof(buf2), f2);
    if (n2 > 0) {
        fclose(f1);
        fclose(f2);
        return 0;
    }
    fclose(f1);
    fclose(f2);
    return 1;
}