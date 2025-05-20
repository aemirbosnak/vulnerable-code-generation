//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_LENGTH 256

typedef struct {
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
    char experience[MAX_LENGTH];
} Resume;

// Function prototypes
void parseResume(char *line, Resume *resume);
void displayResume(Resume *resume);
void trimWhitespace(char *str);

int main() {
    FILE *file;
    char line[MAX_LENGTH];
    Resume resumes[MAX_RESUMES];
    int resumeCount = 0;

    // Open the resumes file
    file = fopen("resumes.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read each line in the file and parse resumes
    while (fgets(line, sizeof(line), file) && resumeCount < MAX_RESUMES) {
        trimWhitespace(line);
        if (strlen(line) > 0) {
            parseResume(line, &resumes[resumeCount]);
            resumeCount++;
        }
    }

    fclose(file);

    // Display all parsed resumes
    for (int i = 0; i < resumeCount; i++) {
        printf("Resume %d:\n", i + 1);
        displayResume(&resumes[i]);
        printf("\n");
    }

    return EXIT_SUCCESS;
}

// Function to parse a line into a Resume object
void parseResume(char *line, Resume *resume) {
    char *token = strtok(line, ",");
    if (token != NULL) {
        strcpy(resume->name, token);
        token = strtok(NULL, ",");
    }
    if (token != NULL) {
        strcpy(resume->email, token);
        token = strtok(NULL, ",");
    }
    if (token != NULL) {
        strcpy(resume->experience, token);
    }
}

// Function to display a Resume
void displayResume(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Experience: %s\n", resume->experience);
}

// Function to trim whitespace from a string
void trimWhitespace(char *str) {
    char *end;

    // Trim leading space
    while(isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;
    end[1] = '\0';
}