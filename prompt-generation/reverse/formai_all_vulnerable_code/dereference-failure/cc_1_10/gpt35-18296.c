//FormAI DATASET v1.0 Category: Password management ; Style: relaxed
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Maximum number of characters in the password
#define MAX_PASSWORD_LENGTH 50

// Function to encrypt the password
char* encrypt(char* password) {
    int length = strlen(password);
    char* encrypted_password = (char*)malloc(sizeof(char)*(length+1));
    for(int i=0;i<length;i++) {
        encrypted_password[i] = password[i] + 2; // ASCII value of each character is increased by 2
    }
    encrypted_password[length] = '\0';
    return encrypted_password;
}

// Function to decrypt the password
char* decrypt(char* password) {
    int length = strlen(password);
    char* decrypted_password = (char*)malloc(sizeof(char)*(length+1));
    for(int i=0;i<length;i++) {
        decrypted_password[i] = password[i] - 2; // ASCII value of each character is decreased by 2
    }
    decrypted_password[length] = '\0';
    return decrypted_password;
}

int main() {
    char password[MAX_PASSWORD_LENGTH]; // stores the password
    char* encrypted_password; // stores the encrypted password
    char* decrypted_password; // stores the decrypted password
    
    // Ask the user for the password
    printf("Enter the password (maximum %d characters): ", MAX_PASSWORD_LENGTH);
    scanf("%s", password);
    
    // Encrypt the password and print it
    encrypted_password = encrypt(password);
    printf("Encrypted password: %s\n", encrypted_password);
    
    // Decrypt the password and print it
    decrypted_password = decrypt(encrypted_password);
    printf("Decrypted password: %s\n", decrypted_password);
    
    // Free the memory allocated for the encrypted and decrypted passwords
    free(encrypted_password);
    free(decrypted_password);
    
    return 0;
}