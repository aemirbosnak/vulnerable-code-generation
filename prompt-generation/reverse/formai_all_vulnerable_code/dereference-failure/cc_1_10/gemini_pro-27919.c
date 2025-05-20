//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the account structure
typedef struct account {
    char *name;
    double balance;
} account;

// Create a new account
account *create_account(char *name, double balance) {
    account *new_account = (account *)malloc(sizeof(account));
    new_account->name = name;
    new_account->balance = balance;
    return new_account;
}

// Deposit money into an account
void deposit(account *account, double amount) {
    account->balance += amount;
}

// Withdraw money from an account
void withdraw(account *account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds\n");
    }
}

// Transfer money between accounts
void transfer(account *from_account, account *to_account, double amount) {
    if (amount <= from_account->balance) {
        from_account->balance -= amount;
        to_account->balance += amount;
    } else {
        printf("Insufficient funds\n");
    }
}

// Print the account balance
void print_balance(account *account) {
    printf("%s: %.2f\n", account->name, account->balance);
}

// Print the accounts
void print_accounts(account **accounts, int num_accounts) {
    for (int i = 0; i < num_accounts; i++) {
        print_balance(accounts[i]);
    }
}

// Get the user input
char *get_input(char *prompt) {
    char *input = NULL;
    size_t len = 0;
    printf("%s", prompt);
    getline(&input, &len, stdin);
    return input;
}

// Get a double from the user
double get_double(char *prompt) {
    char *input = get_input(prompt);
    double value = atof(input);
    free(input);
    return value;
}

// Get an integer from the user
int get_int(char *prompt) {
    char *input = get_input(prompt);
    int value = atoi(input);
    free(input);
    return value;
}

// Main function
int main() {
    // Create the accounts
    account *checking_account = create_account("Checking", 1000.0);
    account *savings_account = create_account("Savings", 2000.0);

    // Create the accounts array
    account *accounts[] = {checking_account, savings_account};
    int num_accounts = sizeof(accounts) / sizeof(accounts[0]);

    // Print the accounts
    print_accounts(accounts, num_accounts);

    // Get the user input
    char *command = get_input("Enter a command (deposit, withdraw, transfer, balance, quit): ");

    // Process the command
    while (strcmp(command, "quit") != 0) {
        if (strcmp(command, "deposit") == 0) {
            // Get the account name
            char *account_name = get_input("Enter the account name: ");

            // Get the amount
            double amount = get_double("Enter the amount: ");

            // Deposit the money
            account *account = NULL;
            for (int i = 0; i < num_accounts; i++) {
                if (strcmp(accounts[i]->name, account_name) == 0) {
                    account = accounts[i];
                    break;
                }
            }
            if (account != NULL) {
                deposit(account, amount);
            } else {
                printf("Invalid account name\n");
            }
        } else if (strcmp(command, "withdraw") == 0) {
            // Get the account name
            char *account_name = get_input("Enter the account name: ");

            // Get the amount
            double amount = get_double("Enter the amount: ");

            // Withdraw the money
            account *account = NULL;
            for (int i = 0; i < num_accounts; i++) {
                if (strcmp(accounts[i]->name, account_name) == 0) {
                    account = accounts[i];
                    break;
                }
            }
            if (account != NULL) {
                withdraw(account, amount);
            } else {
                printf("Invalid account name\n");
            }
        } else if (strcmp(command, "transfer") == 0) {
            // Get the from account name
            char *from_account_name = get_input("Enter the from account name: ");

            // Get the to account name
            char *to_account_name = get_input("Enter the to account name: ");

            // Get the amount
            double amount = get_double("Enter the amount: ");

            // Transfer the money
            account *from_account = NULL;
            account *to_account = NULL;
            for (int i = 0; i < num_accounts; i++) {
                if (strcmp(accounts[i]->name, from_account_name) == 0) {
                    from_account = accounts[i];
                }
                if (strcmp(accounts[i]->name, to_account_name) == 0) {
                    to_account = accounts[i];
                }
            }
            if (from_account != NULL && to_account != NULL) {
                transfer(from_account, to_account, amount);
            } else {
                printf("Invalid account name\n");
            }
        } else if (strcmp(command, "balance") == 0) {
            // Get the account name
            char *account_name = get_input("Enter the account name: ");

            // Print the balance
            account *account = NULL;
            for (int i = 0; i < num_accounts; i++) {
                if (strcmp(accounts[i]->name, account_name) == 0) {
                    account = accounts[i];
                    break;
                }
            }
            if (account != NULL) {
                print_balance(account);
            } else {
                printf("Invalid account name\n");
            }
        } else {
            printf("Invalid command\n");
        }

        // Get the user input
        command = get_input("Enter a command (deposit, withdraw, transfer, balance, quit): ");
    }

    // Free the accounts
    for (int i = 0; i < num_accounts; i++) {
        free(accounts[i]->name);
        free(accounts[i]);
    }

    return 0;
}