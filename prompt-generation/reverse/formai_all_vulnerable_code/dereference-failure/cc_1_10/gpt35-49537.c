//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Resume {
    char *name;
    char *email;
    char *phone;
    char *education[10];
    char *workExperience[10];
    char *skills[10];
} Resume;

// Function to parse the resume file and fill the resume object
Resume *parseResume(char *fileName) {
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error: could not open file\n");
        return NULL;
    }

    Resume *resume = malloc(sizeof(Resume));
    char *buffer = malloc(sizeof(char) * 1024); // Assuming no line in the resume is longer than 1024 characters
    int i;

    // Parsing the Resume
    while (fgets(buffer, 1024, fp)) {
        // Parsing name
        if (strstr(buffer, "Name:")) {
            strtok(buffer, ":");
            resume->name = strdup(strtok(NULL, "\n"));
        }
        // Parsing email
        else if (strstr(buffer, "Email:")) {
            strtok(buffer, ":");
            resume->email = strdup(strtok(NULL, "\n"));
        }
        // Parsing phone number
        else if (strstr(buffer, "Phone:")) {
            strtok(buffer, ":");
            resume->phone = strdup(strtok(NULL, "\n"));
        }
        // Parsing education
        else if (strstr(buffer, "Education:")) {
            strtok(buffer, ":");
            i = 0;
            while (fgets(buffer, 1024, fp) && !strstr(buffer, "\n")) {
                resume->education[i++] = strdup(buffer);
            }
        }
        // Parsing work experience
        else if (strstr(buffer, "Work Experience:")) {
            strtok(buffer, ":");
            i = 0;
            while (fgets(buffer, 1024, fp) && !strstr(buffer, "\n")) {
                resume->workExperience[i++] = strdup(buffer);
            }
        }
        // Parsing skills
        else if (strstr(buffer, "Skills:")) {
            strtok(buffer, ":");
            i = 0;
            while (fgets(buffer, 1024, fp) && !strstr(buffer, "\n")) {
                resume->skills[i++] = strdup(buffer);
            }
        }
    }

    fclose(fp);
    free(buffer);

    return resume;
}

// Function to print the contents of the resume object
void printResume(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n\n", resume->phone);

    printf("Education:\n");
    for (int i = 0; resume->education[i] != NULL; i++) {
        printf("%s", resume->education[i]);
    }
    printf("\n");

    printf("Work Experience:\n");
    for (int i = 0; resume->workExperience[i] != NULL; i++) {
        printf("%s", resume->workExperience[i]);
    }
    printf("\n");

    printf("Skills:\n");
    for (int i = 0; resume->skills[i] != NULL; i++) {
        printf("%s", resume->skills[i]);
    }
}

int main() {
    Resume *resume = parseResume("resume.txt");
    if (resume != NULL) {
        printResume(resume);
    }
    return 0;
}