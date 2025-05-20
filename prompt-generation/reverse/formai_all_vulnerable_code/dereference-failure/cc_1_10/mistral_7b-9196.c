//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY 26
#define MAX_LINE 1000

void encryptChar(char *str, int key);
void readFile(char *filename, char *encryptedFilename, int key);

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <key>\n", argv[0]);
        return 1;
    }

    readFile(argv[1], argv[2], atoi(argv[3]));

    return 0;
}

void encryptChar(char *str, int key) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            if (isupper(str[i])) {
                str[i] = (char)(((int)str[i] + key - 65) % 26 + 65);
            } else {
                str[i] = (char)(((int)str[i] + key - 97) % 26 + 97);
            }
        }
    }
}

void readFile(char *filename, char *encryptedFilename, int key) {
    FILE *input = fopen(filename, "r");
    FILE *output = fopen(encryptedFilename, "w");

    if (input == NULL || output == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }

    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, input)) {
        encryptChar(line, key);
        fputs(line, output);
    }

    fclose(input);
    fclose(output);
}