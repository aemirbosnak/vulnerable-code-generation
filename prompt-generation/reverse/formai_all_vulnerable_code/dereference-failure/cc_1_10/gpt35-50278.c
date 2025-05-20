//FormAI DATASET v1.0 Category: File Encyptor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "cyberpunk2077"

void encrypt_file(char* filename) {
    FILE* fp_in = fopen(filename, "rb");
    if (fp_in == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    FILE* fp_out = fopen(strcat(filename, ".enc"), "wb");
    if (fp_out == NULL) {
        printf("Error creating encrypted file\n");
        return;
    }

    char ch, keych;
    int i = 0;
    while ((ch = fgetc(fp_in)) != EOF) {
        keych = KEY[i++ % strlen(KEY)];
        fputc(ch ^ keych, fp_out);
    }

    fclose(fp_in);
    fclose(fp_out);

    remove(filename);
}

void decrypt_file(char* filename) {
    FILE* fp_in = fopen(filename, "rb");
    if (fp_in == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    const char* extension = ".enc";
    int length = strlen(filename);
    if (length < strlen(extension) || strcmp(&filename[length - strlen(extension)], extension) != 0) {
        printf("Error: file is not encrypted\n");
        return;
    }

    FILE* fp_out = fopen(strncpy(&filename[length - strlen(extension)], "\0", 1), "wb");
    if (fp_out == NULL) {
        printf("Error creating decrypted file\n");
        return;
    }

    char ch, keych;
    int i = 0;
    while ((ch = fgetc(fp_in)) != EOF) {
        keych = KEY[i++ % strlen(KEY)];
        fputc(ch ^ keych, fp_out);
    }

    fclose(fp_in);
    fclose(fp_out);

    remove(filename);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: file_enc <operation> <filename>\n");
        printf("<operation> can be either \"enc\" or \"dec\"\n");
        return -1;
    }

    if (strcmp(argv[1], "enc") == 0) {
        encrypt_file(argv[2]);
        printf("File %s encrypted\n", argv[2]);
    } else if (strcmp(argv[1], "dec") == 0) {
        decrypt_file(argv[2]);
        printf("File %s decrypted\n", argv[2]);
    } else {
        printf("Invalid operation\n");
        return -1;
    }

    return 0;
}