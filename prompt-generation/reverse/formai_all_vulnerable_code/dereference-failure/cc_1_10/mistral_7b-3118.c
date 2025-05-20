//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_STR_LEN 1024
#define MIN_STR_LEN 16
#define BUF_SIZE 8192

char *my_strcat(char *dest, const char *src) {
    size_t dest_len = strlen(dest);
    size_t src_len = strlen(src);

    if (dest_len + src_len >= MAX_STR_LEN) {
        fprintf(stderr, "Error: String concatenation would result in a string longer than %d characters.\n", MAX_STR_LEN);
        exit(EXIT_FAILURE);
    }

    strncat(dest, src, MAX_STR_LEN - 1);
    dest[MAX_STR_LEN - 1] = '\0';

    return dest;
}

void my_strtrim(char *str) {
    size_t start = 0;
    size_t len = strlen(str);

    while (str[start] == ' ' || str[start] == '\t') {
        start++;
    }

    if (start > 0) {
        memmove(str, str + start, len - (start));
    }

    size_t end = len - 1;

    while (str[end] == ' ' || str[end] == '\t') {
        if (--end < 0) {
            fprintf(stderr, "Error: String would be empty after trimming.\n");
            exit(EXIT_FAILURE);
        }
    }

    if (end != (len - 1)) {
        memmove(str + end + 1, str + len, strlen(str + len) + 1);
    }
}

char *read_file_content(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    size_t size = 0;
    char *content = malloc(BUF_SIZE);
    ssize_t bytes_read;

    while ((bytes_read = read(fd, content + size, BUF_SIZE - size - 1)) > 0) {
        size += bytes_read;
        content[size] = '\0';
    }

    close(fd);

    if (size < MIN_STR_LEN) {
        fprintf(stderr, "Error: File content too small.\n");
        free(content);
        exit(EXIT_FAILURE);
    }

    return content;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_string> <destination_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char source_str[MAX_STR_LEN];
    strcpy(source_str, argv[1]);
    my_strtrim(source_str);

    char *file_content = read_file_content(argv[2]);
    my_strcat(source_str, " : ");
    my_strcat(source_str, file_content);
    my_strtrim(source_str);

    printf("%s\n", source_str);

    free(file_content);
    return EXIT_SUCCESS;
}