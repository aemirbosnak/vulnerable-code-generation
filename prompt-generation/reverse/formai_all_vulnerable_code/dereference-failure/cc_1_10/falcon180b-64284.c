//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LEN 50
#define MAX_ACCOUNT_NUMBER_LEN 20
#define MAX_BALANCE_LEN 15

typedef struct {
    char name[MAX_NAME_LEN];
    char account_number[MAX_ACCOUNT_NUMBER_LEN];
    char balance[MAX_BALANCE_LEN];
} record;

int main() {
    record records[MAX_RECORDS];
    int num_records = 0;
    char input_buffer[256];
    char *token;
    int i;

    printf("Enter records (name account_number balance):\n");
    while (fgets(input_buffer, sizeof(input_buffer), stdin)!= NULL) {
        token = strtok(input_buffer, " ");
        strcpy(records[num_records].name, token);
        token = strtok(NULL, " ");
        strcpy(records[num_records].account_number, token);
        token = strtok(NULL, " ");
        strcpy(records[num_records].balance, token);
        num_records++;
        if (num_records >= MAX_RECORDS) {
            break;
        }
    }

    printf("Sorting records by account number...\n");
    for (i = 0; i < num_records - 1; i++) {
        if (strcmp(records[i].account_number, records[i+1].account_number) > 0) {
            record temp = records[i];
            records[i] = records[i+1];
            records[i+1] = temp;
        }
    }

    printf("Displaying sorted records:\n");
    for (i = 0; i < num_records; i++) {
        printf("%s %s %s\n", records[i].name, records[i].account_number, records[i].balance);
    }

    return 0;
}