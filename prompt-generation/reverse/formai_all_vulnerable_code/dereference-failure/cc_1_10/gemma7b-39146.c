//Gemma-7B DATASET v1.0 Category: Email Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 16
#define MESSAGE_LENGTH 256

#ifdef DEBUG
#define PRINTF printf
#else
#define PRINTF(x...)
#endif

void crypt_message(char *message, char *key)
{
    int i, j, k;
    for (i = 0; i < MESSAGE_LENGTH; i++)
    {
        for (j = 0; j < KEY_LENGTH; j++)
        {
            k = (message[i] - key[j]) ^ 0x3F;
            message[i] = (k & 0xFF) + 0x20;
        }
    }
}

void decrypt_message(char *message, char *key)
{
    int i, j, k;
    for (i = 0; i < MESSAGE_LENGTH; i++)
    {
        for (j = 0; j < KEY_LENGTH; j++)
        {
            k = (message[i] - key[j]) ^ 0x3F;
            message[i] = (k & 0xFF) + 0x20;
        }
    }
}

int main()
{
    char key[] = "SECRET_KEY";
    char message[] = "HELLO WORLD!";

    crypt_message(message, key);
    decrypt_message(message, key);

    printf("%s\n", message);

    return 0;
}