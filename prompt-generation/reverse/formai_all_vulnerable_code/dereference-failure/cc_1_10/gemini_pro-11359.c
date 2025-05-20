//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *experience;
} resume;

resume *parse_resume(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        return NULL;
    }

    resume *r = malloc(sizeof(resume));
    if (!r) {
        fclose(fp);
        return NULL;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        if (!strcmp(key, "name")) {
            r->name = strdup(value);
        } else if (!strcmp(key, "email")) {
            r->email = strdup(value);
        } else if (!strcmp(key, "phone")) {
            r->phone = strdup(value);
        } else if (!strcmp(key, "skills")) {
            r->skills = strdup(value);
        } else if (!strcmp(key, "experience")) {
            r->experience = strdup(value);
        }
    }

    fclose(fp);
    return r;
}

void print_resume(resume *r) {
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Phone: %s\n", r->phone);
    printf("Skills: %s\n", r->skills);
    printf("Experience: %s\n", r->experience);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    resume *r = parse_resume(argv[1]);
    if (!r) {
        fprintf(stderr, "Error: could not parse resume\n");
        return 1;
    }

    print_resume(r);

    free(r->name);
    free(r->email);
    free(r->phone);
    free(r->skills);
    free(r->experience);
    free(r);

    return 0;
}