//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store resume data
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *experience;
    char *education;
} resume_t;

// Function to parse a resume file and store the data in a resume struct
resume_t *parse_resume(const char *filename) {
    // Open the resume file
    FILE *file = fopen(filename, "r");
    if (!file) {
        return NULL;
    }

    // Allocate memory for the resume struct
    resume_t *resume = malloc(sizeof(resume_t));
    if (!resume) {
        fclose(file);
        return NULL;
    }

    // Initialize the resume struct
    resume->name = NULL;
    resume->email = NULL;
    resume->phone = NULL;
    resume->skills = NULL;
    resume->experience = NULL;
    resume->education = NULL;

    // Read the resume file line by line
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Parse the line and store the data in the resume struct
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
        } else if (strstr(line, "Education:")) {
            resume->education = strdup(line + 11);
        }
    }

    // Close the resume file
    fclose(file);

    // Return the resume struct
    return resume;
}

// Function to print the resume data
void print_resume(resume_t *resume) {
    // Print the resume data
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
    printf("Education: %s\n", resume->education);
}

// Function to free the memory allocated for the resume struct
void free_resume(resume_t *resume) {
    // Free the memory allocated for the resume data
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->skills);
    free(resume->experience);
    free(resume->education);

    // Free the memory allocated for the resume struct
    free(resume);
}

int main(int argc, char *argv[]) {
    // Parse the resume file
    resume_t *resume = parse_resume(argv[1]);

    // Print the resume data
    print_resume(resume);

    // Free the memory allocated for the resume struct
    free_resume(resume);

    return 0;
}