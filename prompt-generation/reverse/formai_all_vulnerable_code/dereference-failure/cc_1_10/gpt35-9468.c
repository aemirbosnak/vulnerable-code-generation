//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defined maximum size of buffer
#define BUFFER_SIZE 1000

// Struct for storing resume attributes
typedef struct {
    char name[50];
    char skills[200];
    char education[100];
    char experience[200];
} Resume;

// Function to parse each line of the resume
Resume parseLine(char* buffer) {
    Resume newResume;
    // Initialize all fields to empty strings
    strcpy(newResume.name, "");
    strcpy(newResume.skills, "");
    strcpy(newResume.education, "");
    strcpy(newResume.experience, "");

    // Base case
    if (strlen(buffer) == 0) {
        return newResume;
    }

    // Find the index of the first colon
    int colonIndex = -1;
    for (int i = 0; i < strlen(buffer); i++) {
        if (buffer[i] == ':') {
            colonIndex = i;
            break;
        }
    }

    // If no colon was found, return the struct with empty fields
    if (colonIndex == -1) {
        return newResume;
    }

    // Copy the attribute name into a separate buffer
    char attributeName[50];
    strncpy(attributeName, buffer, colonIndex);
    attributeName[colonIndex] = '\0';

    // Copy the attribute value into a separate buffer
    char attributeValue[BUFFER_SIZE];
    strncpy(attributeValue, buffer + colonIndex + 1, BUFFER_SIZE - 1);
    attributeValue[strlen(attributeValue) - 1] = '\0'; // Remove newline character

    // Assign the attribute value to the appropriate field in the struct
    if (strcmp(attributeName, "Name") == 0) {
        strcpy(newResume.name, attributeValue);
    } else if (strcmp(attributeName, "Skills") == 0) {
        strcpy(newResume.skills, attributeValue);
    } else if (strcmp(attributeName, "Education") == 0) {
        strcpy(newResume.education, attributeValue);
    } else if (strcmp(attributeName, "Experience") == 0) {
        strcpy(newResume.experience, attributeValue);
    }

    // Recursive call to parse the next line of the resume
    Resume nextResume = parseLine(buffer + strlen(attributeName) + strlen(attributeValue) + 2);
    
    // Merge the parsed resume with the current resume
    strcat(newResume.name, nextResume.name);
    strcat(newResume.skills, nextResume.skills);
    strcat(newResume.education, nextResume.education);
    strcat(newResume.experience, nextResume.experience);

    // Return the merged resume
    return newResume;
}

int main() {
    // Read the resume text file into a buffer
    char buffer[BUFFER_SIZE];
    FILE* resumeFile = fopen("resume.txt", "r");
    fread(buffer, sizeof(char), BUFFER_SIZE, resumeFile);

    // Parse the resume recursively
    Resume myResume = parseLine(buffer);

    // Print the parsed resume attributes
    printf("Name: %s\n", myResume.name);
    printf("Skills: %s\n", myResume.skills);
    printf("Education: %s\n", myResume.education);
    printf("Experience: %s\n", myResume.experience);

    return 0;
}