//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *experience;
    char *education;
} Resume;

Resume *parse_resume(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    Resume *resume = malloc(sizeof(Resume));
    resume->name = NULL;
    resume->email = NULL;
    resume->phone = NULL;
    resume->skills = NULL;
    resume->experience = NULL;
    resume->education = NULL;

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "Name:", 5) == 0) {
            resume->name = strdup(line + 5);
        } else if (strncmp(line, "Email:", 6) == 0) {
            resume->email = strdup(line + 6);
        } else if (strncmp(line, "Phone:", 6) == 0) {
            resume->phone = strdup(line + 6);
        } else if (strncmp(line, "Skills:", 7) == 0) {
            resume->skills = strdup(line + 7);
        } else if (strncmp(line, "Experience:", 10) == 0) {
            resume->experience = strdup(line + 10);
        } else if (strncmp(line, "Education:", 9) == 0) {
            resume->education = strdup(line + 9);
        }
    }

    fclose(fp);

    return resume;
}

void print_resume(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
    printf("Education: %s\n", resume->education);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    Resume *resume = parse_resume(argv[1]);
    if (resume == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", argv[1]);
        return 1;
    }

    print_resume(resume);

    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->skills);
    free(resume->experience);
    free(resume->education);
    free(resume);

    return 0;
}