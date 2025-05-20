//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024 // Max line length to read
#define DELIMITER "," // Delimiter character in CSV file

// Define a struct to hold each person's information from the CSV file
typedef struct Person {
    char* name;
    int age;
    char* occupation;
} Person;

// Print out a person's information
void printPerson(Person* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Occupation: %s\n", person->occupation);
}

int main() {
    char* fileName = "people.csv"; // CSV file to read
    FILE* file = fopen(fileName, "r"); // Open file for reading

    if (file == NULL) { // Check if there was an error opening the file
        printf("Error opening file: %s\n", fileName);
        return 1;
    }

    char line[MAX_LINE_LENGTH]; // Buffer to hold each line read from the file
    Person* people[100]; // Array to hold pointers to each person's struct
    int numPeople = 0; // Counter variable to keep track of number of people read

    while(fgets(line, MAX_LINE_LENGTH, file)) { // Read each line from the file
        char* token = strtok(line, DELIMITER); // Tokenize each line by the delimiter

        Person* person = (Person*)malloc(sizeof(Person)); // Allocate memory for a new person's struct

        // Process each token and assign it to the appropriate field in the Person struct
        person->name = strdup(token);
        token = strtok(NULL, DELIMITER);
        person->age = atoi(token);
        token = strtok(NULL, DELIMITER);
        person->occupation = strdup(token);

        people[numPeople] = person; // Add the new person to the array
        numPeople++; // Increment the counter
    }

    fclose(file); // Close the CSV file

    // Print out each person's information using the printPerson function
    for (int i = 0; i < numPeople; i++) {
        printPerson(people[i]);
    }

    // Free memory for each person's struct and name/occupation strings
    for (int i = 0; i < numPeople; i++) {
        free(people[i]->name);
        free(people[i]->occupation);
        free(people[i]);
    }

    return 0;
}