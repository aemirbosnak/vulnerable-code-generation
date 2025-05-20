//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_FILE_SIZE 1024 * 1024 * 1024
#define BUF_SIZE 1024
#define WORD_SIZE 64

// Function to check if file exists and is readable
int file_is_valid(const char *filename) {
    struct stat file_stat;

    if (stat(filename, &file_stat) < 0) {
        perror("Error: Could not stat file.");
        exit(1);
    }

    if (S_ISDIR(file_stat.st_mode)) {
        fprintf(stderr, "Error: File is a directory.\n");
        exit(1);
    }

    if (file_stat.st_size > MAX_FILE_SIZE) {
        fprintf(stderr, "Error: File size exceeds maximum allowed.\n");
        exit(1);
    }

    return 1;
}

// Function to count words in a given buffer
int count_words(const char *buf) {
    int count = 0;
    int i = 0;

    while (buf[i] != '\0') {
        if (isspace(buf[i])) {
            count++;
        }

        i++;
    }

    // Add one for the last word
    count++;

    return count;
}

// Function to read file content into a buffer
char *read_file(const char *filename) {
    int fd;
    size_t file_size;
    char *buffer;

    fd = open(filename, O_RDONLY);

    if (fd < 0) {
        perror("Error: Could not open file.");
        exit(1);
    }

    fseek(fd, 0, SEEK_END);
    file_size = ftell(fd);
    fseek(fd, 0, SEEK_SET);

    buffer = malloc(file_size + 1);

    if (buffer == NULL) {
        perror("Error: Could not allocate memory for buffer.");
        exit(1);
    }

    read(fd, buffer, file_size);
    close(fd);

    buffer[file_size] = '\0';

    return buffer;
}

int main(int argc, char **argv) {
    int i;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    if (!file_is_valid(argv[1])) {
        fprintf(stderr, "Error: Invalid file.\n");
        exit(1);
    }

    char *content = read_file(argv[1]);

    int words_count = count_words(content);

    printf("Word count in file '%s': %d\n", argv[1], words_count);

    free(content);

    return 0;
}