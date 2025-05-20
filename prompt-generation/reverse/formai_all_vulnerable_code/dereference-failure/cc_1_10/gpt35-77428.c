//FormAI DATASET v1.0 Category: Database querying ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store table rows
struct student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    // Open the database connection
    FILE *db = fopen("students.db", "rb");
    if (db == NULL) {
        printf("Error: Could not open database\n");
        return 1;
    }

    // Determine the number of records in the database
    fseek(db, 0L, SEEK_END);
    long num_records = ftell(db) / sizeof(struct student);
    rewind(db);

    // Allocate memory for an array of structs to store all the rows
    struct student *students = (struct student*)malloc(num_records * sizeof(struct student));

    // Read all the rows into memory
    fread(students, sizeof(struct student), num_records, db);

    // Query the database
    printf("Enter a name to search for: ");
    char query_name[50];
    scanf("%s", query_name);

    // Use linear search to find all rows with the matching name
    int num_matches = 0;
    for (int i = 0; i < num_records; i++) {
        if (strcmp(students[i].name, query_name) == 0) {
            num_matches++;
            printf("%s\t%d\t%.2f\n", students[i].name, students[i].age, students[i].gpa);
        }
    }

    // Print the number of matches found
    printf("Found %d matches\n", num_matches);

    // Close the database connection and free memory
    fclose(db);
    free(students);

    return 0;
}