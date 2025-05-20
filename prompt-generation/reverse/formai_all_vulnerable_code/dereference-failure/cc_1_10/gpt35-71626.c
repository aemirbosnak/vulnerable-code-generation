//FormAI DATASET v1.0 Category: File Encyptor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 25 //key for encryption

void encrypt(char *filename); //function to encrypt file
void decrypt(char *filename); //function to decrypt file

int main(int argc, char *argv[]) {
    if(argc != 3) { //checking if correct number of arguments are provided
        printf("Usage: %s [e/d] [filename]\n", argv[0]);
        exit(0);
    }
    if(strcmp(argv[1], "e") == 0) { //checking if user wants to encrypt
        encrypt(argv[2]);
        printf("Encryption Successful!\n");
    } else if(strcmp(argv[1], "d") == 0) { //checking if user wants to decrypt
        decrypt(argv[2]);
        printf("Decryption Successful!\n");
    } else { //if user enters invalid option
        printf("Invalid option! Usage: %s [e/d] [filename]\n", argv[0]);
        exit(0);
    }
    return 0;
}

void encrypt(char* filename) { //function implementation to encrypt file
    FILE *fp = fopen(filename, "rb+");
    if(fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(0);
    }
    char ch;
    while((ch = fgetc(fp)) != EOF) { //reading file character by character
        ch = (ch + KEY) % 256; //adding key to each character to encrypt
        fseek(fp, -1, SEEK_CUR); //moving file pointer back by 1 as we've read a character
        fputc(ch, fp); //writing encrypted character to file
    }
    fclose(fp);
}

void decrypt(char* filename) { //function implementation to decrypt file
    FILE *fp = fopen(filename, "rb+");
    if(fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(0);
    }
    char ch;
    while((ch = fgetc(fp)) != EOF) { //reading file character by character
        ch = (ch - KEY + 256) % 256; //subtracting key to each character to decrypt
        fseek(fp, -1, SEEK_CUR); //moving file pointer back by 1 as we've read a character
        fputc(ch, fp); //writing decrypted character to file
    }
    fclose(fp);
}