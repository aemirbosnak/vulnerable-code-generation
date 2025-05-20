//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *experience;
    char *education;
} resume;

resume *parse_resume(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    resume *r = malloc(sizeof(resume));
    if (r == NULL) {
        fclose(fp);
        return NULL;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while ((nread = getline(&line, &len, fp)) != -1) {
        if (strncmp(line, "Name: ", 6) == 0) {
            r->name = strdup(line + 6);
        } else if (strncmp(line, "Email: ", 7) == 0) {
            r->email = strdup(line + 7);
        } else if (strncmp(line, "Phone: ", 7) == 0) {
            r->phone = strdup(line + 7);
        } else if (strncmp(line, "Skills: ", 8) == 0) {
            r->skills = strdup(line + 8);
        } else if (strncmp(line, "Experience: ", 11) == 0) {
            r->experience = strdup(line + 11);
        } else if (strncmp(line, "Education: ", 11) == 0) {
            r->education = strdup(line + 11);
        }
    }

    free(line);
    fclose(fp);

    return r;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    resume *r = parse_resume(argv[1]);
    if (r == NULL) {
        fprintf(stderr, "Error: Could not parse resume file.\n");
        return EXIT_FAILURE;
    }

    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Phone: %s\n", r->phone);
    printf("Skills: %s\n", r->skills);
    printf("Experience: %s\n", r->experience);
    printf("Education: %s\n", r->education);

    free(r->name);
    free(r->email);
    free(r->phone);
    free(r->skills);
    free(r->experience);
    free(r->education);
    free(r);

    return EXIT_SUCCESS;
}