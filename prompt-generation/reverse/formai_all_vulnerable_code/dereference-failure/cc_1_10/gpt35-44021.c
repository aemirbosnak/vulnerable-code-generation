//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum size of input string
#define MAX_SIZE 1000

// Define structure to hold the parsed data
typedef struct {
    char name[50];
    char email[50];
    char skills[500];
} Resume;

// Define function to parse the input string and populate the Resume structure
void parse_resume(char *input, Resume *resume) {
    char *delimiter = ", ";
    char *token;

    // Parse name
    token = strtok(input, delimiter);
    strcpy(resume->name, token);

    // Parse email
    token = strtok(NULL, delimiter);
    strcpy(resume->email, token);

    // Parse skills
    token = strtok(NULL, delimiter);
    strcpy(resume->skills, token);

    // Print parsed data for debugging purposes
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Skills: %s\n", resume->skills);
}

int main() {
    char input[MAX_SIZE];
    Resume resume;

    // Get input string from user
    printf("Enter resume data in the format: Name, Email, Skills\n");
    fgets(input, MAX_SIZE, stdin);

    // Remove newline character from input string
    input[strcspn(input, "\n")] = '\0';

    // Parse input string
    parse_resume(input, &resume);

    // Exit program
    return 0;
}