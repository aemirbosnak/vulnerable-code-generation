//FormAI DATASET v1.0 Category: File Encyptor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encrypt(char *file_name, char *key){
    FILE *file_input, *file_output;
    int key_length, i = 0;
    char buffer[BUFFER_SIZE], output_file[BUFFER_SIZE];

    key_length = strlen(key);

    sprintf(output_file,"%s.enc", file_name);

    file_input = fopen(file_name, "rb");
    if (file_input == NULL){
        printf("Error: Unable to open file %s\n", file_name);
        return;
    }

    file_output = fopen(output_file, "wb");
    if (file_output == NULL){
        printf("Error: Unable to open file %s\n", output_file);
        fclose(file_input);
        return;
    }

    while(!feof(file_input)){
        size_t read = fread(buffer, 1, BUFFER_SIZE, file_input);

        for(i = 0; i < read; i++){
            buffer[i] = buffer[i] ^ key[i % key_length];
        }

        fwrite(buffer, 1, read, file_output);
    }

    fclose(file_input);
    fclose(file_output);

    printf("Encryption completed successfully!\n");
    printf("Encrypted file created: %s\n", output_file);
}

void decrypt(char *file_name, char *key){
    FILE *file_input, *file_output;
    int key_length, i = 0;
    char buffer[BUFFER_SIZE], output_file[BUFFER_SIZE];

    key_length = strlen(key);

    sprintf(output_file,"%s.dec", file_name);

    file_input = fopen(file_name, "rb");
    if (file_input == NULL){
        printf("Error: Unable to open file %s\n", file_name);
        return;
    }

    file_output = fopen(output_file, "wb");
    if (file_output == NULL){
        printf("Error: Unable to open file %s\n", output_file);
        fclose(file_input);
        return;
    }

    while(!feof(file_input)){
        size_t read = fread(buffer, 1, BUFFER_SIZE, file_input);

        for(i = 0; i < read; i++){
            buffer[i] = buffer[i] ^ key[i % key_length];
        }

        fwrite(buffer, 1, read, file_output);
    }

    fclose(file_input);
    fclose(file_output);

    printf("Decryption completed successfully!\n");
    printf("Decrypted file created: %s\n", output_file);
}

int main(int argc, char **argv) {
    if(argc != 4){
        printf("Usage: %s <file_name> <key> <mode>\n", argv[0]);
        printf("Mode can only be 'e' (encrypt) or 'd' (decrypt)\n");
    }
    else if(strcmp(argv[3], "e") == 0){
        encrypt(argv[1], argv[2]);
    }
    else if(strcmp(argv[3], "d") == 0){
        decrypt(argv[1], argv[2]);
    }
    else {
        printf("Invalid mode specified.\n");
    }

    return 0;
}