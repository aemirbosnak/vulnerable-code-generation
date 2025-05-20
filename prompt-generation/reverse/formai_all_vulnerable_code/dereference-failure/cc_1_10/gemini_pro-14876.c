//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store resume data
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *experience;
    char *education;
} resume;

// Function to parse a resume from a file
resume *parse_resume(char *filename) {
    FILE *fp;
    char *buffer;
    long length;
    resume *r;

    // Open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Get the length of the file
    fseek(fp, 0, SEEK_END);
    length = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate a buffer to hold the file contents
    buffer = malloc(length + 1);
    if (buffer == NULL) {
        fclose(fp);
        return NULL;
    }

    // Read the file into the buffer
    fread(buffer, 1, length, fp);
    fclose(fp);

    // Allocate a resume structure
    r = malloc(sizeof(resume));
    if (r == NULL) {
        free(buffer);
        return NULL;
    }

    // Parse the resume data from the buffer
    r->name = strtok(buffer, "\n");
    r->email = strtok(NULL, "\n");
    r->phone = strtok(NULL, "\n");
    r->address = strtok(NULL, "\n");
    r->skills = strtok(NULL, "\n");
    r->experience = strtok(NULL, "\n");
    r->education = strtok(NULL, "\n");

    // Free the buffer
    free(buffer);

    // Return the resume
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
int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Parse the resume
    resume *r = parse_resume(argv[1]);
    if (r == NULL) {
        printf("Error parsing resume\n");
        return 1;
    }

    // Print the resume
    print_resume(r);

    // Free the resume
    free(r);

    return 0;
}