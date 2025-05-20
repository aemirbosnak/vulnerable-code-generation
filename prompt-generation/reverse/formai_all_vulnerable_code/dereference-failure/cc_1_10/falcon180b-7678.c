//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 50
#define DELIMITER ","

typedef struct {
    char *fields[MAX_FIELD_SIZE];
    int num_fields;
} Record;

Record records[MAX_RECORDS];
int num_records = 0;

void add_record(char *line) {
    char *token;
    int field_count = 0;

    if (num_records >= MAX_RECORDS) {
        printf("Error: Maximum number of records reached.\n");
        return;
    }

    records[num_records].num_fields = 0;

    token = strtok(line, DELIMITER);
    while (token!= NULL) {
        if (field_count >= MAX_FIELD_SIZE) {
            printf("Error: Maximum number of fields per record reached.\n");
            return;
        }

        records[num_records].fields[field_count] = malloc(strlen(token) + 1);
        strcpy(records[num_records].fields[field_count], token);

        field_count++;
        token = strtok(NULL, DELIMITER);
    }

    records[num_records].num_fields = field_count;
    num_records++;
}

void print_records() {
    int i;

    for (i = 0; i < num_records; i++) {
        printf("Record %d:\n", i);

        int j;
        for (j = 0; j < records[i].num_fields; j++) {
            printf("%s\n", records[i].fields[j]);
        }
    }
}

int main() {
    char line[1000];

    while (fgets(line, sizeof(line), stdin)!= NULL) {
        add_record(line);
    }

    print_records();

    return 0;
}