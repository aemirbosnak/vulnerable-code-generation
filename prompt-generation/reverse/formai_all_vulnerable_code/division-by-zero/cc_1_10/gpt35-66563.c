//FormAI DATASET v1.0 Category: File Encyptor ; Style: protected
/*
  This program demonstrates a simple C file encryptor using 
  XOR encryption algorithm. The program prompts the user to input 
  the name of the file to encrypt, and the key to encrypt the file.
  The program then encrypts the file using the key and saves the
  encrypted file with the name "enc_file" in the same directory.

  Author: AI Bot
  Date: 2021-08-20
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encrypt_file(const char* filename, const char* key);

int main(void) {
    char filename[256], key[256];
    
    printf("*** File Encryptor ***\n\n");
    printf("Enter the name of the file to encrypt: ");
    scanf("%255s", filename);
    
    printf("Enter the encryption key: ");
    scanf("%255s", key);
    
    encrypt_file(filename, key);
    
    printf("\nFile has been encrypted successfully!\n");
    printf("Encrypted file saved as 'enc_file'\n");
    
    return 0;
}

void encrypt_file(const char* filename, const char* key) {
    FILE* fp_in = NULL;
    FILE* fp_out = NULL;
    char buffer[BUFFER_SIZE];
    int length = strlen(key);
    int i = 0;
    
    fp_in = fopen(filename, "rb");
    if (fp_in == NULL) {
        printf("Error: Cannot open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }
    
    fp_out = fopen("enc_file", "wb");
    if (fp_out == NULL) {
        printf("Error: Cannot create encrypted file.\n");
        fclose(fp_in);
        exit(EXIT_FAILURE);
    }

    while (!feof(fp_in)) {
        int bytes_read = fread(buffer, 1, BUFFER_SIZE, fp_in);
        for (int j = 0; j < bytes_read; j++) {
            buffer[j] ^= key[i % length];
            i++;
        }
        fwrite(buffer, 1, bytes_read, fp_out);
    }
    
    fclose(fp_in);
    fclose(fp_out);
}