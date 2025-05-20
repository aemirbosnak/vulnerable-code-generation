//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_PATH 1024
#define MAX_FILES 1024
#define MAX_SIZE 1024 * 1024

typedef struct {
    char path[MAX_PATH];
    time_t mtime;
    size_t size;
} file_t;

file_t files[MAX_FILES];
int nfiles = 0;

void add_file(const char *path) {
    struct stat st;
    if (stat(path, &st) != 0) {
        perror("stat");
        return;
    }
    if (nfiles >= MAX_FILES) {
        fprintf(stderr, "too many files\n");
        return;
    }
    strcpy(files[nfiles].path, path);
    files[nfiles].mtime = st.st_mtime;
    files[nfiles].size = st.st_size;
    nfiles++;
}

void backup_files(const char *dir) {
    char path[MAX_PATH];
    for (int i = 0; i < nfiles; i++) {
        snprintf(path, sizeof(path), "%s/%s", dir, files[i].path);
        int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1) {
            perror("open");
            continue;
        }
        char buf[MAX_SIZE];
        int fd1 = open(files[i].path, O_RDONLY);
        if (fd1 == -1) {
            perror("open");
            close(fd);
            continue;
        }
        while (1) {
            ssize_t n = read(fd1, buf, sizeof(buf));
            if (n == -1) {
                perror("read");
                close(fd);
                close(fd1);
                break;
            }
            if (n == 0) {
                close(fd1);
                break;
            }
            if (write(fd, buf, n) != n) {
                perror("write");
                close(fd);
                close(fd1);
                break;
            }
        }
        close(fd);
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "usage: %s <files> <dir>\n", argv[0]);
        return EXIT_FAILURE;
    }
    for (int i = 1; i < argc - 1; i++) {
        add_file(argv[i]);
    }
    backup_files(argv[argc - 1]);
    return EXIT_SUCCESS;
}