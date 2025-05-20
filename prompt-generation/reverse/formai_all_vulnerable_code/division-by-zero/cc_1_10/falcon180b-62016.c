//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

char* encrypt_file(char* filename, char* key) {
    FILE* input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    FILE* output_file = fopen("encrypted.txt", "w");
    if (output_file == NULL) {
        printf("Error: Unable to create file encrypted.txt\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    char encrypted_line[MAX_LINE_LENGTH];
    int key_index = 0;

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        // Encrypt the line using the key
        for (int i = 0; line[i]!= '\0'; i++) {
            if (isalpha(line[i])) {
                encrypted_line[i] = line[i] + key_index;
                if (encrypted_line[i] > 'z') {
                    encrypted_line[i] = encrypted_line[i] - 26;
                } else if (encrypted_line[i] < 'a') {
                    encrypted_line[i] = encrypted_line[i] + 26;
                }
            } else {
                encrypted_line[i] = line[i];
            }
        }

        // Write the encrypted line to the output file
        fputs(encrypted_line, output_file);

        // Increment the key index
        key_index = (key_index + 1) % strlen(key);
    }

    fclose(input_file);
    fclose(output_file);

    return encrypted_line;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <filename> <key>\n", argv[0]);
        exit(1);
    }

    char* filename = argv[1];
    char* key = argv[2];

    char* encrypted_file = encrypt_file(filename, key);

    printf("File encrypted with key '%s'\n", key);
    printf("Encrypted content:\n%s", encrypted_file);

    return 0;
}