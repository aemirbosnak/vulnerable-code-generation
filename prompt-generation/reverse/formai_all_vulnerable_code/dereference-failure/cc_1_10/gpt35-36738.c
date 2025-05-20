//FormAI DATASET v1.0 Category: Image Steganography ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *encrypt(char*, int);
char *decrypt(char*, int);

int main(){
    char message[100];
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    printf("\nOriginal message: %s", message);

    char *encrypted = encrypt(message, 5);
    printf("Encrypted message: %s", encrypted);

    char *decrypted = decrypt(encrypted, 5);
    printf("Decrypted message: %s", decrypted);

    return 0;
}

char *encrypt(char *message, int key){
    char *encrypted = (char*)malloc(sizeof(char)*strlen(message));
    strcpy(encrypted, message);

    int i;
    for(i=0; i<strlen(encrypted); i++){
        if(encrypted[i] == ' '){
            continue;
        }
        int temp = ((int)encrypted[i] + key - 97) % 26;
        encrypted[i] = (char)(temp + 97);
    }
    return encrypted;
}

char *decrypt(char *encrypted, int key){
    char *decrypted = (char*)malloc(sizeof(char)*strlen(encrypted));
    strcpy(decrypted, encrypted);

    int i;
    for(i=0; i<strlen(decrypted); i++){
        if(decrypted[i] == ' '){
            continue;
        }
        int temp = ((int)decrypted[i] - key - 97) % 26;
        if(temp < 0){
            temp += 26;
        }
        decrypted[i] = (char)(temp + 97);
    }
    return decrypted;
}