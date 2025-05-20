//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_SKILLS_LENGTH 100
#define NUM_FIELDS 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    char skills[MAX_SKILLS_LENGTH];
} Resume;

void parse_line(char *line, Resume *resume) {
    char *token[NUM_FIELDS];
    int i;

    // Tokenize the line using space as delimiter
    token[0] = strtok(line, " ");
    for (i = 1; i < NUM_FIELDS; i++) {
        token[i] = strtok(NULL, " ");
    }

    // Parse the name field
    strcpy(resume->name, token[0]);

    // Parse the skills field
    int j = 0;
    for (i = 1; i < NUM_FIELDS && token[i] != NULL; i++) {
        if (j + strlen(token[i]) + 1 > MAX_SKILLS_LENGTH) {
            fprintf(stderr, "Skills field too long\n");
            exit(1);
        }
        strcat(resume->skills, token[i]);
        strcat(resume->skills, " ");
        j += strlen(token[i]) + 1;
    }
    resume->skills[strlen(resume->skills) - 1] = '\0'; // Remove last space
}

int main() {
    FILE *fp;
    char line[1024];
    Resume resume;

    // Open the resume file
    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Could not open file\n");
        exit(1);
    }

    // Parse each line of the file
    while (fgets(line, sizeof(line), fp) != NULL) {
        parse_line(line, &resume);
        printf("Name: %s\nSkills: %s\n\n", resume.name, resume.skills);
        memset(&resume, 0, sizeof(Resume)); // Reset resume for next iteration
    }

    fclose(fp);
    return 0;
}