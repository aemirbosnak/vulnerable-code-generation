//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 1024
#define BUFFER_SIZE 1024

/* Function prototypes */
int read_file(char*, char*, int);
int write_file(char*, char*, int);
void encrypt(char*, char*);
void decrypt(char*, char*);

int main(int argc, char ** argv){

    char key[MAX_KEY_SIZE];
    char buffer[BUFFER_SIZE];

    // Step 1: Read the encryption or decryption key
    printf("Enter encryption key: ");
    fgets(key, MAX_KEY_SIZE, stdin);

    // Step 2: Read the input file
    printf("Enter input file name: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    strtok(buffer, "\n");
    char * input_file = buffer;
    int input_size = read_file(input_file, buffer, BUFFER_SIZE);

    // Step 3: Encrypt or decrypt the input file
    printf("Enter output file name: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    strtok(buffer, "\n");
    char * output_file = buffer;

    if(strcmp(argv[1], "encrypt") == 0){
        encrypt(buffer, key);
    }
    else if(strcmp(argv[1], "decrypt") == 0){
        decrypt(buffer, key);
    }
    else{
        printf("Invalid argument. Use 'encrypt' or 'decrypt' as argument.\n");
        exit(-1);
    }

    // Step 4: Write the encrypted or decrypted message to output file
    int output_size = strlen(buffer);
    write_file(output_file, buffer, output_size);

    return 0;
}

/**
 * Reads the contents of a file and stores them in a buffer.
 * Returns the size of the file.
 */
int read_file(char * filename, char * buffer, int buffer_size){

    FILE * fp;
    int file_size;

    fp = fopen(filename, "r");
    if(fp == NULL){
        perror("Error opening file.");
        exit(-1);
    }

    fseek(fp, 0L, SEEK_END);
    file_size = ftell(fp);
    
    if(file_size > buffer_size){
        printf("File too large.\n");
        fclose(fp);
        exit(-1);
    }

    fseek(fp, 0L, SEEK_SET);
    fread(buffer, file_size, 1, fp);
    fclose(fp);

    return file_size;
}

/**
 * Writes the contents of a buffer to a file.
 */
int write_file(char * filename, char * buffer, int buffer_size){

    FILE * fp;

    fp = fopen(filename, "w");
    if(fp == NULL){
        perror("Error opening file.");
        exit(-1);
    }

    fwrite(buffer, buffer_size, 1, fp);
    fclose(fp);

    return buffer_size;
}

/**
 * Encrypts the message using the given key.
 */
void encrypt(char * message, char * key){

    int message_length = strlen(message);
    int key_length = strlen(key);

    int i, j;
    for(i = 0, j = 0; i < message_length; ++i, ++j){
        if(j == key_length){
            j = 0;
        }
        message[i] = message[i] ^ key[j];
    }

}

/**
 * Decrypts the message using the given key.
 */
void decrypt(char * message, char * key){

    int message_length = strlen(message);
    int key_length = strlen(key);

    int i, j;
    for(i = 0, j = 0; i < message_length; ++i, ++j){
        if(j == key_length){
            j = 0;
        }
        message[i] = message[i] ^ key[j];
    }

}