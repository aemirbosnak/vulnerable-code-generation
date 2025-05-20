//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define KEY 0x32

void encrypt_char(char c, FILE *input, FILE *output) {
    if (input == NULL || output == NULL) {
        printf("Invalid file handles\n");
        exit(1);
    }

    if (feof(input)) {
        return;
    }

    char ch = fgetc(input);
    fputc(ch ^ KEY, output);

    encrypt_char(ch, input, output);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    int input_fd = open(argv[1], O_RDONLY);
    int output_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (input_fd < 0 || output_fd < 0) {
        perror("Error opening files");
        exit(1);
    }

    FILE *input = fdopen(input_fd, "r");
    FILE *output = fdopen(output_fd, "w");

    if (input == NULL || output == NULL) {
        perror("Error opening file streams");
        exit(1);
    }

    encrypt_char(EOF, input, output);

    fclose(input);
    fclose(output);

    close(input_fd);
    close(output_fd);

    printf("File encrypted successfully\n");

    return 0;
}