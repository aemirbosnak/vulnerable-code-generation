//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILE_SIZE (1024 * 1024) // Max file size: 1MB
#define BUFFER_SIZE 1024
#define MAX_LINES 1000
#define WORD_DELIMITER " \t\r\n\f,\\;:\"'()[]{}<>@#$%^&*_+-=`~|\\\\/?!"

// Function to count the number of words in a string
int count_words(const char *str, char delimiter) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] != delimiter) {
            count++;
        } else {
            while (str[i] == delimiter && str[i + 1]) i++;
        }
    }
    return count;
}

// Function to read file line by line
void read_file(const char *filename, char ***lines) {
    int line_count = 0;
    int buffer_size = BUFFER_SIZE;
    int file_size = 0;
    int fd = open(filename, O_RDONLY);

    if (fd < 0) {
        perror("Error opening file");
        return;
    }

    char *buffer = malloc(buffer_size);
    char *line = NULL;

    while (1) {
        int bytes_read = read(fd, buffer, buffer_size);
        if (bytes_read <= 0) break;

        line = strtok(buffer, "\n");

        if (line_count >= MAX_LINES) {
            fprintf(stderr, "Too many lines in file: %s\n", filename);
            break;
        }

        if (lines) {
            *(lines + line_count) = line;
        }

        file_size += bytes_read;

        if (bytes_read < buffer_size) {
            buffer_size = bytes_read + 1; // +1 for null terminator
            *lines = realloc(*lines, sizeof(char*) * (line_count + 1));
            *(lines + line_count) = NULL;
        } else {
            *lines = realloc(*lines, sizeof(char*) * (line_count + 1));
            *(lines + line_count) = buffer;
            buffer = malloc(buffer_size);
        }

        line_count++;
    }

    if (line) free(line);
    free(buffer);
    close(fd);

    *lines = realloc(*lines, sizeof(char*) * (line_count + 1));
    *(lines + line_count) = NULL;
}

// Function to print words from an array of strings
void print_words(const char **words, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s ", words[i]);
        int word_count = count_words(words[i], WORD_DELIMITER[0]);
        printf("=> %d words\n", word_count);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    char **lines = NULL;
    int lines_count = 0;

    read_file(argv[1], &lines);

    if (!lines) {
        perror("Error reading file");
        return 1;
    }

    print_words(lines, lines_count);

    for (int i = 0; lines[i]; i++) {
        free(lines[i]);
    }

    free(lines);

    return 0;
}