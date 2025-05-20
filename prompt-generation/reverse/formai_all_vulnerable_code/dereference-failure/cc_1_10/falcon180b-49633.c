//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* input_file, char* output_file, char* key) {
    FILE* input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    FILE* output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error opening output file.\n");
        fclose(input);
        exit(1);
    }

    char buffer[1024];
    int key_length = strlen(key);

    while (fgets(buffer, sizeof(buffer), input)!= NULL) {
        int buffer_length = strlen(buffer);
        for (int i = 0; i < buffer_length; i++) {
            char c = buffer[i];
            if (isalpha(c)) {
                c = (c - 'a' + key_length) % 26 + 'a';
            } else if (isdigit(c)) {
                c = (c - '0' + key_length) % 10 + '0';
            }
            fputc(c, output);
        }
        fputc('\n', output);
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        return 1;
    }

    encrypt(argv[1], argv[2], argv[3]);

    printf("File encrypted successfully!\n");
    return 0;
}