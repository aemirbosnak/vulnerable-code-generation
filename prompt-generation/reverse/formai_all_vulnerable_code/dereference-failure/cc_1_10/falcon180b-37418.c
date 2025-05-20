//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 100
#define MAX_ADDRESS_LENGTH 200
#define MAX_PHONE_NUMBER_LENGTH 20

// Define the structure of a person's information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
} Person;

// Function to parse a resume and extract the person's information
int parse_resume(FILE *resume_file, Person *person) {
    char line[MAX_NAME_LENGTH];
    char *token;

    // Read the first line, which should contain the person's name
    if (fgets(line, MAX_NAME_LENGTH, resume_file) == NULL) {
        printf("Error: Failed to read name from resume.\n");
        return 1;
    }
    token = strtok(line, " ");
    strcpy(person->name, token);

    // Read the next line, which should contain the person's address
    if (fgets(line, MAX_ADDRESS_LENGTH, resume_file) == NULL) {
        printf("Error: Failed to read address from resume.\n");
        return 1;
    }
    strcpy(person->address, line);

    // Read the next line, which should contain the person's phone number
    if (fgets(line, MAX_PHONE_NUMBER_LENGTH, resume_file) == NULL) {
        printf("Error: Failed to read phone number from resume.\n");
        return 1;
    }
    strcpy(person->phone_number, line);

    return 0;
}

// Function to print the person's information
void print_person(Person person) {
    printf("Name: %s\n", person.name);
    printf("Address: %s\n", person.address);
    printf("Phone number: %s\n", person.phone_number);
}

// Main function
int main() {
    FILE *resume_file;
    Person person;

    // Open the resume file for reading
    resume_file = fopen("resume.txt", "r");
    if (resume_file == NULL) {
        printf("Error: Failed to open resume file.\n");
        return 1;
    }

    // Parse the resume and extract the person's information
    if (parse_resume(resume_file, &person)!= 0) {
        printf("Error: Failed to parse resume.\n");
        return 1;
    }

    // Print the person's information
    print_person(person);

    // Close the resume file
    fclose(resume_file);

    return 0;
}