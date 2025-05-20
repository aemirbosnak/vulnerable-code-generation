//FormAI DATASET v1.0 Category: Database querying ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold data from database
typedef struct {
    int id;
    char name[50];
    int age;
    char occupation[50];
} Person;

// Function to query database based on occupation
void query_database(const char* occupation) {
    FILE* file_ptr;
    file_ptr = fopen("database.txt", "r"); // Open file for reading
    char line[100];

    // Loop through file line by line
    while (fgets(line, 100, file_ptr)) {
        char* token;
        token = strtok(line, ","); // Split line using commas
        Person person;
        int field = 0;

        // Loop through line token by token
        while (token != NULL) {
            switch (field) {
                case 0: person.id = atoi(token); break; // First field is id
                case 1: strcpy(person.name, token); break; // Second field is name
                case 2: person.age = atoi(token); break; // Third field is age
                case 3: strcpy(person.occupation, token); break; // Fourth field is occupation
                default: break;
            }
            token = strtok(NULL, ",");
            field++;
        }

        // Check if occupation matches query
        if (strcmp(person.occupation, occupation) == 0) {
            printf("ID: %d, Name: %s, Age: %d, Occupation: %s\n", person.id, person.name, person.age, person.occupation);
        }
    }

    fclose(file_ptr); // Close file
}

int main() {
    query_database("Engineer"); // Query database for all persons with occupation "Engineer"
    return 0;
}