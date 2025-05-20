//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *experience;
    char *education;
} Candidate;

Candidate *parse_resume(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    Candidate *candidate = malloc(sizeof(Candidate));
    if (candidate == NULL) {
        fclose(fp);
        return NULL;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        char *key = strtok(buffer, ":");
        char *value = strtok(NULL, "\n");

        if (strcmp(key, "Name") == 0) {
            candidate->name = strdup(value);
        } else if (strcmp(key, "Email") == 0) {
            candidate->email = strdup(value);
        } else if (strcmp(key, "Phone") == 0) {
            candidate->phone = strdup(value);
        } else if (strcmp(key, "Skills") == 0) {
            candidate->skills = strdup(value);
        } else if (strcmp(key, "Experience") == 0) {
            candidate->experience = strdup(value);
        } else if (strcmp(key, "Education") == 0) {
            candidate->education = strdup(value);
        }
    }

    fclose(fp);
    return candidate;
}

int main(void) {
    Candidate *candidate = parse_resume("resume.txt");
    if (candidate == NULL) {
        printf("Could not parse resume.\n");
        return 1;
    }

    printf("Name: %s\n", candidate->name);
    printf("Email: %s\n", candidate->email);
    printf("Phone: %s\n", candidate->phone);
    printf("Skills: %s\n", candidate->skills);
    printf("Experience: %s\n", candidate->experience);
    printf("Education: %s\n", candidate->education);

    free(candidate->name);
    free(candidate->email);
    free(candidate->phone);
    free(candidate->skills);
    free(candidate->experience);
    free(candidate->education);
    free(candidate);

    return 0;
}