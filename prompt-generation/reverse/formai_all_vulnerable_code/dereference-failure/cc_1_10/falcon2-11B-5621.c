//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

struct Record {
    char name[MAX_LENGTH];
    char address[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char email[MAX_LENGTH];
    char notes[MAX_LENGTH];
};

struct Record records[100];
int record_count = 0;

void add_record() {
    char name[MAX_LENGTH];
    char address[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char email[MAX_LENGTH];
    char notes[MAX_LENGTH];

    printf("Enter name: ");
    fgets(name, MAX_LENGTH, stdin);
    printf("Enter address: ");
    fgets(address, MAX_LENGTH, stdin);
    printf("Enter phone: ");
    fgets(phone, MAX_LENGTH, stdin);
    printf("Enter email: ");
    fgets(email, MAX_LENGTH, stdin);
    printf("Enter notes: ");
    fgets(notes, MAX_LENGTH, stdin);

    struct Record new_record = {
       .name = name,
       .address = address,
       .phone = phone,
       .email = email,
       .notes = notes,
    };

    if (record_count < 100) {
        records[record_count] = new_record;
        record_count++;
    } else {
        printf("Database is full!\n");
    }
}

void search_record() {
    char name[MAX_LENGTH];
    char address[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char email[MAX_LENGTH];
    char notes[MAX_LENGTH];

    printf("Enter name to search: ");
    fgets(name, MAX_LENGTH, stdin);
    printf("Enter address to search: ");
    fgets(address, MAX_LENGTH, stdin);
    printf("Enter phone to search: ");
    fgets(phone, MAX_LENGTH, stdin);
    printf("Enter email to search: ");
    fgets(email, MAX_LENGTH, stdin);
    printf("Enter notes to search: ");
    fgets(notes, MAX_LENGTH, stdin);

    int found = 0;
    for (int i = 0; i < record_count; i++) {
        struct Record record = records[i];
        if (strcmp(name, record.name) == 0 &&
            strcmp(address, record.address) == 0 &&
            strcmp(phone, record.phone) == 0 &&
            strcmp(email, record.email) == 0 &&
            strcmp(notes, record.notes) == 0) {
            printf("Record found!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record not found!\n");
    }
}

void delete_record() {
    char name[MAX_LENGTH];
    char address[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char email[MAX_LENGTH];
    char notes[MAX_LENGTH];

    printf("Enter name to delete: ");
    fgets(name, MAX_LENGTH, stdin);
    printf("Enter address to delete: ");
    fgets(address, MAX_LENGTH, stdin);
    printf("Enter phone to delete: ");
    fgets(phone, MAX_LENGTH, stdin);
    printf("Enter email to delete: ");
    fgets(email, MAX_LENGTH, stdin);
    printf("Enter notes to delete: ");
    fgets(notes, MAX_LENGTH, stdin);

    int found = 0;
    for (int i = 0; i < record_count; i++) {
        struct Record record = records[i];
        if (strcmp(name, record.name) == 0 &&
            strcmp(address, record.address) == 0 &&
            strcmp(phone, record.phone) == 0 &&
            strcmp(email, record.email) == 0 &&
            strcmp(notes, record.notes) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record not found!\n");
    } else {
        printf("Deleting record...\n");
        for (int i = found; i < record_count - 1; i++) {
            records[i] = records[i + 1];
        }
        record_count--;
    }
}

int main() {
    printf("Welcome to the Database Indexing System!\n");
    printf("1. Add Record\n");
    printf("2. Search Record\n");
    printf("3. Delete Record\n");
    printf("4. Exit\n");
    int choice;

    while (1) {
        printf("Enter your choice: ");
        fgets(choice, MAX_LENGTH, stdin);
        choice = atoi(choice);

        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                search_record();
                break;
            case 3:
                delete_record();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}