//FormAI DATASET v1.0 Category: File Encyptor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The game is afoot!
int main(){

    // Open the file to be encrypted
    FILE *fileToEncrypt = fopen("secret_file.txt", "rb");

    // Error handling
    if(fileToEncrypt == NULL){
        printf("Elementary, my dear Watson. The file cannot be found\n");
        return 1;
    }

    // Open the file to write the encrypted information
    FILE *encryptedFile = fopen("encrypted_file.txt", "wb");

    // Error handling
    if(encryptedFile == NULL){
        printf("The game is up. The encrypted file could not be created\n");
        return 1;
    }

    // Secret key for encryption
    char secretKey[] = "BakerStreet221B";

    // Encryption process
    int keyIndex = 0;
    char ch;
    while((ch = fgetc(fileToEncrypt)) != EOF){
        ch ^= secretKey[keyIndex];
        fwrite(&ch, sizeof(char), 1, encryptedFile);
        keyIndex++;

        // Restart the keyIndex when it is equal to the size of the secret key
        if(keyIndex == strlen(secretKey)){
            keyIndex = 0;
        }
    }

    // Close the files
    fclose(fileToEncrypt);
    fclose(encryptedFile);

    // Success!
    printf("Elementary, my dear Watson. The file has been encrypted\n");

    return 0;
}