//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the resume structure
typedef struct Resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *experience;
    char *education;
} Resume;

// Define the resume parsing function
Resume *parse_resume(char *filename) {
    // Open the resume file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    // Read the resume file into a buffer
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *buffer = malloc(size + 1);
    fread(buffer, size, 1, file);
    buffer[size] = '\0';
    fclose(file);

    // Parse the resume file
    Resume *resume = malloc(sizeof(Resume));
    resume->name = NULL;
    resume->email = NULL;
    resume->phone = NULL;
    resume->address = NULL;
    resume->skills = NULL;
    resume->experience = NULL;
    resume->education = NULL;

    char *line = strtok(buffer, "\n");
    while (line != NULL) {
        if (strstr(line, "Name:") != NULL) {
            resume->name = strdup(line + strlen("Name: "));
        } else if (strstr(line, "Email:") != NULL) {
            resume->email = strdup(line + strlen("Email: "));
        } else if (strstr(line, "Phone:") != NULL) {
            resume->phone = strdup(line + strlen("Phone: "));
        } else if (strstr(line, "Address:") != NULL) {
            resume->address = strdup(line + strlen("Address: "));
        } else if (strstr(line, "Skills:") != NULL) {
            resume->skills = strdup(line + strlen("Skills: "));
        } else if (strstr(line, "Experience:") != NULL) {
            resume->experience = strdup(line + strlen("Experience: "));
        } else if (strstr(line, "Education:") != NULL) {
            resume->education = strdup(line + strlen("Education: "));
        }

        line = strtok(NULL, "\n");
    }

    // Free the buffer
    free(buffer);

    // Return the resume
    return resume;
}

// Define the main function
int main() {
    // Parse the resume file
    Resume *resume = parse_resume("resume.txt");

    // Print the resume
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
    printf("Education: %s\n", resume->education);

    // Free the resume
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->address);
    free(resume->skills);
    free(resume->experience);
    free(resume->education);
    free(resume);

    return 0;
}