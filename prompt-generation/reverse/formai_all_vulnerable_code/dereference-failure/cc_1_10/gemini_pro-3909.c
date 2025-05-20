//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct resume {
    char *name;
    char *title;
    char *skills;
    char *experience;
    char *education;
} resume;

resume *parse_resume(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    resume *r = malloc(sizeof(resume));
    r->name = NULL;
    r->title = NULL;
    r->skills = NULL;
    r->experience = NULL;
    r->education = NULL;

    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[0] == '#') {
            continue;
        }

        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        if (strcmp(key, "name") == 0) {
            r->name = strdup(value);
        } else if (strcmp(key, "title") == 0) {
            r->title = strdup(value);
        } else if (strcmp(key, "skills") == 0) {
            r->skills = strdup(value);
        } else if (strcmp(key, "experience") == 0) {
            r->experience = strdup(value);
        } else if (strcmp(key, "education") == 0) {
            r->education = strdup(value);
        }
    }

    fclose(fp);
    return r;
}

void print_resume(resume *r) {
    printf("Name: %s\n", r->name);
    printf("Title: %s\n", r->title);
    printf("Skills: %s\n", r->skills);
    printf("Experience: %s\n", r->experience);
    printf("Education: %s\n", r->education);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    resume *r = parse_resume(argv[1]);
    if (r == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", argv[1]);
        return 1;
    }

    print_resume(r);
    return 0;
}