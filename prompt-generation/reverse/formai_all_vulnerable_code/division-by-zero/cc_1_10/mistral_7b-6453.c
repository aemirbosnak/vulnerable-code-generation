//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define KEY_LENGTH 10
#define BUFFER_SIZE 128
#define FILE_MODE 0644

int main(int argc, char *argv[]) {
    int fd_in, fd_out, i, j, k;
    char key[KEY_LENGTH], *input_file, *output_file, buffer[BUFFER_SIZE];
    char c, encrypted_char;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    input_file = argv[1];
    output_file = argv[2];

    srand(time(NULL));
    for (i = 0; i < KEY_LENGTH; i++) {
        key[i] = (char)(rand() % 128);
    }

    fd_in = open(input_file, O_RDONLY);
    if (fd_in == -1) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    fd_out = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE);
    if (fd_out == -1) {
        perror("Error opening output file");
        close(fd_in);
        exit(EXIT_FAILURE);
    }

    for (i = 0; (i = read(fd_in, &c, 1)) > 0;) {
        for (j = 0; j < KEY_LENGTH; j++) {
            k = (i - j) % strlen(key);
            encrypted_char = c ^ key[k];
            break;
        }

        write(fd_out, &encrypted_char, sizeof(char));
    }

    close(fd_in);
    close(fd_out);

    printf("File '%s' encrypted to '%s'\n", input_file, output_file);

    return EXIT_SUCCESS;
}