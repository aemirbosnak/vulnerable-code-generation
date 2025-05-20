//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *experience;
    struct resume *next;
} resume_t;

resume_t *parse_resume(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    resume_t *head = NULL;
    resume_t *tail = NULL;

    while ((read = getline(&line, &len, fp)) != -1) {
        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        if (strcmp(key, "Name") == 0) {
            resume_t *new_resume = malloc(sizeof(resume_t));
            new_resume->name = malloc(strlen(value) + 1);
            strcpy(new_resume->name, value);
            new_resume->email = NULL;
            new_resume->phone = NULL;
            new_resume->skills = NULL;
            new_resume->experience = NULL;
            new_resume->next = NULL;

            if (head == NULL) {
                head = new_resume;
                tail = new_resume;
            } else {
                tail->next = new_resume;
                tail = new_resume;
            }
        } else if (strcmp(key, "Email") == 0) {
            tail->email = malloc(strlen(value) + 1);
            strcpy(tail->email, value);
        } else if (strcmp(key, "Phone") == 0) {
            tail->phone = malloc(strlen(value) + 1);
            strcpy(tail->phone, value);
        } else if (strcmp(key, "Skills") == 0) {
            tail->skills = malloc(strlen(value) + 1);
            strcpy(tail->skills, value);
        } else if (strcmp(key, "Experience") == 0) {
            tail->experience = malloc(strlen(value) + 1);
            strcpy(tail->experience, value);
        }
    }

    free(line);

    return head;
}

void print_resume(resume_t *resume) {
    if (resume == NULL) {
        return;
    }

    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);

    print_resume(resume->next);
}

void free_resume(resume_t *resume) {
    if (resume == NULL) {
        return;
    }

    free_resume(resume->next);

    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->skills);
    free(resume->experience);
    free(resume);
}

int main() {
    FILE *fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    resume_t *resume = parse_resume(fp);
    if (resume == NULL) {
        fprintf(stderr, "Error parsing resume\n");
        return EXIT_FAILURE;
    }

    print_resume(resume);

    free_resume(resume);

    fclose(fp);

    return EXIT_SUCCESS;
}