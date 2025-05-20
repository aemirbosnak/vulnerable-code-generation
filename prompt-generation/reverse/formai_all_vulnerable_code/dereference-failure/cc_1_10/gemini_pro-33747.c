//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *experience;
    char *education;
    char *awards;
    char *publications;
};

struct resume *parse_resume(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    char *line = NULL;
    size_t len = 0;
    struct resume *resume = malloc(sizeof(struct resume));
    resume->name = NULL;
    resume->email = NULL;
    resume->phone = NULL;
    resume->address = NULL;
    resume->skills = NULL;
    resume->experience = NULL;
    resume->education = NULL;
    resume->awards = NULL;
    resume->publications = NULL;

    char *field = NULL;
    char *value = NULL;
    while ((getline(&line, &len, fp)) != -1) {
        if (line[0] == '\n') {
            continue;
        }

        field = strtok(line, ":");
        if (field != NULL) {
            value = strtok(NULL, "\n");
            if (value != NULL) {
                if (strcmp(field, "Name") == 0) {
                    resume->name = strdup(value);
                } else if (strcmp(field, "Email") == 0) {
                    resume->email = strdup(value);
                } else if (strcmp(field, "Phone") == 0) {
                    resume->phone = strdup(value);
                } else if (strcmp(field, "Address") == 0) {
                    resume->address = strdup(value);
                } else if (strcmp(field, "Skills") == 0) {
                    resume->skills = strdup(value);
                } else if (strcmp(field, "Experience") == 0) {
                    resume->experience = strdup(value);
                } else if (strcmp(field, "Education") == 0) {
                    resume->education = strdup(value);
                } else if (strcmp(field, "Awards") == 0) {
                    resume->awards = strdup(value);
                } else if (strcmp(field, "Publications") == 0) {
                    resume->publications = strdup(value);
                }
            }
        }
    }

    fclose(fp);
    return resume;
}

void free_resume(struct resume *resume) {
    if (resume != NULL) {
        free(resume->name);
        free(resume->email);
        free(resume->phone);
        free(resume->address);
        free(resume->skills);
        free(resume->experience);
        free(resume->education);
        free(resume->awards);
        free(resume->publications);
        free(resume);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct resume *resume = parse_resume(argv[1]);
    if (resume != NULL) {
        printf("Name: %s\n", resume->name);
        printf("Email: %s\n", resume->email);
        printf("Phone: %s\n", resume->phone);
        printf("Address: %s\n", resume->address);
        printf("Skills: %s\n", resume->skills);
        printf("Experience: %s\n", resume->experience);
        printf("Education: %s\n", resume->education);
        printf("Awards: %s\n", resume->awards);
        printf("Publications: %s\n", resume->publications);

        free_resume(resume);
    } else {
        fprintf(stderr, "Error parsing resume\n");
        return 1;
    }

    return 0;
}