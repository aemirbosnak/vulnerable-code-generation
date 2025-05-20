//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <time.h>

#define KEY 3
#define MAX_LEN 100

int encrypt_char(int c) {
    if (isalpha(c)) {
        return (isupper(c) ? ((int)'A' + ((int)(c - (int)'A') + KEY) % 26) : ((int)'a' + ((int)(c - (int)'a') + KEY) % 26));
    }
    return c;
}

void encrypt_file(const char *input_file, const char *output_file) {
    int fd_input, fd_output;
    char *input_buffer, *output_buffer;
    size_t input_len, output_len;

    fd_input = open(input_file, O_RDONLY);
    fd_output = open(output_file, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    input_buffer = mmap(NULL, 4096, PROT_READ, MAP_PRIVATE, fd_input, 0);
    output_buffer = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd_output, 0);

    input_len = read(fd_input, input_buffer, 4096);

    for (size_t i = 0; i < input_len; i++) {
        output_buffer[i] = encrypt_char((int)input_buffer[i]);
    }

    output_len = write(fd_output, output_buffer, input_len);

    munmap(input_buffer, 4096);
    munmap(output_buffer, 4096);

    close(fd_input);
    close(fd_output);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    srand(time(NULL));

    encrypt_file(argv[1], argv[2]);

    printf("Encrypted file saved as %s\n", argv[2]);

    return 0;
}