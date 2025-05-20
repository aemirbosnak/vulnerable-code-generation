//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store resume data
typedef struct Resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills[10];
    int num_skills;
} Resume;

// Function to parse a resume file
Resume *parse_resume(char *filename) {
    // Open the resume file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Allocate memory for the resume struct
    Resume *resume = malloc(sizeof(Resume));
    if (resume == NULL) {
        printf("Error allocating memory for resume\n");
        fclose(file);
        return NULL;
    }

    // Initialize the resume struct
    resume->name = NULL;
    resume->email = NULL;
    resume->phone = NULL;
    resume->address = NULL;
    resume->num_skills = 0;
    for (int i = 0; i < 10; i++) {
        resume->skills[i] = NULL;
    }

    // Read the resume file line by line
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Parse the line
        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        // Store the data in the resume struct
        if (strcmp(key, "Name") == 0) {
            resume->name = malloc(strlen(value) + 1);
            strcpy(resume->name, value);
        } else if (strcmp(key, "Email") == 0) {
            resume->email = malloc(strlen(value) + 1);
            strcpy(resume->email, value);
        } else if (strcmp(key, "Phone") == 0) {
            resume->phone = malloc(strlen(value) + 1);
            strcpy(resume->phone, value);
        } else if (strcmp(key, "Address") == 0) {
            resume->address = malloc(strlen(value) + 1);
            strcpy(resume->address, value);
        } else if (strcmp(key, "Skills") == 0) {
            char *skill = strtok(value, ", ");
            while (skill != NULL) {
                resume->skills[resume->num_skills] = malloc(strlen(skill) + 1);
                strcpy(resume->skills[resume->num_skills], skill);
                resume->num_skills++;
                skill = strtok(NULL, ", ");
            }
        }
    }

    // Close the resume file
    fclose(file);

    // Return the resume struct
    return resume;
}

// Function to print the resume data
void print_resume(Resume *resume) {
    // Print the resume data
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Skills:\n");
    for (int i = 0; i < resume->num_skills; i++) {
        printf(" - %s\n", resume->skills[i]);
    }
}

// Main function
int main() {
    // Parse the resume file
    Resume *resume = parse_resume("resume.txt");

    // Print the resume data
    print_resume(resume);

    // Free the memory allocated for the resume struct
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->address);
    for (int i = 0; i < resume->num_skills; i++) {
        free(resume->skills[i]);
    }
    free(resume);

    return 0;
}