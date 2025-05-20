//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

typedef struct {
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
    int age;
} Person;

int main() {

    // Open the CSV file for reading
    FILE* file = fopen("people.csv", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char line[MAX_LENGTH];
    char* token;
    Person person;

    // Read the first line of the CSV file (headers)
    fgets(line, MAX_LENGTH, file);

    // Read each line of the CSV file and parse the data
    while (fgets(line, MAX_LENGTH, file)) {
        memset(&person, 0, sizeof(Person));
        token = strtok(line, ",");
        strcpy(person.name, token);
        token = strtok(NULL, ",");
        strcpy(person.email, token);
        token = strtok(NULL, ",");
        person.age = atoi(token);

        // Print the data that has been read and parsed
        printf("Name: %s\n", person.name);
        printf("Email: %s\n", person.email);
        printf("Age: %d\n", person.age);
        printf("\n");
    }

    // Close the CSV file
    fclose(file);

    return 0;
}