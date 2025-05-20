//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define _CRYPTIC_ENCRYPTOR_

#ifdef _CRYPTIC_ENCRYPTOR_

char key[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890!@#$%^&*()_+-=<>?";

void encrypt(FILE *input, FILE *output) {
    char c, d;
    int i;

    while ((c = getc(input)) != EOF) {
        for (i = 0; i < strlen(key); i++) {
            if (key[i] == c) {
                d = key[(i + 1) % strlen(key)];
                putc(d, output);
                break;
            }
        }

        if (i == strlen(key)) putc(c, output);
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");

    if (input == NULL || output == NULL) {
        perror("Error opening file(s)");
        return 1;
    }

    encrypt(input, output);
    fclose(input);
    fclose(output);

    return 0;
}

#endif // _CRYPTIC_ENCRYPTOR_