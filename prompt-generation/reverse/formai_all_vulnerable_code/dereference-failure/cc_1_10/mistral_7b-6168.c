//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <err.h>
#include <alloca.h>

#define BUF_SIZE 1024
#define WORD_DELIM " \t\n\r\f,;.!?()[]{}\"''`<->/|\\"

void count_words(const char *path, char **argv, int *count) {
    int fd;
    struct stat file_stat;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (stat(path, &file_stat) == -1) {
        warn("Failed to stat %s", path);
        exit(EXIT_FAILURE);
    }

    fd = open(path, O_RDONLY);
    if (fd == -1) {
        warn("Failed to open %s", path);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fd)) != -1) {
        char *token = strtok(line, WORD_DELIM);
        int tokens_count = 0;

        while (token != NULL) {
            tokens_count++;
            token = strtok(NULL, WORD_DELIM);
        }

        *count += tokens_count;
    }

    if (line) free(line);
    close(fd);

    if (argv && *argv) {
        int argc = strlen(argv[0]) + 1;
        *count += argc;
    }
}

int main(int argc, char **argv) {
    int word_count = 0;
    int i;

    if (argc > 2) {
        errx(EXIT_FAILURE, "Usage: %s [file]", argv[0]);
    }

    if (argc == 1) {
        char *stdin_line = NULL;
        size_t stdin_len = 0;

        while (getline(&stdin_line, &stdin_len, STDIN_FILENO) != -1) {
            char *token = strtok(stdin_line, WORD_DELIM);
            int tokens_count = 0;

            while (token != NULL) {
                tokens_count++;
                token = strtok(NULL, WORD_DELIM);
            }

            word_count += tokens_count;
        }

        if (stdin_line) free(stdin_line);
    } else {
        char *path = argv[1];

        count_words(path, argv, &word_count);
    }

    printf("%d\n", word_count);
    return EXIT_SUCCESS;
}