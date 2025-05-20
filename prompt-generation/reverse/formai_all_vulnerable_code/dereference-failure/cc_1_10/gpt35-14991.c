//FormAI DATASET v1.0 Category: Modern Encryption ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPTED_FILE_NAME "encrypted_file.txt"
#define DECRYPTED_FILE_NAME "decrypted_file.txt"

int key = 5;
char alphabet[27] = "abcdefghijklmnopqrstuvwxyz\0";

int encrypt(char *input_string);
int decrypt(char *input_string);

int main() {

    FILE *encrypt_file;
    FILE *decrypt_file;
    
    char input_string[100];
    
    printf("Please enter the string you would like to encrypt: ");
    fgets(input_string, 100, stdin);
    
    int input_length = strlen(input_string);
    
    if (input_length < 2) {
        printf("Error: input string must be at least 2 characters long.\n");
        return 1;
    }
    
    encrypt(input_string);
    
    encrypt_file = fopen(ENCRYPTED_FILE_NAME, "r");
    
    char encrypted_string[100];
    fgets(encrypted_string, 100, encrypt_file);
    
    printf("Encrypted string: %s\n", encrypted_string);
    
    decrypt(encrypted_string);
    
    decrypt_file = fopen(DECRYPTED_FILE_NAME, "r");
    
    char decrypted_string[100];
    fgets(decrypted_string, 100, decrypt_file);
    
    printf("Decrypted string: %s\n", decrypted_string);
    
    return 0;
}

int encrypt(char *input_string) {
    
    FILE *encrypted_file;
    encrypted_file = fopen(ENCRYPTED_FILE_NAME, "w");
    
    int input_length = strlen(input_string);
    
    for (int i = 0; i < input_length; i++) {
        char current_char = input_string[i];
        if (current_char == ' ') {
            fprintf(encrypted_file, " ");
        } else {
            int current_index = strchr(alphabet, current_char) - alphabet;
            int encrypted_index = (current_index + key) % 26;
            fprintf(encrypted_file, "%c", alphabet[encrypted_index]);
        }
    }
    
    fclose(encrypted_file);
    return 0;
}

int decrypt(char *input_string) {
    
    FILE *decrypted_file;
    decrypted_file = fopen(DECRYPTED_FILE_NAME, "w");
    
    int input_length = strlen(input_string);
    
    for (int i = 0; i < input_length; i++) {
        char current_char = input_string[i];
        if (current_char == ' ') {
            fprintf(decrypted_file, " ");
        } else {
            int current_index = strchr(alphabet, current_char) - alphabet;
            int decrypted_index = (current_index - key + 26) % 26;
            fprintf(decrypted_file, "%c", alphabet[decrypted_index]);
        }
    }
    
    fclose(decrypted_file);
    return 0;
}