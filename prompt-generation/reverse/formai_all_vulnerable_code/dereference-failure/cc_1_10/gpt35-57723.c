//FormAI DATASET v1.0 Category: File Encyptor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptFile(FILE *input, FILE *output, char *key) {
    char ch;
    int i = 0; // Counter for key string
    
    // Loop through each character of file
    while((ch = fgetc(input)) != EOF) {
        fputc(ch ^ key[i], output); // XOR with key character and write to output
        i++; // Move to next character in key
        
        // Reset counter to 0 if end of key is reached
        if(key[i] == '\0') {
            i = 0;
        }
    }
}

int main() {
    // Declare file pointers and key string
    FILE *inputFile, *encryptedFile;
    char key[20];
    
    // Get file name and key from user
    printf("Enter name of file to encrypt: ");
    char fileName[50];
    scanf("%s", fileName);
    
    printf("Enter key for encryption: ");
    scanf("%s", key);
    
    // Open input file in read mode and check for errors
    inputFile = fopen(fileName, "r");
    if(inputFile == NULL) {
        printf("Error opening file!");
        exit(1);
    }
    
    // Create new encrypted file in write mode and check for errors
    encryptedFile = fopen("encrypted.bin", "wb");
    if(encryptedFile == NULL) {
        printf("Error creating encrypted file!");
        exit(1);
    }
    
    // Call function to encrypt file
    encryptFile(inputFile, encryptedFile, key);
    
    // Close file pointers
    fclose(inputFile);
    fclose(encryptedFile);
    
    printf("File encrypted successfully!");
    return 0;
}