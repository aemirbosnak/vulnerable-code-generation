//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_RESUME_LENGTH 100000

typedef struct {
    char name[100];
    char contact[100];
    char email[100];
    char education[500];
    char experience[500];
} Resume;

Resume resume;

void clearResume() {
    memset(&resume, 0, sizeof(Resume));
}

void parseResume(char* line) {
    char* token = strtok(line, ":");
    if (token == NULL) {
        return;
    }

    if (strcmp(token, "Name") == 0) {
        strcpy(resume.name, strtok(NULL, ":"));
    } else if (strcmp(token, "Contact") == 0) {
        strcpy(resume.contact, strtok(NULL, ":"));
    } else if (strcmp(token, "Email") == 0) {
        strcpy(resume.email, strtok(NULL, ":"));
    } else if (strcmp(token, "Education") == 0) {
        strcpy(resume.education, strtok(NULL, ":"));
    } else if (strcmp(token, "Experience") == 0) {
        strcpy(resume.experience, strtok(NULL, ":"));
    }
}

void printResume() {
    printf("Name: %s\n", resume.name);
    printf("Contact: %s\n", resume.contact);
    printf("Email: %s\n", resume.email);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
}

int main() {
    FILE* resumeFile;
    char line[MAX_LINE_SIZE];
    char* resumeText = NULL;
    size_t resumeLength = 0;

    resumeFile = fopen("resume.txt", "r");
    if (resumeFile == NULL) {
        printf("Error opening resume file.\n");
        return 1;
    }

    clearResume();

    while (fgets(line, MAX_LINE_SIZE, resumeFile)!= NULL) {
        if (resumeLength + strlen(line) > MAX_RESUME_LENGTH) {
            printf("Resume too long. Exceeded maximum length of %d characters.\n", MAX_RESUME_LENGTH);
            fclose(resumeFile);
            free(resumeText);
            return 1;
        }

        resumeText = realloc(resumeText, resumeLength + strlen(line) + 1);
        strcat(resumeText, line);
        resumeLength += strlen(line);
    }

    fclose(resumeFile);

    if (resumeLength == 0) {
        printf("Resume is empty.\n");
        free(resumeText);
        return 1;
    }

    resume.name[0] = '\0';
    resume.contact[0] = '\0';
    resume.email[0] = '\0';
    resume.education[0] = '\0';
    resume.experience[0] = '\0';

    char* token = strtok(resumeText, "\n");
    while (token!= NULL) {
        parseResume(token);
        token = strtok(NULL, "\n");
    }

    printResume();

    free(resumeText);

    return 0;
}