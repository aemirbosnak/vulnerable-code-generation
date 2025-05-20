//FormAI DATASET v1.0 Category: Password management ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // Maximum number of passwords stored

struct password {
    char website[100];
    char username[50];
    char password[50];
};

void add_password(struct password passwords[]);
void view_passwords(struct password passwords[]);
void delete_password(struct password passwords[]);
void encrypt_passwords(struct password passwords[]);
void decrypt_passwords(struct password passwords[]);

int main() {
    struct password passwords[MAX];
    int choice, n = 0;
    
    do {
        printf("Password Management System \n");
        printf("1. Add a password \n");
        printf("2. View saved passwords \n");
        printf("3. Delete a password \n");
        printf("4. Encrypt saved passwords \n");
        printf("5. Decrypt saved passwords \n");
        printf("0. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_password(passwords);
                n++;
                break;
            case 2:
                view_passwords(passwords);
                break;
            case 3:
                delete_password(passwords);
                n--;
                break;
            case 4:
                encrypt_passwords(passwords);
                printf("Passwords encrypted successfully \n");
                break;
            case 5:
                decrypt_passwords(passwords);
                printf("Passwords decrypted successfully \n");
                break;
            case 0:
                printf("Exiting program... \n");
                exit(0);
            default:
                printf("Invalid choice. Please try again \n");
                break;
        }
    } while(choice != 0);
    
    return 0;
}

void add_password(struct password passwords[]) {
    char website[100], username[50], password[50];
    printf("Enter the website: ");
    scanf("%s", website);
    printf("Enter the username: ");
    scanf("%s", username);
    printf("Enter the password: ");
    scanf("%s", password);
    
    strcpy(passwords[MAX-1].website, website);
    strcpy(passwords[MAX-1].username, username);
    strcpy(passwords[MAX-1].password, password);
}

void view_passwords(struct password passwords[]) {
    int i;
    if(strlen(passwords[0].website) == 0) {
        printf("No passwords saved \n");
    } else {
        printf("%-25s %-15s %-15s \n", "Website", "Username", "Password");
        for(i=0; i<MAX; i++) {
            if(strlen(passwords[i].website) == 0) {
                break;
            }
            printf("%-25s %-15s %-15s \n", passwords[i].website, passwords[i].username, passwords[i].password);
        }
    }
}

void delete_password(struct password passwords[]) {
    int i, num;
    printf("Enter the password number to delete: ");
    scanf("%d", &num);
    
    if(num > MAX || strlen(passwords[num-1].website) == 0) {
        printf("Invalid password number. Please try again \n");
    } else {
        for(i=num-1; i<MAX-1; i++) {
            strcpy(passwords[i].website, passwords[i+1].website);
            strcpy(passwords[i].username, passwords[i+1].username);
            strcpy(passwords[i].password, passwords[i+1].password);
        }
        strcpy(passwords[MAX-1].website, "");
        strcpy(passwords[MAX-1].username, "");
        strcpy(passwords[MAX-1].password, "");
        printf("Password deleted successfully \n");
    }
}

void encrypt_passwords(struct password passwords[]) {
    int i;
    char ch;
    for(i=0; i<MAX; i++) {
        if(strlen(passwords[i].website) == 0) {
            break;
        }
        int len = strlen(passwords[i].password);
        for(int j=0; j<len; j++) {
            ch = passwords[i].password[j];
            if(ch >= 'a' && ch <= 'z'){
                ch = ch + 3;
                if(ch > 'z'){
                    ch = ch - 'z' + 'a' - 1;
                }
                passwords[i].password[j] = ch;
            }
            else if(ch >= 'A' && ch <= 'Z'){
                ch = ch + 3;
                if(ch > 'Z'){
                    ch = ch - 'Z' + 'A' - 1;
                }
                passwords[i].password[j] = ch;
            }
            else if(ch >= '0' && ch <= '9'){
                ch = ch + 3;
                if(ch > '9'){
                    ch = ch - '9' + '0' - 1;
                }
                passwords[i].password[j] = ch;
            }
        }
    }
}

void decrypt_passwords(struct password passwords[]) {
    int i;
    char ch;
    for(i=0; i<MAX; i++) {
        if(strlen(passwords[i].website) == 0) {
            break;
        }
        int len = strlen(passwords[i].password);
        for(int j=0; j<len; j++) {
            ch = passwords[i].password[j];
            if(ch >= 'a' && ch <= 'z'){
                ch = ch - 3;
                if(ch < 'a'){
                    ch = ch + 'z' - 'a' + 1;
                }
                passwords[i].password[j] = ch;
            }
            else if(ch >= 'A' && ch <= 'Z'){
                ch = ch - 3;
                if(ch < 'A'){
                    ch = ch + 'Z' - 'A' + 1;
                }
                passwords[i].password[j] = ch;
            }
            else if(ch >= '0' && ch <= '9'){
                ch = ch - 3;
                if(ch < '0'){
                    ch = ch + '9' - '0' + 1;
                }
                passwords[i].password[j] = ch;
            }
        }
    }
}