//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_RECORDS 10

typedef struct Record
{
    char name[20];
    int account_num;
    double balance;
    struct Record* next;
} Record;

Record* head = NULL;

void add_record(char* name, int account_num, double balance)
{
    Record* new_record = malloc(sizeof(Record));

    strcpy(new_record->name, name);
    new_record->account_num = account_num;
    new_record->balance = balance;

    if (head == NULL)
    {
        head = new_record;
    }
    else
    {
        head->next = new_record;
        head = new_record;
    }
}

void check_balance(int account_num)
{
    Record* current_record = head;

    while (current_record)
    {
        if (current_record->account_num == account_num)
        {
            printf("Balance: $%.2lf\n", current_record->balance);
            break;
        }
        current_record = current_record->next;
    }

    if (current_record == NULL)
    {
        printf("Account not found.\n");
    }
}

int main()
{
    add_record("John Doe", 12345, 1000.0);
    add_record("Jane Doe", 65432, 2000.0);
    add_record("Bob Smith", 34567, 3000.0);

    check_balance(12345);
    check_balance(65432);
    check_balance(99999);

    return 0;
}