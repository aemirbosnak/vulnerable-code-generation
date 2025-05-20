//FormAI DATASET v1.0 Category: Modern Encryption ; Style: secure
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

int encryption_key_m = 7; //Encryption key for Transposition Cipher
int encryption_key_caesar = 3; //Encryption key for Caesar Cipher

//Function Declarations
char* encrypt_caesar(char* message);
char* decrypt_caesar(char* message);
char* encrypt_transposition(char* message);
char* decrypt_transposition(char* message);

//Main Function
int main()
{
    char message[1000];
    char* encrypted_message_caesar;
    char* decrypted_message_caesar;
    char* encrypted_message_transposition;
    char* decrypted_message_transposition;
    int choice;

    //Menu
    printf("Choose an option:\n");
    printf("1. Encrypt a message using Caesar Cipher\n2. Decrypt a message using Caesar Cipher\n");
    printf("3. Encrypt a message using Transposition Cipher\n4. Decrypt a message using Transposition Cipher\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nEnter a message to encrypt using Caesar Cipher:\n");
            scanf(" %[^\n]s", message);
            encrypted_message_caesar = encrypt_caesar(message);
            printf("\nEncrypted message: %s\n", encrypted_message_caesar);
            break;

        case 2:
            printf("\nEnter a message to decrypt using Caesar Cipher:\n");
            scanf(" %[^\n]s", message);
            decrypted_message_caesar = decrypt_caesar(message);
            printf("\nDecrypted message: %s\n", decrypted_message_caesar);
            break;

        case 3:
            printf("\nEnter a message to encrypt using Transposition Cipher:\n");
            scanf(" %[^\n]s", message);
            encrypted_message_transposition = encrypt_transposition(message);
            printf("\nEncrypted message: %s\n", encrypted_message_transposition);
            break;

        case 4:
            printf("\nEnter a message to decrypt using Transposition Cipher:\n");
            scanf(" %[^\n]s", message);
            decrypted_message_transposition = decrypt_transposition(message);
            printf("\nDecrypted message: %s\n", decrypted_message_transposition);
            break;

        default:
            printf("\nInvalid choice!\n");
            break;
    }

    return 0;
}

//Function Definitions

//Caesar Cipher Encryption Function
char* encrypt_caesar(char* message)
{
    int length = strlen(message);
    char* encrypted_message = (char*) malloc(length * sizeof(char));

    for(int i=0; i<length; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            encrypted_message[i] = (message[i] + encryption_key_caesar - 'a') % 26 + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            encrypted_message[i] = (message[i] + encryption_key_caesar - 'A') % 26 + 'A';
        }
        else {
            encrypted_message[i] = message[i];
        }
    }

    return encrypted_message;
}

//Caesar Cipher Decryption Function
char* decrypt_caesar(char* message)
{
    int length = strlen(message);
    char* decrypted_message = (char*) malloc(length * sizeof(char));

    for(int i=0; i<length; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            decrypted_message[i] = (message[i] - encryption_key_caesar - 'a' + 26) % 26 + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            decrypted_message[i] = (message[i] - encryption_key_caesar - 'A' + 26) % 26 + 'A';
        }
        else {
            decrypted_message[i] = message[i];
        }
    }

    return decrypted_message;
}

//Transposition Cipher Encryption Function
char* encrypt_transposition(char* message)
{
    int length = strlen(message);
    int rows, columns;

    if(length % encryption_key_m == 0) {
        rows = length / encryption_key_m;
        columns = encryption_key_m;
    }
    else {
        rows = length / encryption_key_m + 1;
        columns = length % encryption_key_m;
    }

    char** matrix = (char**) malloc(rows * sizeof(char*));

    for(int i=0; i<rows; i++) {
        matrix[i] = (char*) malloc(columns * sizeof(char));
    }

    int k=0;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            if(k < length) {
                matrix[i][j] = message[k];
            }
            else {
                matrix[i][j] = ' ';
            }
            k++;
        }
    }

    char* encrypted_message = (char*) malloc(length * sizeof(char));

    k=0;
    for(int i=0; i<columns; i++) {
        for(int j=0; j<rows; j++) {
            encrypted_message[k] = matrix[j][i];
            k++;
        }
    }

    return encrypted_message;
}

//Transposition Cipher Decryption Function
char* decrypt_transposition(char* message)
{
    int length = strlen(message);
    int rows = length / encryption_key_m;
    int columns = encryption_key_m;

    char** matrix = (char**) malloc(rows * sizeof(char*));

    for(int i=0; i<rows; i++) {
        matrix[i] = (char*) malloc(columns * sizeof(char));
    }

    int k=0;
    for(int i=0; i<columns; i++) {
        for(int j=0; j<rows; j++) {
            matrix[j][i] = message[k];
            k++;
        }
    }

    char* decrypted_message = (char*) malloc(length * sizeof(char));

    k=0;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            decrypted_message[k] = matrix[i][j];
            k++;
        }
    }

    return decrypted_message;
}