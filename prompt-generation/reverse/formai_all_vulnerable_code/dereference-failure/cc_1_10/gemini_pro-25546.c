//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Data structures
typedef struct {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *experience;
    char *education;
} Resume;

// Function prototypes
Resume *parse_resume(char *filename);
void print_resume(Resume *resume);

// Main function
int main(int argc, char *argv[]) {
    // Check if a filename is provided
    if (argc != 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse the resume
    Resume *resume = parse_resume(argv[1]);

    // Print the resume
    print_resume(resume);

    // Free the memory allocated for the resume
    free(resume);

    return EXIT_SUCCESS;
}

// Function to parse a resume from a file
Resume *parse_resume(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Allocate memory for the resume
    Resume *resume = malloc(sizeof(Resume));

    // Read the resume header
    char line[1024];
    fgets(line, sizeof(line), file);
    if (strncmp(line, "Name:", 5) != 0) {
        printf("Error reading resume header\n");
        free(resume);
        fclose(file);
        return NULL;
    }
    resume->name = strdup(line + 5);

    // Read the resume email
    fgets(line, sizeof(line), file);
    if (strncmp(line, "Email:", 6) != 0) {
        printf("Error reading resume email\n");
        free(resume->name);
        free(resume);
        fclose(file);
        return NULL;
    }
    resume->email = strdup(line + 6);

    // Read the resume phone
    fgets(line, sizeof(line), file);
    if (strncmp(line, "Phone:", 6) != 0) {
        printf("Error reading resume phone\n");
        free(resume->name);
        free(resume->email);
        free(resume);
        fclose(file);
        return NULL;
    }
    resume->phone = strdup(line + 6);

    // Read the resume skills
    fgets(line, sizeof(line), file);
    if (strncmp(line, "Skills:", 7) != 0) {
        printf("Error reading resume skills\n");
        free(resume->name);
        free(resume->email);
        free(resume->phone);
        free(resume);
        fclose(file);
        return NULL;
    }
    resume->skills = strdup(line + 7);

    // Read the resume experience
    fgets(line, sizeof(line), file);
    if (strncmp(line, "Experience:", 11) != 0) {
        printf("Error reading resume experience\n");
        free(resume->name);
        free(resume->email);
        free(resume->phone);
        free(resume->skills);
        free(resume);
        fclose(file);
        return NULL;
    }
    resume->experience = strdup(line + 11);

    // Read the resume education
    fgets(line, sizeof(line), file);
    if (strncmp(line, "Education:", 10) != 0) {
        printf("Error reading resume education\n");
        free(resume->name);
        free(resume->email);
        free(resume->phone);
        free(resume->skills);
        free(resume->experience);
        free(resume);
        fclose(file);
        return NULL;
    }
    resume->education = strdup(line + 10);

    // Close the file
    fclose(file);

    // Return the resume
    return resume;
}

// Function to print a resume
void print_resume(Resume *resume) {
    // Print the resume header
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);

    // Print the resume skills
    printf("Skills:\n");
    printf("%s\n", resume->skills);

    // Print the resume experience
    printf("Experience:\n");
    printf("%s\n", resume->experience);

    // Print the resume education
    printf("Education:\n");
    printf("%s\n", resume->education);
}