//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_FILE_SIZE (1024 * 1024)

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        die("Could not open file");
    }

    struct stat file_stat;
    if (fstat(fd, &file_stat) == -1) {
        die("Could not get file size");
    }

    if (file_stat.st_size > MAX_FILE_SIZE) {
        fprintf(stderr, "File too large (%.2f MB)\n", (float)file_stat.st_size / 1024 / 1024);
        close(fd);
        return EXIT_FAILURE;
    }

    char *file_content = malloc(file_stat.st_size + 1);
    if (file_content == NULL) {
        die("Could not allocate memory for file content");
    }

    ssize_t bytes_read = read(fd, file_content, file_stat.st_size);
    if (bytes_read != file_stat.st_size) {
        fprintf(stderr, "Could not read entire file\n");
        free(file_content);
        close(fd);
        return EXIT_FAILURE;
    }

    file_content[file_stat.st_size] = '\0';

    int num_words = 1;
    char *token = strtok(file_content, " \t\r\n\f\v");

    while (token != NULL) {
        num_words++;
        token = strtok(NULL, " \t\r\n\f\v");
    }

    printf("Found %d words in file\n", num_words);

    free(file_content);
    close(fd);
    return EXIT_SUCCESS;
}