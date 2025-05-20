//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100

// Function to split a line into tokens
void split_line(char *line, char **tokens, int *num_tokens) {
    char *token;
    int i = 0;

    // Initialize the first token
    token = strtok(line, " ");

    // Loop through the rest of the line
    while (token!= NULL && i < MAX_TOKENS) {
        tokens[i] = token;
        i++;

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Set the number of tokens
    *num_tokens = i;
}

// Function to parse a resume
void parse_resume(char *filename, void (*callback)(char **)) {
    FILE *fp;
    char line[1024];
    int num_tokens;
    char **tokens;

    // Open the file
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    // Loop through each line
    while (fgets(line, sizeof(line), fp)!= NULL) {
        // Split the line into tokens
        split_line(line, tokens, &num_tokens);

        // Call the callback function
        callback(tokens);
    }

    // Close the file
    fclose(fp);
}

// Function to print the name and email
void print_name_email(char **tokens) {
    printf("Name: %s\n", tokens[0]);
    printf("Email: %s\n", tokens[1]);
}

// Function to print the education
void print_education(char **tokens) {
    printf("Education:\n");
    printf("School: %s\n", tokens[0]);
    printf("Degree: %s\n", tokens[1]);
    printf("GPA: %s\n", tokens[2]);
}

// Function to print the work experience
void print_work_experience(char **tokens) {
    printf("Work Experience:\n");
    printf("Company: %s\n", tokens[0]);
    printf("Position: %s\n", tokens[1]);
    printf("Duration: %s\n", tokens[2]);
}

// Function to print the skills
void print_skills(char **tokens) {
    printf("Skills:\n");
    for (int i = 0; i < 3; i++) {
        printf("- %s\n", tokens[i]);
    }
}

// Main function
int main() {
    // Parse the resume
    parse_resume("resume.txt", print_name_email);
    parse_resume("resume.txt", print_education);
    parse_resume("resume.txt", print_work_experience);
    parse_resume("resume.txt", print_skills);

    return 0;
}