//Falcon2-11B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateKeys()
{
    FILE *fp;
    fp = fopen("public_key.txt", "w");
    fp = fopen("private_key.txt", "w");
    srand(time(0));
    int key = rand() % 100;
    fputc(key, fp);
    fclose(fp);
}

void encryptMessage(char* message, char* public_key)
{
    FILE *fp;
    fp = fopen("encrypted_message.txt", "w");
    fp = fopen(public_key, "r");
    int key = fgetc(fp);
    char encrypted[100];
    for(int i = 0; i < strlen(message); i++)
    {
        encrypted[i] = message[i] ^ key;
    }
    fputs(encrypted, fp);
    fclose(fp);
}

void decryptMessage(char* message, char* private_key)
{
    FILE *fp;
    fp = fopen("decrypted_message.txt", "w");
    fp = fopen(private_key, "r");
    int key = fgetc(fp);
    char decrypted[100];
    for(int i = 0; i < strlen(message); i++)
    {
        decrypted[i] = message[i] ^ key;
    }
    fputs(decrypted, fp);
    fclose(fp);
}

int main()
{
    char message[100];
    char public_key[100];
    char private_key[100];
    generateKeys();
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    encryptMessage(message, public_key);
    printf("Enter message to decrypt: ");
    fgets(message, 100, stdin);
    decryptMessage(message, private_key);
    return 0;
}