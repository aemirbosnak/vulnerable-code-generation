//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct {
    char *name;
    size_t size;
    char *data;
} File;

File *files;
size_t num_files;

int read_files(char *dir) {
    DIR *d;
    struct dirent *entry;
    int fd;
    struct stat st;

    d = opendir(dir);
    if (!d) {
        perror("opendir");
        return -1;
    }

    while ((entry = readdir(d))) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        if (lstat(entry->d_name, &st) == -1) {
            perror("lstat");
            continue;
        }

        if (!S_ISREG(st.st_mode)) {
            continue;
        }

        fd = open(entry->d_name, O_RDONLY);
        if (fd == -1) {
            perror("open");
            continue;
        }

        files = realloc(files, sizeof(File) * (num_files + 1));
        if (!files) {
            perror("realloc");
            close(fd);
            continue;
        }

        files[num_files].name = strdup(entry->d_name);
        files[num_files].size = st.st_size;
        files[num_files].data = malloc(st.st_size);
        if (!files[num_files].data) {
            perror("malloc");
            close(fd);
            continue;
        }

        if (read(fd, files[num_files].data, st.st_size) != st.st_size) {
            perror("read");
            close(fd);
            continue;
        }

        close(fd);
        num_files++;
    }

    closedir(d);
    return 0;
}

int write_files() {
    int fd;

    for (size_t i = 0; i < num_files; i++) {
        fd = open(files[i].name, O_CREAT | O_WRONLY, 0644);
        if (fd == -1) {
            perror("open");
            continue;
        }

        if (write(fd, files[i].data, files[i].size) != files[i].size) {
            perror("write");
            close(fd);
            continue;
        }

        close(fd);
    }

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <dir>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (read_files(argv[1]) == -1) {
        return EXIT_FAILURE;
    }

    if (write_files() == -1) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}