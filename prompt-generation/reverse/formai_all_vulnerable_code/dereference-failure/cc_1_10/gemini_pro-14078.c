//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>

// Define the keywords that will be used for parsing
#define SKILL "Skills"
#define EDUCATION "Education"
#define EXPERIENCE "Experience"

// Structure to store the parsed resume data
typedef struct resume_data {
    char name[100];
    char email[100];
    char phone[20];
    char linkedin[100];
    char skills[500];
    char education[500];
    char experience[500];
} resume_data;

// Function to parse the resume
resume_data parse_resume(char *resume) {
    resume_data data;
    memset(&data, 0, sizeof(data));  // Initialize the data to zero

    // Parse the name
    char *name = strstr(resume, "Name:");
    if (name) {
        sscanf(name, "Name: %s", data.name);
    }

    // Parse the email
    char *email = strstr(resume, "Email:");
    if (email) {
        sscanf(email, "Email: %s", data.email);
    }

    // Parse the phone
    char *phone = strstr(resume, "Phone:");
    if (phone) {
        sscanf(phone, "Phone: %s", data.phone);
    }

    // Parse the linkedin
    char *linkedin = strstr(resume, "LinkedIn:");
    if (linkedin) {
        sscanf(linkedin, "LinkedIn: %s", data.linkedin);
    }

    // Parse the skills
    char *skills = strstr(resume, SKILL);
    if (skills) {
        char *start = strchr(skills, ':');
        if (start) {
            strcpy(data.skills, start + 1);
        }
    }

    // Parse the education
    char *education = strstr(resume, EDUCATION);
    if (education) {
        char *start = strchr(education, ':');
        if (start) {
            strcpy(data.education, start + 1);
        }
    }

    // Parse the experience
    char *experience = strstr(resume, EXPERIENCE);
    if (experience) {
        char *start = strchr(experience, ':');
        if (start) {
            strcpy(data.experience, start + 1);
        }
    }

    return data;
}

// Function to print the resume data
void print_resume(resume_data data) {
    printf("Name: %s\n", data.name);
    printf("Email: %s\n", data.email);
    printf("Phone: %s\n", data.phone);
    printf("LinkedIn: %s\n", data.linkedin);
    printf("Skills: %s\n", data.skills);
    printf("Education: %s\n", data.education);
    printf("Experience: %s\n", data.experience);
}

// Main function
int main() {
    // Read the resume from a file
    char *resume = NULL;
    int len = 0;
    FILE *fp = fopen("resume.txt", "r");
    if (fp) {
        fseek(fp, 0, SEEK_END);
        len = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        resume = malloc(len + 1);
        fread(resume, 1, len, fp);
        fclose(fp);
    }

    // Parse the resume
    resume_data data = parse_resume(resume);

    // Print the resume data
    print_resume(data);

    return 0;
}