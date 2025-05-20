//FormAI DATASET v1.0 Category: Banking Record System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BankRecord {
    int accountNumber;
    char accountType[20];
    double balance;
    char lastTransaction[50];
} BankRecord;

void displayTransactionHistory(BankRecord record) {
  printf("Transaction history for account %d\n", record.accountNumber);
  printf("\tLast transaction: %s\n", record.lastTransaction);
}

void updateBalance(BankRecord *record, double amount) {
  record->balance += amount;
  if (amount > 0) {
    strcpy(record->lastTransaction, "Deposit");
  } else {
    strcpy(record->lastTransaction, "Withdrawal");
  }
}

void printAccountInfo(BankRecord record) {
  printf("Account number: %d\n", record.accountNumber);
  printf("Account type: %s\n", record.accountType);
  printf("Balance: %.2lf\n\n", record.balance);
}

void initializeRecords(BankRecord *records, int size) {
  for (int i = 0; i < size; i++) {
    printf("Enter details for account %d\n", i+1);
    printf("Account number: ");
    scanf("%d", &records[i].accountNumber);
    printf("Account type: ");
    scanf("%s", records[i].accountType);
    records[i].balance = 0;
    strcpy(records[i].lastTransaction, "N/A");
    printf("\n");
  }
}

int main() {
  int numAccounts;
  printf("How many bank records would you like to create? ");
  scanf("%d", &numAccounts);

  BankRecord *bankRecords = malloc(numAccounts * sizeof(BankRecord));
  initializeRecords(bankRecords, numAccounts);

  int option = 0;

  while (option != 4) {
    printf("\nSelect an option:\n");
    printf("\t1. Make a deposit\n");
    printf("\t2. Make a withdrawal\n");
    printf("\t3. Display transaction history\n");
    printf("\t4. Quit the program\n");
    printf("Option: ");
    scanf("%d", &option);

    int accountNum;
    double amount;

    switch (option) {
      case 1:
        printf("Enter the account number: ");
        scanf("%d", &accountNum);
        printf("Enter the deposit amount: ");
        scanf("%lf", &amount);
        for (int i = 0; i < numAccounts; i++) {
          if (bankRecords[i].accountNumber == accountNum) {
            updateBalance(&bankRecords[i], amount);
            break;
          }
        }
        break;
      case 2:
        printf("Enter the account number: ");
        scanf("%d", &accountNum);
        printf("Enter the withdrawal amount: ");
        scanf("%lf", &amount);
        for (int i = 0; i < numAccounts; i++) {
          if (bankRecords[i].accountNumber == accountNum) {
            if (amount <= bankRecords[i].balance) {
              updateBalance(&bankRecords[i], -1*amount);
            } else {
              printf("Insufficient funds\n");
            }
            break;
          }
        }
        break;
      case 3:
        printf("Enter the account number: ");
        scanf("%d", &accountNum);
        for (int i = 0; i < numAccounts; i++) {
          if (bankRecords[i].accountNumber == accountNum) {
            displayTransactionHistory(bankRecords[i]);
            break;
          }
        }
        break;
      case 4:
        printf("Exiting the program\n");
        break;
      default:
        printf("Invalid option\n");
        break;
    }

    printf("\nCurrent account balances:\n");
    for (int i = 0; i < numAccounts; i++) {
      printAccountInfo(bankRecords[i]);
    }
  }

  free(bankRecords);

  return 0;
}