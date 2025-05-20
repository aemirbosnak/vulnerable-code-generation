//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FILE_MODE 0644
#define BUFFER_SIZE 256
#define MIN_KEY_LENGTH 1
#define MAX_KEY_LENGTH 25

typedef struct {
    char filename[256];
    int file_descriptor;
    char key[MAX_KEY_LENGTH + 1];
} FileEncryptorContext;

void die(const char *msg) {
    perror(msg);
    exit(1);
}

void print_usage() {
    printf("Usage: %s <input_file> <output_file> <key>\n", __FILE__);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        print_usage();
    }

    FileEncryptorContext context = {0};
    strcpy(context.filename, argv[1]);
    strcpy(context.key, argv[3]);

    int input_file = open(context.filename, O_RDONLY);
    if (input_file < 0) {
        die("Cannot open input file");
    }

    int output_file = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE);
    if (output_file < 0) {
        die("Cannot create or open output file");
    }

    context.file_descriptor = output_file;

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = read(input_file, buffer, BUFFER_SIZE)) > 0) {
        for (int i = 0; i < bytes_read; ++i) {
            if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
                buffer[i] = (char)(((int)buffer[i] + (int)*context.key - 65) % 26 + 65);
            } else if (buffer[i] >= 'a' && buffer[i] <= 'z') {
                buffer[i] = (char)(((int)buffer[i] + (int)*context.key - 97) % 26 + 97);
            }
        }

        if (write(context.file_descriptor, buffer, bytes_read) != bytes_read) {
            die("Error writing to output file");
        }
    }

    if (close(input_file) < 0) {
        die("Error closing input file");
    }

    if (close(context.file_descriptor) < 0) {
        die("Error closing output file");
    }

    printf("File encrypted successfully.\n");
    return 0;
}