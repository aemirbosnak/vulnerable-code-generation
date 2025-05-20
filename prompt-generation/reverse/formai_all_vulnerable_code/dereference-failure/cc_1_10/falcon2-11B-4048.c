//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char key[16] = {0};
char file[256] = {0};
char encrypted_file[256] = {0};

void generate_key() {
    time_t t = time(NULL);
    srand(t);
    for (int i = 0; i < 16; i++) {
        key[i] = 'a' + rand() % 26;
    }
}

void encrypt_file(const char* file_path, const char* key_path) {
    FILE* fp = fopen(file_path, "rb");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    FILE* fk = fopen(key_path, "r");
    if (fk == NULL) {
        printf("Error: Unable to open key file.\n");
        fclose(fp);
        return;
    }

    char key[16] = {0};
    fscanf(fk, "%s", key);

    fclose(fk);

    char buffer[1024] = {0};
    while (fread(buffer, sizeof(char), 1024, fp) > 0) {
        for (int i = 0; i < 16; i++) {
            buffer[i] ^= key[i];
        }

        fwrite(buffer, sizeof(char), strlen(buffer), stdout);
    }

    fclose(fp);
}

void decrypt_file(const char* file_path, const char* key_path) {
    FILE* fp = fopen(file_path, "rb");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    FILE* fk = fopen(key_path, "r");
    if (fk == NULL) {
        printf("Error: Unable to open key file.\n");
        fclose(fp);
        return;
    }

    char key[16] = {0};
    fscanf(fk, "%s", key);

    fclose(fk);

    char buffer[1024] = {0};
    while (fread(buffer, sizeof(char), 1024, fp) > 0) {
        for (int i = 0; i < 16; i++) {
            buffer[i] ^= key[i];
        }

        fwrite(buffer, sizeof(char), strlen(buffer), stdout);
    }

    fclose(fp);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <file_path> <key_path>\n", argv[0]);
        return 1;
    }

    strcpy(file, argv[1]);
    strcpy(key, argv[2]);

    generate_key();

    encrypt_file(file, key);
    decrypt_file(file, key);

    printf("File encrypted and decrypted successfully!\n");

    return 0;
}