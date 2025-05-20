//FormAI DATASET v1.0 Category: Modern Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, int key) {
    char *cipher = (char*)malloc((strlen(message)+1) * sizeof(char)); 
    
    for(int i=0; i<strlen(message); i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            cipher[i] = ((message[i] - 97 + key) % 26) + 97;
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            cipher[i] = ((message[i] - 65 + key) % 26) + 65;
        }
        else {
            cipher[i] = message[i];
        }
    }
    cipher[strlen(message)] = '\0';
    printf("Encrypted Message: %s\n", cipher);
    free(cipher);
}

void decrypt(char *message, int key) {
    char *plain = (char*)malloc((strlen(message)+1) * sizeof(char));
    
    for(int i=0; i<strlen(message); i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            plain[i] = ((message[i] - 97 - key + 26) % 26) + 97;
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            plain[i] = ((message[i] - 65 - key + 26) % 26) + 65;
        }
        else {
            plain[i] = message[i];
        }
    }
    plain[strlen(message)] = '\0';
    printf("Decrypted Message: %s\n", plain);
    free(plain);
}

int main() {
    printf("----Modern Encryption System----\n");
    char message[100];
    int key;
    int choice;
    do {
        printf("Enter 1 to Encrypt message\n");
        printf("Enter 2 to Decrypt message\n");
        printf("Enter 3 to Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the message you want to encrypt: ");
                scanf(" %[^\n]s", message);
                printf("Enter the key: ");
                scanf("%d", &key);
                encrypt(message, key);
                printf("\n");
                break;
            case 2:
                printf("Enter the message you want to decrypt: ");
                scanf(" %[^\n]s", message);
                printf("Enter the key: ");
                scanf("%d", &key);
                decrypt(message, key);
                printf("\n");
                break;
            case 3:
                printf("Thank you for using Modern Encryption System!");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 3);
    return 0;
}