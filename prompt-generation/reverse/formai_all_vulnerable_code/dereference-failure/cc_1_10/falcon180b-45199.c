//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define SIZE 10000

char *encrypt(char *input, int key);
char *decrypt(char *input, int key);

int main(){
    char input[SIZE];
    int key, choice;
    char *encrypted, *decrypted;
    
    printf("Enter a string to encrypt: ");
    scanf("%s", input);
    
    printf("Enter the encryption key (1-100): ");
    scanf("%d", &key);
    
    encrypted = encrypt(input, key);
    decrypted = decrypt(encrypted, key);
    
    printf("Encrypted string: %s\n", encrypted);
    printf("Decrypted string: %s\n", decrypted);
    
    return 0;
}

char *encrypt(char *input, int key){
    int i, j, len;
    char *output = malloc(strlen(input) + 1);
    char *encrypt_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    
    for(i = 0, j = 0; i < strlen(input); i++){
        if(isalpha(input[i])){
            if(isupper(input[i])){
                output[j] = encrypt_table[toupper(input[i]) + key - 65];
            }
            else{
                output[j] = encrypt_table[tolower(input[i]) + key - 97];
            }
            j++;
        }
        else{
            output[j] = input[i];
            j++;
        }
    }
    
    output[j] = '\0';
    return output;
}

char *decrypt(char *input, int key){
    int i, j, len;
    char *output = malloc(strlen(input) + 1);
    char *decrypt_table = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    for(i = 0, j = 0; i < strlen(input); i++){
        if(isalpha(input[i])){
            if(isupper(input[i])){
                output[j] = decrypt_table[toupper(input[i]) - key + 65];
            }
            else{
                output[j] = decrypt_table[tolower(input[i]) - key + 97];
            }
            j++;
        }
        else{
            output[j] = input[i];
            j++;
        }
    }
    
    output[j] = '\0';
    return output;
}