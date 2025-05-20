//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NAME_LENGTH 64
#define MAX_COMPANY_LENGTH 64
#define MAX_JOB_LENGTH 64
#define MAX_SKILLS_LENGTH 256
#define MAX_EDUCATION_LENGTH 64

// Struct to hold resume data
typedef struct {
    char name[MAX_NAME_LENGTH];
    char company[MAX_COMPANY_LENGTH];
    char job[MAX_JOB_LENGTH];
    char skills[MAX_SKILLS_LENGTH];
    char education[MAX_EDUCATION_LENGTH];
} Resume;

// Function to parse resume data
void parseResume(Resume *resume, char *line) {
    char *token;
    char *saveptr = NULL;

    // Parse name
    token = strtok_r(line, ",", &saveptr);
    strcpy(resume->name, token);

    // Parse company
    token = strtok_r(NULL, ",", &saveptr);
    strcpy(resume->company, token);

    // Parse job
    token = strtok_r(NULL, ",", &saveptr);
    strcpy(resume->job, token);

    // Parse skills
    token = strtok_r(NULL, ",", &saveptr);
    strcpy(resume->skills, token);

    // Parse education
    token = strtok_r(NULL, ",", &saveptr);
    strcpy(resume->education, token);
}

// Function to print resume data
void printResume(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Company: %s\n", resume->company);
    printf("Job: %s\n", resume->job);
    printf("Skills: %s\n", resume->skills);
    printf("Education: %s\n", resume->education);
}

// Function to read resume file
void readResume(Resume *resume, FILE *fp) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        parseResume(resume, line);
    }
}

// Function to write resume file
void writeResume(Resume *resume, FILE *fp) {
    fprintf(fp, "%s,%s,%s,%s,%s\n", resume->name, resume->company, resume->job, resume->skills, resume->education);
}

// Main function
int main() {
    // Open input and output files
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    // Check if files were opened successfully
    if (inputFile == NULL || outputFile == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Create resume struct
    Resume resume;

    // Read input file
    readResume(&resume, inputFile);

    // Print resume data
    printf("Input resume:\n");
    printResume(&resume);

    // Write output file
    writeResume(&resume, outputFile);

    // Print success message
    printf("Output resume written to file.\n");

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}