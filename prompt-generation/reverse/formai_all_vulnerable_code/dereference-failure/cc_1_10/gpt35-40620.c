//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 200
#define MAX_COLUMN_LENGTH 50
#define MAX_RECORDS 100

typedef struct record {
    char name[MAX_COLUMN_LENGTH];
    char address[MAX_COLUMN_LENGTH];
    char phone[MAX_COLUMN_LENGTH];
} Record;

int read_csv_file(char *filename, Record *records);

int main() {
    char filename[] = "data.csv";
    Record records[MAX_RECORDS];
    int num_records = read_csv_file(filename, records);

    // Printing all the records
    printf("All records:\n");
    for (int i = 0; i < num_records; i++) {
        printf("Name: %s\n", records[i].name);
        printf("Address: %s\n", records[i].address);
        printf("Phone: %s\n\n", records[i].phone);
    }

    return 0;
}

int read_csv_file(char *filename, Record *records) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int num_records = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Reading first line which contains headers
    fgets(line, MAX_LINE_LENGTH, fp);

    // Reading records
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL && num_records < MAX_RECORDS) {
        char *token;
        token = strtok(line, ",");
        strcpy(records[num_records].name, token);

        token = strtok(NULL, ",");
        strcpy(records[num_records].address, token);

        token = strtok(NULL, ",");
        strcpy(records[num_records].phone, token);

        num_records++;
    }

    fclose(fp);
    return num_records;
}