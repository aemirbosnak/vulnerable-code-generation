//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define KEY "Once upon a time in the murky fogs of London town"
#define BLOCK_SIZE 16
#define FILE_NAME "input.txt"
#define OUTPUT_FILE "output.txt"

void xor_operation(unsigned char *buffer, int length) {
    unsigned char key_char[strlen(KEY)];
    int i;

    for (i = 0; i < strlen(KEY); i++) {
        key_char[i] = KEY[i];
    }

    for (i = 0; i < length; i++) {
        buffer[i] ^= key_char[i % strlen(KEY)];
    }
}

void encrypt_file(char *input_file, char *output_file) {
    int fd_input, fd_output;
    struct stat file_stat;
    char *buffer;
    int bytes_read, bytes_written;

    fd_input = open(input_file, O_RDONLY);
    fstat(fd_input, &file_stat);
    buffer = (char *) malloc(file_stat.st_size);

    bytes_read = read(fd_input, buffer, file_stat.st_size);

    xor_operation(buffer, bytes_read);

    fd_output = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    bytes_written = write(fd_output, buffer, bytes_read);

    close(fd_input);
    close(fd_output);

    free(buffer);
}

int main() {
    printf("The game is afoot! The input file shall be encrypted.\n");
    encrypt_file(FILE_NAME, OUTPUT_FILE);
    printf("The file '%s' has been encrypted and saved as '%s'\n", FILE_NAME, OUTPUT_FILE);

    return 0;
}