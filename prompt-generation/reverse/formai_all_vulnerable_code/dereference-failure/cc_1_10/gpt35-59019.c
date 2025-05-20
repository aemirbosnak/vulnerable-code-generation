//FormAI DATASET v1.0 Category: Encryption ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Function to encrypt a message using Caesar Cipher*/
char* caesar_crypt(char message[], int shift)
{
    int message_len = strlen(message);
    
    /*Allocate memory for encrypted message*/
    char* encrypted_message = (char*)malloc(message_len+1);
    
    /*Encrypt each letter in message*/
    for(int i=0; i<message_len; i++)
    {
        if((message[i]>= 'a' && message[i] <= 'z') || (message[i]>= 'A' && message[i] <= 'Z'))
        {
            if(message[i] >= 'a' && message[i] <= 'z')
            {
                encrypted_message[i] = ((message[i] - 'a') + shift) % 26 + 'a';
            }
            else
            {
                encrypted_message[i] = ((message[i] - 'A') + shift) % 26 + 'A';
            }
        }
        else {
            encrypted_message[i] = message[i];
        }
    }
    
    encrypted_message[message_len] = '\0';
    
    return encrypted_message;
}

int main()
{
    char message[100];
    int shift;
    
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    
    printf("Enter shift (1-25): ");
    scanf("%d", &shift);
    
    /*Encrypt message using Caesar Cipher*/
    char* encrypted_message = caesar_crypt(message, shift);
    
    printf("Encrypted message: %s\n", encrypted_message);
    
    free(encrypted_message);
    
    return 0;
}