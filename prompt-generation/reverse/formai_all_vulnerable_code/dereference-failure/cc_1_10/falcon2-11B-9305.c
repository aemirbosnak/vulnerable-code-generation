//Falcon2-11B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: optimized
#include <stdio.h>
#include <string.h>

// Function to generate a public key from a private key
void generate_public_key(char *private_key, char *public_key) {
    // Convert the private key to an integer
    int private_key_int = atoi(private_key);
    
    // Calculate the public key using the private key
    int public_key_int = private_key_int * 2;
    
    // Convert the public key back to a string
    char *public_key_str = (char *)malloc(strlen(public_key) + 1);
    sprintf(public_key_str, "%d", public_key_int);
    
    // Copy the public key string to the output string
    strcpy(public_key, public_key_str);
    
    // Free the memory allocated for the public key string
    free(public_key_str);
}

// Function to encrypt a message using the public key
void encrypt_message(char *public_key, char *message) {
    // Convert the public key to an integer
    int public_key_int = atoi(public_key);
    
    // Convert the message to an integer
    int message_int = atoi(message);
    
    // Calculate the encrypted message using the public key
    int encrypted_message_int = public_key_int * message_int;
    
    // Convert the encrypted message back to a string
    char *encrypted_message_str = (char *)malloc(strlen(message) + 1);
    sprintf(encrypted_message_str, "%d", encrypted_message_int);
    
    // Copy the encrypted message string to the output string
    strcpy(message, encrypted_message_str);
    
    // Free the memory allocated for the encrypted message string
    free(encrypted_message_str);
}

// Function to decrypt a message using the private key
void decrypt_message(char *private_key, char *encrypted_message) {
    // Convert the private key to an integer
    int private_key_int = atoi(private_key);
    
    // Convert the encrypted message to an integer
    int encrypted_message_int = atoi(encrypted_message);
    
    // Calculate the decrypted message using the private key
    int decrypted_message_int = private_key_int * encrypted_message_int;
    
    // Convert the decrypted message back to a string
    char *decrypted_message_str = (char *)malloc(strlen(encrypted_message) + 1);
    sprintf(decrypted_message_str, "%d", decrypted_message_int);
    
    // Copy the decrypted message string to the output string
    strcpy(encrypted_message, decrypted_message_str);
    
    // Free the memory allocated for the decrypted message string
    free(decrypted_message_str);
}

int main() {
    // Generate a public key from a private key
    char private_key[] = "12345";
    char public_key[100];
    generate_public_key(private_key, public_key);
    
    // Print the public key
    printf("Public key: %s\n", public_key);
    
    // Encrypt a message using the public key
    char message[] = "Hello, world!";
    char encrypted_message[100];
    encrypt_message(public_key, message);
    
    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
    
    // Decrypt the encrypted message using the private key
    char private_key2[] = "12345";
    char decrypted_message[100];
    decrypt_message(private_key2, encrypted_message);
    
    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
    
    return 0;
}