//FormAI DATASET v1.0 Category: Database querying ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

// Structure representing a record
typedef struct {
    char name[30];
    int age;
    char city[20];
    float salary;
} Record;

int main() {
    // Allocate memory for the records
    Record* records = (Record*)malloc(MAX_RECORDS * sizeof(Record));

    // Insert some sample records
    strcpy(records[0].name, "John");
    records[0].age = 32;
    strcpy(records[0].city, "New York");
    records[0].salary = 75000.00;

    strcpy(records[1].name, "Mary");
    records[1].age = 25;
    strcpy(records[1].city, "Chicago");
    records[1].salary = 65000.00;

    strcpy(records[2].name, "Alex");
    records[2].age = 29;
    strcpy(records[2].city, "San Francisco");
    records[2].salary = 80000.00;

    // Query records by city
    char city_query[20];
    printf("Enter city name to search records: ");
    scanf("%s", city_query);

    int matches = 0; // Counter for matching records
    for (int i = 0; i < MAX_RECORDS; i++) {
        if (strcmp(records[i].city, city_query) == 0) {
            printf("Name: %s, Age: %d, City: %s, Salary: $%.2f\n", 
                    records[i].name, records[i].age, records[i].city, records[i].salary);
            matches++;
        }
    }

    // Handle no matches found
    if (matches == 0) {
        printf("No records found for city %s.\n", city_query);
    }

    // Free memory
    free(records);

    return 0;
}