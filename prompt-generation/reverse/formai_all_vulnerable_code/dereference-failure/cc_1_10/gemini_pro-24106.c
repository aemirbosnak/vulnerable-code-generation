//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "my_secret_key"

void encrypt(char *filename) {
    FILE *fin, *fout;
    char buffer[1024];
    int i, keylen;
    
    fin = fopen(filename, "rb");
    if (fin == NULL) {
        perror("Error opening input file");
        exit(1);
    }
    
    fout = fopen("encrypted.bin", "wb");
    if (fout == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    keylen = strlen(KEY);
    
    while (fgets(buffer, sizeof(buffer), fin)) {
        for (i = 0; i < strlen(buffer); i++) {
            buffer[i] ^= KEY[i % keylen];
        }
        
        fwrite(buffer, strlen(buffer), 1, fout);
    }
    
    fclose(fin);
    fclose(fout);
}

void decrypt(char *filename) {
    FILE *fin, *fout;
    char buffer[1024];
    int i, keylen;
    
    fin = fopen(filename, "rb");
    if (fin == NULL) {
        perror("Error opening input file");
        exit(1);
    }
    
    fout = fopen("decrypted.txt", "wb");
    if (fout == NULL) {
        perror("Error opening output file");
        exit(1);
    }
    
    keylen = strlen(KEY);
    
    while (fgets(buffer, sizeof(buffer), fin)) {
        for (i = 0; i < strlen(buffer); i++) {
            buffer[i] ^= KEY[i % keylen];
        }
        
        fwrite(buffer, strlen(buffer), 1, fout);
    }
    
    fclose(fin);
    fclose(fout);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <encrypt/decrypt> <filename>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt(argv[2]);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt(argv[2]);
    } else {
        printf("Invalid operation: %s\n", argv[1]);
        return 1;
    }
    
    return 0;
}