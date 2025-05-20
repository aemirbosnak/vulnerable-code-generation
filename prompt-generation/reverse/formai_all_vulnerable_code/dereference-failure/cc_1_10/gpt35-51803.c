//FormAI DATASET v1.0 Category: modern Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encryption key (a random string of characters)
char key[] = "Z!2b9jP$#k7L";

// Function to encrypt a string and return the encrypted text
char *encrypt(char *str)
{
    int i, j = 0, len = strlen(str);
    char *encrypted = (char *)malloc(sizeof(char) * (len + 1));

    for (i = 0; i < len; i++) {
        if (j == strlen(key))
            j = 0;
        encrypted[i] = str[i] ^ key[j++];
    }
    encrypted[i] = '\0';

    return encrypted;
}

// Function to decrypt an encrypted string and return the decrypted text
char *decrypt(char *encrypted)
{
    int i, j = 0, len = strlen(encrypted);
    char *decrypted = (char *)malloc(sizeof(char) * (len + 1));

    for (i = 0; i < len; i++) {
        if (j == strlen(key))
            j = 0;
        decrypted[i] = encrypted[i] ^ key[j++];
    }
    decrypted[i] = '\0';

    return decrypted;
}

int main(void)
{
    char str1[100], *encrypted, *decrypted;

    // Take input from user
    printf("Enter a string to encrypt: ");
    scanf("%[^\n]%*c", str1);

    // Encrypt the string
    encrypted = encrypt(str1);
    printf("Encrypted string: %s\n", encrypted);
    
    // Decrypt the string
    decrypted = decrypt(encrypted);
    printf("Decrypted string: %s\n", decrypted);

    // free allocated memory
    free(encrypted);
    free(decrypted);

    return 0;
}