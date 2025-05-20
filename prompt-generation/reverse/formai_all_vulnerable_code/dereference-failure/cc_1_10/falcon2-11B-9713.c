//Falcon2-11B DATASET v1.0 Category: Password management ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to generate a random password
char* generate_password(int length) {
    char* password = (char*)malloc(length + 1);
    password[length] = '\0';
    for (int i = 0; i < length; i++) {
        password[i] = (char)('a' + rand() % 26);
    }
    return password;
}

// Function to encrypt the password
char* encrypt_password(char* password, char* salt) {
    char* encrypted_password = (char*)malloc(strlen(password) + strlen(salt) + 1);
    encrypted_password[0] = '\0';
    int i = 0;
    for (int j = 0; j < strlen(password); j++) {
        encrypted_password[i++] = password[j] ^ salt[j % strlen(salt)];
    }
    encrypted_password[i] = '\0';
    return encrypted_password;
}

// Function to decrypt the password
char* decrypt_password(char* encrypted_password, char* salt) {
    char* decrypted_password = (char*)malloc(strlen(encrypted_password) + 1);
    decrypted_password[0] = '\0';
    int i = 0;
    for (int j = 0; j < strlen(encrypted_password); j++) {
        decrypted_password[i++] = encrypted_password[j] ^ salt[j % strlen(salt)];
    }
    decrypted_password[i] = '\0';
    return decrypted_password;
}

int main() {
    // Generate a random password
    char* password = generate_password(10);
    printf("Generated password: %s\n", password);

    // Encrypt the password
    char* salt = "1234567890";
    char* encrypted_password = encrypt_password(password, salt);
    printf("Encrypted password: %s\n", encrypted_password);

    // Decrypt the password
    char* decrypted_password = decrypt_password(encrypted_password, salt);
    printf("Decrypted password: %s\n", decrypted_password);

    // Free allocated memory
    free(password);
    free(encrypted_password);
    free(decrypted_password);

    return 0;
}