//MISTRAL-7B DATASET v1.0 Category: Data recovery tool ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUF_SIZE 1024

void recover_love_letters(char *input_file, char *output_file) {
    int fd_input, fd_output;
    char buffer[BUF_SIZE];
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fd_input = open(input_file, O_RDONLY);
    fd_output = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (fd_input < 0 || fd_output < 0) {
        perror("Error opening files.");
        exit(EXIT_FAILURE);
    }

    printf("My dearest, I'm diving into the depths of your heart,\n");
    printf("To rescue your love letters, lost in the digital abyss.\n");

    while ((read = getline(&line, &len, fd_input)) > 0) {
        if (strstr(line, "I love you") || strstr(line, "I love you not")) {
            write(fd_output, line, read);
            printf("Found a treasure, %s:\n%s\n", input_file, line);
        }
    }

    free(line);

    close(fd_input);
    close(fd_output);

    printf("My dear, I've recovered your love letters,\n");
    printf("And now they're safe and sound, together we'll grow.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    recover_love_letters(argv[1], argv[2]);

    return EXIT_SUCCESS;
}