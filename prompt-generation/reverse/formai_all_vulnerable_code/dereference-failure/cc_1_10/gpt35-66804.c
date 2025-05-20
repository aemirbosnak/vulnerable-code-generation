//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define Struct that stores resume info
typedef struct {
    char* name;
    char* email;
    char* education[10];
    char* skills[10];
    char* workExperience[10];
    char* certifications[10];
} Resume;

// Function to parse out sections of text by keyword
void parseResume(char* text, Resume* resume) {
    char* token;
    char* delimiters = "\n\t ";

    // Search for name and email
    token = strtok(text, delimiters);
    while (token != NULL) {
        if (strstr(token, "Name:") != NULL) {
            resume->name = strtok(NULL, delimiters);
        } else if (strstr(token, "Email:") != NULL) {
            resume->email = strtok(NULL, delimiters);
        } else if (strstr(token, "Education:") != NULL) {
            int i = 0;
            token = strtok(NULL, delimiters);
            while (token != NULL && i < 10) {
                resume->education[i++] = token;
                token = strtok(NULL, delimiters);
            }
        } else if (strstr(token, "Skills:") != NULL) {
            int i = 0;
            token = strtok(NULL, delimiters);
            while (token != NULL && i < 10) {
                resume->skills[i++] = token;
                token = strtok(NULL, delimiters);
            }
        } else if (strstr(token, "Work Experience:") != NULL) {
            int i = 0;
            token = strtok(NULL, delimiters);
            while (token != NULL && i < 10) {
                resume->workExperience[i++] = token;
                token = strtok(NULL, delimiters);
            }
        } else if (strstr(token, "Certifications:") != NULL) {
            int i = 0;
            token = strtok(NULL, delimiters);
            while (token != NULL && i < 10) {
                resume->certifications[i++] = token;
                token = strtok(NULL, delimiters);
            }
        } 

        token = strtok(NULL, delimiters);
    }
}

// Function to print out the fields of the parsed resume
void printResume(Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Education:\n");
    for (int i = 0; i < 10 && resume->education[i] != NULL; i++) {
        printf("\t- %s\n", resume->education[i]);
    }
    printf("Skills:\n");
    for (int i = 0; i < 10 && resume->skills[i] != NULL; i++) {
        printf("\t- %s\n", resume->skills[i]);
    }
    printf("Work Experience:\n");
    for (int i = 0; i < 10 && resume->workExperience[i] != NULL; i++) {
        printf("\t- %s\n", resume->workExperience[i]);
    }
    printf("Certifications:\n");
    for (int i = 0; i < 10 && resume->certifications[i] != NULL; i++) {
        printf("\t- %s\n", resume->certifications[i]);
    }
}

// Main function
int main() {
    printf("Welcome to the Resume Parsing System!\n");
    printf("Please enter your resume below:\n");

    char* text = (char*) malloc(2048 * sizeof(char));
    fgets(text, 2048, stdin);

    Resume resume;
    parseResume(text, &resume);

    printf("Resume parsed successfully:\n");
    printResume(&resume);

    free(text);

    return 0;
}