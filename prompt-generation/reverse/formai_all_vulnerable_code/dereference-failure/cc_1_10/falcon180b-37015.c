//Falcon-180B DATASET v1.0 Category: File handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

typedef struct {
    char *name;
    int age;
    char *address;
} Person;

int main() {
    FILE *fp;
    char filename[50] = "data.txt";
    Person *person;
    int count = 0;
    char line[MAX_LINE_SIZE];

    // Open the file
    fp = fopen(filename, "r");

    // Check if the file is opened successfully
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Allocate memory for the person structure
    person = (Person *)malloc(sizeof(Person));

    // Read the data from the file
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        // Split the line into fields
        char *token = strtok(line, ",");
        person->name = (char *)malloc(strlen(token) + 1);
        strcpy(person->name, token);

        token = strtok(NULL, ",");
        person->age = atoi(token);

        token = strtok(NULL, ",");
        person->address = (char *)malloc(strlen(token) + 1);
        strcpy(person->address, token);

        // Print the data
        printf("Name: %s\nAge: %d\nAddress: %s\n\n", person->name, person->age, person->address);

        // Free the memory allocated for the person structure
        free(person->name);
        free(person->address);
        free(person);

        // Allocate memory for the next person structure
        person = (Person *)malloc(sizeof(Person));
        count++;
    }

    // Close the file
    fclose(fp);

    // Print the total number of records
    printf("Total records: %d\n", count);

    return 0;
}