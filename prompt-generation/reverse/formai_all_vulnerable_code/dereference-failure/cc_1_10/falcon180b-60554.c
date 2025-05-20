//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 10
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    int key_length;
    FILE *file;
} file_encryptor_t;

void generate_key(char *key, int key_length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?";
    for (int i = 0; i < key_length; i++) {
        key[i] = charset[rand() % strlen(charset)];
    }
    key[key_length] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <key_length> <file_name>\n", argv[0]);
        return 1;
    }
    int key_length = atoi(argv[1]);
    if (key_length < 1 || key_length > MAX_KEY_LENGTH) {
        printf("Invalid key length.\n");
        return 1;
    }
    char *file_name = argv[2];
    if (strlen(file_name) >= MAX_FILE_NAME_LENGTH) {
        printf("File name too long.\n");
        return 1;
    }
    file_encryptor_t encryptor;
    encryptor.key[0] = '\0';
    generate_key(encryptor.key, key_length);
    encryptor.key_length = key_length;
    encryptor.file = fopen(file_name, "rb+");
    if (encryptor.file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }
    printf("Enter the key to encrypt the file: ");
    char input_key[MAX_KEY_LENGTH];
    scanf("%s", input_key);
    if (strcmp(encryptor.key, input_key)!= 0) {
        printf("Invalid key.\n");
        fclose(encryptor.file);
        return 1;
    }
    fseek(encryptor.file, 0, SEEK_END);
    int file_size = ftell(encryptor.file);
    fseek(encryptor.file, 0, SEEK_SET);
    char buffer[1024];
    int bytes_read;
    for (int i = 0; i < file_size; i += bytes_read) {
        bytes_read = fread(buffer, 1, sizeof(buffer), encryptor.file);
        for (int j = 0; j < bytes_read; j++) {
            buffer[j] ^= encryptor.key[i % encryptor.key_length];
        }
        fwrite(buffer, 1, bytes_read, encryptor.file);
    }
    fclose(encryptor.file);
    printf("File encrypted successfully.\n");
    return 0;
}