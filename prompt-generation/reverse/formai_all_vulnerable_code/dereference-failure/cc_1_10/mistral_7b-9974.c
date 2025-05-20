//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[50];
    int age;
    float gpa;
    char skills[100][20];
} Candidate;

void parse_resume(FILE *fp, Candidate *candidate) {
    char line[100], *token;
    int i = 0;

    fgets(line, sizeof(line), fp); // Consume the first line (header)

    while (fgets(line, sizeof(line), fp) != NULL) {
        token = strtok(line, ": ");

        if (strcmp(token, "Name") == 0) {
            strcpy(candidate->name, strtok(NULL, "\n"));
        } else if (strcmp(token, "Age") == 0) {
            sscanf(strtok(NULL, "\n"), "%d", &candidate->age);
        } else if (strcmp(token, "GPA") == 0) {
            sscanf(strtok(NULL, "\n"), "%f", &candidate->gpa);
        } else if (strncmp(token, "Skills:", 6) == 0) {
            int j = 0;
            char *skill = strtok(NULL, "\n");

            while (skill != NULL && i < 9) {
                strcpy(candidate->skills[i], skill);
                i++;
                skill = strtok(NULL, "\n");
            }
        }
    }
}

int main() {
    FILE *fp;
    Candidate candidate;

    fp = fopen("resume.txt", "r");

    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    parse_resume(fp, &candidate);

    printf("Name: %s\n", candidate.name);
    printf("Age: %d\n", candidate.age);
    printf("GPA: %.2f\n", candidate.gpa);

    for (int i = 0; i < 9; i++) {
        printf("Skill %d: %s\n", i + 1, candidate.skills[i]);
    }

    fclose(fp);
    return 0;
}