//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_FILES 10

struct File {
    char *name;
    char *content;
    size_t size;
};

struct File **files;
int num_files;

void add_file(char *name, char *content, size_t size) {
    if (num_files >= MAX_FILES) {
        fprintf(stderr, "Error: too many files\n");
        return;
    }

    files[num_files] = malloc(sizeof(struct File));
    files[num_files]->name = strdup(name);
    files[num_files]->content = malloc(size);
    memcpy(files[num_files]->content, content, size);
    files[num_files]->size = size;
    num_files++;
}

void write_files() {
    int i, fd;

    for (i = 0; i < num_files; i++) {
        fd = open(files[i]->name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd < 0) {
            fprintf(stderr, "Error: cannot open file %s\n", files[i]->name);
            continue;
        }

        if (write(fd, files[i]->content, files[i]->size) != files[i]->size) {
            fprintf(stderr, "Error: cannot write to file %s\n", files[i]->name);
            close(fd);
            continue;
        }

        close(fd);
    }
}

void read_files() {
    int i, fd;
    char buf[1024];
    size_t size;

    for (i = 0; i < num_files; i++) {
        fd = open(files[i]->name, O_RDONLY);
        if (fd < 0) {
            fprintf(stderr, "Error: cannot open file %s\n", files[i]->name);
            continue;
        }

        size = read(fd, buf, sizeof(buf));
        if (size < 0) {
            fprintf(stderr, "Error: cannot read from file %s\n", files[i]->name);
            close(fd);
            continue;
        }

        files[i]->content = malloc(size);
        memcpy(files[i]->content, buf, size);
        files[i]->size = size;

        close(fd);
    }
}

void compare_files() {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i]->content, files[0]->content) != 0) {
            fprintf(stdout, "Error: file %s is different\n", files[i]->name);
        }
    }
}

int main(int argc, char **argv) {
    int i, status;

    files = malloc(sizeof(struct File *) * MAX_FILES);
    num_files = 0;

    for (i = 1; i < argc; i++) {
        add_file(argv[i], argv[i], strlen(argv[i]));
    }

    write_files();

    if (fork() == 0) {
        read_files();
        exit(0);
    } else {
        wait(&status);
        compare_files();
    }

    return 0;
}