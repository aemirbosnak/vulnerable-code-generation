//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: romantic
#include <stdio.h>
#include <string.h>

#define ROTATION 3 // the number of rotations in the Caesar cipher

char* encrypt(char* plaintext)
{
    int i;
    int length = strlen(plaintext);
    char* ciphertext = (char*)malloc(length + 1);
    
    for(i = 0; i < length; i++) 
    {
        if(plaintext[i] >= 'a' && plaintext[i] <= 'z')
            ciphertext[i] = 'a' + (plaintext[i] - 'a' + ROTATION) % 26 ;
        else if(plaintext[i] >= 'A' && plaintext[i] <= 'Z')
            ciphertext[i] = 'A' + (plaintext[i] - 'A' + ROTATION) % 26 ;
        else 
            ciphertext[i] = plaintext[i];
    }

    ciphertext[length] = '\0';

    return ciphertext;
}

char* decrypt(char* ciphertext)
{
    int i;
    int length = strlen(ciphertext);
    char* plaintext = (char*)malloc(length + 1);
    
    for(i = 0; i < length; i++) 
    {
        if(ciphertext[i] >= 'a' && ciphertext[i] <= 'z')
            plaintext[i] = 'a' + (ciphertext[i] - 'a' + 26 - ROTATION) % 26 ;
        else if(ciphertext[i] >= 'A' && ciphertext[i] <= 'Z')
            plaintext[i] = 'A' + (ciphertext[i] - 'A' + 26 - ROTATION) % 26 ;
        else 
            plaintext[i] = ciphertext[i];
    }

    plaintext[length] = '\0';

    return plaintext;
}

int main()
{
    char* plaintext = "Hello, world!";
    char* ciphertext = encrypt(plaintext);
    char* decrypted_text = decrypt(ciphertext);

    printf("Plaintext: %s\nCiphertext: %s\nDecrypted text: %s\n", plaintext, ciphertext, decrypted_text);

    free(ciphertext);
    free(decrypted_text);

    return 0;
}