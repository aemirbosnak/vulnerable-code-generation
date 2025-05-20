//FormAI DATASET v1.0 Category: Data mining ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the maximum number of records
#define MAX_RECORDS 100

// Defining the maximum length of the string fields
#define MAX_STRING_LENGTH 50

struct Record {
    int id;
    char name[MAX_STRING_LENGTH];
    int age;
};

// Function to read data from a file and store in an array of records
int read_data(struct Record *records) {
    FILE *data_file;
    char line[MAX_STRING_LENGTH];
    int num_records = 0;

    // Opening the data file
    data_file = fopen("data.txt", "r");

    // Reading the data from the file
    while (fgets(line, MAX_STRING_LENGTH, data_file)) {
        // Splitting the line into fields
        char *token = strtok(line, ",");
        records[num_records].id = atoi(token);

        token = strtok(NULL, ",");
        strcpy(records[num_records].name, token);

        token = strtok(NULL, ",");
        records[num_records].age = atoi(token);

        num_records++;
    }

    // Closing the data file
    fclose(data_file);

    return num_records;
}

// Function to print the records stored in the array
void print_records(struct Record *records, int num_records) {
    printf("\nID\tName\tAge\n");
    for (int i = 0; i < num_records; i++) {
        printf("%d\t%s\t%d\n", records[i].id, records[i].name, records[i].age);
    }
}

// Function to find the oldest person in the data
void find_oldest_person(struct Record *records, int num_records) {
    int max_age = 0;
    char oldest_person[MAX_STRING_LENGTH];

    for (int i = 0; i < num_records; i++) {
        if (records[i].age > max_age) {
            max_age = records[i].age;
            strcpy(oldest_person, records[i].name);
        }
    }

    printf("\nThe oldest person is %s with age %d\n", oldest_person, max_age);
}

int main() {
    // Creating an array of records
    struct Record records[MAX_RECORDS];

    // Reading data from a file and storing it in the array
    int num_records = read_data(records);

    // Printing the records stored in the array
    print_records(records, num_records);

    // Finding the oldest person in the data
    find_oldest_person(records, num_records);

    return 0;
}