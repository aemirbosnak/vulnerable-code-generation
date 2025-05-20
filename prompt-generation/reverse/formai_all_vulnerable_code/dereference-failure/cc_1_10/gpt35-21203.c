//FormAI DATASET v1.0 Category: Database querying ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_PHONE_LENGTH 15

// Define a struct to represent a person record in the database
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Person;

// Define a function that reads in a person record from the database
Person *read_person_record(int id) {
    // Open the database file for reading
    FILE *f = fopen("database.txt", "r");
    if (f == NULL) {
        printf("Error: could not open database file\n");
        return NULL;
    }

    // Read through the file line-by-line until we find the record with the given ID
    char line[MAX_NAME_LENGTH + MAX_ADDRESS_LENGTH + MAX_PHONE_LENGTH + 10];
    while (fgets(line, sizeof(line), f) != NULL) {
        // Parse the ID from the beginning of the line
        int line_id = atoi(strtok(line, "|"));

        // If this is the record we're looking for, parse the rest of the fields
        if (line_id == id) {
            Person *p = (Person *) malloc(sizeof(Person));
            p->id = line_id;
            strcpy(p->name, strtok(NULL, "|"));
            strcpy(p->address, strtok(NULL, "|"));
            strcpy(p->phone, strtok(NULL, "\n"));
            fclose(f);
            return p;
        }
    }

    // If we got here, we didn't find the record
    fclose(f);
    return NULL;
}

int main() {
    // Example usage: read in the person record with ID 1234 and print it out
    Person *p = read_person_record(1234);
    if (p == NULL) {
        printf("Error: no person record with ID 1234 found\n");
        return 1;
    }
    printf("ID: %d\nName: %s\nAddress: %s\nPhone: %s\n", p->id, p->name, p->address, p->phone);
    free(p);
    return 0;
}