//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define FILE_SIZE 4096
#define KEY_SIZE 26

void encrypt_char(char *input, int key) {
    for (int i = 0; input[i] != '\0'; ++i) {
        if (isalpha(input[i])) {
            char ch = input[i];
            if (isupper(ch))
                input[i] = (char)(((int)ch + key - 65) % KEY_SIZE + 65);
            else
                input[i] = (char)(((int)ch + key - 97) % KEY_SIZE + 97);
        }
    }
}

bool read_file(const char *filename, char *buffer, size_t *size) {
    size_t bytes_read = 0;
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return false;
    }

    *size = fread(buffer, 1, FILE_SIZE, file);
    if (*size <= 0) {
        perror("Error reading file");
        fclose(file);
        return false;
    }

    fclose(file);
    return true;
}

void write_file(const char *filename, const char *buffer, size_t size) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    size_t bytes_written = fwrite(buffer, 1, size, file);
    if (bytes_written != size) {
        perror("Error writing to file");
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <key>\n", argv[0]);
        return 1;
    }

    char input_file[1024], output_file[1024], buffer[FILE_SIZE];
    strcpy(input_file, argv[1]);
    int key = atoi(argv[2]);

    if (read_file(input_file, buffer, NULL) == false)
        return 1;

    encrypt_char(buffer, key);

    size_t size = strlen(buffer);
    write_file("output.bin", buffer, size + 1);

    printf("File %s encrypted with key %d and saved as output.bin\n", input_file, key);

    return 0;
}