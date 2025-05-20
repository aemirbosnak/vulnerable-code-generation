//Falcon-180B DATASET v1.0 Category: Sorting ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold data
typedef struct {
    int id;
    char name[50];
} Record;

// Function to compare two records based on their ID
int compare(const void *a, const void *b) {
    Record *record1 = (Record *)a;
    Record *record2 = (Record *)b;

    if (record1->id < record2->id) {
        return -1;
    } else if (record1->id > record2->id) {
        return 1;
    } else {
        return 0;
    }
}

// Function to print the sorted records
void print_records(Record *records, int num_records) {
    printf("Sorted records:\n");
    for (int i = 0; i < num_records; i++) {
        printf("%d - %s\n", records[i].id, records[i].name);
    }
}

int main() {
    // Initialize the number of records
    int num_records = 0;

    // Prompt the user to enter the number of records
    printf("Enter the number of records: ");
    scanf("%d", &num_records);

    // Initialize an array of records
    Record records[num_records];

    // Prompt the user to enter the data for each record
    for (int i = 0; i < num_records; i++) {
        printf("Enter the ID and name for record %d:\n", i+1);
        scanf("%d %s", &records[i].id, records[i].name);
    }

    // Sort the records based on their ID
    qsort(records, num_records, sizeof(Record), compare);

    // Print the sorted records
    print_records(records, num_records);

    return 0;
}