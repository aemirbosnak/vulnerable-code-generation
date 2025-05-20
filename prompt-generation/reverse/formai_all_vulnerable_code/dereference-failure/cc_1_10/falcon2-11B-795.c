//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Function to parse a resume line and extract relevant information
void parseResumeLine(char* line, char* name, char* email, char* phone, char* location) {
    // Convert line to lowercase for case-insensitive comparison
    char* lowercaseLine = strdup(line);
    for (int i = 0; i < strlen(lowercaseLine); i++) {
        lowercaseLine[i] = tolower(lowercaseLine[i]);
    }
    
    // Check if the line starts with a name
    if (strncmp(lowercaseLine, "name:", 5) == 0) {
        char* nameEnd = strchr(lowercaseLine, ':');
        if (nameEnd!= NULL) {
            *nameEnd = '\0';
            strcpy(name, lowercaseLine + 5);
        }
    }
    
    // Check if the line starts with an email
    else if (strncmp(lowercaseLine, "email:", 6) == 0) {
        char* emailEnd = strchr(lowercaseLine, ':');
        if (emailEnd!= NULL) {
            *emailEnd = '\0';
            strcpy(email, lowercaseLine + 6);
        }
    }
    
    // Check if the line starts with a phone number
    else if (strncmp(lowercaseLine, "phone:", 6) == 0) {
        char* phoneEnd = strchr(lowercaseLine, ':');
        if (phoneEnd!= NULL) {
            *phoneEnd = '\0';
            strcpy(phone, lowercaseLine + 6);
        }
    }
    
    // Check if the line starts with a location
    else if (strncmp(lowercaseLine, "location:", 9) == 0) {
        char* locationEnd = strchr(lowercaseLine, ':');
        if (locationEnd!= NULL) {
            *locationEnd = '\0';
            strcpy(location, lowercaseLine + 9);
        }
    }
    
    // Free memory
    free(lowercaseLine);
}

// Function to parse a resume and extract relevant information
void parseResume(FILE* resumeFile, char* name, char* email, char* phone, char* location) {
    char line[256];
    while (fgets(line, sizeof(line), resumeFile)) {
        parseResumeLine(line, name, email, phone, location);
    }
}

// Function to print relevant information
void printInfo(char* name, char* email, char* phone, char* location) {
    printf("Name: %s\n", name);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Location: %s\n", location);
}

// Main function
int main() {
    char name[256];
    char email[256];
    char phone[256];
    char location[256];
    
    // Open the resume file
    FILE* resumeFile = fopen("resume.txt", "r");
    if (resumeFile == NULL) {
        fprintf(stderr, "Error opening resume file\n");
        exit(1);
    }
    
    // Parse the resume
    parseResume(resumeFile, name, email, phone, location);
    
    // Print the relevant information
    printInfo(name, email, phone, location);
    
    // Close the resume file
    fclose(resumeFile);
    
    return 0;
}