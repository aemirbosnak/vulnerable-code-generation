//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: multivariable
#include<stdio.h>

void encrypt(char *, int, int*);

void decrypt(int *, int, char *);

int main(){

    char message[100];
    int key, i, len;

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    printf("Enter key: ");
    scanf("%d", &key);

    len = strlen(message);

    int cipher[len];

    encrypt(message, key, cipher);

    printf("Encrypted Text: ");
    for(i=0;i<len;i++){
        printf("%d ",cipher[i]);
    }

    char decrypted[len];

    decrypt(cipher, key, decrypted);

    printf("\nDecrypted Text: %s", decrypted);

    return 0;
}

void encrypt(char *message, int key, int *cipher){

    int i, character;
    for(i=0; message[i] != '\0'; i++){
        character = message[i];

        if(character >= 'a' && character <= 'z'){
            character = character + key;

            if(character > 'z'){
                character = character - 'z' + 'a' - 1;
            }
            message[i] = character;
            cipher[i] = character;
        }
        else if(character >= 'A' && character <= 'Z'){
            character = character + key;

            if(character > 'Z'){
                character = character - 'Z' + 'A' - 1;
            }
            message[i] = character;
            cipher[i] = character;
        }
        else{
            cipher[i] = character;
        }
    }
}

void decrypt(int *cipher, int key, char *decrypted){

    int i, character;
    for(i=0; cipher[i] != '\0'; i++){
        character = cipher[i];

        if(character >= 'a' && character <= 'z'){
            character = character - key;

            if(character < 'a'){
                character = character + 'z' - 'a' + 1;
            }
            decrypted[i] = character;
        }
        else if(character >= 'A' && character <= 'Z'){
            character = character - key;

            if(character < 'A'){
                character = character + 'Z' - 'A' + 1;
            }
            decrypted[i] = character;
        }
        else{
            decrypted[i] = character;
        }
    }
    decrypted[i] = '\0';
}