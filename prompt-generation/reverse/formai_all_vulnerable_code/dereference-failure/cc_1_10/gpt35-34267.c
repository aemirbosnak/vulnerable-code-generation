//FormAI DATASET v1.0 Category: Modern Encryption ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to encrypt the input string using a specified key
char* encrypt(char* input, char* key){
    int len_input = strlen(input);
    int len_key = strlen(key);
    char* output = (char*)malloc((len_input + 1) * sizeof(char));

    for(int i=0; i<len_input; i++){
        output[i] = ((input[i] + key[i%len_key]) % 26) + 'A';
    }
    output[len_input] = '\0';
    return output;
}

// Function to decrypt the encrypted string using the same key 
char* decrypt(char* input, char* key){
    int len_input = strlen(input);
    int len_key = strlen(key);
    char* output = (char*)malloc((len_input + 1) * sizeof(char));

    for(int i=0; i<len_input; i++){
        output[i] = ((input[i] - key[i%len_key] + 26) % 26) + 'A';
    }
    output[len_input] = '\0';
    return output;
}

int main(){
    char input[MAX_LENGTH], key[MAX_LENGTH];
    char* encrypted, *decrypted;

    printf("Enter the string to be encrypted: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0;    // remove the '\n' character

    printf("Enter the key for encryption: ");
    fgets(key, MAX_LENGTH, stdin);
    key[strcspn(key, "\n")] = 0;    // remove the '\n' character

    encrypted = encrypt(input, key);
    printf("Encrypted string: %s\n", encrypted);

    decrypted = decrypt(encrypted, key);
    printf("Decrypted string: %s\n", decrypted);

    free(encrypted);
    free(decrypted);
    return 0;
}