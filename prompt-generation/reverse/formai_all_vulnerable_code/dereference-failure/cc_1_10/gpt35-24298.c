//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a structure to hold the resume details */
struct Resume {
    char name[50];
    char phone[15];
    char email[50];
    char objective[200];
    char education[200];
    char skills[200];
    char experience[200];
};

/* Declare a function to parse the resume */
void parseResume(struct Resume *resume) {
    char resumeStr[1000]; // The resume string
    
    // Read the resume from a file
    FILE *fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error opening file");
        exit(1);
    }
    fgets(resumeStr, 1000, fp);
    fclose(fp);
    
    // Parse the resume string and populate the struct fields
    char *token = strtok(resumeStr, "|");
    strcpy(resume->name, token);
    token = strtok(NULL, "|");
    strcpy(resume->phone, token);
    token = strtok(NULL, "|");
    strcpy(resume->email, token);
    token = strtok(NULL, "|");
    strcpy(resume->objective, token);
    token = strtok(NULL, "|");
    strcpy(resume->education, token);
    token = strtok(NULL, "|");
    strcpy(resume->skills, token);
    token = strtok(NULL, "|");
    strcpy(resume->experience, token);
}

/* Declare a function to print the resume details */
void printResume(struct Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Phone: %s\n", resume->phone);
    printf("Email: %s\n", resume->email);
    printf("Objective: %s\n", resume->objective);
    printf("Education: %s\n", resume->education);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
}

/* Declare the main function */
int main() {
    struct Resume resume; // Declare a resume struct
    
    printf("Parsing the resume...\n");
    parseResume(&resume); // Parse the resume
    
    printf("Printing the resume...\n");
    printResume(&resume); // Print the resume details
    
    return 0;
}