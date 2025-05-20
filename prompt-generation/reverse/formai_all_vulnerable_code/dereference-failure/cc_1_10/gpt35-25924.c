//FormAI DATASET v1.0 Category: Database simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int id;
    char* name;
    int age;
    char* address;
} Record;

#define MAX_RECORDS 100

Record* database[MAX_RECORDS];
int num_records = 0;

void add_record(int id, char* name, int age, char* address) {
    if (num_records >= MAX_RECORDS) {
        printf("Database Full! Unable to add record.\n");
        return;
    }

    Record* new_record = malloc(sizeof(Record));
    new_record->id = id;
    new_record->name = malloc(strlen(name) + 1);
    new_record->age = age;
    new_record->address = malloc(strlen(address) + 1);

    strcpy(new_record->name, name);
    strcpy(new_record->address, address);

    database[num_records] = new_record;
    num_records++;
}

void delete_record(int id) {
    for (int i = 0; i < num_records; i++) {
        if (database[i]->id == id) {
            free(database[i]->name);
            free(database[i]->address);
            free(database[i]);

            for (int j = i + 1; j < num_records; j++) {
                database[j-1] = database[j];
            }

            num_records--;
            return;
        }
    }

    printf("Record with ID %d not found.\n", id);
}

Record* find_record(int id) {
    for (int i = 0; i < num_records; i++) {
        if (database[i]->id == id) {
            return database[i];
        }
    }

    printf("Record with ID %d not found.\n", id);
    return NULL;
}

void print_record(Record* record) {
    printf("ID: %d\n", record->id);
    printf("Name: %s\n", record->name);
    printf("Age: %d\n", record->age);
    printf("Address: %s\n", record->address);
}

void print_database() {
    printf("Number of Records: %d\n", num_records);

    for (int i = 0; i < num_records; i++) {
        printf("---Record %d---\n", i+1);
        print_record(database[i]);
    }
}

int main() {
    srand(time(0));

    // Add Initial Records
    add_record(1, "Alex", 25, "123 Main St");
    add_record(2, "Chris", 32, "456 Elm St");
    add_record(3, "Sarah", 18, "789 Oak St");

    // Display Initial Database State
    print_database();
    printf("\n");

    // Add Random Records up to Max Capacity
    for (int i = 4; i <= MAX_RECORDS; i++) {
        int random_age = (rand() % 50) + 18;
        char* random_name;
        char* random_address;

        // Generate Random Name
        switch (rand() % 5) {
            case 0:
                random_name = "John";
                break;
            case 1:
                random_name = "Mary";
                break;
            case 2:
                random_name = "Tom";
                break;
            case 3:
                random_name = "Lisa";
                break;
            case 4:
                random_name = "David";
                break;
        }

        // Generate Random Address
        switch (rand() % 3) {
            case 0:
                random_address = "123 Main St";
                break;
            case 1:
                random_address = "456 Elm St";
                break;
            case 2:
                random_address = "789 Oak St";
                break;
        }

        add_record(i, random_name, random_age, random_address);
    }

    // Display Final Database State
    print_database();

    return 0;
}