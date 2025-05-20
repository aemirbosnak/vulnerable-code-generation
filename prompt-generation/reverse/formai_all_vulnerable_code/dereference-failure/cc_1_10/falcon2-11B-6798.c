//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Function to parse a resume line by line
void parse_resume(FILE* resume_file, char* name, char* email) {
    // Open the resume file
    FILE* resume = fopen(resume_file, "r");
    if (resume == NULL) {
        printf("Error opening resume file\n");
        return;
    }
    
    // Read the lines of the resume
    char line[100];
    while (fgets(line, sizeof(line), resume)) {
        // Remove leading and trailing whitespaces
        line[strcspn(line, "\n")] = '\0';
        
        // Check if the line starts with "NAME:" or "EMAIL:"
        if (strncmp(line, "NAME:", 5) == 0 || strncmp(line, "EMAIL:", 6) == 0) {
            // Extract the value of the field
            int index = strcspn(line, ":");
            char* value = (char*) malloc(index + 1);
            strncpy(value, line + 6, index);
            value[index] = '\0';
            
            // Set the parsed value
            if (strncmp(line, "NAME:", 5) == 0) {
                strncpy(name, value, sizeof(name));
            } else if (strncmp(line, "EMAIL:", 6) == 0) {
                strncpy(email, value, sizeof(email));
            }
            
            // Free the allocated memory
            free(value);
        }
    }
    
    // Close the resume file
    fclose(resume);
}

// Main function
int main() {
    // Get the name and email from the user
    char name[50];
    char email[50];
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("Enter your email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';
    
    // Open the resume file
    FILE* resume = fopen("resume.txt", "r");
    if (resume == NULL) {
        printf("Error opening resume file\n");
        return 1;
    }
    
    // Parse the resume
    parse_resume(resume, name, email);
    
    // Close the resume file
    fclose(resume);
    
    return 0;
}