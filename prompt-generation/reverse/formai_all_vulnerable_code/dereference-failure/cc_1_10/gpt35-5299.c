//FormAI DATASET v1.0 Category: File Encyptor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 50
#define MAX_DATA_SIZE 10000
#define XOR_KEY 0xA5

void xor_encrypt(unsigned char *data, unsigned int data_len, unsigned char *key, unsigned int key_len) {
    int i, j = 0;
    for (i = 0; i < data_len; i++) {
        data[i] ^= key[j++];
        if (j == key_len) j = 0;
    }
}

void encypt_file(char *file_name) {
    unsigned char key[] = { 0x12, 0x34, 0x56, 0x78 };
    FILE *fp = NULL;
    unsigned char data[MAX_DATA_SIZE];
    unsigned int data_len = 0;

    fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Error - cannot open file: %s\n", file_name);
        return;
    }

    fseek(fp, 0, SEEK_END);
    data_len = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if (data_len > MAX_DATA_SIZE) {
        printf("Error - file too big\n");
        fclose(fp);
        return;
    }

    fread(data, 1, data_len, fp);

    xor_encrypt(data, data_len, key, sizeof(key));

    fclose(fp);

    fp = fopen(file_name, "wb");
    fwrite(data, 1, data_len, fp);
    fclose(fp);
}

void decrypt_file(char *file_name) {
    encypt_file(file_name);
}

int main(int argc, char *argv[]) {
    char file_name[MAX_FILE_NAME_LEN];
    int option;

    if (argc < 2) {
        printf("Usage: %s <file_name> -e or -d\n", argv[0]);
        return -1;
    }

    strncpy(file_name, argv[1], MAX_FILE_NAME_LEN);
    if (argc < 3) {
        printf("Error - option (-e or -d) not specified\n");
        return -1;
    }

    option = strcmp(argv[2], "-e") == 0 ? 1 : strcmp(argv[2], "-d") == 0 ? 2 : 0;

    if (option == 0) {
        printf("Error - invalid option specified, use -e to encrypt and -d to decrypt\n");
        return -1;
    }

    if (option == 1) {
        encypt_file(file_name);
        printf("File encrypted successfully\n");
    } else if (option == 2) {
        decrypt_file(file_name);
        printf("File decrypted successfully\n");
    }

    return 0;
}