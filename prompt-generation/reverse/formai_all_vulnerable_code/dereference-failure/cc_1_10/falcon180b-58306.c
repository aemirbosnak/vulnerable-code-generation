//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define ENCRYPTION_KEY "mysecretkey"

void encrypt_file(FILE *input_file, FILE *output_file) {
    char input_buffer[1024];
    char output_buffer[1024];
    int input_buffer_size = 0;
    int output_buffer_size = 0;

    while (fgets(input_buffer, sizeof(input_buffer), input_file)!= NULL) {
        input_buffer_size = strlen(input_buffer);
        output_buffer_size = 0;

        for (int i = 0; i < input_buffer_size; i++) {
            char c = input_buffer[i];

            if (isalpha(c)) {
                c = (c - 'a' + 13) % 26 + 'a';
            } else if (isdigit(c)) {
                c = (c + 5) % 10 + '0';
            }

            output_buffer[output_buffer_size++] = c;
        }

        output_buffer[output_buffer_size] = '\0';
        fputs(output_buffer, output_file);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file(s).\n");
        return 1;
    }

    time_t now = time(NULL);
    srand(now);

    int key_length = strlen(ENCRYPTION_KEY);
    char encryption_key[key_length + 1];
    strcpy(encryption_key, ENCRYPTION_KEY);

    for (int i = 0; i < key_length; i++) {
        encryption_key[i] = encryption_key[i] ^ ((rand() % 26) + 'a');
    }

    encrypt_file(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully.\n");

    return 0;
}