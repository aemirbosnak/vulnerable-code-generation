//Falcon2-11B DATASET v1.0 Category: Encryption ; Style: dynamic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Function to encrypt the message
char* encrypt(char* message, int key)
{
    int len = strlen(message);
    int i;
    char* encrypted_message = (char*)malloc(sizeof(char)*(len+1));

    for (i=0; i<len; i++)
    {
        encrypted_message[i] = message[i] + key;
        if (encrypted_message[i] > 'z')
            encrypted_message[i] = encrypted_message[i] - 'z' + 'a';
        else if (encrypted_message[i] < 'a')
            encrypted_message[i] = encrypted_message[i] + 'z' - 'a';
    }

    encrypted_message[i] = '\0';
    return encrypted_message;
}

// Function to decrypt the encrypted message
char* decrypt(char* encrypted_message, int key)
{
    int len = strlen(encrypted_message);
    int i;
    char* decrypted_message = (char*)malloc(sizeof(char)*(len+1));

    for (i=0; i<len; i++)
    {
        decrypted_message[i] = encrypted_message[i] - key;
        if (decrypted_message[i] > 'z')
            decrypted_message[i] = decrypted_message[i] - 'z' + 'a';
        else if (decrypted_message[i] < 'a')
            decrypted_message[i] = decrypted_message[i] + 'z' - 'a';
    }

    decrypted_message[i] = '\0';
    return decrypted_message;
}

// Function to generate a random key
int generateKey()
{
    int key;
    int range = 0;
    srand(time(NULL));
    do {
        key = rand() % 26;
    } while (range!= 0);
    return key;
}

// Main function
int main()
{
    char* message = "Hello World";
    int key = generateKey();
    char* encrypted_message = encrypt(message, key);
    printf("Encrypted Message: %s\n", encrypted_message);
    char* decrypted_message = decrypt(encrypted_message, key);
    printf("Decrypted Message: %s\n", decrypted_message);
    free(encrypted_message);
    free(decrypted_message);
    return 0;
}