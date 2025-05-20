//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_TEXT_SIZE 1000
#define MAX_KEY_SIZE 100

char Encrypt(char text, char key)
{
    return ((text+key)%26)+'A';
}

char Decrypt(char text, char key)
{
    return ((text-key+26)%26)+'A';
}

void Encryption(char PlainText[], char Key[], char CipherText[])
{
    int i;
    int keyLength = strlen(Key);
 
    for(i=0;i<strlen(PlainText);i++)
    {
        CipherText[i] = Encrypt(PlainText[i], Key[i%keyLength]);
    }
    CipherText[i] = '\0';
}

void Decryption(char CipherText[], char Key[], char PlainText[])
{
    int i;
    int keyLength = strlen(Key);
 
    for(i=0;i<strlen(CipherText);i++)
    {
        PlainText[i] = Decrypt(CipherText[i], Key[i%keyLength]);
    }
    PlainText[i] = '\0';
}

int main()
{
    char PlainText[MAX_TEXT_SIZE], Key[MAX_KEY_SIZE], CipherText[MAX_TEXT_SIZE];
 
    printf("Enter the Plain Text: ");
    fgets(PlainText, MAX_TEXT_SIZE, stdin);
    printf("Enter the Key: ");
    fgets(Key, MAX_KEY_SIZE, stdin);
 
    Encryption(PlainText, Key, CipherText);
    printf("\nEncrypted Text: %s", CipherText);
 
    Decryption(CipherText, Key, PlainText);
    printf("\nDecrypted Text: %s", PlainText);
 
    return 0;
}