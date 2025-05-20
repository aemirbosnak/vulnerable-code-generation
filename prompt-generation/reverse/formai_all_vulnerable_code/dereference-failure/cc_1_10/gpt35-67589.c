//FormAI DATASET v1.0 Category: File Encyptor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void surreal_encryption(char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        return;
    }

    char* extension = strrchr(filename, '.');
    if (extension == NULL) {
        printf("Error: file has no extension\n");
        fclose(file);
        return;
    }

    int extension_length = strlen(extension);
    char* encrypted_filename = (char*)malloc(strlen(filename) + extension_length + 1);

    if (encrypted_filename == NULL) {
        printf("Error: out of memory\n");
        fclose(file);
        return;
    }

    strcpy(encrypted_filename, filename);
    encrypted_filename[strlen(filename) - extension_length] = '\0';

    strcat(encrypted_filename, "_surreal");
    strcat(encrypted_filename, extension);

    FILE* encrypted_file = fopen(encrypted_filename, "wb");

    if (encrypted_file == NULL) {
        printf("Error: could not create encrypted file\n");
        fclose(file);
        free(encrypted_filename);
        return;
    }

    int byte;
    while ((byte = fgetc(file)) != EOF) {
        byte = ~byte;
        fputc(byte, encrypted_file);
        byte = rand() % 256;
        fputc(byte, encrypted_file);
    }

    fclose(file);
    fclose(encrypted_file);
    free(encrypted_filename);

    printf("Encryption complete! Encrypted file saved as '%s'\n", encrypted_filename);
}

int main() {
    char filename[256];

    printf("Enter filename to encrypt: ");
    fgets(filename, 256, stdin);

    filename[strcspn(filename, "\n")] = '\0';

    surreal_encryption(filename);

    return 0;
}