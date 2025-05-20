//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures and functions

typedef struct {
    char *name;
    char *title;
    char *company;
    char *location;
    char *years_of_experience;
    char *skills;
} resume_entry;

// Function to parse a resume file and create a resume entry
resume_entry parse_resume_file(char *filename) {
    
    resume_entry entry;
    char resume_text[2000]; // assuming resume file is less than 2000 bytes
    
    FILE *resume = fopen(filename, "r");
    
    if (resume == NULL) {
        printf("Error opening file\n");
        exit(1);
    }  
    
    char line[200];
    
    while (fgets(line, sizeof(line), resume)) {
        // Parse the line and extract relevant information
        char *keyword = strtok(line, ":");
        char *value = strtok(NULL, "\n");
    
        if (strcmp(keyword, "Name") == 0) {
            entry.name = strdup(value);
        } else if (strcmp(keyword, "Title") == 0) {
            entry.title = strdup(value);
        } else if (strcmp(keyword, "Company") == 0) {
            entry.company = strdup(value);
        } else if (strcmp(keyword, "Location") == 0) {
            entry.location = strdup(value);
        } else if (strcmp(keyword, "Years of Experience") == 0) {
            entry.years_of_experience = strdup(value);
        } else if (strcmp(keyword, "Skills") == 0) {
            entry.skills = strdup(value);
        }
    }

    fclose(resume);

    return entry;
}

// Function to print a resume entry
void print_resume_entry(resume_entry entry) {
    printf("Name: %s\n", entry.name);
    printf("Title: %s\n", entry.title);
    printf("Company: %s\n", entry.company);
    printf("Location: %s\n", entry.location);
    printf("Years of Experience: %s\n", entry.years_of_experience);
    printf("Skills: %s\n", entry.skills);
}

// Main function
int main() {
    resume_entry entry = parse_resume_file("resume.txt");
    print_resume_entry(entry);

    return 0;
}