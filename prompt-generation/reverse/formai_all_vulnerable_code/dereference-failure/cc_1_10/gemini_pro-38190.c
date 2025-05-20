//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *experience;
    char *education;
} Resume;

// Function to parse a resume
Resume *parse_resume(char *filename) {
    // Read the resume file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening resume file: %s\n", filename);
        return NULL;
    }
    char *buffer = malloc(1024);
    fread(buffer, 1024, 1, file);
    fclose(file);

    // Tokenize the resume
    char *token = strtok(buffer, "\n");
    char *tokens[100];
    int i = 0;
    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, "\n");
    }

    // Parse the tokens
    Resume *resume = malloc(sizeof(Resume));
    resume->name = tokens[0];
    resume->email = tokens[1];
    resume->phone = tokens[2];
    resume->skills = tokens[3];
    resume->experience = tokens[4];
    resume->education = tokens[5];

    // Return the resume
    return resume;
}

// Function to print a resume
void print_resume(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
    printf("Education: %s\n", resume->education);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <resume file>\n", argv[0]);
        return 1;
    }

    // Parse the resume
    Resume *resume = parse_resume(argv[1]);
    if (resume == NULL) {
        return 1;
    }

    // Print the resume
    print_resume(resume);

    // Free the resume
    free(resume);

    return 0;
}