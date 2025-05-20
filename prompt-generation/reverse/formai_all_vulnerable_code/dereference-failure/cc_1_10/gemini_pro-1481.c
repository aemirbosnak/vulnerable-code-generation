//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1000

// Structure to store resume data
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills[10];
    char *education[10];
    char *experience[10];
} resume_t;

// Function to parse a line of text and extract the corresponding data
void parse_line(char *line, resume_t *resume) {
    char *token;

    // Split the line into tokens using strtok()
    token = strtok(line, ":");

    // Check if the token is empty
    if (token == NULL) {
        return;
    }

    // Extract the data based on the token
    if (strcmp(token, "Name") == 0) {
        token = strtok(NULL, ":");
        resume->name = strdup(token);
    } else if (strcmp(token, "Email") == 0) {
        token = strtok(NULL, ":");
        resume->email = strdup(token);
    } else if (strcmp(token, "Phone") == 0) {
        token = strtok(NULL, ":");
        resume->phone = strdup(token);
    } else if (strcmp(token, "Address") == 0) {
        token = strtok(NULL, ":");
        resume->address = strdup(token);
    } else if (strcmp(token, "Skills") == 0) {
        int i = 0;
        while ((token = strtok(NULL, ",")) != NULL) {
            resume->skills[i++] = strdup(token);
        }
    } else if (strcmp(token, "Education") == 0) {
        int i = 0;
        while ((token = strtok(NULL, ",")) != NULL) {
            resume->education[i++] = strdup(token);
        }
    } else if (strcmp(token, "Experience") == 0) {
        int i = 0;
        while ((token = strtok(NULL, ",")) != NULL) {
            resume->experience[i++] = strdup(token);
        }
    }
}

// Function to parse a resume file
resume_t *parse_resume(char *filename) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    resume_t *resume;

    // Allocate memory for the resume
    resume = malloc(sizeof(resume_t));

    // Open the resume file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    // Parse the resume file line by line
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        parse_line(line, resume);
    }

    // Close the resume file
    fclose(fp);

    // Return the parsed resume
    return resume;
}

// Function to print the resume
void print_resume(resume_t *resume) {
    int i;

    // Print the resume header
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);

    // Print the resume skills
    printf("Skills:\n");
    for (i = 0; i < 10; i++) {
        if (resume->skills[i] != NULL) {
            printf("  %s\n", resume->skills[i]);
        }
    }

    // Print the resume education
    printf("Education:\n");
    for (i = 0; i < 10; i++) {
        if (resume->education[i] != NULL) {
            printf("  %s\n", resume->education[i]);
        }
    }

    // Print the resume experience
    printf("Experience:\n");
    for (i = 0; i < 10; i++) {
        if (resume->experience[i] != NULL) {
            printf("  %s\n", resume->experience[i]);
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    resume_t *resume;

    // Check if the user provided a resume file
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <resume file>\n", argv[0]);
        return 1;
    }

    // Parse the resume file
    resume = parse_resume(argv[1]);

    // Print the resume
    print_resume(resume);

    return 0;
}