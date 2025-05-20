//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to parse the resume string
void parse_resume(char* resume) {
    // Initialize variables
    char* name = NULL;
    char* title = NULL;
    char* company = NULL;
    char* location = NULL;
    char* skills = NULL;
    char* experience = NULL;

    // Split the resume string into sections
    char* section = strtok(resume, "|");
    while (section!= NULL) {
        // Check for name
        if (strcmp(section, "Name:") == 0) {
            name = strtok(NULL, "\n");
        }
        // Check for title
        else if (strcmp(section, "Title:") == 0) {
            title = strtok(NULL, "\n");
        }
        // Check for company
        else if (strcmp(section, "Company:") == 0) {
            company = strtok(NULL, "\n");
        }
        // Check for location
        else if (strcmp(section, "Location:") == 0) {
            location = strtok(NULL, "\n");
        }
        // Check for skills
        else if (strcmp(section, "Skills:") == 0) {
            skills = strtok(NULL, "\n");
        }
        // Check for experience
        else if (strcmp(section, "Experience:") == 0) {
            experience = strtok(NULL, "\n");
        }
        // Check for new section
        section = strtok(NULL, "|");
    }

    // Print the parsed information
    printf("Name: %s\n", name);
    printf("Title: %s\n", title);
    printf("Company: %s\n", company);
    printf("Location: %s\n", location);
    printf("Skills: %s\n", skills);
    printf("Experience: %s\n", experience);

    // Free memory
    free(name);
    free(title);
    free(company);
    free(location);
    free(skills);
    free(experience);
}

int main() {
    // Read the resume from a file
    FILE* fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read the resume string
    char* resume = malloc(sizeof(char) * 100000);
    fread(resume, sizeof(char), 100000, fp);
    fclose(fp);

    // Parse the resume
    parse_resume(resume);

    // Free memory
    free(resume);

    return 0;
}