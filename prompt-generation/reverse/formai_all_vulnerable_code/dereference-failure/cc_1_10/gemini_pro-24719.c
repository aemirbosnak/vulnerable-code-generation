//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: statistical
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
} resume_t;

// Define the resume parser function
resume_t *parse_resume(char *filename) {
    // Open the resume file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    // Read the resume into a string
    char *resume_str = NULL;
    size_t resume_len = 0;
    if (getline(&resume_str, &resume_len, file) == -1) {
        fprintf(stderr, "Error reading file %s\n", filename);
        fclose(file);
        return NULL;
    }

    // Close the resume file
    fclose(file);

    // Allocate memory for the resume struct
    resume_t *resume = malloc(sizeof(resume_t));
    if (resume == NULL) {
        fprintf(stderr, "Error allocating memory for resume\n");
        free(resume_str);
        return NULL;
    }

    // Parse the resume string
    char *delim = "\n";
    char *token = strtok(resume_str, delim);
    while (token != NULL) {
        // Parse the name
        if (strstr(token, "Name:") != NULL) {
            resume->name = strdup(token + strlen("Name: "));
        }

        // Parse the email
        else if (strstr(token, "Email:") != NULL) {
            resume->email = strdup(token + strlen("Email: "));
        }

        // Parse the phone
        else if (strstr(token, "Phone:") != NULL) {
            resume->phone = strdup(token + strlen("Phone: "));
        }

        // Parse the address
        else if (strstr(token, "Address:") != NULL) {
            resume->address = strdup(token + strlen("Address: "));
        }

        // Parse the skills
        else if (strstr(token, "Skills:") != NULL) {
            resume->skills = strdup(token + strlen("Skills: "));
        }

        // Parse the experience
        else if (strstr(token, "Experience:") != NULL) {
            resume->experience = strdup(token + strlen("Experience: "));
        }

        // Parse the education
        else if (strstr(token, "Education:") != NULL) {
            resume->education = strdup(token + strlen("Education: "));
        }

        // Get the next token
        token = strtok(NULL, delim);
    }

    // Free the resume string
    free(resume_str);

    // Return the resume struct
    return resume;
}

// Define the main function
int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <resume_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse the resume file
    resume_t *resume = parse_resume(argv[1]);
    if (resume == NULL) {
        return EXIT_FAILURE;
    }

    // Print the resume
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
    printf("Education: %s\n", resume->education);

    // Free the resume struct
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->address);
    free(resume->skills);
    free(resume->experience);
    free(resume->education);
    free(resume);

    return EXIT_SUCCESS;
}