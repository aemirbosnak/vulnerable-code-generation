//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a resume
#define MAX_RESUME_LENGTH 10000

// Define the maximum number of skills
#define MAX_SKILLS 10

// Define the maximum number of experiences
#define MAX_EXPERIENCES 10

// Define the maximum number of educations
#define MAX_EDUCATIONS 10

// Define the resume struct
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *summary;
    char *skills[MAX_SKILLS];
    char *experiences[MAX_EXPERIENCES];
    char *educations[MAX_EDUCATIONS];
} resume;

// Define the function to parse a resume
resume *parse_resume(char *resume_text) {
    // Allocate memory for the resume
    resume *resume = malloc(sizeof(resume));

    // Parse the name
    char *name = strtok(resume_text, "\n");
    resume->name = malloc(strlen(name) + 1);
    strcpy(resume->name, name);

    // Parse the email
    char *email = strtok(NULL, "\n");
    resume->email = malloc(strlen(email) + 1);
    strcpy(resume->email, email);

    // Parse the phone
    char *phone = strtok(NULL, "\n");
    resume->phone = malloc(strlen(phone) + 1);
    strcpy(resume->phone, phone);

    // Parse the summary
    char *summary = strtok(NULL, "\n");
    resume->summary = malloc(strlen(summary) + 1);
    strcpy(resume->summary, summary);

    // Parse the skills
    int num_skills = 0;
    while (num_skills < MAX_SKILLS) {
        char *skill = strtok(NULL, "\n");
        if (skill == NULL) {
            break;
        }
        resume->skills[num_skills] = malloc(strlen(skill) + 1);
        strcpy(resume->skills[num_skills], skill);
        num_skills++;
    }

    // Parse the experiences
    int num_experiences = 0;
    while (num_experiences < MAX_EXPERIENCES) {
        char *experience = strtok(NULL, "\n");
        if (experience == NULL) {
            break;
        }
        resume->experiences[num_experiences] = malloc(strlen(experience) + 1);
        strcpy(resume->experiences[num_experiences], experience);
        num_experiences++;
    }

    // Parse the educations
    int num_educations = 0;
    while (num_educations < MAX_EDUCATIONS) {
        char *education = strtok(NULL, "\n");
        if (education == NULL) {
            break;
        }
        resume->educations[num_educations] = malloc(strlen(education) + 1);
        strcpy(resume->educations[num_educations], education);
        num_educations++;
    }

    // Return the resume
    return resume;
}

// Define the function to print a resume
void print_resume(resume *resume) {
    // Print the name
    printf("Name: %s\n", resume->name);

    // Print the email
    printf("Email: %s\n", resume->email);

    // Print the phone
    printf("Phone: %s\n", resume->phone);

    // Print the summary
    printf("Summary: %s\n", resume->summary);

    // Print the skills
    printf("Skills:\n");
    for (int i = 0; i < MAX_SKILLS; i++) {
        if (resume->skills[i] != NULL) {
            printf(" - %s\n", resume->skills[i]);
        }
    }

    // Print the experiences
    printf("Experiences:\n");
    for (int i = 0; i < MAX_EXPERIENCES; i++) {
        if (resume->experiences[i] != NULL) {
            printf(" - %s\n", resume->experiences[i]);
        }
    }

    // Print the educations
    printf("Educations:\n");
    for (int i = 0; i < MAX_EDUCATIONS; i++) {
        if (resume->educations[i] != NULL) {
            printf(" - %s\n", resume->educations[i]);
        }
    }
}

// Define the main function
int main() {
    // Read the resume text from a file
    FILE *file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    char *resume_text = malloc(MAX_RESUME_LENGTH);
    fread(resume_text, 1, MAX_RESUME_LENGTH, file);
    fclose(file);

    // Parse the resume
    resume *resume = parse_resume(resume_text);

    // Print the resume
    print_resume(resume);

    // Free the memory allocated for the resume
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->summary);
    for (int i = 0; i < MAX_SKILLS; i++) {
        if (resume->skills[i] != NULL) {
            free(resume->skills[i]);
        }
    }
    for (int i = 0; i < MAX_EXPERIENCES; i++) {
        if (resume->experiences[i] != NULL) {
            free(resume->experiences[i]);
        }
    }
    for (int i = 0; i < MAX_EDUCATIONS; i++) {
        if (resume->educations[i] != NULL) {
            free(resume->educations[i]);
        }
    }
    free(resume);

    return 0;
}