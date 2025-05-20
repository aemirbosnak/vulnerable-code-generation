//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLUMNS 10

typedef struct {
    char name[50];
    int value;
} Record;

void read_database(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    Record records[MAX_ROWS];
    int num_rows = fread(records, sizeof(Record), MAX_ROWS, file);
    if (num_rows!= MAX_ROWS) {
        printf("Error reading file\n");
        exit(1);
    }

    for (int i = 0; i < num_rows; i++) {
        printf("Record %d: %s %d\n", i+1, records[i].name, records[i].value);
    }

    fclose(file);
}

void write_database(const char* filename, const Record* records, int num_rows) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    for (int i = 0; i < num_rows; i++) {
        fprintf(file, "%s %d\n", records[i].name, records[i].value);
    }

    fclose(file);
}

int main() {
    const char* filename = "database.txt";
    Record records[MAX_ROWS];

    // Create some sample records
    strcpy(records[0].name, "Alice");
    records[0].value = 25;
    strcpy(records[1].name, "Bob");
    records[1].value = 30;
    strcpy(records[2].name, "Charlie");
    records[2].value = 35;

    // Write the records to a file
    write_database(filename, records, 3);

    // Read the records from the file
    read_database(filename);

    // Add a new record to the file
    strcpy(records[3].name, "David");
    records[3].value = 40;
    write_database(filename, records, 4);

    // Read the updated records from the file
    read_database(filename);

    return 0;
}