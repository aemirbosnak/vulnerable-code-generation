//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *education;
    char *experience;
    char *references;
} resume_t;

resume_t *parse_resume(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    resume_t *resume = malloc(sizeof(resume_t));
    if (resume == NULL) {
        fclose(fp);
        return NULL;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        if (key == NULL || value == NULL) {
            continue;
        }

        if (strcmp(key, "Name") == 0) {
            resume->name = strdup(value);
        } else if (strcmp(key, "Email") == 0) {
            resume->email = strdup(value);
        } else if (strcmp(key, "Phone") == 0) {
            resume->phone = strdup(value);
        } else if (strcmp(key, "Address") == 0) {
            resume->address = strdup(value);
        } else if (strcmp(key, "Skills") == 0) {
            resume->skills = strdup(value);
        } else if (strcmp(key, "Education") == 0) {
            resume->education = strdup(value);
        } else if (strcmp(key, "Experience") == 0) {
            resume->experience = strdup(value);
        } else if (strcmp(key, "References") == 0) {
            resume->references = strdup(value);
        }
    }

    fclose(fp);
    free(line);

    return resume;
}

void print_resume(resume_t *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Skills: %s\n", resume->skills);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
    printf("References: %s\n", resume->references);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    resume_t *resume = parse_resume(argv[1]);
    if (resume == NULL) {
        fprintf(stderr, "Error parsing resume file.\n");
        return EXIT_FAILURE;
    }

    print_resume(resume);

    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->address);
    free(resume->skills);
    free(resume->education);
    free(resume->experience);
    free(resume->references);
    free(resume);

    return EXIT_SUCCESS;
}