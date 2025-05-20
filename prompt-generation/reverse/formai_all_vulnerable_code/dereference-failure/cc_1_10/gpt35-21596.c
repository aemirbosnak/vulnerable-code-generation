//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

struct resume {
    char name[50];
    char education[50];
    char skills[100];
    struct resume *next;
};

void print_resume(struct resume *r) {
    printf("Name: %s\n", r->name);
    printf("Education: %s\n", r->education);
    printf("Skills: %s\n", r->skills);
    printf("--------------------------\n");
}

struct resume *parse_resume(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file '%s' for reading\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    struct resume *r = NULL;
    struct resume *last_r = NULL;

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        char *newline = strchr(line, '\n');
        if (newline != NULL) *newline = '\0'; // remove trailing newline
        if (line[0] == '\0') continue; // skip empty lines

        if (strncasecmp(line, "name:", 5) == 0) {
            r = malloc(sizeof(struct resume));
            if (last_r != NULL) {
                last_r->next = r;
            }
            last_r = r;
            memset(r, 0, sizeof(struct resume));

            strncpy(r->name, line + 5, sizeof(r->name) - 1);
            // Trim whitespace from name
            char *name_end = strchr(r->name, '\0');
            while (name_end > r->name && isspace(*(name_end-1))) {
                name_end--;
            }
            *name_end = '\0';
        } else if (r != NULL) {
            if (strncasecmp(line, "education:", 10) == 0) {
                strncpy(r->education, line + 10, sizeof(r->education) - 1);
            } else if (strncasecmp(line, "skills:", 7) == 0) {
                strncpy(r->skills, line + 7, sizeof(r->skills) - 1);
            } else {
                fprintf(stderr, "Unknown line type: '%s'\n", line);
            }
        } else {
            fprintf(stderr, "Found line before name: '%s'\n", line);
        }
    }

    fclose(fp);
    return r;
}

void free_resumes(struct resume *r) {
    if (r == NULL) return;
    free_resumes(r->next);
    free(r);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <resume_file>\n", argv[0]);
        return 1;
    }

    struct resume *r = parse_resume(argv[1]);
    while (r != NULL) {
        print_resume(r);
        r = r->next;
    }
    free_resumes(r);

    return 0;
}