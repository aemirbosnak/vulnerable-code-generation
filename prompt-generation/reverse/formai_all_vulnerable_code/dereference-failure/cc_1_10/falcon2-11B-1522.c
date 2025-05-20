//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to parse a resume and extract the name, skills, and experience
void parseResume(char* resume) {
    // Split the resume into lines
    char* line = strtok(resume, "\n");
    while (line!= NULL) {
        // Split each line into words
        char* word = strtok(NULL, " ");
        while (word!= NULL) {
            // Check if the word is a name
            if (strstr(word, "NAME")!= NULL) {
                // Extract the name
                char* name = strtok(NULL, " ");
                printf("Name: %s\n", name);
            }
            // Check if the word is a skill
            else if (strstr(word, "SKILL")!= NULL) {
                // Extract the skill
                char* skill = strtok(NULL, " ");
                printf("Skill: %s\n", skill);
            }
            // Check if the word is an experience
            else if (strstr(word, "EXPERIENCE")!= NULL) {
                // Extract the experience
                char* experience = strtok(NULL, " ");
                printf("Experience: %s\n", experience);
            }
            // Move to the next word
            word = strtok(NULL, " ");
        }
        // Move to the next line
        line = strtok(NULL, "\n");
    }
}

// Function to read a resume from a file
void readResume(char* filename) {
    // Open the file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    // Read the file into a string
    char* resume = (char*)malloc(sizeof(char) * 1000);
    fread(resume, sizeof(char), 1000, file);
    // Close the file
    fclose(file);
    // Parse the resume
    parseResume(resume);
    // Free the memory
    free(resume);
}

// Main function
int main() {
    // Read a resume from a file
    char* filename = "resume.txt";
    readResume(filename);
    // Return 0
    return 0;
}