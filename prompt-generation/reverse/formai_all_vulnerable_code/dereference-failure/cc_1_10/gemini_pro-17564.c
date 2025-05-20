//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct {
    char *name;
    int size;
    int offset;
} file_entry;

int compare_files(const void *a, const void *b) {
    file_entry *fa = (file_entry *)a;
    file_entry *fb = (file_entry *)b;
    return fa->size - fb->size;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <boot image>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        return 1;
    }

    char *buf = malloc(st.st_size);
    if (buf == NULL) {
        perror("malloc");
        return 1;
    }

    if (read(fd, buf, st.st_size) != st.st_size) {
        perror("read");
        return 1;
    }

    close(fd);

    // Parse boot image
    int num_files = 0;
    file_entry *files = NULL;

    char *p = buf;
    while (p < buf + st.st_size) {
        char *name = p;
        while (*p != '\0') {
            p++;
        }
        p++;

        int size = *(int *)p;
        p += sizeof(int);

        int offset = *(int *)p;
        p += sizeof(int);

        num_files++;
        files = realloc(files, num_files * sizeof(file_entry));
        files[num_files - 1] = (file_entry){name, size, offset};
    }

    // Sort files by size
    qsort(files, num_files, sizeof(file_entry), compare_files);

    // Optimize boot image
    char *new_buf = malloc(st.st_size);
    if (new_buf == NULL) {
        perror("malloc");
        return 1;
    }

    p = new_buf;
    for (int i = 0; i < num_files; i++) {
        memcpy(p, files[i].name, strlen(files[i].name) + 1);
        p += strlen(files[i].name) + 1;

        *(int *)p = files[i].size;
        p += sizeof(int);

        *(int *)p = files[i].offset;
        p += sizeof(int);

        memcpy(p, buf + files[i].offset, files[i].size);
        p += files[i].size;
    }

    // Write optimized boot image
    fd = open(argv[1], O_WRONLY | O_TRUNC);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    if (write(fd, new_buf, st.st_size) != st.st_size) {
        perror("write");
        return 1;
    }

    close(fd);

    free(buf);
    free(new_buf);
    free(files);

    return 0;
}