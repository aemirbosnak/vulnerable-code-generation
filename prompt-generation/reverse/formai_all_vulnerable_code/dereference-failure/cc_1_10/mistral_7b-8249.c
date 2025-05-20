//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 256
#define BUFFER_SIZE 1024

void encrypt_file(FILE *input, FILE *output, int key) {
    char buffer[BUFFER_SIZE];
    char encrypted_buffer[BUFFER_SIZE];

    while (fgets(buffer, BUFFER_SIZE, input)) {
        for (int i = 0; buffer[i]; i++) {
            if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
                encrypted_buffer[i] = ((buffer[i] - 'A' + key) % 26) + 'A';
            } else if (buffer[i] >= 'a' && buffer[i] <= 'z') {
                encrypted_buffer[i] = ((buffer[i] - 'a' + key) % 26) + 'a';
            } else {
                encrypted_buffer[i] = buffer[i];
            }
        }

        fwrite(encrypted_buffer, strlen(encrypted_buffer), 1, output);
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");
    int key = atoi(argv[3]);

    if (!input || !output) {
        printf("Error opening files.\n");
        return 1;
    }

    encrypt_file(input, output, key);
    fclose(input);
    fclose(output);

    printf("File encrypted successfully.\n");
    return 0;
}