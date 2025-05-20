//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define KEY_SIZE 3
#define MAX_CHAR 127
#define BUF_SIZE 4096

void encrypt_char(int key, char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            if (isupper(input[i]))
                input[i] = ((input[i] + key - 'A') % 26 + 'A');
            else
                input[i] = ((input[i] + key) % 26 + 'a');
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <key> <file>\n", argv[0]);
        return 1;
    }

    int key = atoi(argv[1]);
    if (key < 1 || key > KEY_SIZE * 26) {
        printf("Invalid key. Please enter a number between 1 and %d\n", KEY_SIZE * 26);
        return 1;
    }

    FILE *input_file = fopen(argv[2], "rb");
    if (input_file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char *input_buffer = malloc(BUF_SIZE);
    char *output_buffer = malloc(BUF_SIZE);
    time_t t;

    srand((unsigned)time(&t));

    while (fread(input_buffer, 1, BUF_SIZE, input_file) != 0) {
        int read_bytes = strlen(input_buffer);
        encrypt_char(key, input_buffer);

        for (int i = 0; i < read_bytes; i++) {
            output_buffer[i] = input_buffer[i];
        }

        fwrite(output_buffer, 1, read_bytes, stdout);
    }

    free(input_buffer);
    free(output_buffer);
    fclose(input_file);

    return 0;
}