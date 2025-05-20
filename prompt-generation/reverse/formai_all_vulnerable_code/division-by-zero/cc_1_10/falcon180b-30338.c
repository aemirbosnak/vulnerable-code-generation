//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1000

void encrypt(char* message, char* key, char* encrypted_message){
    int i, j, k;
    char temp;
    for(i=0, j=0; message[i]!='\0'; i++){
        temp = message[i];
        if(isalpha(temp)){
            temp = (temp + key[j] - 65) % 26 + 65;
            encrypted_message[i] = temp;
            j = (j+1) % strlen(key);
        }
        else{
            encrypted_message[i] = temp;
        }
    }
    encrypted_message[i] = '\0';
}

void decrypt(char* encrypted_message, char* key, char* message){
    int i, j, k;
    char temp;
    for(i=0, j=0; encrypted_message[i]!='\0'; i++){
        temp = encrypted_message[i];
        if(isalpha(temp)){
            temp = (temp - key[j] - 65 + 26) % 26 + 65;
            message[i] = temp;
            j = (j+1) % strlen(key);
        }
        else{
            message[i] = temp;
        }
    }
    message[i] = '\0';
}

int main(){
    char message[MAX_SIZE], key[MAX_SIZE];
    char encrypted_message[MAX_SIZE], decrypted_message[MAX_SIZE];
    srand(time(NULL));
    message[0] = '\0';
    printf("Enter the message to be encrypted: ");
    fgets(message, MAX_SIZE, stdin);
    printf("Enter the encryption key: ");
    fgets(key, MAX_SIZE, stdin);
    encrypt(message, key, encrypted_message);
    printf("Encrypted message: %s\n", encrypted_message);
    printf("Decrypted message: ");
    decrypt(encrypted_message, key, decrypted_message);
    printf("%s\n", decrypted_message);
    return 0;
}