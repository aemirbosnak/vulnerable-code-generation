//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100

typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Customer;

Customer* customers[MAX_CUSTOMERS];
int customerCount = 0;

void printMenu() {
    printf("=== Banking Record System ===\n");
    printf("1. Add Customer\n");
    printf("2. View All Customers\n");
    printf("3. Deposit Money\n");
    printf("4. Withdraw Money\n");
    printf("5. Search Customer\n");
    printf("6. Exit\n");
    printf("============================\n");
    printf("Enter your choice: ");
}

void addCustomer() {
    if (customerCount >= MAX_CUSTOMERS) {
        printf("Customer limit reached! Cannot add more customers.\n");
        return;
    }
    
    Customer* newCustomer = (Customer*)malloc(sizeof(Customer));
    printf("Enter account number: ");
    scanf("%d", &newCustomer->accountNumber);
    printf("Enter name: ");
    scanf(" %[^\n]", newCustomer->name);
    newCustomer->balance = 0.0f; // Initial balance

    customers[customerCount] = newCustomer;
    customerCount++;
    
    printf("Customer added successfully!\n");
}

void viewCustomers() {
    if (customerCount == 0) {
        printf("No customers to display.\n");
        return;
    }
    
    printf("Customer List:\n");
    for (int i = 0; i < customerCount; i++) {
        printf("Account Number: %d | Name: %s | Balance: %.2f\n", 
                customers[i]->accountNumber, customers[i]->name, customers[i]->balance);
    }
}

void depositMoney() {
    int accNum;
    float amount;

    printf("Enter account number to deposit: ");
    scanf("%d", &accNum);
    
    for (int i = 0; i < customerCount; i++) {
        if (customers[i]->accountNumber == accNum) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            customers[i]->balance += amount;
            printf("Deposit successful! New balance: %.2f\n", customers[i]->balance);
            return;
        }
    }
    
    printf("Account not found.\n");
}

void withdrawMoney() {
    int accNum;
    float amount;

    printf("Enter account number to withdraw: ");
    scanf("%d", &accNum);
    
    for (int i = 0; i < customerCount; i++) {
        if (customers[i]->accountNumber == accNum) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > customers[i]->balance) {
                printf("Insufficient funds. Withdrawal failed.\n");
            } else {
                customers[i]->balance -= amount;
                printf("Withdrawal successful! New balance: %.2f\n", customers[i]->balance);
            }
            return;
        }
    }
    
    printf("Account not found.\n");
}

void searchCustomer() {
    int accNum;

    printf("Enter account number to search: ");
    scanf("%d", &accNum);
    
    for (int i = 0; i < customerCount; i++) {
        if (customers[i]->accountNumber == accNum) {
            printf("Account Number: %d | Name: %s | Balance: %.2f\n", 
                    customers[i]->accountNumber, customers[i]->name, customers[i]->balance);
            return;
        }
    }
    
    printf("Account not found.\n");
}

int main() {
    int choice;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                viewCustomers();
                break;
            case 3:
                depositMoney();
                break;
            case 4:
                withdrawMoney();
                break;
            case 5:
                searchCustomer();
                break;
            case 6:
                // Free dynamic memory before exiting
                for (int i = 0; i < customerCount; i++) {
                    free(customers[i]);
                }
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}