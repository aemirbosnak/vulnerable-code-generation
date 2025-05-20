//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PATH_LENGTH 1024
#define MAX_SYNC_ITEMS 100

struct sync_item {
    char src_path[MAX_PATH_LENGTH];
    char dst_path[MAX_PATH_LENGTH];
};

void print_banner() {
    printf("The Adventure of the File Synchronizer\n");
    printf("-------------------------------------\n\n");
}

void print_help() {
    printf("Usage: fsync SRC_DIR DST_DIR\n\n");
    printf("Description:\n");
    printf("  Synchronize the content of the SRC_DIR with the DST_DIR.\n");
    printf("  This program will compare the files in SRC_DIR and DST_DIR,\n");
    printf("  and copy the missing or outdated files from SRC_DIR to DST_DIR.\n\n");
}

int is_directory(const char *path) {
    struct stat st;
    if (stat(path, &st) == 0) {
        return S_ISDIR(st.st_mode);
    }
    return 0;
}

void list_files(const char *path, struct sync_item *items, int *count) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        char file_path[MAX_PATH_LENGTH];
        snprintf(file_path, MAX_PATH_LENGTH, "%s/%s", path, entry->d_name);
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        if (is_directory(file_path)) {
            list_files(file_path, items, count);
        } else {
            struct sync_item item;
            strncpy(item.src_path, file_path, MAX_PATH_LENGTH);
            snprintf(item.dst_path, MAX_PATH_LENGTH, "%s/%s", path, entry->d_name);
            items[*count] = item;
            (*count)++;
        }
    }
    closedir(dir);
}

int need_copy(const char *src_path, const char *dst_path) {
    struct stat src_st, dst_st;
    if (stat(src_path, &src_st) != 0) {
        return 0;
    }
    if (stat(dst_path, &dst_st) != 0) {
        return 1;
    }
    return difftime(src_st.st_mtime, dst_st.st_mtime) > 0;
}

void synchronize(struct sync_item *items, int count) {
    for (int i = 0; i < count; i++) {
        if (need_copy(items[i].src_path, items[i].dst_path)) {
            int src_fd = open(items[i].src_path, O_RDONLY);
            if (src_fd == -1) {
                perror("open");
                continue;
            }
            int dst_fd = open(items[i].dst_path, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
            if (dst_fd == -1) {
                perror("open");
                continue;
            }
            char buf[1024];
            ssize_t n;
            while ((n = read(src_fd, buf, sizeof(buf))) > 0) {
                if (write(dst_fd, buf, n) != n) {
                    perror("write");
                    break;
                }
            }
            close(src_fd);
            close(dst_fd);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_banner();
        print_help();
        exit(EXIT_FAILURE);
    }
    char *src_dir = argv[1];
    char *dst_dir = argv[2];
    if (!is_directory(src_dir)) {
        printf("%s is not a directory\n", src_dir);
        exit(EXIT_FAILURE);
    }
    if (!is_directory(dst_dir)) {
        printf("%s is not a directory\n", dst_dir);
        exit(EXIT_FAILURE);
    }
    print_banner();
    printf("Synchronizing %s with %s...\n", src_dir, dst_dir);
    struct sync_item items[MAX_SYNC_ITEMS];
    int count = 0;
    list_files(src_dir, items, &count);
    if (count == 0) {
        printf("No files to synchronize\n");
        exit(EXIT_SUCCESS);
    }
    synchronize(items, count);
    printf("%d files synchronized\n", count);
    exit(EXIT_SUCCESS);
}