//FormAI DATASET v1.0 Category: Password management ; Style: bold
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 25
#define MAX_ACCOUNTS 100

struct Account {
    char username[25];
    char password[25];
};

struct Database {
    struct Account accounts[MAX_ACCOUNTS];
    int num_accounts;
};

void add_account(struct Database *db);
void print_accounts(struct Database db);
void change_password(struct Database *db, char *username, char *old_password, char *new_password);
int password_strength(char *password, int length);

int main() {
    struct Database db;
    db.num_accounts = 0;
    
    int option;
    char username[25], old_password[MAX_PASSWORD_LENGTH], new_password[MAX_PASSWORD_LENGTH], temp_password[MAX_PASSWORD_LENGTH];
    
    printf("\nWelcome to Password Management Program\n");
    printf("----------------------------\n");
    
    do {
        printf("1. Add an account\n");
        printf("2. Print all accounts\n");
        printf("3. Change password\n");
        printf("4. Exit Program\n");
        
        printf("\nEnter your choice: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                add_account(&db);
                break;
            case 2:
                print_accounts(db);
                break;
            case 3:
                printf("\nEnter your username: ");
                scanf("%s", username);
                
                printf("Enter your old password: ");
                scanf("%s", old_password);
                
                printf("Enter your new password: ");
                scanf("%s", new_password);
                
                change_password(&db, username, old_password, new_password);
                break;
            case 4:
                printf("\nThank You for using Password Management Program\n");
                break;
            default:
                printf("\nInvalid Option! Try Again!\n");
        }
        
    } while(option != 4);
    
    return 0;
}

void add_account(struct Database *db) {
    if(db->num_accounts < MAX_ACCOUNTS) {
        printf("\nEnter your username: ");
        scanf("%s", db->accounts[db->num_accounts].username);
        
        printf("Enter your password: ");
        scanf("%s", db->accounts[db->num_accounts].password);
        
        if(password_strength(db->accounts[db->num_accounts].password, strlen(db->accounts[db->num_accounts].password)) < 3) {
            printf("\nWeak password! Try Again!\n");
            return;
        }
        
        printf("\nAccount Added Successfully!\n");
        db->num_accounts++;
    }
    else {
        printf("\nDatabase is Full! Cannot Add New Account!\n");
    }
}

void print_accounts(struct Database db) {
    if(db.num_accounts == 0) {
        printf("\nDatabase is empty! Cannot Print Accounts!\n");
        return;
    }
    
    printf("\nAll Accounts in Database:\n");
    for(int i = 0; i < db.num_accounts; i++)
        printf("%s\n", db.accounts[i].username);
}

void change_password(struct Database *db, char *username, char *old_password, char *new_password) {
    for(int i = 0; i < db->num_accounts; i++) {
        if(strcmp(db->accounts[i].username, username) == 0) {
            if(strcmp(db->accounts[i].password, old_password) == 0) {
                if(password_strength(new_password, strlen(new_password)) < 3) {
                    printf("\nWeak password! Try Again!\n");
                    return;
                }
                
                strcpy(db->accounts[i].password, new_password);
                printf("\nPassword Changed Successfully!\n");
                return;
            }
            else {
                printf("\nInvalid Old Password! Try Again!\n");
                return;
            }
        }
    }
    
    printf("\nNo Such Account Found! Try Again!\n");
}

int password_strength(char *password, int length) {
    int strength = 0;
    
    if(length >= 8)
        strength++;
    
    if(length >= 12)
        strength++;
    
    if(length >= 16)
        strength++;
    
    for(int i = 0; i < length; i++) {
        if(password[i] >= 'A' && password[i] <= 'Z') {
            strength++;
            break;
        }
    }
    
    for(int i = 0; i < length; i++) {
        if(password[i] >= 'a' && password[i] <= 'z') {
            strength++;
            break;
        }
    }
    
    for(int i = 0; i < length; i++) {
        if(password[i] >= '0' && password[i] <= '9') {
            strength++;
            break;
        }
    }
    
    return strength;
}