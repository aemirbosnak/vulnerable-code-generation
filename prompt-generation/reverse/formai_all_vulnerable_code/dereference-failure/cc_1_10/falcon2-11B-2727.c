//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RECORDS 100

struct record {
    int id;
    char name[50];
    int age;
    char address[100];
};

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <database-file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    struct record records[MAX_RECORDS];
    int num_records = 0;

    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        char *token = strtok(line, ",");
        records[num_records].id = atoi(token);
        token = strtok(NULL, ",");
        strncpy(records[num_records].name, token, sizeof(records[num_records].name));
        token = strtok(NULL, ",");
        records[num_records].age = atoi(token);
        token = strtok(NULL, ",");
        strncpy(records[num_records].address, token, sizeof(records[num_records].address));
        num_records++;
    }
    fclose(fp);

    if (num_records == 0) {
        printf("No records found\n");
        return 0;
    }

    int search_id;
    printf("Enter the ID of the record you want to search for: ");
    scanf("%d", &search_id);

    for (int i = 0; i < num_records; i++) {
        if (records[i].id == search_id) {
            printf("ID: %d\n", records[i].id);
            printf("Name: %s\n", records[i].name);
            printf("Age: %d\n", records[i].age);
            printf("Address: %s\n", records[i].address);
            return 0;
        }
    }
    printf("Record not found\n");

    return 0;
}