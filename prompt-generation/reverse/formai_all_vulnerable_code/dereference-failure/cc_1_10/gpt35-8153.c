//FormAI DATASET v1.0 Category: Modern Encryption ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* encrypt(char* message, int key);
void generate_key(int* key);

int main()
{
    char* message = "Hello, World!";
    int key;
    
    generate_key(&key);

    printf("Original Message: %s\n", message);

    char* encrypted_message = encrypt(message, key);

    printf("Encrypted Message: %s\n", encrypted_message);

    free(encrypted_message);

    return 0;
}

char* encrypt(char* message, int key)
{
    int length = strlen(message);
    char* encrypted_message = malloc(length * sizeof(char));

    for(int i = 0; i < length; i++)
    {
        int random = rand() % 10;

        if(random > key)
        {
            encrypted_message[i] = message[i] + (key % 26);
        }
        else
        {
            encrypted_message[i] = message[i] - (key % 26);
        }
    }

    return encrypted_message;
}

void generate_key(int* key)
{
    srand(time(NULL));
    *key = rand() % 10;
}