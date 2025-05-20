//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Function to parse a resume file and return a resume struct
resume *parse_resume(char *filename) {
    // Open the resume file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Allocate memory for the resume struct
    resume *r = malloc(sizeof(resume));
    if (r == NULL) {
        fclose(fp);
        return NULL;
    }

    // Read the resume file line by line
    char line[1024];
    while (fgets(line, 1024, fp) != NULL) {
        // Parse the line and extract the relevant data
        if (strstr(line, "Name:") != NULL) {
            r->name = strdup(strtok(line, ":"));
        } else if (strstr(line, "Email:") != NULL) {
            r->email = strdup(strtok(line, ":"));
        } else if (strstr(line, "Phone:") != NULL) {
            r->phone = strdup(strtok(line, ":"));
        } else if (strstr(line, "Address:") != NULL) {
            r->address = strdup(strtok(line, ":"));
        } else if (strstr(line, "Skills:") != NULL) {
            r->skills = strdup(strtok(line, ":"));
        } else if (strstr(line, "Experience:") != NULL) {
            r->experience = strdup(strtok(line, ":"));
        } else if (strstr(line, "Education:") != NULL) {
            r->education = strdup(strtok(line, ":"));
        }
    }

    // Close the resume file
    fclose(fp);

    // Return the resume struct
    return r;
}

// Function to print a resume
void print_resume(resume *r) {
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Phone: %s\n", r->phone);
    printf("Address: %s\n", r->address);
    printf("Skills: %s\n", r->skills);
    printf("Experience: %s\n", r->experience);
    printf("Education: %s\n", r->education);
}

// Main function
int main() {
    // Parse the resume file
    resume *r = parse_resume("resume.txt");

    // Print the resume
    print_resume(r);

    // Free the memory allocated for the resume struct
    free(r);

    return 0;
}