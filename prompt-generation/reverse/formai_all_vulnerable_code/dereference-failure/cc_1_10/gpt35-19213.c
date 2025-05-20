//FormAI DATASET v1.0 Category: Encryption ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ceasarShift(char *message, int shift){
    char *result = calloc(strlen(message), sizeof(char));

    for(size_t i=0; i<strlen(message); i++){
        if(message[i]>='a' && message[i]<='z'){
            result[i] = (((message[i] - 'a') + shift) % 26) + 'a';
        }else if(message[i]>='A' && message[i]<='Z'){
            result[i] = (((message[i] - 'A') + shift) % 26) + 'A';
        }else{
            result[i] = message[i];
        }
    }

    return result;
}

char* vigenereShift(char *message, char *key){
    size_t keyLength = strlen(key);
    char *result = calloc(strlen(message), sizeof(char));

    for(size_t i=0; i<strlen(message); i++){
        if(message[i]>='a' && message[i]<='z'){
            result[i] = (((message[i] - 'a') + (key[i%keyLength] - 'a')) % 26) + 'a';
        }else if(message[i]>='A' && message[i]<='Z'){
            result[i] = (((message[i] - 'A') + (key[i%keyLength] - 'a')) % 26) + 'A';            
        }else{
            result[i] = message[i];
        }
    }

    return result;
}

int main(){

    char *message = "This is a secret message";
    char *key = "cat";
    int shift = 3;

    printf("Original message: %s\n", message);

    char *ceasarResult = ceasarShift(message, shift);
    printf("Ceasar encrypted message with shift %d: %s\n", shift, ceasarResult);

    char *vigenereResult = vigenereShift(message, key);
    printf("Vigenere encrypted message with key %s: %s\n", key, vigenereResult);

    free(ceasarResult);
    free(vigenereResult);

    return 0;
}