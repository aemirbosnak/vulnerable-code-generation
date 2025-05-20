//FormAI DATASET v1.0 Category: Banking Record System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for bank account record
typedef struct{
    int account_number;
    char account_name[50];
    float account_balance;
} Account;

// Global variables
int num_accounts = 0;
Account *accounts;

// Function prototypes
void add_account();
void display_accounts();
void save_accounts();

int main(){
    int choice;

    // Allocate memory for array of accounts
    accounts = malloc(sizeof(Account));

    // Load accounts from file
    FILE *file = fopen("accounts.txt", "r");
    if (file != NULL){
        while (!feof(file)){
            int num_read = fscanf(file, "%d,%[^,],%f", 
                                &accounts[num_accounts].account_number,
                                accounts[num_accounts].account_name, 
                                &accounts[num_accounts].account_balance);
            if (num_read == 3){
                num_accounts++;
                accounts = realloc(accounts, sizeof(Account) * (num_accounts + 1));
            }
        }
        fclose(file);
    }

    // Display menu and get user choice
    do {
        printf("\nC BANKING RECORD SYSTEM\n");
        printf("1. Add Account\n");
        printf("2. Display Accounts\n");
        printf("3. Save Accounts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Call appropriate function based on user input
        switch(choice){
            case 1:
                add_account();
                break;
            case 2:
                display_accounts();
                break;
            case 3:
                save_accounts();
                break;
            case 4:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }

    } while (choice != 4);

    // Free memory for array of accounts
    free(accounts);

    return 0;
}

// Adds a new account to the array
void add_account(){
    Account new_account;

    printf("\nEnter account number: ");
    scanf("%d", &new_account.account_number);

    printf("Enter account name: ");
    scanf(" %[^\n]s", new_account.account_name);

    printf("Enter account balance: ");
    scanf("%f", &new_account.account_balance);

    accounts[num_accounts++] = new_account;
    accounts = realloc(accounts, sizeof(Account) * (num_accounts + 1));
    printf("Account added successfully.\n");
}

// Displays all the accounts in the array
void display_accounts(){
    if (num_accounts == 0){
        printf("\nNo accounts found.\n");
        return;
    }

    printf("\n%-20s %-20s %-20s\n", "Account Number", "Account Name", "Account Balance");
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < num_accounts; i++){
        printf("%-20d %-20s %-20.2f\n", 
                accounts[i].account_number, 
                accounts[i].account_name, 
                accounts[i].account_balance);
    }
}

// Saves all accounts to file
void save_accounts(){
    if (num_accounts == 0){
        printf("\nNo accounts found.\n");
        return;
    }

    FILE *file = fopen("accounts.txt", "w");

    for (int i = 0; i < num_accounts; i++){
        fprintf(file, "%d,%s,%.2f\n", 
                accounts[i].account_number, 
                accounts[i].account_name, 
                accounts[i].account_balance);
    }

    fclose(file);
    printf("\nAccounts saved to file.\n");
}