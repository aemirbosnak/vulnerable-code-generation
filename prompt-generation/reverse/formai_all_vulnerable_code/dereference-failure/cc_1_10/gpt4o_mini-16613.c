//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LEN 50
#define FILE_NAME "bank_records.dat"

typedef struct {
    int account_number;
    char name[NAME_LEN];
    float balance;
} Account;

void addAccount();
void viewAccounts();
void deleteAccount();
void saveAccount(Account account);
Account* loadAccounts(int *count);

int main() {
    int choice;

    while (1) {
        printf("Welcome to the Banking Record System\n");
        printf("1. Add Account\n");
        printf("2. View Accounts\n");
        printf("3. Delete Account\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAccount();
                break;
            case 2:
                viewAccounts();
                break;
            case 3:
                deleteAccount();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

void addAccount() {
    Account new_account;
    printf("Enter account number: ");
    scanf("%d", &new_account.account_number);
    printf("Enter account holder's name: ");
    getchar(); // Clear the newline character
    fgets(new_account.name, NAME_LEN, stdin);
    new_account.name[strcspn(new_account.name, "\n")] = 0; // Remove newline
    printf("Enter initial balance: ");
    scanf("%f", &new_account.balance);

    saveAccount(new_account);
    printf("Account created successfully!\n");
}

void saveAccount(Account account) {
    FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        perror("Failed to open file");
        exit(1);
    }
    fwrite(&account, sizeof(Account), 1, file);
    fclose(file);
}

void viewAccounts() {
    int count;
    Account *accounts = loadAccounts(&count);
    
    printf("\nAll Accounts:\n");
    printf("----------------------------------------------------\n");
    printf("%-15s %-20s %-10s\n", "Account Number", "Account Holder", "Balance");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-15d %-20s %-10.2f\n", accounts[i].account_number, accounts[i].name, accounts[i].balance);
    }
    printf("----------------------------------------------------\n\n");

    free(accounts);
}

Account* loadAccounts(int *count) {
    *count = 0;
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        perror("Failed to open file");
        *count = 0;
        return NULL;
    }

    Account *accounts = malloc(MAX_ACCOUNTS * sizeof(Account));
    if (!accounts) {
        perror("Failed to allocate memory");
        exit(1);
    }

    while (fread(&accounts[*count], sizeof(Account), 1, file) == 1) {
        (*count)++;
        if (*count >= MAX_ACCOUNTS) {
            break; // Reach maximum accounts
        }
    }

    fclose(file);
    return accounts;
}

void deleteAccount() {
    int acc_num;
    printf("Enter account number to delete: ");
    scanf("%d", &acc_num);

    int count;
    Account *accounts = loadAccounts(&count);
    FILE *file = fopen(FILE_NAME, "w");
    if (!file) {
        perror("Failed to open file");
        free(accounts);
        return;
    }

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (accounts[i].account_number != acc_num) {
            fwrite(&accounts[i], sizeof(Account), 1, file);
        } else {
            found = 1;
        }
    }
    
    fclose(file);
    free(accounts);

    if (found) {
        printf("Account number %d deleted successfully!\n", acc_num);
    } else {
        printf("Account number %d not found!\n", acc_num);
    }
}