//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cyberpunk-themed constants
#define DATA_BREACH "Data breach detected"
#define ACCESS_GRANTED "Access granted"
#define ACCESS_DENIED "Authorization failed"

typedef struct {
    char *name;
    int age;
    char *city;
} Person;

// Function to read a single line from a CSV file
char *readline(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while ((nread = getline(&line, &len, fp)) != -1) {
        // Remove trailing newline character
        if (line[nread - 1] == '\n') {
            line[nread - 1] = '\0';
        }

        // Exit if a valid line is found
        if (len > 0) {
            break;
        }
    }

    return line;
}

// Function to parse a line of CSV data into a Person struct
Person *parse_person(char *line) {
    Person *person = malloc(sizeof(Person));

    // Extract the name field
    char *name = strtok(line, ",");
    person->name = malloc(strlen(name) + 1);
    strcpy(person->name, name);

    // Extract the age field
    char *age = strtok(NULL, ",");
    person->age = atoi(age);

    // Extract the city field
    char *city = strtok(NULL, ",");
    person->city = malloc(strlen(city) + 1);
    strcpy(person->city, city);

    return person;
}

// Function to print the contents of a Person struct
void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("City: %s\n", person->city);
}

// Function to read data from a CSV file and print the contents of each Person struct
void read_csv(char *filename) {
    // Open the CSV file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror(DATA_BREACH);
        exit(1);
    }

    // Read the header line
    char *header = readline(fp);
    if (header == NULL) {
        perror(DATA_BREACH);
        exit(1);
    }

    // Read each line of data
    char *line;
    while ((line = readline(fp)) != NULL) {
        // Parse the line into a Person struct
        Person *person = parse_person(line);

        // Print the contents of the Person struct
        print_person(person);

        // Free the memory allocated for the Person struct
        free(person->name);
        free(person->city);
        free(person);
    }

    // Close the CSV file
    fclose(fp);
}

// Main function
int main(int argc, char *argv[]) {
    // Check that the user has provided a filename
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    // Get the filename from the command line
    char *filename = argv[1];

    // Check if the user has access to the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror(ACCESS_DENIED);
        exit(1);
    }

    // Grant the user access to the file
    fclose(fp);

    // Read the data from the CSV file
    read_csv(filename);

    return 0;
}