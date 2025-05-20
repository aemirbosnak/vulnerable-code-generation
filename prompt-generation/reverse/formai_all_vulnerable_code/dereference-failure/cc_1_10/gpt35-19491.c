//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a structure to hold the information for a resume
typedef struct {
    char name[50];
    char education[100];
    char experience[200];
    char skills[200];
} ResumeData;

// Define a function to parse a line of text from the resume file
void parseLine(char *line, ResumeData *resume)
{
    char *token;

    // Get the first token
    token = strtok(line, ":");

    // Compare token to known fields and store value in corresponding struct field
    if (strcmp(token, "Name") == 0) {
        strcpy(resume->name, strtok(NULL, ":"));
    } else if (strcmp(token, "Education") == 0) {
        strcpy(resume->education, strtok(NULL, ":"));
    } else if (strcmp(token, "Experience") == 0) {
        strcpy(resume->experience, strtok(NULL, ":"));
    } else if (strcmp(token, "Skills") == 0) {
        strcpy(resume->skills, strtok(NULL, ":"));
    } else {
        // If token is not a known field, ignore it
        return;
    }
}

// Define a function to read and parse a resume file
void readResume(const char* filename, ResumeData *resume)
{
    // Open the file
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return;
    }

    // Read the file line-by-line
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Remove newline character
        strtok(line, "\n");

        // Ignore empty lines
        if (strlen(line) == 0) {
            continue;
        }

        // Parse the line
        parseLine(line, resume);
    }

    // Close the file
    fclose(file);
}

// Define a function to print the resume data
void printResume(ResumeData *resume)
{
    printf("Name: %s\n", resume->name);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
    printf("Skills: %s\n", resume->skills);
}

int main()
{
    // Define a new ResumeData structure
    ResumeData myResume;

    // Read and parse the resume file
    readResume("my_resume.txt", &myResume);

    // Print the resume data
    printResume(&myResume);

    return 0;
}