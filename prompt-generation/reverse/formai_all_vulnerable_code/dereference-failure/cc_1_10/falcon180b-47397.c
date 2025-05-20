//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 32
#define MAX_FILE_NAME_LEN 256

typedef struct {
    char key[MAX_KEY_LEN + 1];
    int encrypted;
} FILE_INFO;

int main(int argc, char *argv[]) {
    FILE_INFO file_info;
    char file_name[MAX_FILE_NAME_LEN + 1];
    FILE *file;
    char buffer[1024];
    int i, j;

    if(argc < 3) {
        printf("Usage: %s [encrypt/decrypt] [file_name]\n", argv[0]);
        return 1;
    }

    strcpy(file_name, argv[2]);

    if(strcmp(argv[1], "encrypt") == 0) {
        printf("Enter encryption key: ");
        scanf("%s", file_info.key);
        file_info.encrypted = 1;
    } else if(strcmp(argv[1], "decrypt") == 0) {
        printf("Enter decryption key: ");
        scanf("%s", file_info.key);
        file_info.encrypted = 0;
    } else {
        printf("Invalid operation.\n");
        return 1;
    }

    file = fopen(file_name, "rb+");
    if(file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    file_info.encrypted =!file_info.encrypted;
    fseek(file, 0, SEEK_SET);

    while((i = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for(j = 0; j < i; j++) {
            if(file_info.encrypted) {
                buffer[j] ^= file_info.key[j % MAX_KEY_LEN];
            } else {
                buffer[j] ^= file_info.key[j % MAX_KEY_LEN];
            }
        }
        fwrite(buffer, 1, i, file);
    }

    fclose(file);

    return 0;
}