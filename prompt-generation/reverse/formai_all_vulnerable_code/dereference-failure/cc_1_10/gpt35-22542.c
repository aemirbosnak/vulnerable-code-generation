//FormAI DATASET v1.0 Category: File Encyptor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char *str) {
    char *result = (char*) malloc(sizeof(char) * strlen(str));
    for(int i=0; str[i] != '\0'; i++) {
        result[i] = str[i] + 3;
    }
    return result;
}

void decrypt(char *str) {
    for(int i=0; str[i] != '\0'; i++) {
        str[i] = str[i] - 3;
    }
}

int main(int argc, char **argv) {
    if(argc != 2 || strlen(argv[1]) <= 0) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "rb");
    if(fp == NULL) {
        fprintf(stderr, "Error: Unable to open file '%s'\n", argv[1]);
        return EXIT_FAILURE;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *buffer = (char*) malloc(size + 1);
    if(fread(buffer, size, 1, fp) != 1) {
        fprintf(stderr, "Error: Unable to read file '%s'\n", argv[1]);
        return EXIT_FAILURE;
    }

    fclose(fp);

    char *encrypted = encrypt(buffer);
    free(buffer);

    strcat(argv[1], ".crypt");
    fp = fopen(argv[1], "wb");
    if(fp == NULL) {
        fprintf(stderr, "Error: Unable to open file '%s'\n", argv[1]);
        return EXIT_FAILURE;
    }

    if(fwrite(encrypted, strlen(encrypted), 1, fp) != 1) {
        fprintf(stderr, "Error: Unable to write to file '%s'\n", argv[1]);
        return EXIT_FAILURE;
    }

    fclose(fp);
    free(encrypted);

    printf("Successfully encrypted file '%s'\n", argv[1]);

    return EXIT_SUCCESS;
}