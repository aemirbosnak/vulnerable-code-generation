//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNT_NUMBER_LEN 10
#define MAX_NAME_LEN 50
#define MAX_AMOUNT_LEN 10

#define TRUE 1
#define FALSE 0

typedef struct {
    int account_number;
    char name[MAX_NAME_LEN];
    float amount;
} Record;

typedef struct {
    char name[MAX_NAME_LEN];
    int account_number;
    float balance;
} Account;

void create_new_record(Record *record, Account *account) {
    printf("Enter the account number: ");
    scanf("%d", &record->account_number);
    printf("Enter the name: ");
    scanf("%s", record->name);
    printf("Enter the amount: ");
    scanf("%f", &record->amount);
    account->balance += record->amount;
}

void modify_record(Record *record, Account *account) {
    printf("Enter the account number: ");
    scanf("%d", &record->account_number);
    printf("Enter the name: ");
    scanf("%s", record->name);
    printf("Enter the amount: ");
    scanf("%f", &record->amount);
    account->balance += record->amount;
}

void delete_record(Record *record, Account *account) {
    printf("Enter the account number: ");
    scanf("%d", &record->account_number);
    printf("Enter the name: ");
    scanf("%s", record->name);
    account->balance -= record->amount;
    free(record);
}

void retrieve_record(Record *record, Account *account) {
    printf("Enter the account number: ");
    scanf("%d", &record->account_number);
    printf("Enter the name: ");
    scanf("%s", record->name);
    printf("The account balance is %f\n", account->balance);
}

void save_records(Record *records, Account *account) {
    FILE *fp;
    fp = fopen("records.txt", "w");
    for (int i = 0; i < 10; i++) {
        Record *record = &records[i];
        fprintf(fp, "%d\t%s\t%f\n", record->account_number, record->name, record->amount);
    }
    fclose(fp);
}

void load_records(Record *records, Account *account) {
    FILE *fp;
    fp = fopen("records.txt", "r");
    int record_index = 0;
    while (fscanf(fp, "%d\t%s\t%f\n", &records[record_index].account_number, records[record_index].name, &records[record_index].amount)!= EOF) {
        record_index++;
    }
    fclose(fp);
}

int main() {
    Record records[10];
    Account account;
    account.balance = 0.0;

    while (1) {
        printf("1. Create a new record\n");
        printf("2. Modify an existing record\n");
        printf("3. Delete a record\n");
        printf("4. Retrieve a record\n");
        printf("5. Save records\n");
        printf("6. Load records\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Creating a new record...\n");
                create_new_record(&records[0], &account);
                save_records(records, &account);
                break;
            case 2:
                printf("Modifying a record...\n");
                modify_record(&records[0], &account);
                save_records(records, &account);
                break;
            case 3:
                printf("Deleting a record...\n");
                delete_record(&records[0], &account);
                save_records(records, &account);
                break;
            case 4:
                printf("Retrieving a record...\n");
                retrieve_record(&records[0], &account);
                break;
            case 5:
                printf("Saving records...\n");
                save_records(records, &account);
                break;
            case 6:
                printf("Loading records...\n");
                load_records(records, &account);
                break;
            case 7:
                printf("Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}