//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORD_NUM 10

typedef struct Record {
    char name[50];
    int account_num;
    double balance;
    struct Record* next;
} Record;

Record* head = NULL;

void add_record(char* name, int account_num, double balance) {
    Record* new_record = malloc(sizeof(Record));
    strcpy(new_record->name, name);
    new_record->account_num = account_num;
    new_record->balance = balance;
    new_record->next = head;
    head = new_record;
}

void print_records() {
    Record* current = head;
    while (current) {
        printf("%s (%d) - Balance: %.2lf\n", current->name, current->account_num, current->balance);
        current = current->next;
    }
}

void update_balance(int account_num, double new_balance) {
    Record* current = head;
    while (current) {
        if (current->account_num == account_num) {
            current->balance = new_balance;
            return;
        }
        current = current->next;
    }

    printf("Account not found.\n");
}

int main() {
    add_record("John Doe", 123456, 1000.0);
    add_record("Jane Doe", 654321, 2000.0);
    add_record("Bob Smith", 789412, 3000.0);

    print_records();

    update_balance(123456, 1500.0);

    print_records();

    return 0;
}