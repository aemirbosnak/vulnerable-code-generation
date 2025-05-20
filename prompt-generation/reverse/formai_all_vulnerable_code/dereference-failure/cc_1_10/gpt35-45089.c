//FormAI DATASET v1.0 Category: File Encyptor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void encrypt(char* file_name);
void decrypt(char* file_name);

int main(int argc, char** argv){
    if(argc != 3){
        printf("Usage: %s [file name] [action e/d]\n", argv[0]);
        return 0;
    }
    if(strcmp(argv[2], "e") == 0){
        encrypt(argv[1]);
    }
    else if(strcmp(argv[2], "d") == 0){
        decrypt(argv[1]);
    }
    else{
        printf("Invalid action! Only e or d is allowed.\n");
    }
    return 0;
}

void encrypt(char* file_name){
    srand(time(NULL));
    FILE* file = fopen(file_name, "rb");
    if(!file){
        printf("File does not exist!\n");
        return;
    }
    char new_file_name[strlen(file_name)+9];
    sprintf(new_file_name, "%d_encrypted", rand()*rand());
    FILE* new_file = fopen(new_file_name, "wb");
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    char buffer[file_size];
    fread(buffer, 1, file_size, file);
    for(int i = 0; i < file_size; i++){
        buffer[i] = buffer[i] ^ rand()%256;
    }
    fwrite(buffer, 1, file_size, new_file);
    fclose(file);
    fclose(new_file);
    printf("Encryption completed! Encrypted file name: %s\n", new_file_name);
}

void decrypt(char* file_name){
    FILE* file = fopen(file_name, "rb");
    if(!file){
        printf("File does not exist!\n");
        return;
    }
    char buffer[10];
    fread(buffer, 1, 10, file);
    if(strcmp(buffer, "encrypted\n") != 0){
        printf("Invalid encrypted file format!\n");
        return;
    }
    char new_file_name[strlen(file_name)];
    strcpy(new_file_name, file_name);
    new_file_name[strlen(file_name)-10] = '\0';
    FILE* new_file = fopen(new_file_name, "wb");
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    char buffer2[file_size-10];
    fread(buffer2, 1, file_size-10, file);
    for(int i = 0; i < file_size-10; i++){
        buffer2[i] = buffer2[i] ^ rand()%256;
    }
    fwrite(buffer2, 1, file_size-10, new_file);
    fclose(file);
    fclose(new_file);
    printf("Decryption completed! Decrypted file name: %s\n", new_file_name);
}