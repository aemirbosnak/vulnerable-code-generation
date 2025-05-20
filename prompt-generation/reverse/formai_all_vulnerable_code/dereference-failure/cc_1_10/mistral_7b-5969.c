//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: irregular
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char education[100];
    char skills[200];
} Candidate;

void parse_resume(FILE *fp, Candidate *candidate) {
    char line[100];
    char *token;

    fgets(line, sizeof(line), fp); // Read the first line
    strcpy(candidate->name, strtok(line, ",")); // Extract name

    fgets(line, sizeof(line), fp); // Read the second line
    candidate->age = atoi(strtok(line, "\n")); // Extract age

    fgets(line, sizeof(line), fp); // Read the third line
    strcpy(candidate->education, "");
    token = strtok(line, ",");
    strcat(candidate->education, token);
    while (token != NULL) {
        strcat(candidate->education, " ");
        strcat(candidate->education, token);
        token = strtok(NULL, ",");
    }

    fgets(line, sizeof(line), fp); // Read the fourth line
    strcpy(candidate->skills, "");
    token = strtok(line, "\n");
    strcat(candidate->skills, token);
    while (token != NULL) {
        strcat(candidate->skills, " ");
        strcat(candidate->skills, token);
        token = strtok(NULL, "\n");
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    Candidate candidate;

    if (argc != 2) {
        printf("Usage: %s <resume.txt>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s.\n", argv[1]);
        return 1;
    }

    parse_resume(fp, &candidate);
    printf("Name: %s\n", candidate.name);
    printf("Age: %d\n", candidate.age);
    printf("Education: %s\n", candidate.education);
    printf("Skills: %s\n", candidate.skills);

    fclose(fp);
    return 0;
}