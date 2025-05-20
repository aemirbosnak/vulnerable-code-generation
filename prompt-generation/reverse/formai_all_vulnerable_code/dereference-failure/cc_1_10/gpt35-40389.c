//FormAI DATASET v1.0 Category: Modern Encryption ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_LEN 16

char* generate_key(){
    char* key = malloc(sizeof(char)*KEY_LEN);
    srand(time(0));
    for(int i=0; i<KEY_LEN; i++){
        key[i] = (rand()%26)+97; //generate lowercase alphabets
    }
    return key;
}

char* encrypt(char* message, char* key){
    int len = strlen(message);
    char* encrypted = malloc(sizeof(char)*len);
    for(int i=0; i<len; i++){
        if(message[i] >= 'a' && message[i] <= 'z'){
            //shift by value of key[i]
            char shifted = message[i] + key[i%KEY_LEN] - 97;
            if(shifted > 'z'){
                shifted -= 26; //wrap around to a
            }
            encrypted[i] = shifted;
        }
        else{
            encrypted[i] = message[i]; //if not a letter, leave as is
        }
    }
    return encrypted;
}

char* decrypt(char* message, char* key){
    int len = strlen(message);
    char* decrypted = malloc(sizeof(char)*len);
    for(int i=0; i<len; i++){
        if(message[i] >= 'a' && message[i] <= 'z'){
            //shift back by value of key[i]
            char shifted = message[i] - key[i%KEY_LEN] + 97;
            if(shifted < 'a'){
                shifted += 26; //wrap around to z
            }
            decrypted[i] = shifted;
        }
        else{
            decrypted[i] = message[i]; //if not a letter, leave as is
        }
    }
    return decrypted;
}

int main(){
    char message[100];
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = 0; //remove newline character
    char* key = generate_key();
    char* encrypted_message = encrypt(message, key);
    char* decrypted_message = decrypt(encrypted_message, key);
    printf("Message: %s\n", message);
    printf("Key: %s\n", key);
    printf("Encrypted message: %s\n", encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);
    free(key);
    free(encrypted_message);
    free(decrypted_message);
    return 0;
}