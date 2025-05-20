//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 500

int main() {
    char key[MAX_KEY_LENGTH];
    char file_name[MAX_FILE_NAME_LENGTH];
    FILE *file;
    int file_size;
    unsigned char *file_data;
    int i, j;

    printf("Enter the name of the file to be encrypted: ");
    scanf("%s", file_name);

    printf("Enter the encryption key: ");
    scanf("%s", key);

    file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    file_data = (unsigned char *)malloc(file_size);
    if (file_data == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    fread(file_data, file_size, 1, file);
    fclose(file);

    for (i = 0; i < file_size; i++) {
        file_data[i] ^= (unsigned char)key[i % strlen(key)];
    }

    printf("Enter the name of the encrypted file: ");
    scanf("%s", file_name);

    file = fopen(file_name, "wb");
    if (file == NULL) {
        printf("Error: File creation failed.\n");
        exit(1);
    }

    fwrite(file_data, file_size, 1, file);
    fclose(file);

    printf("File encrypted successfully.\n");
    free(file_data);

    return 0;
}