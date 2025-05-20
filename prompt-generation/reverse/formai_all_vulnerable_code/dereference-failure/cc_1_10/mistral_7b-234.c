//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define KEY 3

void encrypt_char(int key, char *str, int length) {
    int i;
    for (i = 0; i < length; i++) {
        if (isalpha(*(str + i))) {
            if (isupper(*(str + i))) {
                *(str + i) = (char)(((int)*(str + i) + key - 65) % 26 + 65);
            } else {
                *(str + i) = (char)(((int)*(str + i) + key) % 122);
            }
        }
    }
}

int main(int argc, char **argv) {
    int fd_in, fd_out, len;
    char *input_file, *output_file;

    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    input_file = argv[1];
    output_file = argv[2];

    fd_in = open(input_file, O_RDONLY);
    if (fd_in < 0) {
        perror("Error opening input file.");
        return 1;
    }

    fd_out = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd_out < 0) {
        perror("Error opening output file.");
        close(fd_in);
        return 1;
    }

    struct stat st;
    fstat(fd_in, &st);
    len = st.st_size;

    char *input_buffer = (char *)malloc(len);
    read(fd_in, input_buffer, len);

    encrypt_char(KEY, input_buffer, len);

    write(fd_out, input_buffer, len);

    free(input_buffer);

    close(fd_in);
    close(fd_out);

    printf("File %s encrypted and saved as %s.\n", input_file, output_file);

    return 0;
}