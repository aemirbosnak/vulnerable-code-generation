//FormAI DATASET v1.0 Category: File Encyptor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

void encrypt_file(char* filename);
void decrypt_file(char* filename);

int main(int argc, char* argv[]){
    if(argc < 3 || (strcmp(argv[1], "-e") != 0 && strcmp(argv[1], "-d") != 0)){
        printf("Invalid arguments\n");
        printf("Usage: %s -e/-d filename\n", argv[0]);
        return 0;
    }
    if(strcmp(argv[1], "-e") == 0)
        encrypt_file(argv[2]);
    else if(strcmp(argv[1], "-d") == 0)
        decrypt_file(argv[2]);
    return 0;
}

void encrypt_file(char* filename){
    char output_filename[100];
    sprintf(output_filename, "encrypted_%s", filename);
    FILE* input_file = fopen(filename, "rb");
    if(input_file == NULL){
        printf("File not found\n");
        return;
    }
    FILE* output_file = fopen(output_filename, "wb");
    char key = 'a';
    char buffer[MAX_FILE_SIZE];
    int k = 0;
    while(!feof(input_file)){
        char c = fgetc(input_file);
        if(c != EOF){
            if(k % 10 == 0)
                key++;
            char encrypted_char = c ^ key;
            buffer[k] = encrypted_char;
            k++;
            fputc(encrypted_char, output_file);
        }
    }
    fclose(input_file);
    fclose(output_file);
    printf("File %s encrypted successfully. Encrypted file saved as %s\n", filename, output_filename);
}

void decrypt_file(char* filename){
    char output_filename[100];
    sprintf(output_filename, "decrypted_%s", filename);
    FILE* input_file = fopen(filename, "rb");
    if(input_file == NULL){
        printf("File not found\n");
        return;
    }
    FILE* output_file = fopen(output_filename, "wb");
    char key = 'a';
    char buffer[MAX_FILE_SIZE];
    int k = 0;
    while(!feof(input_file)){
        char c = fgetc(input_file);
        if(c != EOF){
            if(k % 10 == 0)
                key++;
            char decrypted_char = c ^ key;
            buffer[k] = decrypted_char;
            k++;
            fputc(decrypted_char, output_file);
        }
    }
    fclose(input_file);
    fclose(output_file);
    printf("File %s decrypted successfully. Decrypted file saved as %s\n", filename, output_filename);
}