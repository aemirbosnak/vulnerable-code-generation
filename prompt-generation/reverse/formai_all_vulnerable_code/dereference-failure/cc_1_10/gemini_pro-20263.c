//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a resume
#define MAX_RESUME_LENGTH 1024

// Define the maximum number of skills
#define MAX_SKILLS 10

// Define the maximum length of a skill
#define MAX_SKILL_LENGTH 32

// Define the maximum number of experiences
#define MAX_EXPERIENCES 10

// Define the maximum length of an experience
#define MAX_EXPERIENCE_LENGTH 128

// Define the maximum number of educations
#define MAX_EDUCATIONS 10

// Define the maximum length of an education
#define MAX_EDUCATION_LENGTH 128

// Define the maximum number of certifications
#define MAX_CERTIFICATIONS 10

// Define the maximum length of a certification
#define MAX_CERTIFICATION_LENGTH 128

// Define the structure of a resume
typedef struct {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills[MAX_SKILLS];
    char *experiences[MAX_EXPERIENCES];
    char *educations[MAX_EDUCATIONS];
    char *certifications[MAX_CERTIFICATIONS];
} Resume;

// Define the function to parse a resume
Resume *parse_resume(char *resume) {
    // Allocate memory for the resume
    Resume *resume_struct = malloc(sizeof(Resume));

    // Parse the name
    char *name = strtok(resume, "\n");
    resume_struct->name = malloc(strlen(name) + 1);
    strcpy(resume_struct->name, name);

    // Parse the email
    char *email = strtok(NULL, "\n");
    resume_struct->email = malloc(strlen(email) + 1);
    strcpy(resume_struct->email, email);

    // Parse the phone
    char *phone = strtok(NULL, "\n");
    resume_struct->phone = malloc(strlen(phone) + 1);
    strcpy(resume_struct->phone, phone);

    // Parse the address
    char *address = strtok(NULL, "\n");
    resume_struct->address = malloc(strlen(address) + 1);
    strcpy(resume_struct->address, address);

    // Parse the skills
    int num_skills = 0;
    while (num_skills < MAX_SKILLS) {
        char *skill = strtok(NULL, "\n");
        if (skill == NULL) {
            break;
        }
        resume_struct->skills[num_skills] = malloc(strlen(skill) + 1);
        strcpy(resume_struct->skills[num_skills], skill);
        num_skills++;
    }

    // Parse the experiences
    int num_experiences = 0;
    while (num_experiences < MAX_EXPERIENCES) {
        char *experience = strtok(NULL, "\n");
        if (experience == NULL) {
            break;
        }
        resume_struct->experiences[num_experiences] = malloc(strlen(experience) + 1);
        strcpy(resume_struct->experiences[num_experiences], experience);
        num_experiences++;
    }

    // Parse the educations
    int num_educations = 0;
    while (num_educations < MAX_EDUCATIONS) {
        char *education = strtok(NULL, "\n");
        if (education == NULL) {
            break;
        }
        resume_struct->educations[num_educations] = malloc(strlen(education) + 1);
        strcpy(resume_struct->educations[num_educations], education);
        num_educations++;
    }

    // Parse the certifications
    int num_certifications = 0;
    while (num_certifications < MAX_CERTIFICATIONS) {
        char *certification = strtok(NULL, "\n");
        if (certification == NULL) {
            break;
        }
        resume_struct->certifications[num_certifications] = malloc(strlen(certification) + 1);
        strcpy(resume_struct->certifications[num_certifications], certification);
        num_certifications++;
    }

    // Return the resume struct
    return resume_struct;
}

// Define the function to print a resume
void print_resume(Resume *resume) {
    // Print the name
    printf("Name: %s\n", resume->name);

    // Print the email
    printf("Email: %s\n", resume->email);

    // Print the phone
    printf("Phone: %s\n", resume->phone);

    // Print the address
    printf("Address: %s\n", resume->address);

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

    // Print the certifications
    printf("Certifications:\n");
    for (int i = 0; i < MAX_CERTIFICATIONS; i++) {
        if (resume->certifications[i] != NULL) {
            printf(" - %s\n", resume->certifications[i]);
        }
    }
}

// Define the main function
int main() {
    // Read the resume from the file
    char *resume = malloc(MAX_RESUME_LENGTH + 1);
    FILE *fp = fopen("resume.txt", "r");
    fread(resume, MAX_RESUME_LENGTH, 1, fp);
    fclose(fp);

    // Parse the resume
    Resume *resume_struct = parse_resume(resume);

    // Print the resume
    print_resume(resume_struct);

    // Free the memory allocated for the resume
    free(resume_struct->name);
    free(resume_struct->email);
    free(resume_struct->phone);
    free(resume_struct->address);
    for (int i = 0; i < MAX_SKILLS; i++) {
        if (resume_struct->skills[i] != NULL) {
            free(resume_struct->skills[i]);
        }
    }
    for (int i = 0; i < MAX_EXPERIENCES; i++) {
        if (resume_struct->experiences[i] != NULL) {
            free(resume_struct->experiences[i]);
        }
    }
    for (int i = 0; i < MAX_EDUCATIONS; i++) {
        if (resume_struct->educations[i] != NULL) {
            free(resume_struct->educations[i]);
        }
    }
    for (int i = 0; i < MAX_CERTIFICATIONS; i++) {
        if (resume_struct->certifications[i] != NULL) {
            free(resume_struct->certifications[i]);
        }
    }
    free(resume_struct);

    return 0;
}