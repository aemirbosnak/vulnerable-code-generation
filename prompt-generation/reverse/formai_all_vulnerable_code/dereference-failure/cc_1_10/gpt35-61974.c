//FormAI DATASET v1.0 Category: Password management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *username;
    char *password;
} Account;

Account *accounts;
int num_accounts = 0;

void add_account() {
    accounts = realloc(accounts, (num_accounts+1)*sizeof(Account));
    printf("Enter username: ");
    char buffer[50];
    scanf("%s", buffer);
    accounts[num_accounts].username = malloc(strlen(buffer)+1);
    strcpy(accounts[num_accounts].username, buffer);
    printf("Enter password: ");
    scanf("%s", buffer);
    accounts[num_accounts].password = malloc(strlen(buffer)+1);
    strcpy(accounts[num_accounts].password, buffer);
    num_accounts++;
}

void list_accounts() {
    printf("Username\tPassword\n");
    for (int i=0; i<num_accounts; i++) {
        printf("%s\t\t%s\n", accounts[i].username, accounts[i].password);
    }
}

void delete_account() {
    list_accounts();
    printf("Enter account to delete: ");
    int account_num;
    scanf("%d", &account_num);
    if (account_num < 1 || account_num > num_accounts) {
        printf("Invalid account number\n");
        return;
    }
    account_num--;
    free(accounts[account_num].username);
    free(accounts[account_num].password);
    for (int i=account_num; i<num_accounts-1; i++) {
        accounts[i].username = accounts[i+1].username;
        accounts[i].password = accounts[i+1].password;
    }
    accounts = realloc(accounts, (num_accounts-1)*sizeof(Account));
    num_accounts--;
    printf("Account deleted\n");
}

int main() {
    int choice;
    do{
        printf("\nC Password Management\n");
        printf("1) Add account\n");
        printf("2) List accounts\n");
        printf("3) Delete account\n");
        printf("4) Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_account();
                break;
            case 2:
                list_accounts();
                break;
            case 3:
                delete_account();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while(choice != 4);
    for (int i=0; i<num_accounts; i++) {
        free(accounts[i].username);
        free(accounts[i].password);
    }
    free(accounts);
    return 0;
}