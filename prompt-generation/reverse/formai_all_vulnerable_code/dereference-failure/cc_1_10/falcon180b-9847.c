//Falcon-180B DATASET v1.0 Category: System administration ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_LINE_LEN 1024

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <file> <search_string>\n", argv[0]);
        return 1;
    }

    char *file_path = argv[1];
    char *search_str = argv[2];

    int fd = open(file_path, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error: Could not open file %s\n", file_path);
        return 1;
    }

    struct stat file_stat;
    if (fstat(fd, &file_stat) == -1) {
        fprintf(stderr, "Error: Could not get file status for %s\n", file_path);
        return 1;
    }

    size_t file_size = file_stat.st_size;
    char *file_content = malloc(file_size + 1);

    if (read(fd, file_content, file_size)!= file_size) {
        fprintf(stderr, "Error: Could not read file content for %s\n", file_path);
        free(file_content);
        return 1;
    }

    file_content[file_size] = '\0';

    char *result = strstr(file_content, search_str);

    if (result == NULL) {
        fprintf(stdout, "Search string not found in file %s\n", file_path);
    } else {
        fprintf(stdout, "Search string found in file %s at line %d\n", file_path, result - file_content + 1);
    }

    free(file_content);
    close(fd);

    return 0;
}