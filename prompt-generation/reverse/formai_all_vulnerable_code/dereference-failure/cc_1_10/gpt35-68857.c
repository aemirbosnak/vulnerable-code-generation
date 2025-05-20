//FormAI DATASET v1.0 Category: File Encyptor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(FILE *f, int key) {
    char c;
    int pos = 0;

    while ((c = fgetc(f)) != EOF) {
        char encrypted = c ^ (key + pos);
        fseek(f, pos, SEEK_SET);
        fputc(encrypted, f);
        pos++;
    }
}

void decrypt(FILE *f, int key) {
    char c;
    int pos = 0;

    while ((c = fgetc(f)) != EOF) {
        char decrypted = c ^ (key + pos);
        fseek(f, pos, SEEK_SET);
        fputc(decrypted, f);
        pos++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <encrypt|decrypt> <filename> <key>\n", argv[0]);
        exit(1);
    }

    char *mode = argv[1];
    char *filename = argv[2];
    int key = atoi(argv[3]);

    FILE *f = fopen(filename, "r+");
    if (f == NULL) {
        printf("Error: could not open file \"%s\".\n", filename);
        exit(1);
    }

    if (strcmp(mode, "encrypt") == 0) {
        encrypt(f, key);
        printf("File \"%s\" encrypted with key %d.\n", filename, key);
    } else if (strcmp(mode, "decrypt") == 0) {
        decrypt(f, key);
        printf("File \"%s\" decrypted with key %d.\n", filename, key);
    } else {
        printf("Invalid mode \"%s\". Must be \"encrypt\" or \"decrypt\".\n", mode);
        exit(1);
    }

    fclose(f);
    return 0;
}