//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store resume data
typedef struct {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *experience;
    char *education;
} Resume;

// Function to parse a line of text and extract a specific field
char *parse_field(char *line, char *field_name) {
    char *start = strstr(line, field_name);
    if (!start) {
        return NULL;
    }
    start += strlen(field_name);
    char *end = strchr(start, '\n');
    if (!end) {
        return NULL;
    }
    *end = '\0';
    return start;
}

// Function to parse a resume from a file
Resume parse_resume(FILE *file) {
    Resume resume;

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // Get the name
    read = getline(&line, &len, file);
    if (read == -1) {
        return resume;
    }
    resume.name = parse_field(line, "Name:");

    // Get the email
    read = getline(&line, &len, file);
    if (read == -1) {
        return resume;
    }
    resume.email = parse_field(line, "Email:");

    // Get the phone
    read = getline(&line, &len, file);
    if (read == -1) {
        return resume;
    }
    resume.phone = parse_field(line, "Phone:");

    // Get the skills
    read = getline(&line, &len, file);
    if (read == -1) {
        return resume;
    }
    resume.skills = parse_field(line, "Skills:");

    // Get the experience
    read = getline(&line, &len, file);
    if (read == -1) {
        return resume;
    }
    resume.experience = parse_field(line, "Experience:");

    // Get the education
    read = getline(&line, &len, file);
    if (read == -1) {
        return resume;
    }
    resume.education = parse_field(line, "Education:");

    free(line);
    return resume;
}

// Function to print a resume
void print_resume(Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Skills: %s\n", resume.skills);
    printf("Experience: %s\n", resume.experience);
    printf("Education: %s\n", resume.education);
}

int main() {
    // Open the resume file
    FILE *file = fopen("resume.txt", "r");
    if (!file) {
        perror("Error opening resume file");
        return EXIT_FAILURE;
    }

    // Parse the resume
    Resume resume = parse_resume(file);

    // Print the resume
    print_resume(resume);

    // Close the resume file
    fclose(file);

    return EXIT_SUCCESS;
}