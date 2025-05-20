//FormAI DATASET v1.0 Category: File Encyptor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 0x41

void encrypt(char* file_path);

int main(int argc, char** argv) {
    if(argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return -1;
    }

    encrypt(argv[1]);

    return 0;
}

void encrypt(char* file_path) {
    FILE* file = fopen(file_path, "rb");
    if(file == NULL) {
        printf("File not found!\n");
        return;
    }

    // Get file size 
    fseek(file , 0 , SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Read file contents into buffer
    char* buffer = (char*) malloc(file_size * sizeof(char));
    fread(buffer, 1, file_size, file);

    // Encrypt buffer
    for(int i = 0; i < file_size; i++) {
        buffer[i] ^= KEY;
    }

    fclose(file);

    // Write encrypted buffer to new file
    char* encrypted_file_path = malloc((strlen(file_path) + 5) * sizeof(char));
    strcpy(encrypted_file_path, file_path);
    strcat(encrypted_file_path, ".enc");
    FILE* encrypted_file = fopen(encrypted_file_path, "wb");
    fwrite(buffer, 1, file_size, encrypted_file);
    fclose(encrypted_file);

    printf("File encrypted successfully!\n");

    free(buffer);
    free(encrypted_file_path);
}