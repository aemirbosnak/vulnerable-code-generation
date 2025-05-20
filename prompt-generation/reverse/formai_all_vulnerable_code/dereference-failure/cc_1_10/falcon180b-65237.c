//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define KEY "MySecretKey"
#define BLOCK_SIZE 64

void encrypt(FILE *input, FILE *output) {
    char buffer[BLOCK_SIZE + 1];
    char key[strlen(KEY)];
    strcpy(key, KEY);

    while (fgets(buffer, BLOCK_SIZE, input)!= NULL) {
        for (int i = 0; i < strlen(buffer); i++) {
            buffer[i] = toupper(buffer[i]) ^ key[i % strlen(KEY)];
        }
        fputs(buffer, output);
    }
}

void decrypt(FILE *input, FILE *output) {
    char buffer[BLOCK_SIZE + 1];
    char key[strlen(KEY)];
    strcpy(key, KEY);

    while (fgets(buffer, BLOCK_SIZE, input)!= NULL) {
        for (int i = 0; i < strlen(buffer); i++) {
            buffer[i] = toupper(buffer[i]) ^ key[i % strlen(KEY)];
        }
        fputs(buffer, output);
    }
}

int main() {
    FILE *input, *output;
    char filename[100];
    char choice;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    input = fopen(filename, "r");
    if (input == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    output = fopen("encrypted.txt", "w");
    if (output == NULL) {
        printf("Error creating output file.\n");
        exit(1);
    }

    printf("Do you want to encrypt or decrypt the file? (E/D): ");
    scanf("%c", &choice);

    if (choice == 'E' || choice == 'e') {
        encrypt(input, output);
        printf("File encrypted successfully.\n");
    } else if (choice == 'D' || choice == 'd') {
        decrypt(input, output);
        printf("File decrypted successfully.\n");
    } else {
        printf("Invalid choice.\n");
        exit(1);
    }

    fclose(input);
    fclose(output);

    return 0;
}