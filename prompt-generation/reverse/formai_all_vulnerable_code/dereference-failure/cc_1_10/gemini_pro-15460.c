//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of a resume field
#define MAX_FIELD_LENGTH 100

// Define the maximum number of resume fields
#define MAX_FIELDS 100

// Define the structure of a resume field
typedef struct {
    char name[MAX_FIELD_LENGTH];
    char value[MAX_FIELD_LENGTH];
} ResumeField;

// Define the structure of a resume
typedef struct {
    int numFields;
    ResumeField fields[MAX_FIELDS];
} Resume;

// Function to parse a resume file
Resume* parseResume(char* filename) {
    // Open the resume file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening resume file");
        return NULL;
    }

    // Create a new resume object
    Resume* resume = malloc(sizeof(Resume));
    if (resume == NULL) {
        perror("Error allocating memory for resume");
        fclose(file);
        return NULL;
    }

    // Initialize the resume's number of fields to 0
    resume->numFields = 0;

    // Read the resume file line by line
    char line[MAX_FIELD_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        // Remove the newline character from the line
        line[strcspn(line, "\n")] = 0;

        // Split the line into the field name and value
        char* delimiter = ":";
        char* name = strtok(line, delimiter);
        char* value = strtok(NULL, delimiter);

        // If the field name is not empty, add it to the resume
        if (strlen(name) > 0) {
            strcpy(resume->fields[resume->numFields].name, name);
            strcpy(resume->fields[resume->numFields].value, value);
            resume->numFields++;
        }
    }

    // Close the resume file
    fclose(file);

    // Return the resume object
    return resume;
}

// Function to print a resume
void printResume(Resume* resume) {
    // Print the resume's fields
    for (int i = 0; i < resume->numFields; i++) {
        printf("%s: %s\n", resume->fields[i].name, resume->fields[i].value);
    }
}

// Function to free the memory allocated for a resume
void freeResume(Resume* resume) {
    // Free the resume's fields
    for (int i = 0; i < resume->numFields; i++) {
        free(resume->fields[i].name);
        free(resume->fields[i].value);
    }

    // Free the resume object
    free(resume);
}

// Main function
int main(int argc, char* argv[]) {
    // Check if the user provided a resume file
    if (argc != 2) {
        printf("Usage: %s <resume_file>\n", argv[0]);
        return 1;
    }

    // Parse the resume file
    Resume* resume = parseResume(argv[1]);
    if (resume == NULL) {
        return 1;
    }

    // Print the resume
    printResume(resume);

    // Free the memory allocated for the resume
    freeResume(resume);

    return 0;
}