//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: all-encompassing
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

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    Resume *resume = malloc(sizeof(Resume));
    if (resume == NULL) {
        fclose(fp);
        return NULL;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strncmp(line, "Name:", 5) == 0) {
            resume->name = strdup(line + 5);
        } else if (strncmp(line, "Email:", 6) == 0) {
            resume->email = strdup(line + 6);
        } else if (strncmp(line, "Phone:", 6) == 0) {
            resume->phone = strdup(line + 6);
        } else if (strncmp(line, "Skills:", 7) == 0) {
            resume->skills = strdup(line + 7);
        } else if (strncmp(line, "Experience:", 11) == 0) {
            resume->experience = strdup(line + 11);
        } else if (strncmp(line, "Education:", 10) == 0) {
            resume->education = strdup(line + 10);
        }
    }

    fclose(fp);
    free(line);

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
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Resume *resume = parse_resume(argv[1]);
    if (resume == NULL) {
        fprintf(stderr, "Error: could not parse resume\n");
        return EXIT_FAILURE;
    }

    print_resume(resume);

    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->skills);
    free(resume->experience);
    free(resume->education);
    free(resume);

    return EXIT_SUCCESS;
}