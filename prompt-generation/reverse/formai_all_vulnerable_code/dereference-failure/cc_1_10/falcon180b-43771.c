//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* encrypt(char* message, int key){
    int i, j, n = strlen(message);
    char* result = malloc(n+1);

    for(i=0, j=0; i<n; i++){
        if(isalpha(message[i])){
            if(isupper(message[i])){
                result[j] = (message[i] + key - 65) % 26 + 65;
            }
            else{
                result[j] = (message[i] + key - 97) % 26 + 97;
            }
            j++;
        }
    }

    result[j] = '\0';

    return result;
}

char* decrypt(char* message, int key){
    int i, j, n = strlen(message);
    char* result = malloc(n+1);

    for(i=0, j=0; i<n; i++){
        if(isalpha(message[i])){
            if(isupper(message[i])){
                result[j] = (message[i] - key - 65 + 26) % 26 + 65;
            }
            else{
                result[j] = (message[i] - key - 97 + 26) % 26 + 97;
            }
            j++;
        }
    }

    result[j] = '\0';

    return result;
}

int main(){
    char* message = "Hello World!";
    int key = 3;

    char* encrypted = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted);

    char* decrypted = decrypt(encrypted, key);
    printf("Decrypted message: %s\n", decrypted);

    free(encrypted);
    free(decrypted);

    return 0;
}