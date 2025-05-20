//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum length of a line in the resume file
#define MAX_LINE_LENGTH 1024

// Define the maximum number of skills to store in the resume
#define MAX_SKILLS 10

// Define the maximum number of experiences to store in the resume
#define MAX_EXPERIENCES 10

// Define the maximum number of educations to store in the resume
#define MAX_EDUCATIONS 10

// Structure to store the information in the resume
typedef struct Resume {
    char *name;
    char *email;
    char *phone_number;
    char *skills[MAX_SKILLS];
    int num_skills;
    char *experiences[MAX_EXPERIENCES];
    int num_experiences;
    char *educations[MAX_EDUCATIONS];
    int num_educations;
} Resume;

// Function to parse a line of text and extract the name
char *parse_name(char *line) {
    // Allocate memory to store the name
    char *name = malloc(MAX_LINE_LENGTH * sizeof(char));
    
    // Copy the name from the line
    strcpy(name, line);
    
    // Return the name
    return name;
}

// Function to parse a line of text and extract the email address
char *parse_email(char *line) {
    // Allocate memory to store the email address
    char *email = malloc(MAX_LINE_LENGTH * sizeof(char));
    
    // Copy the email address from the line
    strcpy(email, line);
    
    // Return the email address
    return email;
}

// Function to parse a line of text and extract the phone number
char *parse_phone_number(char *line) {
    // Allocate memory to store the phone number
    char *phone_number = malloc(MAX_LINE_LENGTH * sizeof(char));
    
    // Copy the phone number from the line
    strcpy(phone_number, line);
    
    // Return the phone number
    return phone_number;
}

// Function to parse a line of text and extract the skills
void parse_skills(char *line, char **skills, int *num_skills) {
    // Tokenize the line by comma
    char *token = strtok(line, ",");

    // Iterate over the tokens
    while (token != NULL) {
        // Allocate memory to store the skill
        skills[*num_skills] = malloc(MAX_LINE_LENGTH * sizeof(char));

        // Copy the skill from the token
        strcpy(skills[*num_skills], token);

        // Increment the number of skills
        (*num_skills)++;

        // Get the next token
        token = strtok(NULL, ",");
    }
}

// Function to parse a line of text and extract the experiences
void parse_experiences(char *line, char **experiences, int *num_experiences) {
    // Tokenize the line by newline
    char *token = strtok(line, "\n");

    // Iterate over the tokens
    while (token != NULL) {
        // Allocate memory to store the experience
        experiences[*num_experiences] = malloc(MAX_LINE_LENGTH * sizeof(char));

        // Copy the experience from the token
        strcpy(experiences[*num_experiences], token);

        // Increment the number of experiences
        (*num_experiences)++;

        // Get the next token
        token = strtok(NULL, "\n");
    }
}

// Function to parse a line of text and extract the educations
void parse_educations(char *line, char **educations, int *num_educations) {
    // Tokenize the line by newline
    char *token = strtok(line, "\n");

    // Iterate over the tokens
    while (token != NULL) {
        // Allocate memory to store the education
        educations[*num_educations] = malloc(MAX_LINE_LENGTH * sizeof(char));

        // Copy the education from the token
        strcpy(educations[*num_educations], token);

        // Increment the number of educations
        (*num_educations)++;

        // Get the next token
        token = strtok(NULL, "\n");
    }
}

// Function to parse a resume file
Resume *parse_resume(char *filename) {
    // Open the resume file
    FILE *file = fopen(filename, "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Allocate memory to store the resume
    Resume *resume = malloc(sizeof(Resume));

    // Initialize the resume
    resume->name = NULL;
    resume->email = NULL;
    resume->phone_number = NULL;
    resume->num_skills = 0;
    resume->num_experiences = 0;
    resume->num_educations = 0;

    // Read the lines of the resume file
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        // Parse the name
        if (strstr(line, "Name:")) {
            resume->name = parse_name(line);
        }

        // Parse the email address
        else if (strstr(line, "Email:")) {
            resume->email = parse_email(line);
        }

        // Parse the phone number
        else if (strstr(line, "Phone Number:")) {
            resume->phone_number = parse_phone_number(line);
        }

        // Parse the skills
        else if (strstr(line, "Skills:")) {
            parse_skills(line, resume->skills, &resume->num_skills);
        }

        // Parse the experiences
        else if (strstr(line, "Experiences:")) {
            parse_experiences(line, resume->experiences, &resume->num_experiences);
        }

        // Parse the educations
        else if (strstr(line, "Educations:")) {
            parse_educations(line, resume->educations, &resume->num_educations);
        }
    }

    // Close the resume file
    fclose(file);

    // Return the resume
    return resume;
}

// Function to print the resume
void print_resume(Resume *resume) {
    // Print the name
    printf("Name: %s\n", resume->name);

    // Print the email address
    printf("Email: %s\n", resume->email);

    // Print the phone number
    printf("Phone Number: %s\n", resume->phone_number);

    // Print the skills
    printf("Skills: ");
    for (int i = 0; i < resume->num_skills; i++) {
        printf("%s, ", resume->skills[i]);
    }
    printf("\n");

    // Print the experiences
    printf("Experiences: ");
    for (int i = 0; i < resume->num_experiences; i++) {
        printf("%s\n", resume->experiences[i]);
    }

    // Print the educations
    printf("Educations: ");
    for (int i = 0; i < resume->num_educations; i++) {
        printf("%s\n", resume->educations[i]);
    }
}

// Main function
int main() {
    // Parse the resume file
    Resume *resume = parse_resume("resume.txt");

    // Print the resume
    print_resume(resume);

    // Free the memory allocated for the resume
    free(resume->name);
    free(resume->email);
    free(resume->phone_number);
    for (int i = 0; i < resume->num_skills; i++) {
        free(resume->skills[i]);
    }
    for (int i = 0; i < resume->num_experiences; i++) {
        free(resume->experiences[i]);
    }
    for (int i = 0; i < resume->num_educations; i++) {
        free(resume->educations[i]);
    }
    free(resume);

    return 0;
}