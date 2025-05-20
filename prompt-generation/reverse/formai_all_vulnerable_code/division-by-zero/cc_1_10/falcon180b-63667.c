//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_FILE_LENGTH 1000000

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage:./encryptor <input_file> <output_file>\n");
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    char key[MAX_KEY_LENGTH];
    printf("Enter encryption key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    key[strcspn(key, "\n")] = '\0';

    char buffer[MAX_FILE_LENGTH];
    int buffer_length = 0;

    while ((buffer_length = fread(buffer, 1, MAX_FILE_LENGTH, input_file)) > 0) {
        for (int i = 0; i < buffer_length; i++) {
            char c = tolower(buffer[i]);
            if (isalpha(c)) {
                c = (c - 97 + (int)key[i % strlen(key)]) % 26 + 97;
            }
            fprintf(output_file, "%c", c);
        }
    }

    fclose(input_file);
    fclose(output_file);

    printf("Encryption completed successfully.\n");
    return 0;
}