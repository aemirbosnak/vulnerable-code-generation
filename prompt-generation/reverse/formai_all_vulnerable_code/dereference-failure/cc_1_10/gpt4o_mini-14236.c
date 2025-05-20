//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RESUMES 100
#define MAX_LINE_LENGTH 256

typedef struct {
    char name[50];
    char email[50];
    char phone[20];
    char skills[5][30]; // Support for up to 5 skills
    int skills_count;
} Resume;

void parseResume(const char* line, Resume* resume) {
    char* token = strtok(line, ";");
    
    strcpy(resume->name, token);
    
    token = strtok(NULL, ";");
    strcpy(resume->email, token);
    
    token = strtok(NULL, ";");
    strcpy(resume->phone, token);
    
    resume->skills_count = 0;
    while ((token = strtok(NULL, ",")) != NULL && resume->skills_count < 5) {
        strcpy(resume->skills[resume->skills_count], token);
        resume->skills_count++;
    }
}

void printResume(const Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: ");
    for (int i = 0; i < resume->skills_count; i++) {
        printf("%s", resume->skills[i]);
        if (i < resume->skills_count - 1) {
            printf(", ");
        }
    }
    printf("\n\n");
}

bool readResumes(const char* filename, Resume resumes[], int* count) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return false;
    }
    
    char line[MAX_LINE_LENGTH];
    *count = 0;
    
    while (fgets(line, sizeof(line), file) && *count < MAX_RESUMES) {
        line[strcspn(line, "\n")] = 0; // Remove newline character
        parseResume(line, &resumes[*count]);
        (*count)++;
    }

    fclose(file);
    return true;
}

int main() {
    Resume resumes[MAX_RESUMES];
    int count;

    if (!readResumes("resumes.txt", resumes, &count)) {
        return EXIT_FAILURE;
    }

    printf("Parsed Resumes:\n");
    for (int i = 0; i < count; i++) {
        printResume(&resumes[i]);
    }

    return EXIT_SUCCESS;
}