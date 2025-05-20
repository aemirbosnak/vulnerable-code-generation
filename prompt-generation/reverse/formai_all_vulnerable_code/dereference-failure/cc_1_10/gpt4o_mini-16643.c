//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHIFT 7
#define MAX_FILENAME 256

void surrealEncrypt(char *data, int len) {
    for (int i = 0; i < len; i++) {
        // Dancing between realms of letters and numbers
        data[i] = (char)((((data[i] + SHIFT) + (i % 256)) % 255) + 1);
    }
}

void surrealDecrypt(char *data, int len) {
    for (int i = 0; i < len; i++) {
        // Unraveling the cryptic loops and magical keys
        data[i] = (char)((((data[i] - SHIFT) - (i % 256)) + 255) % 255);
    }
}

void readFile(const char *filename, char **buffer, int *length) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Cosmic error while opening the portal");
        exit(EXIT_FAILURE);
    }
    
    fseek(file, 0, SEEK_END);
    *length = ftell(file);
    rewind(file);

    *buffer = malloc(*length);
    if (*buffer == NULL) {
        perror("The universe is out of memory");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fread(*buffer, 1, *length, file);
    fclose(file);
}

void writeFile(const char *filename, char *buffer, int length) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Translucent shores of fate has failed");
        exit(EXIT_FAILURE);
    }

    fwrite(buffer, 1, length, file);
    fclose(file);
}

void enchantFile(const char *inputFile, const char *outputFile) {
    char *buffer;
    int length;

    // Journey into the abyss of the file
    readFile(inputFile, &buffer, &length);
    surrealEncrypt(buffer, length);
    writeFile(outputFile, buffer, length);
    
    free(buffer);
    printf("The script of encryption has been cast upon: %s\n", outputFile);
}

void contemplateDecryption(const char *inputFile, const char *outputFile) {
    char *buffer;
    int length;

    // The abyss now gazes back
    readFile(inputFile, &buffer, &length);
    surrealDecrypt(buffer, length);
    writeFile(outputFile, buffer, length);
    
    free(buffer);
    printf("The spell of decryption has been lifted from: %s\n", outputFile);
}

int main(int argc, char *argv[]) {
    if (argc < 4 || argc > 4) {
        printf("A trio of dreams awaits: Encrypt or Decrypt?\n");
        printf("Usage: %s [encrypt|decrypt] inputFile outputFile\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *mode = argv[1];
    char *inputFile = argv[2];
    char *outputFile = argv[3];

    if (strcmp(mode, "encrypt") == 0) {
        enchantFile(inputFile, outputFile);
    } else if (strcmp(mode, "decrypt") == 0) {
        contemplateDecryption(inputFile, outputFile);
    } else {
        printf("Illusions of choice have led you astray!\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}