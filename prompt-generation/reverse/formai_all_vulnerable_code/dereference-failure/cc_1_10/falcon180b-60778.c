//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    char *name;
    int age;
} Person;

typedef struct {
    char *name;
    int age;
    int id;
} Row;

int main() {
    Person *people = malloc(sizeof(Person) * MAX_ROWS);
    Row *rows = malloc(sizeof(Row) * MAX_ROWS);
    int num_rows = 0;

    // Initialize data
    for (int i = 0; i < MAX_ROWS; i++) {
        people[i].name = malloc(50);
        people[i].age = i;
    }

    // Insert data into database
    for (int i = 0; i < MAX_ROWS; i++) {
        rows[num_rows].name = strdup(people[i].name);
        rows[num_rows].age = people[i].age;
        rows[num_rows].id = i;
        num_rows++;
    }

    // Query data from database
    char *query = "SELECT * FROM people WHERE age > 25";
    int num_results = 0;
    for (int i = 0; i < MAX_ROWS; i++) {
        if (people[i].age > 25) {
            printf("Name: %s\nAge: %d\nID: %d\n", people[i].name, people[i].age, i);
            num_results++;
        }
    }
    printf("Number of results: %d\n", num_results);

    // Close database connection
    free(rows);
    free(people);
    return 0;
}