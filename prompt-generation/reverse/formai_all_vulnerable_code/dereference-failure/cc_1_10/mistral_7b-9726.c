//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_LINE 1024

typedef struct {
    char *filename;
    char *extension;
    int is_text;
} file_info;

int check_extension(char *filename) {
    char *dot = strrchr(filename, '.');
    if (!dot) return 0;

    int len = strlen(dot);
    if (len <= 3) return 0;

    char *ext = dot;
    len -= (int) (dot - filename);

    if (!strcmp(ext, "txt") || !strcmp(ext, "text"))
        return 1;

    return 0;
}

file_info parse_filename(char *filename) {
    file_info info;
    info.filename = strdup(filename);

    char *dot = strrchr(filename, '.');
    if (!dot) {
        info.extension = "";
        info.is_text = check_extension(info.filename);
        return info;
    }

    int len = strlen(dot);
    info.extension = malloc(len + 1);
    strncpy(info.extension, dot, len + 1);

    info.is_text = check_extension(filename);

    return info;
}

void process_file(file_info file) {
    int fd = open(file.filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        free(file.filename);
        free(file.extension);
        return;
    }

    char line[MAX_LINE];
    int count = 0;

    while (fgets(line, MAX_LINE, fd) != NULL) {
        count++;
        printf("%d: %s", count, line);
    }

    close(fd);

    free(file.filename);
    free(file.extension);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file_info file = parse_filename(argv[1]);

    if (!file.is_text) {
        printf("Invalid file type: %s\n", file.extension);
        return 1;
    }

    process_file(file);
    return 0;
}