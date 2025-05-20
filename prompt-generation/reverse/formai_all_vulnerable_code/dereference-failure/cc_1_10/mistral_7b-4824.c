//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 256
#define BLOCK_SIZE 16

void xor_key(unsigned char *plaintext, unsigned char *key, int length) {
    int i;
    for (i = 0; i < length; i++)
        plaintext[i] ^= key[i % KEY_SIZE];
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char filename[100], password[100];
    char *file_content;
    int file_size, i;

    if (argc != 3) {
        printf("Usage: %s <filename> <password>\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);
    strcpy(password, argv[2]);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    file_content = (char *)malloc(file_size);
    rewind(fp);

    fread(file_content, 1, file_size, fp);
    fclose(fp);

    unsigned char key[KEY_SIZE];
    for (i = 0; i < strlen(password); i++)
        key[i] = password[i];

    xor_key(file_content, key, file_size);

    fp = fopen("encrypted.bin", "wb");
    fwrite(file_content, 1, file_size, fp);
    fclose(fp);

    free(file_content);

    printf("File encrypted successfully!\n");

    return 0;
}