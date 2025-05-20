//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the resume struct
typedef struct {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *experience;
} Resume;

// Function to parse a resume
Resume *parse_resume(char *filename) {
    // Open the resume file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    // Allocate memory for the resume struct
    Resume *resume = malloc(sizeof(Resume));
    if (resume == NULL) {
        fprintf(stderr, "Error allocating memory for resume\n");
        return NULL;
    }

    // Read the resume file line by line
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Strip the newline character from the line
        line[strcspn(line, "\n")] = 0;

        // Parse the line and extract the resume data
        if (strstr(line, "Name:")) {
            resume->name = strdup(line + 6);
        } else if (strstr(line, "Email:")) {
            resume->email = strdup(line + 7);
        } else if (strstr(line, "Phone:")) {
            resume->phone = strdup(line + 7);
        } else if (strstr(line, "Skills:")) {
            resume->skills = strdup(line + 8);
        } else if (strstr(line, "Experience:")) {
            resume->experience = strdup(line + 12);
        }
    }

    // Close the resume file
    fclose(file);

    // Return the resume struct
    return resume;
}

// Function to print the resume
void print_resume(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
}

// Main function
int main(int argc, char **argv) {
    // Check if the user specified a resume file
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <resume file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse the resume file
    Resume *resume = parse_resume(argv[1]);
    if (resume == NULL) {
        return EXIT_FAILURE;
    }

    // Print the resume
    print_resume(resume);

    // Free the memory allocated for the resume struct
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->skills);
    free(resume->experience);
    free(resume);

    return EXIT_SUCCESS;
}