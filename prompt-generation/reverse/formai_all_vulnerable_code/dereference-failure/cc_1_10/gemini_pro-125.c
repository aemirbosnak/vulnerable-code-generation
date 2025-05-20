//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: mathematical
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
    char *education;
    char *experience;
} Resume;

// Define the parser function
Resume *parse_resume(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    // Read the file into a string
    char *buffer = NULL;
    size_t len = 0;
    getline(&buffer, &len, file);

    // Close the file
    fclose(file);

    // Parse the string into a resume
    Resume *resume = malloc(sizeof(Resume));
    resume->name = strtok(buffer, ",");
    resume->email = strtok(NULL, ",");
    resume->phone = strtok(NULL, ",");
    resume->address = strtok(NULL, ",");
    resume->skills = strtok(NULL, ",");
    resume->education = strtok(NULL, ",");
    resume->experience = strtok(NULL, ",");

    // Return the resume
    return resume;
}

// Define the main function
int main(int argc, char **argv) {
    // Check if the user provided a filename
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Parse the resume
    Resume *resume = parse_resume(argv[1]);

    // Print the resume
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Skills: %s\n", resume->skills);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);

    // Free the resume
    free(resume);

    return 0;
}