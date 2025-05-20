//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a struct to store the information from the resume */
typedef struct {
    char* name;
    char* email;
    char* phone_number;
    char* education;
    char* experience;
} Resume;

/* Function to parse the resume */
Resume* parse_resume(char* resume_text) {
    Resume* resume = malloc(sizeof(Resume));
    char* delimiter = "\n\n";
    char* token;
    
    /* Parsing for the name */
    token = strtok(resume_text, delimiter);
    resume->name = malloc(strlen(token) + 1);
    strcpy(resume->name, token);
    
    /* Parsing for the email */
    token = strtok(NULL, delimiter);
    resume->email = malloc(strlen(token) + 1);
    strcpy(resume->email, token);
    
    /* Parsing for the phone number */
    token = strtok(NULL, delimiter);
    resume->phone_number = malloc(strlen(token) + 1);
    strcpy(resume->phone_number, token);
    
    /* Parsing for the education */
    token = strtok(NULL, delimiter);
    resume->education = malloc(strlen(token) + 1);
    strcpy(resume->education, token);
    
    /* Parsing for the experience */
    token = strtok(NULL, delimiter);
    resume->experience = malloc(strlen(token) + 1);
    strcpy(resume->experience, token);
    
    return resume;
}

int main() {
    /* Example input */
    char* input = "John Doe\njohndoe@email.com\n(123) 456-7890\nBachelor of Science in Computer Science\nSoftware Developer";
    
    /* Parsing */
    Resume* resume = parse_resume(input);
    
    /* Output */
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone Number: %s\n", resume->phone_number);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
    
    /* Cleanup */
    free(resume->name);
    free(resume->email);
    free(resume->phone_number);
    free(resume->education);
    free(resume->experience);
    free(resume);
    
    return 0;
}