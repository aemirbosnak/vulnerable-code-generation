//FormAI DATASET v1.0 Category: Password management ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure for storing username and password
typedef struct {
    char* username;
    char* password;
} Credential;

//Function to get credentials from the user
void getCredential(Credential* credential) {
    printf("Enter username: ");
    char username[50];
    scanf("%s", username);
    credential->username = (char*) malloc(strlen(username) + 1);
    strcpy(credential->username, username);
    
    printf("Enter password: ");
    char password[50];
    scanf("%s", password);
    credential->password = (char*) malloc(strlen(password) + 1);
    strcpy(credential->password, password);
}

//Function to encrypt the password using Caesar Cipher
char* encryptPassword(char* password, int shift) {
    int len = strlen(password);
    char* encryptedPassword = (char*) malloc(len + 1);
    for(int i=0; i<len; i++) {
        if(password[i] >= 'a' && password[i] <= 'z') {
            encryptedPassword[i] = ((password[i] - 'a' + shift) % 26) + 'a';
        }
        else {
            encryptedPassword[i] = password[i];
        }
    }
    encryptedPassword[len] = '\0';
    return encryptedPassword;
}

//Function to decrypt the password
char* decryptPassword(char* encryptedPassword, int shift) {
    int len = strlen(encryptedPassword);
    char* password = (char*) malloc(len + 1);
    for(int i=0; i<len; i++) {
        if(encryptedPassword[i] >= 'a' && encryptedPassword[i] <= 'z') {
            password[i] = ((encryptedPassword[i] - 'a' - shift + 26) % 26) + 'a';
        }
        else {
            password[i] = encryptedPassword[i];
        }
    }
    password[len] = '\0';
    return password;
}

//Main function
int main() {
    int size = 10; //Maximum number of credentials to be stored
    Credential* credentials = (Credential*) malloc(size * sizeof(Credential));
    int count = 0; //Number of credentials stored
    int shift = 3; //Shift value for Caesar Cipher
    
    while(1) {
        printf("\n");
        printf("######################################\n");
        printf("## Password Management System Menu: ##\n");
        printf("######################################\n");
        printf("1. Add New Credential\n");
        printf("2. View All Credentials\n");
        printf("3. Search Credential by Username\n");
        printf("4. Delete Credential\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if(count == size) {
                    printf("Storage full! Cannot store more credentials.\n");
                }
                else {
                    Credential credential;
                    getCredential(&credential);
                    credential.password = encryptPassword(credential.password, shift);
                    credentials[count] = credential;
                    count++;
                    printf("Credential added successfully!\n");
                }
                break;
            
            case 2:
                if(count == 0) {
                    printf("No credentials found!\n");
                }
                else {
                    printf("\nAll Credentials:\n");
                    for(int i=0; i<count; i++) {
                        printf("Username: %s, Password: %s\n", credentials[i].username, decryptPassword(credentials[i].password, shift));
                    }
                }
                break;
            
            case 3:
                if(count == 0) {
                    printf("No credentials found!\n");
                }
                else {
                    printf("Enter username to search: ");
                    char username[50];
                    scanf("%s", username);
                    int flag = 0;
                    for(int i=0; i<count; i++) {
                        if(strcmp(credentials[i].username, username) == 0) {
                            printf("Credential found! Username: %s, Password: %s\n", credentials[i].username, decryptPassword(credentials[i].password, shift));
                            flag = 1;
                            break;
                        }
                    }
                    if(!flag) {
                        printf("Credential not found for the given username!\n");
                    }
                }
                break;
            
            case 4:
                if(count == 0) {
                    printf("No credentials found!\n");
                }
                else {
                    printf("Enter username to delete: ");
                    char username[50];
                    scanf("%s", username);
                    int flag = 0;
                    for(int i=0; i<count; i++) {
                        if(strcmp(credentials[i].username, username) == 0) {
                            for(int j=i; j<count-1; j++) {
                                credentials[j] = credentials[j+1];
                            }
                            count--;
                            printf("Credential deleted successfully!\n");
                            flag = 1;
                            break;
                        }
                    }
                    if(!flag) {
                        printf("Credential not found for the given username!\n");
                    }
                }
                break;
            
            case 5:
                printf("Exiting...\n");
                exit(0);
                break;
            
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
}