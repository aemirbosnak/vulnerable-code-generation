//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: futuristic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Function to generate key
char* generate_key(char* message, char* password){
    int message_length = strlen(message);
    int password_length = strlen(password);

    char* key = (char*) malloc(sizeof(char)*message_length);

    int j = 0;
    for(int i=0; i < message_length; i++){
        if(j >= password_length)
            j = 0;

        key[i] = password[j];
        j++;
    }

    return key;
}

// Function to encrypt message
char* encrypt(char* message, char* password){
    int message_length = strlen(message);
    char* encrypted_message = (char*) malloc(sizeof(char)*message_length);

    char* key = generate_key(message, password);

    for(int i=0; i < message_length; i++){
        encrypted_message[i] = message[i]^key[i];
    }

    return encrypted_message;
}

// Function to decrypt message
char* decrypt(char* encrypted_message, char* password){
    int message_length = strlen(encrypted_message);
    char* decrypted_message = (char*) malloc(sizeof(char)*message_length);

    char* key = generate_key(encrypted_message, password);

    for(int i=0; i < message_length; i++){
        decrypted_message[i] = encrypted_message[i]^key[i];
    }

    return decrypted_message;
}

// Main function
int main(){
    char message[] = "Hello, World!";
    char password[] = "This is my password. Don't share it with anyone!";

    char* encrypted_message = encrypt(message, password);
    char* decrypted_message = decrypt(encrypted_message, password);

    printf("Message: %s\n", message);
    printf("Password: %s\n", password);
    printf("Encrypted Message: %s\n", encrypted_message);
    printf("Decrypted Message: %s\n", decrypted_message);

    free(encrypted_message);
    free(decrypted_message);

    return 0;
}