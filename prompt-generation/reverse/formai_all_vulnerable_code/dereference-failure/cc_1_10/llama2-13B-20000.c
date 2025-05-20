//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_SIZE 1024 * 1024 * 10

typedef struct {
    char *file_name;
    size_t file_size;
    size_t line_count;
    char *data;
} file_info_t;

file_info_t *get_file_info(const char *file_name) {
    file_info_t *fi = malloc(sizeof(file_info_t));
    fi->file_name = strdup(file_name);
    fi->file_size = 0;
    fi->line_count = 0;
    fi->data = NULL;

    int fd = open(file_name, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return NULL;
    }

    struct stat stat_buf;
    if (fstat(fd, &stat_buf) == -1) {
        perror("fstat");
        close(fd);
        return NULL;
    }

    fi->file_size = stat_buf.st_size;

    char *line = NULL;
    size_t line_len = 0;
    size_t bytes_read = 0;

    while ((bytes_read = read(fd, &line, 1)) > 0) {
        line_len += bytes_read;
        if (line_len >= MAX_LINE_LENGTH) {
            break;
        }
        fi->data = realloc(fi->data, fi->line_count * (MAX_LINE_LENGTH + 1));
        memcpy(fi->data + fi->line_count * (MAX_LINE_LENGTH + 1) - line_len, line, line_len);
        fi->line_count++;
        line = NULL;
    }

    close(fd);

    return fi;
}

int main(void) {
    file_info_t *fi = get_file_info("example.c");
    if (fi == NULL) {
        perror("get_file_info");
        return 1;
    }

    printf("File name: %s\n", fi->file_name);
    printf("File size: %zu bytes\n", fi->file_size);
    printf("Line count: %zu\n", fi->line_count);

    for (size_t i = 0; i < fi->line_count; i++) {
        printf("%d: %s\n", i, fi->data + i * (MAX_LINE_LENGTH + 1));
    }

    free(fi->data);
    free(fi->file_name);
    free(fi);

    return 0;
}