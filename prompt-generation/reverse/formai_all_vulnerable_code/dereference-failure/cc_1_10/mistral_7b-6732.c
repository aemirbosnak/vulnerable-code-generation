//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY 26
#define BUFFER_SIZE 1024
#define FILE_NAME_SIZE 256

void encrypt_char(char *input, int key) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            if (isupper(input[i])) {
                input[i] = (((input[i] - 'A' + key) % 26) + 'A');
            } else {
                input[i] = (((input[i] - 'a' + key) % 26) + 'a');
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        return 1;
    }

    char input_buffer[BUFFER_SIZE];
    char output_buffer[BUFFER_SIZE];
    int key = atoi(argv[3]);

    if (key < 0 || key > MAX_KEY) {
        printf("Invalid key. Key should be between 0 and %d.\n", MAX_KEY);
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    while (fgets(input_buffer, BUFFER_SIZE, input_file)) {
        encrypt_char(input_buffer, key);
        fwrite(input_buffer, strlen(input_buffer), 1, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully.\n");
    return 0;
}