//FormAI DATASET v1.0 Category: Modern Encryption ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 256

char *encrypt(char *message, int key);
char *decrypt(char *message, int key);

int main()
{
    char message[MAX_LEN];
    int key, choice;
    bool repeat = true;

    while(repeat)
    {
        printf("Enter message to encrypt/decrypt (max %d characters): ", MAX_LEN-1);
        fgets(message, MAX_LEN, stdin);
        message[strcspn(message, "\n")] = '\0'; // removes trailing newline character

        printf("Enter key: ");
        scanf("%d", &key);

        do
        {
            printf("\nChoose operation:");
            printf("\n1. Encrypt");
            printf("\n2. Decrypt");
            printf("\n3. Quit\n");
            scanf("%d", &choice);
            getchar();

            if(choice == 1)
            {
                char *encrypted = encrypt(message, key);
                printf("\nEncrypted message: %s\n", encrypted);
                free(encrypted);
            }
            else if(choice == 2)
            {
                char *decrypted = decrypt(message, key);
                printf("\nDecrypted message: %s\n", decrypted);
                free(decrypted);
            }
            else if(choice == 3)
            {
                printf("\nExiting program.");
                repeat = false;
            }
            else
            {
                printf("\nInvalid choice. Try again.\n");
            }
        }
        while (choice != 3);
    }

    return 0;
}

char *encrypt(char *message, int key)
{
    char *encrypted = (char *)malloc(sizeof(char) * MAX_LEN);
    int i;

    for (i = 0; message[i] != '\0'; i++)
    {
        encrypted[i] = (message[i] + key) % 256;
    }

    encrypted[i] = '\0';

    return encrypted;
}

char *decrypt(char *message, int key)
{
    char *decrypted = (char *)malloc(sizeof(char) * MAX_LEN);
    int i;

    for (i = 0; message[i] != '\0'; i++)
    {
        decrypted[i] = (message[i] - key + 256) % 256;
    }

    decrypted[i] = '\0';

    return decrypted;
}