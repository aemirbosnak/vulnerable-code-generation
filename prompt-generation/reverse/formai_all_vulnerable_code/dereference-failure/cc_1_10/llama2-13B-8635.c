//LLAMA2-13B DATASET v1.0 Category: Data recovery tool ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 4096

typedef struct {
    char *name;
    char *extension;
} file_info_t;

file_info_t *get_file_info(const char *path) {
    file_info_t *fi = malloc(sizeof(file_info_t));
    struct stat stat_buf;

    if (stat(path, &stat_buf) == -1) {
        perror("stat");
        return NULL;
    }

    fi->name = malloc(strlen(path) + 1);
    strcpy(fi->name, path);
    fi->extension = NULL;

    if (S_ISREG(stat_buf.st_mode)) {
        fi->extension = strrchr(fi->name, '.');
        if (fi->extension == NULL) {
            fi->extension = strchr(fi->name, ' ');
        }
    }

    return fi;
}

int recover_file(const char *path, const char *new_path) {
    file_info_t *fi = get_file_info(path);
    if (fi == NULL) {
        return 1;
    }

    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        free(fi);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read == -1) {
        perror("read");
        close(fd);
        free(fi);
        return 1;
    }

    if (bytes_read > 0) {
        char *new_name = new_path;
        if (fi->extension != NULL) {
            new_name = strcat(new_name, fi->extension);
        }
        write(1, buffer, bytes_read);
        close(fd);
        free(fi);
        return 0;
    }

    close(fd);
    free(fi);
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <path> <new_path>\n", argv[0]);
        return 1;
    }

    if (recover_file(argv[1], argv[2]) == 1) {
        printf("Failed to recover file %s\n", argv[1]);
        return 1;
    }

    printf("File %s recovered to %s\n", argv[1], argv[2]);
    return 0;
}