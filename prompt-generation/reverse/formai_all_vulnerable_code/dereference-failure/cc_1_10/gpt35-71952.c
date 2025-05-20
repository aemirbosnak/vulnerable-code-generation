//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 1000
#define MAX_FIELDS 10
#define MAX_FIELD_LENGTH 100

// Struct to store resume information
typedef struct {
    char name[MAX_FIELD_LENGTH];
    char email[MAX_FIELD_LENGTH];
    char phone[MAX_FIELD_LENGTH];
    char address[MAX_FIELD_LENGTH];
    char education[MAX_FIELD_LENGTH];
    char experience[MAX_FIELD_LENGTH];
    char skills[MAX_FIELD_LENGTH];
} Resume;

// Array of resumes
Resume resumes[MAX_RESUMES];
int num_resumes = 0;

// Function to parse a resume string and fill in a Resume struct
void parse_resume(char *resume_str, Resume *resume) {
    // Split the resume string by newline character
    char *line = strtok(resume_str, "\n");
    while (line != NULL) {
        // Split each line by colon character
        char *field = strtok(line, ":");
        char *value = strtok(NULL, ":");

        // Store the field value in the appropriate struct field
        if (strcmp(field, "Name") == 0) {
            strcpy(resume->name, value);
        } else if (strcmp(field, "Email") == 0) {
            strcpy(resume->email, value);
        } else if (strcmp(field, "Phone") == 0) {
            strcpy(resume->phone, value);
        } else if (strcmp(field, "Address") == 0) {
            strcpy(resume->address, value);
        } else if (strcmp(field, "Education") == 0) {
            strcpy(resume->education, value);
        } else if (strcmp(field, "Experience") == 0) {
            strcpy(resume->experience, value);
        } else if (strcmp(field, "Skills") == 0) {
            strcpy(resume->skills, value);
        }

        // Get the next line
        line = strtok(NULL, "\n");
    }
}

// Function to read resumes from a file
void read_resumes(char *filename) {
    // Open the file for reading
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Read each line and parse the resume
    char line[MAX_FIELD_LENGTH];
    while (fgets(line, MAX_FIELD_LENGTH, file) != NULL) {
        Resume resume;
        parse_resume(line, &resume);
        resumes[num_resumes++] = resume;
    }

    // Close the file
    fclose(file);
}

// Main function
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <resumes_filename>\n", argv[0]);
        exit(1);
    }

    // Read resumes from the file
    read_resumes(argv[1]);

    // Print the resumes
    for (int i = 0; i < num_resumes; i++) {
        Resume resume = resumes[i];
        printf("Name: %s\n", resume.name);
        printf("Email: %s\n", resume.email);
        printf("Phone: %s\n", resume.phone);
        printf("Address: %s\n", resume.address);
        printf("Education: %s\n", resume.education);
        printf("Experience: %s\n", resume.experience);
        printf("Skills: %s\n", resume.skills);
        printf("\n");
    }

    return 0;
}