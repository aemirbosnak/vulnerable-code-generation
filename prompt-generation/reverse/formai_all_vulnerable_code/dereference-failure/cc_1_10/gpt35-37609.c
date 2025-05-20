//FormAI DATASET v1.0 Category: Modern Encryption ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// Function to encrypt the message
char* encrypt(char* message, int key)
{   
    int i;
    int n = strlen(message);  // length of the message
    char *cipher = (char*)malloc(n*sizeof(char));    // create cipher text of same size

    // encrypting each character one by one
    for(i=0; i<n; i++)
    {
        if(message[i]==' ')  // ignore spaces
            cipher[i] = ' ';

        // encrypt alphabets
        else if(message[i]>='a' && message[i]<='z')
            cipher[i] = (message[i]-'a'+key)%26 + 'a';

        else if(message[i]>='A' && message[i]<='Z')
            cipher[i] = (message[i]-'A'+key)%26 + 'A';

        // encrypt numbers
        else if(message[i]>='0' && message[i]<='9')
            cipher[i] = (message[i]-'0'+key)%10 + '0';
    }

    return cipher;
}

int main()
{   
    srand(time(NULL));  // initialize seed for rand() function
    
    // accepting input from user
    char *message = (char*)malloc(100*sizeof(char));
    printf("Enter the message: ");
    fgets(message, 100, stdin);

    int key;
    printf("Enter the encryption key (1-25): ");
    scanf("%d", &key);

    // encrypting the message
    char *cipher = encrypt(message, key);
    printf("\nEncrypted message: %s\n", cipher);

    free(message);
    free(cipher);
    return 0;
}