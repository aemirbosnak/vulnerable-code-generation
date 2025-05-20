//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Define a structure to hold CSV data
typedef struct {
    char name[MAX_LENGTH];
    int age;
    float height;
} Person;

// Define a function to parse the CSV file and create an array of Person
Person* readCSV(char* filename, int* numPersons) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file '%s'", filename);
        return NULL;
    }

    // Allocate memory for array of Persons
    Person* persons = malloc(sizeof(Person) * MAX_LENGTH);
    if (persons == NULL) {
        fprintf(stderr, "Error: could not allocate memory");
        return NULL;
    }

    char line[MAX_LENGTH];
    int i = 0;

    // Read CSV file line by line
    while (fgets(line, MAX_LENGTH, file) != NULL) {
        char* token;
        char* rest = line;

        // Parse name field
        token = strtok_r(rest, ",", &rest);
        if (token == NULL) {
            fprintf(stderr, "Error: invalid CSV format");
            return NULL;
        }
        strcpy(persons[i].name, token);

        // Parse age field
        token = strtok_r(rest, ",", &rest);
        if (token == NULL) {
            fprintf(stderr, "Error: invalid CSV format");
            return NULL;
        }
        persons[i].age = atoi(token);

        // Parse height field
        token = strtok_r(rest, ",", &rest);
        if (token == NULL) {
            fprintf(stderr, "Error: invalid CSV format");
            return NULL;
        }
        persons[i].height = atof(token);

        i++;
    }

    *numPersons = i;

    fclose(file);

    return persons;
}

int main() {
    int numPersons;
    Person* persons = readCSV("example.csv", &numPersons);

    if (persons == NULL) {
        return 1;
    }

    for (int i = 0; i < numPersons; i++) {
        printf("Name: %s, Age: %d, Height: %.2f\n", persons[i].name, persons[i].age, persons[i].height);
    }

    free(persons);

    return 0;
}