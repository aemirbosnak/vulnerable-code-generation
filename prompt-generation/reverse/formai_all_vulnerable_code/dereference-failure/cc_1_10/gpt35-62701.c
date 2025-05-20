//FormAI DATASET v1.0 Category: Banking Record System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BankRecord {
    char name[50];
    char account_number[20];
    float balance;
};

typedef struct BankRecord BankRecord;

void add_record(BankRecord *records, int count) {
    BankRecord record;
    printf("\nEnter name: ");
    fgets(record.name, 50, stdin);
    strtok(record.name, "\n");
    printf("Enter account number: ");
    fgets(record.account_number, 20, stdin);
    strtok(record.account_number, "\n");
    printf("Enter balance: ");
    scanf("%f", &record.balance);
    getchar();
    records[count] = record;
    printf("\nRecord added successfully!\n");
}

void display_records(BankRecord *records, int count) {
    printf("\nName\t\tAccount Number\tBalance\n");
    for(int i = 0; i < count; i++) {
        printf("%s\t\t%s\t$%.2f\n", records[i].name, records[i].account_number, records[i].balance);
    }
    printf("\n");
}

int main() {
    BankRecord *records;
    int count = 0, choice;
    char ch;
    records = (BankRecord *)malloc(sizeof(BankRecord));
    do {
        printf("\n*****Banking Record System*****\n");
        printf("1. Add a record\n");
        printf("2. Display records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch(choice) {
            case 1:
                add_record(records, count++);
                break;
            case 2:
                if(count == 0) {
                    printf("\nNo records to display.\n");
                }
                else {
                    display_records(records, count);
                }
                break;
            case 3:
                printf("\nExiting program.\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }
        printf("\nPress y to continue or any other key to exit: ");
        scanf("%c", &ch);
        getchar();
    } while(ch == 'y' || ch == 'Y');

    free(records);
    return 0;
}