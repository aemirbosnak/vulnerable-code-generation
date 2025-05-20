//LLAMA2-13B DATASET v1.0 Category: Data recovery tool ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

#define GRATEFUL_MAX_FILE_SIZE (1024 * 1024 * 10)

struct grateful_file {
    char *name;
    size_t size;
    size_t offset;
    char *data;
};

static void grateful_file_free(struct grateful_file *file) {
    if (file->data != NULL) {
        free(file->data);
    }
    free(file);
}

static int grateful_file_open(struct grateful_file **file, const char *name, size_t size, size_t offset) {
    int fd;
    struct stat stat_buf;

    if ((fd = open(name, O_RDONLY, 0)) < 0) {
        perror("Error opening file");
        return -1;
    }

    if (fstat(fd, &stat_buf) < 0) {
        perror("Error stat'ing file");
        close(fd);
        return -1;
    }

    if (size > stat_buf.st_size) {
        perror("File too small");
        close(fd);
        return -1;
    }

    if (offset > stat_buf.st_size) {
        perror("Offset too large");
        close(fd);
        return -1;
    }

    *file = calloc(1, sizeof(struct grateful_file));
    if (*file == NULL) {
        perror("Memory allocation failed");
        close(fd);
        return -1;
    }

    (*file)->name = strdup(name);
    if ((*file)->name == NULL) {
        perror("Memory allocation failed");
        grateful_file_free(*file);
        close(fd);
        return -1;
    }

    (*file)->size = size;
    (*file)->offset = offset;
    (*file)->data = malloc(size);
    if ((*file)->data == NULL) {
        perror("Memory allocation failed");
        grateful_file_free(*file);
        close(fd);
        return -1;
    }

    if (read(fd, (*file)->data, size) < 0) {
        perror("Error reading file");
        grateful_file_free(*file);
        close(fd);
        return -1;
    }

    close(fd);

    return 0;
}

static int grateful_file_read(struct grateful_file *file, char *buffer, size_t size) {
    size_t remaining = file->size - file->offset;

    if (remaining > size) {
        size_t copy_size = size;

        if (copy_size > remaining) {
            copy_size = remaining;
        }

        memcpy(buffer, file->data + file->offset, copy_size);
        file->offset += copy_size;

        if (file->offset >= file->size) {
            file->offset = 0;
        }

        return copy_size;
    } else {
        memcpy(buffer, file->data + file->offset, remaining);
        file->offset += remaining;

        if (file->offset >= file->size) {
            file->offset = 0;
        }

        return remaining;
    }
}

int main(int argc, char *argv[]) {
    struct grateful_file *file = NULL;

    if (argc < 3) {
        printf("Usage: %s <file> <offset> <size>\n", argv[0]);
        return 1;
    }

    if (grateful_file_open(&file, argv[1], atoi(argv[2]), atoi(argv[3])) < 0) {
        perror("Error opening file");
        return 2;
    }

    char buffer[1024];
    while (1) {
        size_t read_size = grateful_file_read(file, buffer, sizeof(buffer));

        if (read_size == 0) {
            break;
        }

        printf("%s\n", buffer);
    }

    grateful_file_free(file);

    return 0;
}