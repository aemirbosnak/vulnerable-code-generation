//FormAI DATASET v1.0 Category: Modern Encryption ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1000

char *encrypt(char *message, int key);
char *decrypt(char *message, int key);

int main()
{
    char message[MAX_SIZE];
    int key;

    printf("Enter the message to be encrypted:\n");
    fgets(message, MAX_SIZE, stdin);
    printf("Enter the key for encryption:\n");
    scanf("%d", &key);

    char *encrypted_message = encrypt(message, key);
    printf("\nEncrypted Message:\n%s", encrypted_message);

    char *decrypted_message = decrypt(encrypted_message, key);
    printf("\nDecrypted Message:\n%s", decrypted_message);

    free(encrypted_message);
    free(decrypted_message);

    return 0;
}

char *encrypt(char *message, int key)
{
    int i, j = 0;
    int len = strlen(message);
    char *encrypted_message = (char *) malloc(len * sizeof(char));

    for(i = 0; i < len; i++)
    {
        if(message[i] == ' ')
        {
            encrypted_message[j++] = ' ';
            continue;
        }

        if(isupper(message[i])) 
        {
            encrypted_message[j++] = (((message[i] + key) - 65) % 26) + 65;
        }
        else 
        {
            encrypted_message[j++] = (((message[i] + key) - 97) % 26) + 97;
        }
    }

    encrypted_message[j] = '\0';

    return encrypted_message;
}

char *decrypt(char *message, int key)
{
    int i, j = 0;
    int len = strlen(message);
    char *decrypted_message = (char *) malloc(len * sizeof(char));

    for(i = 0; i < len; i++)
    {
        if(message[i] == ' ')
        {
            decrypted_message[j++] = ' ';
            continue;
        }

        if(isupper(message[i])) 
        {
            decrypted_message[j++] = (((message[i] - key) - 65 + 26) % 26) + 65;
        }
        else 
        {
            decrypted_message[j++] = (((message[i] - key) - 97 + 26) % 26) + 97;
        }
    }

    decrypted_message[j] = '\0';

    return decrypted_message;
}