//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORD_SIZE 100

typedef struct Record {
    char name[50];
    int account_no;
    double balance;
} Record;

void create_record(Record *record) {
    printf("Enter name: ");
    scanf("%s", record->name);

    printf("Enter account number: ");
    scanf("%d", &record->account_no);

    printf("Enter initial balance: ");
    scanf("%lf", &record->balance);
}

void display_record(Record *record) {
    printf("Name: %s\n", record->name);
    printf("Account Number: %d\n", record->account_no);
    printf("Balance: %.2lf\n", record->balance);
}

int main() {
    Record *records = (Record *)malloc(MAX_RECORD_SIZE * sizeof(Record));

    int num_records = 0;

    while (1) {
        char choice;

        printf("Enter 'c' to create a new record, 'd' to display records, or 'q' to quit: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'c':
                records = (Record *)realloc(records, (num_records + 1) * sizeof(Record));
                create_record(&records[num_records]);
                num_records++;
                break;
            case 'd':
                display_record(&records[0]);
                break;
            case 'q':
                free(records);
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}