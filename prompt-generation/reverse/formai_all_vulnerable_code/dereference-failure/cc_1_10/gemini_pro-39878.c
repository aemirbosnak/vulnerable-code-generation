//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defines the structure of a resume.
typedef struct {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *experience;
    char *education;
} Resume;

// Loads a resume from a file.
Resume *load_resume(const char *filename) {
    // Opens the file.
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    // Reads the header of the file.
    char header[1024];
    if (fgets(header, sizeof(header), file) == NULL) {
        fclose(file);
        return NULL;
    }

    // Allocates memory for the resume.
    Resume *resume = malloc(sizeof(Resume));
    if (resume == NULL) {
        fclose(file);
        return NULL;
    }

    // Initializes the resume.
    resume->name = NULL;
    resume->email = NULL;
    resume->phone = NULL;
    resume->address = NULL;
    resume->skills = NULL;
    resume->experience = NULL;
    resume->education = NULL;

    // Parses the header of the file.
    char *name = strtok(header, ",");
    char *email = strtok(NULL, ",");
    char *phone = strtok(NULL, ",");
    char *address = strtok(NULL, ",");

    // Sets the fields of the resume.
    resume->name = strdup(name);
    resume->email = strdup(email);
    resume->phone = strdup(phone);
    resume->address = strdup(address);

    // Reads the body of the file.
    char body[1024];
    while (fgets(body, sizeof(body), file) != NULL) {
        // Parses the body of the file.
        char *skills = strtok(body, ",");
        char *experience = strtok(NULL, ",");
        char *education = strtok(NULL, ",");

        // Sets the fields of the resume.
        resume->skills = strdup(skills);
        resume->experience = strdup(experience);
        resume->education = strdup(education);
    }

    // Closes the file.
    fclose(file);

    // Returns the resume.
    return resume;
}

// Prints a resume.
void print_resume(Resume *resume) {
    // Prints the header of the resume.
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);

    // Prints the body of the resume.
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
    printf("Education: %s\n", resume->education);
}

// Frees the memory allocated for a resume.
void free_resume(Resume *resume) {
    // Frees the fields of the resume.
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->address);
    free(resume->skills);
    free(resume->experience);
    free(resume->education);

    // Frees the resume itself.
    free(resume);
}

// Main function.
int main(int argc, char *argv[]) {
    // Checks the number of arguments.
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Loads the resume.
    Resume *resume = load_resume(argv[1]);
    if (resume == NULL) {
        printf("Error: could not load resume.\n");
        return 1;
    }

    // Prints the resume.
    print_resume(resume);

    // Frees the resume.
    free_resume(resume);

    return 0;
}