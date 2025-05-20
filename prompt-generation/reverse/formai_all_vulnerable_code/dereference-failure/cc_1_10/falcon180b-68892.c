//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000
#define KEY_SIZE 16

char input_file[100];
char output_file[100];
char key[KEY_SIZE+1];

void generate_key(char *key) {
    int i;

    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }

    key[KEY_SIZE] = '\0';
}

void encrypt_file(FILE *input_fp, FILE *output_fp, char *key) {
    int ch, i = 0;

    while ((ch = fgetc(input_fp))!= EOF) {
        if (isalpha(ch)) {
            ch = toupper(ch) - 'A' + 1;
            ch = (ch + i) % 26 + 'A';
            fprintf(output_fp, "%c", ch);
        } else {
            fprintf(output_fp, "%c", ch);
        }

        i = (i + 1) % KEY_SIZE;
    }
}

int main() {
    printf("Enter the name of the file to encrypt: ");
    scanf("%s", input_file);

    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    printf("Enter the encryption key (16 characters): ");
    scanf("%s", key);

    FILE *input_fp = fopen(input_file, "rb");
    FILE *output_fp = fopen(output_file, "wb");

    if (input_fp == NULL || output_fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    generate_key(key);

    encrypt_file(input_fp, output_fp, key);

    fclose(input_fp);
    fclose(output_fp);

    printf("File encrypted successfully.\n");

    return 0;
}