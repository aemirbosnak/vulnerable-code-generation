//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: detailed
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
    char *awards;
} resume;

// Define the resume parser function
resume *parse_resume(char *filename) {
    // Open the resume file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    // Create a new resume
    resume *r = malloc(sizeof(resume));
    if (r == NULL) {
        fclose(file);
        return NULL;
    }

    // Read the resume file into a buffer
    char *buffer = NULL;
    long length;
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);
    buffer = malloc(length + 1);
    if (buffer == NULL) {
        free(r);
        fclose(file);
        return NULL;
    }
    fread(buffer, 1, length, file);
    fclose(file);

    // Tokenize the resume
    char *tokens[1000];
    int num_tokens = 0;
    char *token = strtok(buffer, " \n");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " \n");
    }

    // Parse the resume
    for (int i = 0; i < num_tokens; i++) {
        if (strcmp(tokens[i], "Name:") == 0) {
            r->name = tokens[i + 1];
        } else if (strcmp(tokens[i], "Email:") == 0) {
            r->email = tokens[i + 1];
        } else if (strcmp(tokens[i], "Phone:") == 0) {
            r->phone = tokens[i + 1];
        } else if (strcmp(tokens[i], "Address:") == 0) {
            r->address = tokens[i + 1];
        } else if (strcmp(tokens[i], "Skills:") == 0) {
            r->skills = tokens[i + 1];
        } else if (strcmp(tokens[i], "Experience:") == 0) {
            r->experience = tokens[i + 1];
        } else if (strcmp(tokens[i], "Education:") == 0) {
            r->education = tokens[i + 1];
        } else if (strcmp(tokens[i], "Awards:") == 0) {
            r->awards = tokens[i + 1];
        }
    }

    // Free the buffer
    free(buffer);

    // Return the resume
    return r;
}

// Print the resume
void print_resume(resume *r) {
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Phone: %s\n", r->phone);
    printf("Address: %s\n", r->address);
    printf("Skills: %s\n", r->skills);
    printf("Experience: %s\n", r->experience);
    printf("Education: %s\n", r->education);
    printf("Awards: %s\n", r->awards);
}

// Main function
int main() {
    // Parse the resume
    resume *r = parse_resume("resume.txt");
    if (r == NULL) {
        return 1;
    }

    // Print the resume
    print_resume(r);

    // Free the resume
    free(r);

    return 0;
}