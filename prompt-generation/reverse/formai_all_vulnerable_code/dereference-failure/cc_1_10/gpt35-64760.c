//FormAI DATASET v1.0 Category: Banking Record System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Record {
    char* name;
    char* account_number;
    float balance;
    struct Record* next;
} Record;

Record* head = NULL;
Record* tail = NULL;

char* prompt(char* message) {
    printf("%s", message);
    char* input = malloc(100);
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;
    return input;
}

Record* create_record(char* name, char* account_number, float balance) {
    Record* record = malloc(sizeof(Record));
    record->name = strdup(name);
    record->account_number = strdup(account_number);
    record->balance = balance;
    record->next = NULL;
    return record;
}

void add_record(char* name, char* account_number, float balance) {
    Record* record = create_record(name, account_number, balance);
    if (head == NULL) {
        head = record;
        tail = head;
    } else {
        tail->next = record;
        tail = tail->next;
    }
}

void print_records() {
    Record* current_record = head;
    while (current_record != NULL) {
        printf("%s: %s - %.2f\n", current_record->name, current_record->account_number, current_record->balance);
        current_record = current_record->next;
    }
}

void deposit(char* account_number, float amount) {
    Record* current_record = head;
    while (current_record != NULL) {
        if (strcmp(current_record->account_number, account_number) == 0) {
            current_record->balance += amount;
            printf("Deposited %.2f into account %s\n", amount, account_number);
            return;
        }
        current_record = current_record->next;
    }
    printf("Account %s not found\n", account_number);
}

void withdraw(char* account_number, float amount) {
    Record* current_record = head;
    while (current_record != NULL) {
        if (strcmp(current_record->account_number, account_number) == 0) {
            if (current_record->balance >= amount) {
                current_record->balance -= amount;
                printf("Withdrew %.2f from account %s\n", amount, account_number);
            } else {
                printf("Insufficient funds in account %s\n", account_number);
            }
            return;
        }
        current_record = current_record->next;
    }
    printf("Account %s not found\n", account_number);
}

int main() {
    while (1) {
        char* command = prompt("Enter command (a - add record, p - print records, d - deposit, w - withdraw, q - quit): ");
        if (strcmp(command, "a") == 0) {
            char* name = prompt("Enter name: ");
            char* account_number = prompt("Enter account number: ");
            float balance = atof(prompt("Enter starting balance: "));
            add_record(name, account_number, balance);
        } else if (strcmp(command, "p") == 0) {
            print_records();
        } else if (strcmp(command, "d") == 0) {
            char* account_number = prompt("Enter account number: ");
            float amount = atof(prompt("Enter amount to deposit: "));
            deposit(account_number, amount);
        } else if (strcmp(command, "w") == 0) {
            char* account_number = prompt("Enter account number: ");
            float amount = atof(prompt("Enter amount to withdraw: "));
            withdraw(account_number, amount);
        } else if (strcmp(command, "q") == 0) {
            break;
        }
    }
    return 0;
}