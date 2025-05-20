//FormAI DATASET v1.0 Category: Password management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function is used to encrypt the password.
char* encrypt(char* password) {
    int len = strlen(password);
    char* encrypted_pwd = (char*)malloc(len+1);
    for(int i=0; i<len; i++) {
        encrypted_pwd[i] = password[i] + 3;
    }
    encrypted_pwd[len] = '\0';
    return encrypted_pwd;
}

// This function is used to decrypt the password.
char* decrypt(char* password) {
    int len = strlen(password);
    char* decrypted_pwd = (char*)malloc(len+1);
    for(int i=0; i<len; i++) {
        decrypted_pwd[i] = password[i] - 3;
    }
    decrypted_pwd[len] = '\0';
    return decrypted_pwd;
}

// Main function
int main() {
    char username[20], password[20];
    char* encrypted_password, *decrypted_password;
    int choice;
    while(1) { // Infinite Loop 
        printf("\nPress 1 to Enter Username and Password\n");
        printf("Press 2 to Retrieve Password\n");
        printf("Press 3 to Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter your username: ");
                scanf("%s", username);
                printf("Enter your password: ");
                scanf("%s", password);
                encrypted_password = encrypt(password);
                printf("Your password is encrypted as %s\n", encrypted_password);
                break;
            case 2:
                if(encrypted_password == NULL) {
                    printf("\nNo password found!\n");
                } else {
                    decrypted_password = decrypt(encrypted_password);
                    printf("\nDecrypted password is %s\n", decrypted_password);
                }
                break;
            case 3:
                exit(0); // Program exit
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}