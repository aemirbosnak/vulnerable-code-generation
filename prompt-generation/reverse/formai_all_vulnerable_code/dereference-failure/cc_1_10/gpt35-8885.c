//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100

// Structure to hold resume information
typedef struct {
    char name[100];
    char email[100];
    char title[100];
    char skills[500];
} Resume;

// Function to parse resumes and store information in arrays
void parseResumes(char *filename, Resume *resumes, int *numResumes) {
    FILE *file;
    char line[1024];
    char *token;
    int i = 0;

    // Open file
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file\n");
        exit(1);
    }

    // Parse file line by line
    while (fgets(line, sizeof(line), file)) {
        // Remove newline characters
        line[strcspn(line, "\r\n")] = '\0';

        // Tokenize line
        token = strtok(line, ",");

        // Store resume information in struct
        strcpy(resumes[i].name, token);
        token = strtok(NULL, ",");
        strcpy(resumes[i].email, token);
        token = strtok(NULL, ",");
        strcpy(resumes[i].title, token);
        token = strtok(NULL, ",");
        strcpy(resumes[i].skills, token);

        // Increment number of resumes parsed
        (*numResumes)++;
        i++;
    }

    // Close file
    fclose(file);
}

// Function to print out resumes
void printResumes(Resume *resumes, int numResumes) {
    int i;

    // Print out each resume
    for (i = 0; i < numResumes; i++) {
        printf("Name: %s\n", resumes[i].name);
        printf("Email: %s\n", resumes[i].email);
        printf("Title: %s\n", resumes[i].title);
        printf("Skills: %s\n", resumes[i].skills);
    }
}

int main() {
    char filename[100];
    Resume resumes[MAX_RESUMES];
    int numResumes = 0;

    // Ask user for filename
    printf("Enter file name: ");
    scanf("%s", filename);

    // Parse resumes
    parseResumes(filename, resumes, &numResumes);

    // Print out resumes
    printResumes(resumes, numResumes);

    return 0;
}