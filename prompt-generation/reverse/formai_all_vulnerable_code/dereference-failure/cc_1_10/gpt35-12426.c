//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a row in the csv file
typedef struct {
    char name[50];
    int age;
    char city[50];
} Person;

// Function to parse a single row in the csv file
Person parse_row(char *row) {
    char *token;
    Person p;

    // Get the name
    token = strtok(row, ",");
    strcpy(p.name, token);

    // Get the age
    token = strtok(NULL, ",");
    p.age = atoi(token);

    // Get the city
    token = strtok(NULL, ",");
    strcpy(p.city, token);

    return p;
}

int main() {
    FILE *fp; // File pointer
    char *line = NULL; // Pointer to store each line in the file
    size_t len = 0; // Length of each line
    ssize_t read; // Number of characters read in each line
    int i = 0; // Counter for number of rows

    // Open the csv file
    fp = fopen("people.csv", "r");

    // Check if the file was successfully opened
    if (fp == NULL) {
        printf("Error opening file\n");
        return EXIT_FAILURE;
    }

    // Print a surprised message
    printf("Ahoy! I'm a CSV reader program! Here are the people in the file:\n");

    // Read each line in the file
    while ((read = getline(&line, &len, fp)) != -1) {
        // Parse the row
        Person p = parse_row(line);

        // Print the person's information
        printf("%d. Name: %s, Age: %d, City: %s\n", i+1, p.name, p.age, p.city);

        // Increment the row counter
        i++;
    }

    // Close the file and free the memory used by the line
    fclose(fp);
    if (line) {
        free(line);
    }

    // Print a closing message
    printf("That's all the people there are. Bye bye!\n");

    return 0;
}