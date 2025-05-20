//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the resume structure
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *experience;
    char *education;
} resume;

// Define the skills array
char *skills[] = {"C", "C++", "Java", "Python", "HTML", "CSS", "JavaScript", "SQL", "NoSQL", "Cloud Computing", "Machine Learning", "Artificial Intelligence", "Data Science", "Big Data", "Agile", "Scrum", "Kanban", "DevOps", "CI/CD"};

// Define the experience array
char *experience[] = {"Software Engineer", "Web Developer", "Data Scientist", "Machine Learning Engineer", "Artificial Intelligence Engineer", "Cloud Architect", "DevOps Engineer", "CI/CD Engineer", "Project Manager", "Technical Lead"};

// Define the education array
char *education[] = {"Bachelor of Science in Computer Science", "Master of Science in Computer Science", "PhD in Computer Science"};

// Parse the resume text and extract the data
resume parse_resume(char *resume_text) {
    resume r;

    // Initialize the resume structure
    r.name = NULL;
    r.email = NULL;
    r.phone = NULL;
    r.address = NULL;
    r.skills = NULL;
    r.experience = NULL;
    r.education = NULL;

    // Parse the resume text
    char *p = resume_text;
    while (*p != '\0') {
        // Parse the name
        if (strncmp(p, "Name:", 5) == 0) {
            p += 5;
            while (isspace(*p)) p++;
            r.name = strdup(p);
            while (!isspace(*p)) p++;
        }

        // Parse the email
        else if (strncmp(p, "Email:", 6) == 0) {
            p += 6;
            while (isspace(*p)) p++;
            r.email = strdup(p);
            while (!isspace(*p)) p++;
        }

        // Parse the phone
        else if (strncmp(p, "Phone:", 6) == 0) {
            p += 6;
            while (isspace(*p)) p++;
            r.phone = strdup(p);
            while (!isspace(*p)) p++;
        }

        // Parse the address
        else if (strncmp(p, "Address:", 8) == 0) {
            p += 8;
            while (isspace(*p)) p++;
            r.address = strdup(p);
            while (!isspace(*p)) p++;
        }

        // Parse the skills
        else if (strncmp(p, "Skills:", 7) == 0) {
            p += 7;
            while (isspace(*p)) p++;
            r.skills = strdup(p);
            while (!isspace(*p)) p++;
        }

        // Parse the experience
        else if (strncmp(p, "Experience:", 11) == 0) {
            p += 11;
            while (isspace(*p)) p++;
            r.experience = strdup(p);
            while (!isspace(*p)) p++;
        }

        // Parse the education
        else if (strncmp(p, "Education:", 10) == 0) {
            p += 10;
            while (isspace(*p)) p++;
            r.education = strdup(p);
            while (!isspace(*p)) p++;
        }

        // Skip to the next line
        while (*p != '\n') p++;
        p++;
    }

    // Return the resume structure
    return r;
}

// Print the resume data
void print_resume(resume r) {
    printf("Name: %s\n", r.name);
    printf("Email: %s\n", r.email);
    printf("Phone: %s\n", r.phone);
    printf("Address: %s\n", r.address);
    printf("Skills: %s\n", r.skills);
    printf("Experience: %s\n", r.experience);
    printf("Education: %s\n", r.education);
}

// Free the resume data
void free_resume(resume r) {
    free(r.name);
    free(r.email);
    free(r.phone);
    free(r.address);
    free(r.skills);
    free(r.experience);
    free(r.education);
}

// Main function
int main() {
    // Read the resume text from a file
    FILE *fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        perror("Error opening resume file");
        return EXIT_FAILURE;
    }
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *resume_text = malloc(size + 1);
    fread(resume_text, size, 1, fp);
    fclose(fp);

    // Parse the resume text
    resume r = parse_resume(resume_text);

    // Print the resume data
    print_resume(r);

    // Free the resume data
    free_resume(r);

    // Free the resume text
    free(resume_text);

    return EXIT_SUCCESS;
}