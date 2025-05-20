//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    char position[50];
    char company[100];
    int years_of_experience;
    bool is_married;
} Resume;

void parse_resume(const char *line, Resume *resume) {
    char *token;
    int i = 0;

    strcpy(resume->name, strtok(line, " |:"));

    token = strtok(NULL, " |:");
    strcpy(resume->position, token);

    token = strtok(NULL, " |:");
    strcpy(resume->company, token);

    token = strtok(NULL, " |:");
    resume->years_of_experience = atoi(token);

    token = strtok(NULL, " |:");
    resume->is_married = (strcmp(token, "Married") == 0) ? true : false;
}

int main() {
    FILE *file;
    char line[150];
    Resume resume;

    file = fopen("resumes.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        parse_resume(line, &resume);
        printf("\nName: %s\nPosition: %s\nCompany: %s\nYears of Experience: %d\nMarital Status: %s\n", resume.name, resume.position, resume.company, resume.years_of_experience, resume.is_married ? "Married" : "Single");
    }

    fclose(file);
    return 0;
}

// File resumes.txt contains resumes in the following format:
// Name | Position | Company | Years of Experience | Marital Status
// Romeo Montague | Software Engineer | Microsoft | 5 | Married
// Juliet Capulet | Project Manager | Google | 3 | Single